#pragma once

#include "spdlog/spdlog.h"

namespace Vision {

	class Log
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

// Core log macros
#define VI_CORE_TRACE(...)    ::Vision::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VI_CORE_INFO(...)     ::Vision::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VI_CORE_WARN(...)     ::Vision::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VI_CORE_ERROR(...)    ::Vision::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VI_CORE_FATAL(...)    ::Vision::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define VI_TRACE(...)	      ::Vision::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VI_INFO(...)	      ::Vision::Log::GetClientLogger()->info(__VA_ARGS__)
#define VI_WARN(...)	      ::Vision::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VI_ERROR(...)	      ::Vision::Log::GetClientLogger()->error(__VA_ARGS__)
#define VI_FATAL(...)	      ::Vision::Log::GetClientLogger()->critical(__VA_ARGS__)