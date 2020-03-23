#ifndef _PBUS_LOGGING_H_
#define _PBUS_LOGGING_H_

#include <iostream>
#include <string>

namespace PBus
{
class Logging
{
private:
    static int mLogLevel;

public:
    static int SetLogLevel(int newLevel);
    static int GetLogLevel();
    static int Debug(std::string source, std::string action, std::string message);   //Log Level 0
    static int Info(std::string source, std::string action, std::string message);    //Log Level 1
    static int Warning(std::string source, std::string action, std::string message); //Log Level 2
    static int Error(std::string source, std::string action, std::string message);   //Log Level 3

    static int Debug(std::string source, std::string action, std::string message, std::string &out);   //Log Level 0
    static int Info(std::string source, std::string action, std::string message, std::string &out);    //Log Level 1
    static int Warning(std::string source, std::string action, std::string message, std::string &out); //Log Level 2
    static int Error(std::string source, std::string action, std::string message, std::string &out);   //Log Level 3
};
} // namespace PBus

#endif