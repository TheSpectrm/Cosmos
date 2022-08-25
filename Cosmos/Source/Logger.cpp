#include <stdio.h>
#include <stdarg.h>
#include "Logger.h"

namespace Cosmos
{
	Logger::Logger(const char* name)
		: m_Name(name)
	{ }

	Logger::~Logger() { }

	void Logger::Success(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	void Logger::Info() { }
	void Logger::Warn() { }
	void Logger::Error() { }
}