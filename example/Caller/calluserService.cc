#include <iostream>

#include "../src/include/mprpcapplication.h"
#include "../src/include/mprpcchannel.h"
#include "../user.pb.h"
int main(int argc, char** argv) {
  // 整个程序启动以后，想用mprpc框架来享受rpc服务调用,初始化框架
  MpRpcApplication::Init(argc, argv);

  // 调用rpc的Login
  fixbug::UserServiceRpc_Stub stub(new MpRpcChannel());
  fixbug::LoginRequest request;
  request.set_name("wang");
  request.set_pwd("123456");

  fixbug::LoginResponse response;
  stub.Login(nullptr, &request, &response, nullptr);

  // rpc调用完成
  if (response.result().errcode() == 0) {
    std::cout << "rpc login response:" << response.success() << std::endl;
  } else {
    std::cout << "rpc login response error: " << response.result().errmsg()
              << std::endl;
  }

  return 0;
}