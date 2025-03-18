//
// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 4/7/2024 at 11:29:15 AM.
// Copyright (c) 2024 Rihen. All rights reserved.
//

#ifndef __CORE_EXPORTS_H__
#define __CORE_EXPORTS_H__

#pragma once


#include "Platform.h"

#if !defined(CORE_STATIC)

	#if defined(CORE_PLATFORM_WINDOWS)

		#define CORE_API_EXPORT __declspec(dllexport)
		#define CORE_API_IMPORT __declspec(dllimport)

		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif

	#else

		#define CORE_API_EXPORT __attribute__((__visibility__("default")))
		#define CORE_API_IMPORT __attribute__((__visibility__("default")))

	#endif

#else

	#define CORE_API_EXPORT
	#define CORE_API_IMPORT

#endif

#if defined(CORE_EXPORTS)
	#define CORE_API CORE_API_EXPORT
#else
	#define CORE_API CORE_API_IMPORT
#endif

#endif    // __CORE_EXPORTS_H__