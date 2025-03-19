#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

enum LogLevel { INFO, WARNING, ERROR };

class Logger
{
public:
    explicit Logger(const std::string& filename = "");
    ~Logger();

    void log(LogLevel level, const std::string& message);
    void enableFileLogging(const std::string& filename);

private:
    std::ofstream logFile;
    bool fileLoggingEnabled;
};

#endif