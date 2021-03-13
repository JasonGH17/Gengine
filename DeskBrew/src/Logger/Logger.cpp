#include "Logger.h"

namespace DeskBrew
{
	Logger::Logger() {}
	Logger::~Logger() {}
	void Logger::Init(bool verbose = true) {
		m_Initialized = true;
		if (verbose)
		{
			INFO("Core Logger Initialized", true);
			INFO("App Logger Initialized\n", false);
		}
	}
	std::string Logger::TimeLog() {
		time_t curr_time;
		tm* curr_tm;
		char time_string[100];
		time(&curr_time);
		curr_tm = localtime(&curr_time);
		strftime(time_string, 50, "[%T]", curr_tm);
		std::stringstream ss;
		ss << time_string;
		return ss.str();
	}

	void Logger::TRACE(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 15);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew: " : "App: ") << str << std::endl;
		}
	}
	void Logger::FATAL(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 71);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew::FATAL - " : "App::FATAL - ") << str << std::endl;
		}
	}
	void Logger::ERROR(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew::ERROR - " : "App::ERROR - ") << str << std::endl;
		}
	}
	void Logger::INFO(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 10);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew: " : "App: ") << str << std::endl;
		}
	}
	void Logger::WARN(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 6);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew: " : "App: ") << str << std::endl;
		}
	}
}