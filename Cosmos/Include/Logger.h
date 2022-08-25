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
		void Info();
		void Warn();
		void Error();
	};
}