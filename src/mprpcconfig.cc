#include "include/mprpcconfig.h"

#include <iostream>
#include <string>
// 加载配置文件
void MpRpcConfig::LoadConfigFile(const char* config_file) {
  FILE* pf = fopen(config_file, "r");
  if (nullptr == pf) {
    std::cout << config_file << "is not exist!" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (!feof(pf)) {
    char buf[512] = {0};
    fgets(buf, 512, pf);

    // 去掉空格
    std::string src_buf(buf);
    int idx = src_buf.find_first_not_of(' ');
    if (idx != -1) {
      src_buf = src_buf.substr(idx, src_buf.size() - idx);
    }

    idx = src_buf.find_last_not_of(' ');
    if (idx != -1) {
      src_buf = src_buf.substr(0, idx + 1);
    }

    if (src_buf[0] == '#' || src_buf.empty()) {
      continue;
    }

    // 解析配置项
    idx = src_buf.find('=');
    if (idx == -1) {
      continue;
    }

    std::string key;
    std::string value;
    key = src_buf.substr(0, idx);
    value = src_buf.substr(idx + 1, src_buf.size() - idx);

    m_configMap[key] = value;
  }
}

// 查询配置项
std::string MpRpcConfig::Load(std::string& key) {
  auto it = m_configMap.find(key);
  if (it == m_configMap.end()) {
    return "";
  }
  return it->second;
}