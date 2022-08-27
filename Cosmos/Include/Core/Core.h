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