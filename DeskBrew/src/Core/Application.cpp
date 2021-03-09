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
		wnd->Init(L"DeskBrewWND", L"DeskBrew");
	}
}
