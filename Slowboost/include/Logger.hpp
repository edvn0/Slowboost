
#pragma once

// clang-format off
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
//clang-format on

#include <memory>
#include <xtensor/xio.hpp>

class Logger {
public:
	static void init();

	static std::shared_ptr<spdlog::logger> get_core_logger();
	static std::shared_ptr<spdlog::logger> get_client_logger();

private:
    static bool is_initialized;
    
	static std::shared_ptr<spdlog::logger> core_logger;
	static std::shared_ptr<spdlog::logger> client_logger;
};

#define ERROR(...) ::Logger::get_client_logger()->error(__VA_ARGS__)
#define WARN(...) ::Logger::get_client_logger()->warn(__VA_ARGS__)
#define INFO(...) ::Logger::get_client_logger()->info(__VA_ARGS__)
#define TRACE(...) ::Logger::get_client_logger()->trace(__VA_ARGS__)
