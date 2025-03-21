#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

enum LogLevel { INFO, WARNING, ERROR, DEBUG };

class Logger
{
public:
    static Logger& getLog();
    void initialize(const std::string& filename);
    explicit Logger(const std::string& filename = "");
    ~Logger();

    void log(LogLevel level, const std::string& message);
    void enableFileLogging(const std::string& filename);

    std::ofstream& getLogFile();

private:
    std::ofstream logFile;
    bool fileLoggingEnabled;
};

#endif