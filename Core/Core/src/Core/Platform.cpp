//
// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 2024/04/05.
// Copyright (c) 2024 Rihen. All rights reserved.
//

#include "NSystemPch/ntspch.h"
#include "Platform.h"

namespace core
{
    Platform::Type Platform::GetPlatform() {
        #if defined(CORE_PLATFORM_WIN64)
            return Win64;
        #elif defined(CORE_PLATFORM_WIN32)
            return Win32;
        #elif defined(CORE_PLATFORM_ANDROID)
            return Android;
        #elif defined(CORE_PLATFORM_IOS)
            /*if constexpr (sizeof(void*) == 8) {
                return Mac;
            }*/
            return iOS;
        #elif defined(CORE_PLATFORM_MACOS)
            return Mac;
        #elif defined(CORE_PLATFORM_NDS)
            return Nds;
        #elif defined(CORE_PLATFORM_LINUX)
            return Linux;
        #elif defined(CORE_PLATFORM_FREEBSD)
            return FreeBsd;
        #elif defined(CORE_PLATFORM_OPENBSD)
            return OpenBsd;
        #elif defined(CORE_PLATFORM_NETBSD)
            return NetBsd;
            /*if constexpr (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700) {
                char* name = nullptr;
                uname(&name);
                if (std::string(name).find("Linux") != std::string::npos) {
                    return Linux;
                }
            }*/
        #endif
        return Unknow;
    }

    std::string Platform::GetPlatformName(Platform::Type platform) {
        return STR_PLATFORM;
    }
} // namespace core
