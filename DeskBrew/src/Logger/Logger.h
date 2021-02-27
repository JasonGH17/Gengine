#pragma once

#include "Core/Core.h"

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#undef ERROR

namespace DeskBrew {
	class DB_API Logger
	{
	public:
		Logger();
		~Logger();

		void Init(bool Verbose);
		std::string TimeLog();

		void TRACE(const char* str, bool isCore);
		void FATAL(const char* str, bool isCore);
		void ERROR(const char* str, bool isCore);
		void INFO (const char* str, bool isCore);
		void WARN (const char* str, bool isCore);

	private:
		bool m_Initialized = false;
	};
}
