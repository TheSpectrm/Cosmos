#pragma once

#include "Core.h"

namespace Cosmos
{
	class COSMOS_API Logger
	{
		const char* m_Name;
	public:
		Logger(const char* name);
		~Logger();

		void Success(const char* format, ...) const;
		void Info(const char* format, ...) const;
		void Warn(const char* format, ...) const;
		void Error(const char* format, ...) const;
		char* FormatTime() const;
	};

	class COSMOS_API Log
	{
		static Logger* m_CoreLogger;
	public:
		static void Init();
		inline static Logger* GetCoreLogger() { return m_CoreLogger; }
	};
}