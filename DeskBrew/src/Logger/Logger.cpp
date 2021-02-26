#include "Logger.h"

namespace DeskBrew
{
	Logger::Logger() {}
	Logger::~Logger() {}
	void Logger::Init() { m_Initialized = true; }
	std::string Logger::TimeLog() {
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		std::stringstream ss;
		ss << "[" << (now->tm_hour) << ':'
			<< (now->tm_min) << ':'
			<< now->tm_sec
			<< "] ";
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
			std::cout << time << (isCore ? "Brew: " : "App: ") << str << std::endl;
		}
	}
	void Logger::ERROR(const char* str, bool isCore)
	{
		if (m_Initialized)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);
			std::string time = TimeLog();
			std::cout << time << (isCore ? "Brew: " : "App: ") << str << std::endl;
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