#include "log.h"
#include <iostream>

void Log::SetLevel(int level)
{
    m_LogLevel = level;
}

void Log::Error(std::string message)
{
    if (m_LogLevel >= LogLevelError)
        std::cout << "[ERROR]: " << message << std::endl;
}

void Log::Warn(std::string message)
{
    if (m_LogLevel >= LogLevelWarning)
        std::cout << "[WARNING]: " << message << std::endl;
}

void Log::Info(std::string message)
{
    if (m_LogLevel >= LogLevelInfo)
        std::cout << "[INFO]: " << message << std::endl;
}