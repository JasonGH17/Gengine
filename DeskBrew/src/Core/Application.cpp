#include "Application.h"

namespace DeskBrew {
	Application::Application()
	{
		log->Init(true);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowClass window;
		if (!window.Init())
			return;
		window.Run();
	}
}
