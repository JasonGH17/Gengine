#include "Application.h"

namespace DeskBrew {
	Application::Application()
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 1200, 600, TRUE);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowClass window;
		if (!window.Init())
			return;
		DBINFO("Window initialized", "Application.cpp");
		window.Run();
		while (true);
	}
}
