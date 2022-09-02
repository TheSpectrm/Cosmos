#include <cspch.h>

namespace Cosmos
{
	#define CS_RED    4
	#define CS_YELLOW 6
	#define CS_GREEN  2
	#define CS_GRAY   8

	#define CS_IMPLEMENT_LOGGER_FUNC(name, color)						 \
	void name(const char* format, ...) const							 \
	{																	 \
		va_list args;													 \
		va_start(args, format);											 \
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); \
		printf("%s ", FormatTime().c_str());							 \
		printf("%s: ", m_Name);											 \
		vprintf(format, args);											 \
		putchar('\n');													 \
		va_end(args);													 \
	}

	Logger::Logger(const char* name)
		: m_Name(name) { }

	CS_IMPLEMENT_LOGGER_FUNC(Logger::Info, CS_GREEN)
	CS_IMPLEMENT_LOGGER_FUNC(Logger::Trace, CS_GRAY)
	CS_IMPLEMENT_LOGGER_FUNC(Logger::Warn, CS_YELLOW)
	CS_IMPLEMENT_LOGGER_FUNC(Logger::Error, CS_RED)

	std::string Logger::FormatTime() const
	{
		time_t t = time(0);
		tm* currentTime = localtime(&t);

		char* timestamp = new char[11];
		snprintf(timestamp, 11, "[%02d:%02d:%02d]", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

		return timestamp;
	}

	Logger* Log::m_CoreLogger;

	void Log::Init()
	{
		m_CoreLogger = new Logger("CORE");
		CS_CORE_INFO("Initialized core, console, and core logger");
	}
}