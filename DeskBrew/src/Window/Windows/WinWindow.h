#pragma once

#ifndef UNICODE
#define UNICODE
#endif 

#include <Core/Core.h>

#include <Windows.h>
#include "Logger/Logger.h"

namespace DeskBrew {
	class DB_API WinWindow
	{
	public:
		WinWindow();
		~WinWindow();

		bool Init(); 
		bool Broadcast();
		bool Release();
		bool isRun();

		virtual void onCreate();
		virtual void onUpdate();
		virtual void onDestroy();

	private:
		Logger* log = new Logger;
	protected:
		HWND m_hwnd;
		bool m_is_run;
	};
}

