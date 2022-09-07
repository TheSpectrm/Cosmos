// PRECOMPILED HEADERS
#pragma once
//--------------------------------------
// C Standard Libraries
//--------------------------------------
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
//--------------------------------------
// C++ Standard Template Libraries (STL)
//--------------------------------------
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <functional>
//--------------------------------------
// Win32 API (Windows only)
//--------------------------------------
#ifdef CS_PLATFORM_WINDOWS 
	#include <Windows.h>
#endif
//--------------------------------------
// Cosmos Libraries
//--------------------------------------
#include "core/csdefs.h"
#include "core/logger.h"
//--------------------------------------