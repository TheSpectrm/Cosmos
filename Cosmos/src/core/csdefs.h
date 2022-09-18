/* COSMOS COMMON DEFINITIONS */
#pragma once

// Define a custom null
#ifdef __cplusplus
	#define null nullptr
#else
	#define null ((void*) 0)
#endif

// DLL export and import definitions
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

// Detect compiler
#ifdef _MSC_VER
	#define BUILD_MSVC
	#pragma warning (disable : 4251)
#elif defined(__MINGW32__)
	#define BUILD_MINGW
#endif

// Detect DLL export and import
#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_TYPE_DLL
		#define CS_API DLLEXPORT
	#else
		#define CS_API DLLIMPORT
	#endif
#else
	#error Cosmos Engine only supports Windows for now!
#endif

// Undefine some macros defined by dependencies
#ifdef near
	#undef near
#endif
#ifdef far
	#undef far
#endif

/* Common Cosmos Headers */
#include "core/logger.h"