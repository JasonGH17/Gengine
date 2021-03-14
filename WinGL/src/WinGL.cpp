#include "WinGL.h"

namespace {
	WinGL* g_AppPtr = NULL;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (g_AppPtr)
		return g_AppPtr->EventProc(hwnd, msg, wParam, lParam);
	else
		return DefWindowProc(hwnd, msg, wParam, lParam);
}

WinGL::~WinGL(void) {}

WinGL::WinGL()
{
	m_hInstance = NULL;
	m_hwnd = NULL;
	m_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_SIZEBOX | WS_MAXIMIZEBOX;
	m_hDC = NULL;
	m_hRC = NULL;
	m_width = 1280;
	m_height = 720;
	m_title = L"DeskBrew";
	m_fps = 0.0f;
	g_AppPtr = this;
}

int WinGL::Run()
{
	__int64 prevTime = 0;
	__int64 countPerSec = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTime);
	QueryPerformanceFrequency((LARGE_INTEGER*)&countPerSec);
	float secsPerCount = 1.0f / countPerSec;

	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			__int64 curTime = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
			float deltaTime = (curTime - prevTime) * secsPerCount;
			Update(deltaTime);
			Render();
			CalcFPS(deltaTime);
			SwapBuffers(m_hDC);

			prevTime = curTime;
		}
	}
	Shutdown();
	return static_cast<int>(msg.wParam);
}

bool WinGL::InitWin()
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = m_hInstance;
	wcex.lpfnWndProc = WndProc;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.lpszClassName = L"DeskBrew";
	wcex.lpszMenuName = NULL;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
		return ErrorMsg(L"FAILED TO REGISTER WINDOW CLASS!");

	RECT r{ 0, 0, (LONG)m_width, (LONG)m_height };
	AdjustWindowRect(&r, m_style, FALSE);
	int Width = r.right - r.left;
	int Height = r.bottom - r.top;
	int x = GetSystemMetrics(SM_CXSCREEN) / 2 - Width / 2;
	int y = GetSystemMetrics(SM_CYSCREEN) / 2 - Height / 2;

	m_hwnd = CreateWindow(L"DeskBrew", m_title, m_style, x, y, Width, Height, NULL, NULL, m_hInstance, NULL);
	if (!m_hwnd)
		return ErrorMsg(L"FAILED TO CREATE WINDOW!");

	ShowWindow(m_hwnd, SW_SHOW);
	return true;
}

bool WinGL::InitGL()
{
	m_hDC = GetDC(m_hwnd);
	PIXELFORMATDESCRIPTOR pd;
	ZeroMemory(&pd, sizeof(PIXELFORMATDESCRIPTOR));

	pd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pd.nVersion = 1;
	pd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pd.iPixelType = LPD_TYPE_RGBA;
	pd.cColorBits = 32;
	pd.cDepthBits = 24;
	pd.cStencilBits = 8;

	int format = ChoosePixelFormat(m_hDC, &pd);
	if (!SetPixelFormat(m_hDC, format, &pd))
		return ErrorMsg(L"FAILED TO SET PIXEL FORMAT");

	m_hRC = wglCreateContext(m_hDC);
	if (!wglMakeCurrent(m_hDC, m_hRC))
		return ErrorMsg(L"FAILED TO CREATE RENDER CONTEXT");

	return true;
}

void WinGL::CalcFPS(float dt)
{
	static float elapsed = 0.0f;
	static int frameCnt = 0;

	elapsed += dt;
	frameCnt++;

	if (elapsed >= 1.0f)
	{
		m_fps = (float)frameCnt;
		std::wstringstream ss;
		ss << m_title << " - FPS: " << m_fps;
		SetWindowText(m_hwnd, ss.str().c_str());

		elapsed = 0.0f;
		frameCnt = 0;
	}
}

void WinGL::Shutdown()
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hRC);
	ReleaseDC(m_hwnd, m_hDC);
}

bool WinGL::Init()
{
	if (!InitWin()) return false;
	if (!InitGL())  return false;

	return true;
}

LRESULT WinGL::EventProc(HWND hwnd, UINT u_msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	
	switch (u_msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT:
	{
		Render();
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_SIZE:
	{
		glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		PostMessage(hwnd, WM_PAINT, 0, 0);
		break;
	}
	default:
		return DefWindowProc(hwnd, u_msg, wParam, lParam);
	}
}