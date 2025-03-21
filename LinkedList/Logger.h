#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

enum LogLevel { INFO, WARNING, ERROR, DEBUG };

class Logger
{
public:
    static void initialize(const std::string& filename);
    static void log(LogLevel level, const std::string& message);
    static void shutdown();  

private:
    static std::ofstream logFile;
    static bool fileLoggingEnabled;
};


#endif