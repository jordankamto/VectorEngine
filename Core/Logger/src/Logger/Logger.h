#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include <functional>
#include "Severity.h"

    class  Logger {
    public:
        Logger();
        Logger(const std::string& name);
        virtual ~Logger() = default;
        const std::string& GetName() const;
        void SetName(const std::string& name);

        Logger& Details(const char* file, unsigned int ligne, const char* function);

        void Log(Severity severity, const char* format = "") {
            PreWrite(severity, format);
        }

        // Specific log methods for different severity levels (examples)
        template<typename... Args>
        void Info(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Info, format, args...);
        }

        template<typename... Args>
        void Asserts(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Assert, format, args...);
        }

        template<typename... Args>
        void Error(const char* format = "", Args&&... args) {
            Log(Severity::Error, format, args...);
        }

        template<typename... Args>
        void Warning(const char* format = "", Args&&... args) {
            Log(Severity::Warning, format, args...);
        }

        template<typename... Args>
        void Debug(const char* format = "", Args&&... args) {
            Log(Severity::Debug, format, args...);
        }

        template<typename... Args>
        void Trace(const char* format = "", Args&&... args) {
            Log(Severity::Trace, format, args...);
        }

        template<typename... Args>
        void Critical(const char* format = "", Args&&... args) {
            Log(Severity::Critical, format, args...);
        }

        template<typename... Args>
        void Fatal(const char* format = "", Args&&... args) {
            Log(Severity::Fatal, format, args...);
        }

    private:
        void PreWrite(Severity severity, const std::string& message);
    protected:
        virtual void Write(const LoggerInfos& loggerInfos);
    };

#endif  // __LOGGER_LOGGER_H__"