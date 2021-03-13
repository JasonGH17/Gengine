#pragma once

#include "../src/Utils.h"

class WinGL {
public:
	WinGL(/*HINSTANCE hInstance*/);
	virtual ~WinGL(void);

	int Run();

	virtual bool Init();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual LRESULT EventProc(HWND hwnd, UINT u_msg, WPARAM wParam, LPARAM lParam);

protected:
	bool InitWin();
	bool InitGL();
	void CalcFPS(float dt);
	void Shutdown();

protected:
	HWND		m_hwnd;
	HINSTANCE	m_hInstance;
	DWORD		m_style;
	HDC			m_hDC;
	HGLRC		m_hRC;
	UINT		m_width;
	UINT		m_height;
	LPWSTR		m_title;
	float		m_fps;
};