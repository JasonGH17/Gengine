#include "Application.h"

namespace DeskBrew {
	Application::Application()
	{
		log->Init(); 
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		log->TRACE("TRACE!", true);
		log->FATAL("FATAL!", false);
		log->ERROR("ERROR!", true);
		log->INFO("INFO!", false);
		log->WARN("WARN!", true);
		while (true);
	}
}
