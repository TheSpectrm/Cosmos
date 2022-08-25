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

		void Success(const char* format, ...);
		void Info(const char* format, ...);
		void Warn(const char* format, ...);
		void Error(const char* format, ...);
	};
}