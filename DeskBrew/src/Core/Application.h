#pragma once

#include "Core.h"
#include "Logger/Logger.h"

namespace DeskBrew {
	class DB_API Application
	{
	public:
		Application();
		~Application();


		void Run();

	private:
		Logger *log = new Logger;
	};

	Application* CreateApplication();
}

