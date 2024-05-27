#include <spdlog/spdlog.h>

#include <iostream>
#include <string>

#include "../src/include/mprpcapplication.h"
#include "../src/include/rpcprovider.h"
#include "user.pb.h"

// UserService 是一个本地服务，提供了两个进程内的本地方法Login和GetFriendLists
class UserService : public fixbug::UserServiceRpc {
 public:
  // 这是本地的
  bool Login(std::string name, std::string pwd) {
    spdlog::info("Doing local service: Login");
    spdlog::info("Name:" + name + " pwd:" + pwd);
    return true;
  }

  // 这是在Callee角度分析RPC的功能
  // 重写基类 UserServiceRpc的虚函数
  void Login(::google::protobuf::RpcController* controller,
             const ::fixbug::LoginRequest* request,
             ::fixbug::LoginResponse* response,
             ::google::protobuf::Closure* done) {
    // 1.框架给业务上报了请求参数LoginRequest，应用获取相应数据做本地业务
    std::string name = request->name();
    std::string pwd = request->pwd();

    // 2.做业务
    bool login_result = Login(name, pwd);

    // 3.把响应写入
    fixbug::ResultCode* code = response->mutable_result();
    code->set_errcode(0);
    code->set_errmsg("");
    response->set_success(login_result);

    // 4.做回调操作,执行响应对象数据的序列化和网络发送（都是由框架完成）
    done->Run();
  }
};

int main(int argc, char** argv) {
  // 框架初始化 provider -i conf
  MpRpcApplication::Init(argc, argv);

  // 把UserService对象发布到rpc节点上
  RpcProvider provider;
  provider.NotifyService(new UserService());

  // 启动rpc服务发布节点
  provider.Run();

  return 0;
}