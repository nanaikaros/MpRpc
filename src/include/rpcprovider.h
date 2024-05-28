#pragma once

#include <google/protobuf/descriptor.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>

#include <functional>
#include <memory>
#include <string>

#include "google/protobuf/service.h"

// 框架提供的专门发布rpc服务的网络对象类
class RpcProvider {
 public:
  // 这里是框架提供给外部使用的，发布rpc方法的函数接口
  void NotifyService(google::protobuf::Service* service);

  // 启动rpc服务节点，开始提供rpc提供服务
  void Run();

 private:
  // // 组合了TcpServer
  // std::unique_ptr<muduo::net::TcpServer> m_tcpserverPtr;
  // 组合Eventloop
  muduo::net::EventLoop m_eventLoop;

  struct ServiceInfo {
    google::protobuf::Service* m_service;  // 保存服务对象
    // 保存服务方法
    std::unordered_map<std::string, const google::protobuf::MethodDescriptor*>
        m_methodMap;
  };

  // 存储注册成功的服务对象和器服务方法的所有信息
  std::unordered_map<std::string, ServiceInfo> m_serviceMap;

  // 链接回调
  void OnConnection(const muduo::net::TcpConnectionPtr&);
  // 读写事件回调
  void OnMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*,
                 muduo::Timestamp);

  // 回调操作
  void SendRpcResponse(const muduo::net::TcpConnectionPtr&,
                       google::protobuf::Message*);
};