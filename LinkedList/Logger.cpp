#include "Logger.h"

// Define static members
std::ofstream Logger::logFile;
bool Logger::fileLoggingEnabled = false;

void Logger::initialize(const std::string& filename)
{
    logFile.open(filename, std::ios::trunc);  // Overwrite on each run
    fileLoggingEnabled = logFile.is_open();

    if (!fileLoggingEnabled)
    {
        std::cerr << "[ERROR] Could not open log file: " << filename << std::endl;
    }
}

void Logger::log(LogLevel level, const std::string& message)
{
    std::string logLevelStr;
    switch (level)
    {
    case DEBUG:   
        logLevelStr = "[DEBUG] "; 
        break;
    case INFO:
        logLevelStr = "[INFO] "; 
        break;
    case WARNING: 
        logLevelStr = "[WARNING] "; 
        break;
    case ERROR:   
        logLevelStr = "[ERROR] "; 
        break;
    default:      
        logLevelStr = "[UNKNOWN] "; 
        break;
    }

    std::string fullMessage = logLevelStr + message;

    std::cout << fullMessage << std::endl;

    if (fileLoggingEnabled && logFile.is_open())
    {
        logFile << fullMessage << std::endl;
        logFile.flush();
    }
}

void Logger::shutdown()
{
    if (fileLoggingEnabled && logFile.is_open())
    {
        logFile.close();
        fileLoggingEnabled = false;
    }
}