#ifndef __LOGGER_SEVERITY_H__
#define __LOGGER_SEVERITY_H__

#include <string>

    enum class Severity {
        Severity_Info = 1,
        Severity_Trace,
        Severity_Debug,
        Severity_Warning,
        Severity_Error,
        Severity_Critical,
        Severity_Fatal,
        Severity_Assert,
        Severity_Default = Severity_Trace,
    };

    const std::string ToString(Severity severity);
    Severity FromString(const std::string& type);


#endif  // __LOGGER_SEVERITY_H__"