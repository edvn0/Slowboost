#include "Logger.hpp"

std::shared_ptr<spdlog::logger> Logger::core_logger;
std::shared_ptr<spdlog::logger> Logger::client_logger;
bool Logger::is_initialized;

void Logger::init()
{
	is_initialized = true;
	spdlog::set_pattern("%^[%T] %n: %v%$");
	core_logger = spdlog::stdout_color_mt("Engine");
	core_logger->set_level(spdlog::level::trace);
	client_logger = spdlog::stdout_color_mt("App");
	client_logger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> Logger::get_core_logger()
{
	if (!is_initialized) {
		throw std::runtime_error("You forgot to initalize the Logger. Call Logger::init() somewhere.");
	}
	return core_logger;
}

std::shared_ptr<spdlog::logger> Logger::get_client_logger()
{
	if (!is_initialized) {
		throw std::runtime_error("You forgot to initalize the Logger. Call Logger::init() somewhere.");
	}
	return client_logger;
}
