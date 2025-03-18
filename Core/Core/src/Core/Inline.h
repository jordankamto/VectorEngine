//
// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 4/7/2024 at 11:29:15 AM.
// Copyright (c) 2024 Rihen. All rights reserved.
//

#ifndef __CORE_INLINE_H__
#define __CORE_INLINE_H__

#pragma once

#if defined(__clang__) || defined(__gcc__) || defined(__GNUC__)

	#define CORE_INLINE			__attribute__((always_inline)) inline
	#define CORE_NO_INLINE		__attribute__((noinline))

#elif defined(_MSC_VER)

	#define CORE_INLINE			__forceinline
	#define CORE_NO_INLINE		__declspec(noinline)

#else

	#define CORE_INLINE			static inline
	#define CORE_NO_INLINE

#endif

#endif    // __CORE_INLINE_H__