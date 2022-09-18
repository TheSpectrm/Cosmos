/* LOGGER IMPLEMENTATION */
#pragma once

#include <cspch.h>
#include "core/csdefs.h"

namespace Cosmos
{
	class CS_API Logger
	{
		std::string m_Name;

		std::string FormatTime() const;
	public:
		Logger(const std::string& name);
		void Info(const char* format, ...) const;
		void Trace(const char* format, ...) const;
		void Warn(const char* format, ...) const;
		void Error(const char* format, ...) const;
	};

	class CS_API Log
	{
		static Logger* s_CoreLogger;
	public:
		static void Init();
		static Logger* GetCoreLogger();
	};

	/* Core Logger Macros */
	#define LOG_INIT()		 Cosmos::Log::Init()
	#define CORE_INFO(...)	 Cosmos::Log::GetCoreLogger()->Info(__VA_ARGS__)
	#define CORE_TRACE(...)	 Cosmos::Log::GetCoreLogger()->Trace(__VA_ARGS__)
	#define CORE_WARN(...)	 Cosmos::Log::GetCoreLogger()->Warn(__VA_ARGS__)
	#define CORE_ERROR(...)	 Cosmos::Log::GetCoreLogger()->Error(__VA_ARGS__)
}