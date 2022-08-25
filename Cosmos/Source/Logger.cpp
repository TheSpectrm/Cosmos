#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	void Logger::Info(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);

	}

	void Logger::Warn(const char* format, ...) 
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	
	}

	void Logger::Error(const char* format, ...) 
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	
	}
}