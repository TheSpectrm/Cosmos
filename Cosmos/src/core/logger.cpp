#include <cspch.h>
#include "core/logger.h"

namespace Cosmos
{
	/* Win32 API Color Code Macros */
	#define RED    4
	#define YELLOW 6
	#define GREEN  2
	#define GRAY   8

	#define IMPLEMENT_LOGGER_FUNC(name, color)\
		void name(const char* format, ...) const\
		{\
			va_list args;\
			va_start(args, format);\
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);\
			printf("%s ", FormatTime().c_str());\
			printf("%s: ", m_Name.c_str());\
			vprintf(format, args);\
			putchar('\n');\
			va_end(args);\
		}

	std::string Logger::FormatTime() const
	{
		time_t t = time(0);
		tm* currentTime = localtime(&t);

		char* timestamp = new char[11];
		snprintf(timestamp, 11, "[%02d:%02d:%02d]", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

		return timestamp;
	}

	Logger::Logger(const std::string& name)
		: m_Name(name) { }

	IMPLEMENT_LOGGER_FUNC(Logger::Info, GREEN)
	IMPLEMENT_LOGGER_FUNC(Logger::Trace, GRAY)
	IMPLEMENT_LOGGER_FUNC(Logger::Warn, YELLOW)
	IMPLEMENT_LOGGER_FUNC(Logger::Error, RED)

	// Re-declare Log class static member variables
	Logger* Log::s_CoreLogger;

	void Log::Init()
	{
		s_CoreLogger = new Logger("CORE");
		CORE_INFO("Initialized core and console");
	}

	Logger* Log::GetCoreLogger()
	{
		return s_CoreLogger;
	}
}