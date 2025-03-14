#include "Logger.h"

Logger::Logger(const std::string& filename) : fileLoggingEnabled(false) 
{
    if (!filename.empty()) 
    {
        enableFileLogging(filename);
    }
}

//Destructor: Closes the log file

Logger::~Logger() 
{
    if (fileLoggingEnabled) 
    {
        logFile.close();
    }
}

// Enables logging to a file

void Logger::enableFileLogging(const std::string& filename) 

    logFile.open(filename, std::ios::app);
    if (logFile.is_open()) {
        fileLoggingEnabled = true;
    }
    else 
    {
        std::cerr << "[ERROR] Unable to open log file: " << filename << std::endl;
    }
}

void Logger::log(LogLevel level, const std::string& message)
{
    std::string logLevelStr;

    switch (level)
    {
    case LogLevel::INFO:
        logLevelStr = "[INFO] ";
        break;
    case LogLevel::WARNING:
        logLevelStr = "[WARNING] ";
        break;
    case LogLevel::ERROR:
        logLevelStr = "[ERROR] ";
        break;
    }

    std::string fullMessage = logLevelStr + message;

    std::cout << fullMessage << std::endl;

    if (fileLoggingEnabled && logFile.is_open())
    {
        logFile << fullMessage << std::endl;
    }
}