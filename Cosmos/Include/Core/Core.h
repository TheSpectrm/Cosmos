#pragma once

#ifdef CS_PLATFORM_WINDOWS
	#ifdef CS_BUILD_DLL
		#define COSMOS_API __declspec(dllexport)
	#else
		#define COSMOS_API __declspec(dllimport)
	#endif
#else
	#error "Cosmos Engine only supports Windows for now!"
#endif

#ifdef _MSC_VER
	#define CS_COMPILER_MSVC
#elif defined(__MINGW32__) || defined(__MINGW64__)
	#define CS_COMPILER_MINGW
#endif