#pragma once

#ifdef DB_PLATFORM_WINDOWS
#ifdef DB_BUILD_DLL
#define DB_API _declspec(dllexport)
#else 
#define DB_API _declspec(dllimport)
#endif
#endif