#pragma once

#include <cspch.h>
#include "Core/Core.h"

// LOGGER MACROS
#define CS_LOG_INIT()		 Cosmos::Log::Init()

#define CS_CORE_INFO(...)	 Cosmos::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define CS_CORE_TRACE(...)	 Cosmos::Log::GetCoreLogger()->Trace(__VA_ARGS__)
#define CS_CORE_WARN(...)	 Cosmos::Log::GetCoreLogger()->Warn(__VA_ARGS__)
#define CS_CORE_ERROR(...)	 Cosmos::Log::GetCoreLogger()->Error(__VA_ARGS__)

namespace Cosmos
{
	class COSMOS_API Logger
	{
	public:
		Logger(const char* name);

		void Info(const char* format, ...) const;
		void Trace(const char* format, ...) const;
		void Warn(const char* format, ...) const;
		void Error(const char* format, ...) const;
	private:
		const char* m_Name;

		std::string FormatTime() const;
	};

	class COSMOS_API Log
	{
		static Logger* m_CoreLogger;
	public:
		static void Init();
		inline static Logger* GetCoreLogger() { return m_CoreLogger; }
	};
}