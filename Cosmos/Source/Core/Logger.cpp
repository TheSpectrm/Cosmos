#include <cspch.h>

namespace Cosmos
{
	#define CS_RED    4
	#define CS_YELLOW 6
	#define CS_GREEN  2
	#define CS_GRAY   8

	Logger::Logger(const char* name)
		: m_Name(name) { }

	void Logger::Info(const char* format, ...) const
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

	void Logger::Trace(const char* format, ...) const
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

	void Logger::Warn(const char* format, ...) const
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

	void Logger::Error(const char* format, ...) const
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

	const char* Logger::FormatTime() const
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