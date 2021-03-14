#include "WindowClass.h"

WindowClass::WindowClass() : WinGL()
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
	// KEEP IN FUNCTION
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.5, 0.0, 0.5, 1.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(0, 1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2i(-1, -1);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(1, -1);
	glEnd();

	// KEEP IN FUNCTION
	glFlush();
}

LRESULT WindowClass::EventProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	default:
		return WinGL::EventProc(hwnd, msg, wParam, lParam);
	}
}
