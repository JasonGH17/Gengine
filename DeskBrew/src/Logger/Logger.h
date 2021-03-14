#pragma once

#include <Windows.h>
#include <iostream>

#undef ERROR

#define TRACE(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 15);\
	std::cout << "[" << __TIME__ << "] App:Trace - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define FATAL(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 71);\
	std::cout << "[" << __TIME__ << "] App:Fatal -" << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define ERROR(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);\
	std::cout << "[" << __TIME__ << "] App:Error - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define INFO(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 10);\
	std::cout << "[" << __TIME__ << "] App:Info - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define WARN(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 6);\
	std::cout << "[" << __TIME__ << "] App:Warn - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}

#define DBTRACE(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 15);\
	std::cout << "[" << __TIME__ << "] Brew:Trace - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define DBFATAL(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 71);\
	std::cout << "[" << __TIME__ << "] Brew:Fatal - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define DBERROR(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);\
	std::cout << "[" << __TIME__ << "] Brew:Error - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define DBINFO(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 10);\
	std::cout << "[" << __TIME__ << "] Brew:Info - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}
#define DBWARN(x, filename) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 6);\
	std::cout << "[" << __TIME__ << "] Brew:Warn - " << x << " (in file: " << filename << "::" << __FUNCTION__ << "(Line:" << __LINE__ << "))" << std::endl;\
}