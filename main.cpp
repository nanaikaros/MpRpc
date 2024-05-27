#include <iostream>
#include <string>

#include "test/protobuf/test.pb.h"
int main(int, char**) {
  //   std::cout << "Hello, from mprpc!\n";
  //   fixbug::LoginRequest req;
  //   req.set_name("wang");
  //   req.set_pwd("123456");

  //   std::string send_str;
  //   bool rt = req.SerializeToString(&send_str);

  //   if (rt) {
  //     std::cout << send_str.c_str() << std::endl;
  //   }

  //   // 反序列化
  //   fixbug::LoginRequest req2;
  //   if (req2.ParseFromString(send_str)) {
  //     std::cout << req2.name() << "  " << req2.pwd() << std::endl;
  //   }
  //   fixbug::LoginResponse rsp;
  //   fixbug::ResultCode *rc = rsp.mutable_result();
  //   rc->set_errcode(1);
  //   rc->set_errmsg("Fail");

  fixbug::GetFriendListsResponse rsp;
  fixbug::ResultCode* rc = rsp.mutable_result();
  rc->set_errcode(0);
  fixbug::User* user1 = rsp.add_friendlist();

  return 0;
}
