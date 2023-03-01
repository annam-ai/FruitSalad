#pragma once

#include <memory>
#include "spdlog\spdlog.h"
#include "Core.h"

namespace FruitSalad {

	class FRUITSALAD_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros
// forward arguments from the macro to the function
#define FS_CORE_TRACE(...)    ::FruitSalad::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)     ::FruitSalad::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)     ::FruitSalad::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)    ::FruitSalad::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_FATAL(...)    ::FruitSalad::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define FS_TRACE(...)    ::FruitSalad::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)     ::FruitSalad::Log::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)     ::FruitSalad::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)    ::FruitSalad::Log::GetClientLogger()->error(__VA_ARGS__)
#define FS_FATAL(...)    ::FruitSalad::Log::GetClientLogger()->fatal(__VA_ARGS__)

// If dist build -> can just define it as nothing and it will be stripped from the build
// will not be in binary -> will not be run in distribution builds.
