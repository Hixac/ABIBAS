#pragma once

#include <LoggingSystem.h>

#ifdef DEBUG
	#define LOG_WARN(x) Log::LoggingSystem::Send(x, Log::Types::Warn)
	#define LOG_CRITICAL(x) Log::LoggingSystem::Send(x, Log::Types::Critical)
	#define LOG_INFO(x) Log::LoggingSystem::Send(x, Log::Types::Info)
	#define LOG_ERROR(x) Log::LoggingSystem::Send(x, Log::Types::Error)

	#define INIT_LOG() Log::LoggingSystem::Instantiate("Logger");\
					   LOG_INFO("Log system has initialized!")
#else
	#define LOG_WARN(x)
	#define LOG_CRITICAL(x)
	#define LOG_INFO(x)
	#define LOG_ERROR(x)

	#define INIT_LOG()
#endif

#define ASSERT(x) spdlog::error(x); __debugbreak()
