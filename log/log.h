#pragma once
#include <string>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level);
    void Error(std::string message);
    void Warn(std::string message);
    void Info(std::string message);
};