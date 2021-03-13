#pragma once

#include "../../WinGL/include/WinGL.h"

class WindowClass : public WinGL
{
public:
	WindowClass(/*HINSTANCE hInstance*/);
	~WindowClass();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;
	LRESULT EventProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) override;
};

