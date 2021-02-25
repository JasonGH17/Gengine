#pragma once

#include "Core/Core.h"
#include <stdio.h>

namespace DeskBrew {
	class DB_API Logger
	{
	public:
		Logger();
		~Logger();

		void Init();
	};
}
