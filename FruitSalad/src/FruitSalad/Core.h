#pragma once

#ifdef FS_PLATFORM_WINDOWS
	#ifdef FS_BUILD_DLL
		#define FRUITSALAD_API __declspec(dllexport)
	#else
		#define FRUITSALAD_API __declspec(dllimport)
	#endif
#else
#error Fruitsalad only supports Windows!
#endif