#pragma once

#include <Windows.h>
#include <iostream>

#undef ERROR

#define TRACE(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 15);\
	std::cout << "[" << __TIME__ << "] App:Trace - " << x << std::endl;\
}
#define FATAL(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 71);\
	std::cout << "[" << __TIME__ << "] App:Fatal -" << x << std::endl;\
}
#define ERROR(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);\
	std::cout << "[" << __TIME__ << "] App:Error - " << x << std::endl;\
}
#define INFO(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 10);\
	std::cout << "[" << __TIME__ << "] App:Info - " << x << std::endl;\
}
#define WARN(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 6);\
	std::cout << "[" << __TIME__ << "] App:Warn - " << x << std::endl;\
}

#define DTRACE(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 15);\
	std::cout << "[" << __TIME__ << "] Brew:Trace - " << x << std::endl;\
}
#define DFATAL(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 71);\
	std::cout << "[" << __TIME__ << "] Brew:Fatal - " << x << std::endl;\
}
#define DERROR(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 4);\
	std::cout << "[" << __TIME__ << "] Brew:Error - " << x << std::endl;\
}
#define DINFO(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 10);\
	std::cout << "[" << __TIME__ << "] Brew:Info - " << x << std::endl;\
}
#define DWARN(x) {\
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(hConsole, 6);\
	std::cout << "[" << __TIME__ << "] Brew:Warn - " << x << std::endl;\
}