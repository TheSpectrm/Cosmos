#pragma once

// DLL import and export detection
#ifdef CS_PLATFORM_WINDOWS
	#ifdef CS_BUILD_DLL
		#define COSMOS_API __declspec(dllexport)
	#else
		#define COSMOS_API __declspec(dllimport)
	#endif
#else
	#error "Cosmos Engine only supports Windows for now!"
#endif

// Compiler detection
#ifdef _MSC_VER
	#define CS_BUILD_MSVC
#elif defined(__MINGW32__)
	#define CS_BUILD_MINGW
#endif

// Undefine the macros defined by some headers
#ifdef near
	#undef near
#endif
#ifdef far
	#undef far
#endif

// Define a custom null
#ifdef __cplusplus
	#define null 0
#else
	#define null ((void*) 0)
#endif