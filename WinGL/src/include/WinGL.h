#pragma once

#include <Windows.h>

class WinGL {
public:
	WinGL();
	~WinGL();

	int WINAPI Init(const wchar_t CLASSNAME[], const wchar_t WNDNAME[]);

private:
	int initialized;
	HWND m_hwnd;
};