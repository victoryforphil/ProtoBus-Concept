#include "logging.hpp"


int PBus::Logging::mLogLevel;
// Log Level Functions
int PBus::Logging::SetLogLevel(int newLevel){
    mLogLevel = newLevel;
    return GetLogLevel();
}

int PBus::Logging::GetLogLevel(){
    return mLogLevel;
}

// Compact Logging Functions
int PBus::Logging::Debug(std::string source, std::string action, std::string message){
    std::string out;
    return PBus::Logging::Debug(source, action, message, out);
}

int PBus::Logging::Info(std::string source, std::string action, std::string message){
    std::string out;
    return PBus::Logging::Info(source, action, message, out);
}

int PBus::Logging::Warning(std::string source, std::string action, std::string message){
    std::string out;
    return PBus::Logging::Warning(source, action, message, out);
}

int PBus::Logging::Error(std::string source, std::string action, std::string message){
    std::string out;
    return PBus::Logging::Error(source, action, message, out);
}

// Base Logging Functions
int PBus::Logging::Debug(std::string source, std::string action, std::string message, std::string &out){
    std::string _logString;
    _logString += "[DEBG] [" + source + "] (" + action +") " + message;
    out = _logString;

    if(mLogLevel == 0){
        std::cout << out << std::endl;
    }
    return 0;
}

int PBus::Logging::Info(std::string source, std::string action, std::string message, std::string &out){
    std::string _logString;
    _logString += "[INFO] [" + source + "] (" + action +") " + message;
    out = _logString;

    if(mLogLevel <= 1){
        std::cout << out << std::endl;
    }
    return 0;
}

int PBus::Logging::Warning(std::string source, std::string action, std::string message, std::string &out){
    std::string _logString;
    _logString += "[WARN] [" + source + "] (" + action +") " + message;
    out = _logString;

    if(mLogLevel <= 2){
        std::cout << out << std::endl;
    }
    return 0;
}

int PBus::Logging::Error(std::string source, std::string action, std::string message, std::string &out){
    std::string _logString;
    _logString += "[EROR] [" + source + "] (" + action +") " + message;
    out = _logString;

    if(mLogLevel <= 3){
        std::cout << out << std::endl;
    }
    return 1;
}