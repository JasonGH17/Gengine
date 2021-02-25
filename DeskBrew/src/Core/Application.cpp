#include "Application.h"

namespace DeskBrew {
	Application::Application()
	{
		Logger* log = new Logger;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		log->Init();
		while (true);
	}
}
