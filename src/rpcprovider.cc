#include "include/rpcprovider.h"

// 这里是框架提供给外部使用的，发布rpc方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service* service) {}

// 启动rpc服务节点，开始提供rpc提供服务
void RpcProvider::Run() {}