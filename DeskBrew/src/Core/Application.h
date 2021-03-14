#pragma once

#include "Core.h"
#include "Window/WindowClass.h"
#include "Logger/Logger.h"

namespace DeskBrew {
	class DB_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
}

