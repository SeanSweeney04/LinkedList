#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

enum class LogLevel { INFO, WARNING, ERROR };

class Logger {
public:
    static void log(LogLevel level, const std::string& message);
    static void enableFileLogging(const std::string& filename);

private:
    static std::ofstream logFile;
    static bool fileLoggingEnabled;
};

#endif
