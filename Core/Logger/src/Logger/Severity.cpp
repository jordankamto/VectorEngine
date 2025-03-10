#include "pch.h"
#include "Severity.h"

const std::string ToString(Severity severity){
    if (severity == Severity::Severity_Assert) return "Assert";
    if (severity == Severity::Severity_Trace) return "Trace";
    if (severity == Severity::Severity_Error) return "Error";

    return "Trace";
}

Severity FromString(const std::string& type){
    if (type == "Assert") return Severity::Severity_Assert;

    return Severity::Severity_Default;
}