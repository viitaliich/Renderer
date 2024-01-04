#pragma once

#include "spdlog/spdlog.h"

namespace Renderer {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

#define LOGT(...)    ::Renderer::Log::GetLogger()->trace(__VA_ARGS__)
#define LOGI(...)    ::Renderer::Log::GetLogger()->info(__VA_ARGS__)
#define LOGW(...)    ::Renderer::Log::GetLogger()->warn(__VA_ARGS__)
#define LOGE(...)    ::Renderer::Log::GetLogger()->error(__VA_ARGS__)
#define LOGF(...)    ::Renderer::Log::GetLogger()->fatal(__VA_ARGS__)
