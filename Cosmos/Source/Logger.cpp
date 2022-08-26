#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <Windows.h>
#include "Logger.h"

#define CS_RED    4
#define CS_YELLOW 6
#define CS_GREEN  2
#define CS_GRAY   8

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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CS_GREEN);
		printf("%s ", FormatTime());
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	void Logger::Info(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CS_GRAY);
		printf("%s ", FormatTime());
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	void Logger::Warn(const char* format, ...) 
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CS_YELLOW);
		printf("%s ", FormatTime());
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	void Logger::Error(const char* format, ...) 
	{
		va_list args;
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CS_RED);
		printf("%s ", FormatTime());
		printf("%s: ", m_Name);
		vprintf(format, args);
		putchar('\n');
		va_end(args);
	}

	char* Logger::FormatTime() const
	{
		time_t t = time(0);
		tm* currentTime = localtime(&t);

		char* timestamp = new char[11];
		snprintf(timestamp, 11, "[%02d:%02d:%02d]", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

		return timestamp;
	}
}