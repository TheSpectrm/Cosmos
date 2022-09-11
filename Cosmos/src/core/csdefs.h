#pragma once

// Disable warning C4251 (MSVC only)
#pragma warning (disable:4251)

// DLL import and export detection
#ifdef CS_PLATFORM_WINDOWS
	#ifdef CS_BUILD_DLL
		#define CS_API __declspec(dllexport)
	#else
		#define CS_API __declspec(dllimport)
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

// Undefine some macros defined by dependencies
#ifdef near
	#undef near
#endif
#ifdef far
	#undef far
#endif

// Define a custom null
#ifdef __cplusplus
	#define null nullptr
#else
	#define null ((void*) 0)
#endif