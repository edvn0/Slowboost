#include "Logger.hpp"

std::shared_ptr<spdlog::logger> Logger::core_logger;
std::shared_ptr<spdlog::logger> Logger::client_logger;

void Logger::init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	core_logger = spdlog::stdout_color_mt("Engine");
	core_logger->set_level(spdlog::level::trace);
	client_logger = spdlog::stdout_color_mt("App");
	client_logger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> Logger::get_core_logger() { return core_logger; }

std::shared_ptr<spdlog::logger> Logger::get_client_logger() { return client_logger; }