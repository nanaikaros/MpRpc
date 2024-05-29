#include "logger.h"

#include <time.h>

#include <iostream>
Logger::Logger() {
  // 启动专门的写日志线程
  std::thread writeLogTask([&]() {
    while (true) {
      // 获取当前日期，然后取日志信息，写入响应的日志文件当中
      time_t now = time(nullptr);
      tm* nowtm = localtime(&now);

      char file_name[128];
      sprintf(file_name, "%d-%d-%d-log.txt", nowtm->tm_year + 1900,
              nowtm->tm_mon + 1, nowtm->tm_mday);

      FILE* pf = fopen(file_name, "a+");
      if (pf == nullptr) {
        std::cout << "logger file not exist!" << std::endl;
        exit(EXIT_FAILURE);
      }

      std::string msg = m_lckQue.Pop();

      char time_buf[128] = {0};
      sprintf(time_buf, "%d:%d:%d => [%s]", nowtm->tm_hour, nowtm->tm_min,
              nowtm->tm_sec, m_loglevel == INFO ? "info" : "error");
      msg.insert(0, time_buf);
      msg.append("\n");
      fputs(msg.c_str(), pf);
      fclose(pf);
    }
  });
  // 设置分离线程
  writeLogTask.detach();
}

// 获取日志的单例
Logger& Logger::GetInstance() {
  static Logger logger;
  return logger;
}
// 设置日志级别
void Logger::SetLogLevel(LogLevel level) { m_loglevel = level; }
// 写日志，把日志信息写入lockqueue
void Logger::Log(std::string msg) { m_lckQue.Push(msg); }