#include "pch.h"
#include "Logger.h"
#include "Log.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>

// --- ConsoleLogger Implementation ---
void ConsoleLogger::Log(LogLevel level, const std::string& message,
                        const char* file, int line, const char* func,
                        const std::string& timestamp) {
    std::string color = GetColorCode(level);
    std::cout << color
              << "[Logger] [" << timestamp << "] "
              << "[" << LogLevelToString(level) << "] "
              << message << " "
              << "[" << file << ":" << line << " " << func << "]"
              << "\033[0m" << std::endl;
}

// --- FileLogger Implementation ---
FileLogger::FileLogger(const std::string& filename)
    : OutFile(std::make_unique<std::ofstream>(filename, std::ios::app)) {
    if (!OutFile->is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
    }
}

void FileLogger::Log(LogLevel level, const std::string& message,
                     const char* file, int line, const char* func,
                     const std::string& timestamp) {
    if (OutFile && OutFile->is_open()) {
        (*OutFile) << "[File] [" << timestamp << "] "
                   << "[" << LogLevelToString(level) << "] "
                   << message << " "
                   << "[" << file << ":" << line << " " << func << "]"
                   << std::endl;
    }
}

// --- GuiLogger Implementation ---
void GuiLogger::Log(LogLevel level, const std::string& message,
                    const char* file, int line, const char* func,
                    const std::string& timestamp) {
    std::cout << "[GUI] [" << timestamp << "] "
              << "[" << LogLevelToString(level) << "] "
              << message << " "
              << "[" << file << ":" << line << " " << func << "]"
              << std::endl;
}

// --- Logger Implementation ---
Logger::Logger(const std::string& appName) : ApplicationName(appName) {}

void Logger::SetApplicationName(const std::string& appName) {
    ApplicationName = appName;
}

Logger& Logger::Source(const std::source_location& location) {
    mLocation = location;
    return *this;
}

void Logger::Log(LogLevel level, const std::string& message,
                 const std::source_location& defaultLocation) {
    std::source_location location = mLocation.has_value() ? mLocation.value() : defaultLocation;
    mLocation.reset();

    std::string timestamp = GetCurrentTimestamp();
    std::string fullMessage = "[" + ApplicationName + "] " + message;

    if (Targets.empty()) {
        std::cerr << "[Fallback Logger][" << timestamp << "] "
                  << "[" << LogLevelToString(level) << "] "
                  << fullMessage << std::endl;
        return;
    }

    for (auto& target : Targets) {
        try {
            target->Log(level, fullMessage,
                        location.file_name(),
                        location.line(),
                        location.function_name(),
                        timestamp);
        } catch (const std::exception& ex) {
            std::cerr << "[Logging Error] Exception dans la cible : " << ex.what() << std::endl;
        }
    }
}
void Logger::LogAssert(bool condition, const std::string& message, const std::source_location& defaultLocation) {
    if(condition){
        std::source_location location = mLocation.has_value() ? mLocation.value() : defaultLocation;
        mLocation.reset();

        std::string timestamp = GetCurrentTimestamp();
        std::string fullMessage = "[" + ApplicationName + "] " + message;

        if (Targets.empty()) {
            std::cerr << "[Fallback Logger][" << timestamp << "] "
                    << "[" << "ASSERT" << "] "
                    << fullMessage << std::endl;
            return;
        }

        for (auto& target : Targets) {
            try {
                target->Log(LogLevel::ASSERT, fullMessage,
                            location.file_name(),
                            location.line(),
                            location.function_name(),
                            timestamp);
            } catch (const std::exception& ex) {
                std::cerr << "[Logging Error] Exception dans la cible : " << ex.what() << std::endl;
            }
        }
    }
}

void Logger::AddTarget(std::unique_ptr<LoggerTarget> target) {
    Targets.push_back(std::move(target));
}
