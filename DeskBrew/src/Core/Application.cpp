#include "Application.h"

namespace DeskBrew {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowClass window;
		if (!window.Init())
			return;
		INFO("Window initialized");
		window.Run();
	}
}
