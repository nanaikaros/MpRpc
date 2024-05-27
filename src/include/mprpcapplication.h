#pragma once

#include "mprpcconfig.h"

// 单例
//  mprpc框架基础类
class MpRpcApplication {
 public:
  static void Init(int argc, char** argv);
  static MpRpcApplication& GetInstance();

 private:
  static MpRpcConfig m_config;

  MpRpcApplication(){};
  MpRpcApplication(const MpRpcApplication&) = delete;
  MpRpcApplication(MpRpcApplication&&) = delete;
};