#include "Logger.h"

std::ofstream Logger::logFile;
bool Logger::fileLoggingEnabled = false;

void Logger::enableFileLogging(const std::string& filename) {
    logFile.open(filename, std::ios::app);  
    if (logFile.is_open()) {
        fileLoggingEnabled = true;
    }
    else {
        std::cerr << "Error: Unable to open log file.\n";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string logLevelStr;

    switch (level) {
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

    if (fileLoggingEnabled && logFile.is_open()) {
        logFile << fullMessage << std::endl;
    }
}
