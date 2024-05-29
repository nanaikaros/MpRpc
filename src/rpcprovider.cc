
#include "rpcprovider.h"

#include "mprpcapplication.h"
#include "rpcheader.pb.h"
// 这里是框架提供给外部使用的，发布rpc方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service* service) {
  ServiceInfo service_info;
  // 获取服务对象的描述信息
  const google::protobuf::ServiceDescriptor* pserviceDesc =
      service->GetDescriptor();
  // 获取服务信息
  std::string service_name = pserviceDesc->name();

  std::cout << "service name: " << service_name << std::endl;

  // 获取服务对象方法的数量
  int methodCnt = pserviceDesc->method_count();

  for (int i = 0; i < methodCnt; ++i) {
    // 获取了服务对象指定下标的服务方法的描述
    const google::protobuf::MethodDescriptor* pmethodDesc =
        pserviceDesc->method(i);
    std::string method_name = pmethodDesc->name();
    service_info.m_methodMap.insert({method_name, pmethodDesc});

    std::cout << "method name: " << method_name << std::endl;
  }

  service_info.m_service = service;
  m_serviceMap.insert({service_name, service_info});
}

// 启动rpc服务节点，开始提供rpc提供服务
void RpcProvider::Run() {
  std::string ip =
      MpRpcApplication::GetInstance().GetConfig().Load("rpcserverip");
  uint16_t port = atoi(MpRpcApplication::GetInstance()
                           .GetConfig()
                           .Load("rpcserverport")
                           .c_str());
  muduo::net::InetAddress address(ip, port);

  // 创建Tcpserver对象
  muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");
  // 绑定链接回调和消息读写回调方法
  server.setConnectionCallback(
      std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));

  server.setMessageCallback(
      std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3));
  // 设置muduo库的线程数量
  server.setThreadNum(4);

  // 启动网络服务
  server.start();
  m_eventLoop.loop();
}

void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr& conn) {
  if (!conn->connected()) {
    // 连接断开
    conn->shutdown();
  }
}
/*
在框架内部，RpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型
service_name method_name args
定义proto的message类型，进行数据头的序列化和反序列化 service_name method_name
args_size 16UserServiceLoginzhang san123456

header_size(4个字节) + header_str + args_str
10 "10"
10000 "1000000"
std::string   insert和copy方法
*/
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buffer, muduo::Timestamp) {
  // 网络上接收的远程rpc调用请求的字符流
  std::string recv_buf(buffer->retrieveAllAsString());
  // std::cout << "recv buffer: " << recv_buf << std::endl;
  //  读取前面四个字节的内容
  uint32_t header_size = 0;
  recv_buf.copy((char*)&header_size, 4, 0);

  // 根据header size读取原始字符流
  std::string rpc_header_str = recv_buf.substr(4, header_size);

  // 反序列化数据
  mprpc::RpcHeader rpc_header;
  std::string service_name;
  std::string method_name;
  uint32_t args_size;
  if (rpc_header.ParseFromString(rpc_header_str)) {
    // 数据头
    service_name = rpc_header.service_name();
    method_name = rpc_header.method_name();
    args_size = rpc_header.args_size();
  } else {
    // 数据头反序列化失败
    std::cout << "rpc_header_str:" << rpc_header_str << " parse error!"
              << std::endl;
    return;
  }

  std::string args_str = recv_buf.substr(4 + header_size, args_size);

  std::cout << "````````````````````````````````" << std::endl;
  std::cout << service_name << std::endl;
  std::cout << method_name << std::endl;
  std::cout << args_size << std::endl;

  // 获取service和method对象
  auto it = m_serviceMap.find(service_name);
  if (it == m_serviceMap.end()) {
    std::cout << service_name << "is not exist!" << std::endl;
    return;
  }

  auto mit = it->second.m_methodMap.find(method_name);
  if (mit == it->second.m_methodMap.end()) {
    std::cout << method_name << "is not exist!" << std::endl;
    return;
  }

  google::protobuf::Service* service = it->second.m_service;
  const google::protobuf::MethodDescriptor* method = mit->second;

  // 生成rpc方法调用的请求request和response参数
  google::protobuf::Message* request =
      service->GetRequestPrototype(method).New();

  if (!request->ParseFromString(args_str)) {
    std::cout << "request parse error!" << std::endl;
    return;
  }
  google::protobuf::Message* response =
      service->GetResponsePrototype(method).New();

  // 绑定一个closure的回调函数
  google::protobuf::Closure* done =
      google::protobuf::NewCallback<RpcProvider,
                                    const muduo::net::TcpConnectionPtr&,
                                    google::protobuf::Message*>(
          this, &RpcProvider::SendRpcResponse, conn, response);

  // 框架上根据远端rpc请求，调用当前rpc节点上发布的方法
  service->CallMethod(method, nullptr, request, response, done);
}

void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr& conn,
                                  google::protobuf::Message* response) {
  std::string response_str;
  if (response->SerializeToString(&response_str)) {
    // 通过网络rpc方法执行的结果发送回rpc的调用方
    conn->send(response_str);

  } else {
    std::cout << "response error" << std::endl;
  }
  conn->shutdown();  // rpcprovider主动断开连接
}