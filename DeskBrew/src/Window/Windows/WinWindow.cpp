#include "WinWindow.h"

namespace DeskBrew {
	WinWindow::WinWindow()
	{

	}


	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_CREATE:
		{
			WinWindow* window = (WinWindow*)((LPCREATESTRUCT)lparam)->lpCreateParams;
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
			window->onCreate();
			break;
		}

		case WM_DESTROY:
		{
			WinWindow* window = (WinWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->onDestroy();
			::PostQuitMessage(0);
			break;
		}
		default:
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
		}
		return NULL;
	}


	bool WinWindow::Init()
	{
		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = L"WindowClass";
		wc.lpszMenuName = L"";
		wc.style = NULL;
		wc.lpfnWndProc = &WndProc;

		if (!::RegisterClassEx(&wc))
			return false;
		m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass", L"DeskBrew", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
			NULL, NULL, NULL, this);

		if (!m_hwnd)
			return false;
		::ShowWindow(m_hwnd, SW_SHOW);
		::UpdateWindow(m_hwnd);

		m_is_run = true;
		log->Init(false);
		log->TRACE("Window initialized.", true);

		return true;
	}

	bool WinWindow::Broadcast()
	{
		MSG msg;


		while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			LRESULT event = DispatchMessage(&msg);
			log->TRACE(event, false);
		}

		this->onUpdate();

		Sleep(1);

		return true;
	}


	bool WinWindow::Release()
	{
		if (!::DestroyWindow(m_hwnd))
			return false;

		return true;
	}

	bool WinWindow::isRun()
	{
		return m_is_run;
	}

	void WinWindow::onCreate()
	{
	}

	void WinWindow::onUpdate()
	{
		//log->INFO("Update!", false);
	}

	void WinWindow::onDestroy()
	{
		m_is_run = false;
	}

	WinWindow::~WinWindow()
	{
	}
}