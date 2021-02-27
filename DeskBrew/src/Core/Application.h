#pragma once

#include "Core.h"
#include "Logger/Logger.h"
#include "Window/Windows/WinWindow.h"

namespace DeskBrew {
	class DB_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		Logger *log = new Logger;
		WinWindow* win = new WinWindow();
	};

	Application* CreateApplication();
}

