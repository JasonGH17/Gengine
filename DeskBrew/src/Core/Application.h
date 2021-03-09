#pragma once

#include "Core.h"
#include "Logger/Logger.h"
#include "../../WinGL/src/include/WinGL.h"

namespace DeskBrew {
	class DB_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		Logger *log = new Logger;
		WinGL* wnd = new WinGL;
	};

	Application* CreateApplication();
}

