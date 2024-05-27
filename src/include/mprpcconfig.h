#pragma once

#include <string>
#include <unordered_map>

// 框架读取配置文件类
class MpRpcConfig {
 public:
  void LoadConfigFile(const char* config_file);
  // 查询配置项
  std::string Load(std::string& key);

 private:
  std::unordered_map<std::string, std::string> m_configMap;
};