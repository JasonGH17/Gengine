#include "WindowClass.h"

WindowClass::WindowClass(/*HINSTANCE hInstance*/) : WinGL(/*hInstance*/)
{
}

WindowClass::~WindowClass()
{
}

bool WindowClass::Init()
{
	if (!WinGL::Init())
		return false;
	return true;
}

void WindowClass::Update(float dt)
{
}

void WindowClass::Render()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(5, 10);
	glVertex2f(10, 10);
	glVertex2f(10, 5);
	glVertex2f(5, 5);
	glEnd();
}

LRESULT WindowClass::EventProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	default:
		return WinGL::EventProc(hwnd, msg, wParam, lParam);
	}
}
