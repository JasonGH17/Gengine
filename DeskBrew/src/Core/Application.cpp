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
		if (win->Init())
		{
			while (win->isRun())
				win->Broadcast();
		}
	}
}
