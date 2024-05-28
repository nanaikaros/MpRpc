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
    std::string read_buf(buf);
    Trim(read_buf);

    if (read_buf[0] == '#' || read_buf.empty()) {
      continue;
    }

    // 解析配置项
    int idx = read_buf.find('=');
    if (idx == -1) {
      continue;
    }

    std::string key;
    std::string value;
    key = read_buf.substr(0, idx);
    Trim(key);
    int endidx = read_buf.find('\n', idx);
    value = read_buf.substr(idx + 1, endidx - idx - 1);
    Trim(value);

    m_configMap[key] = value;
  }
}

// 查询配置项
std::string MpRpcConfig::Load(const char* key) {
  auto it = m_configMap.find(key);
  if (it == m_configMap.end()) {
    return "";
  }
  return it->second;
}

void MpRpcConfig::Trim(std::string& src_buf) {
  int idx = src_buf.find_first_not_of(' ');
  if (idx != -1) {
    src_buf = src_buf.substr(idx, src_buf.size() - idx);
  }

  idx = src_buf.find_last_not_of(' ');
  if (idx != -1) {
    src_buf = src_buf.substr(0, idx + 1);
  }
}