//
// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 4/7/2024 at 11:29:15 AM.
// Copyright (c) 2024 Rihen. All rights reserved.
//

#ifndef __CORE_SYSTEM_ASSERTION_H__
#define __CORE_SYSTEM_ASSERTION_H__

#pragma once


#include "Platform.h"


#ifdef CORE_DEBUG
	#include <cassert>
	#if defined(CORE_PLATFORM_WINDOWS)
		#define CORE_ASSERT_BREAK __debugbreak();
	#elif defined(CORE_PLATFORM_UNIX)
		#include <signal.h>
		#define CORE_ASSERT_BREAK raise(SIGTRAP);
	#elif defined(CORE_PLATFORM_APPLE)
		#define CORE_ASSERT_BREAK __builtin_debugtrap();
	#else
		#error "Platform doesn't support debugbreak yet!"
		#define CORE_ASSERT_BREAK
	#endif
#else
    #define CORE_ASSERT_BREAK
#endif

#endif    // __CORE_SYSTEM_ASSERTION_H__