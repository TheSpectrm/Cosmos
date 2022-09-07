#pragma once

#include <cspch.h>

namespace Cosmos
{
	// CORE LOGGER MACROS
	#define CS_LOG_INIT()		 Cosmos::Log::Init()
	#define CS_CORE_INFO(...)	 Cosmos::Log::GetCoreLogger()->Info(__VA_ARGS__)
	#define CS_CORE_TRACE(...)	 Cosmos::Log::GetCoreLogger()->Trace(__VA_ARGS__)
	#define CS_CORE_WARN(...)	 Cosmos::Log::GetCoreLogger()->Warn(__VA_ARGS__)
	#define CS_CORE_ERROR(...)	 Cosmos::Log::GetCoreLogger()->Error(__VA_ARGS__)

	class Logger
	{
		std::string m_Name;

		std::string FormatTime() const;
	public:
		COSMOS_API Logger(std::string name);

		COSMOS_API void Info(const char* format, ...) const;
		COSMOS_API void Trace(const char* format, ...) const;
		COSMOS_API void Warn(const char* format, ...) const;
		COSMOS_API void Error(const char* format, ...) const;
	};

	class COSMOS_API Log
	{
		static Logger* m_CoreLogger;
	public:
		static void Init();
		static Logger* GetCoreLogger();
	};
}