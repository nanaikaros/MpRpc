#include "include/mprpcapplication.h"

#include <unistd.h>

#include <iostream>
#include <string>

MpRpcConfig MpRpcApplication::m_config;

void ShowArgsHelp() {
  std::cout << "format: command -i <configfile>" << std::endl;
}

void MpRpcApplication::Init(int argc, char** argv) {
  if (argc < 2) {
    ShowArgsHelp();
    exit(EXIT_FAILURE);
  }

  int c = 0;
  std::string config_file;
  while ((c = getopt(argc, argv, "i:")) != -1) {
    switch (c) {
      case 'i':
        config_file = optarg;
        break;
      case '?':
        ShowArgsHelp();
        exit(EXIT_FAILURE);
      case ':':
        ShowArgsHelp();
        exit(EXIT_FAILURE);
      default:
        std::cerr << "Unexpected option: '" << char(optopt) << "' with value '"
                  << (optarg ? optarg : "") << "'\n";
        break;
    }
  }

  // 开始加载配置模块
  m_config.LoadConfigFile(config_file.c_str());
  std::cout << "rpcserverip: ";
  std::cout << m_config.Load("rpcserverip") << std::endl;
  std::cout << "rpcserverport: ";
  std::cout << m_config.Load("rpcserverport") << std::endl;
  ;
}

MpRpcApplication& MpRpcApplication::GetInstance() {
  static MpRpcApplication app;
  return app;
}