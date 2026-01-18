#include "log.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace {

}

bool log_init_def()
{
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::debug);
    consoleSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] %n %^%l%$ [%s:%#:%!] %v");
    consoleSink->set_level(spdlog::level::debug);
    auto logger = std::make_shared<spdlog::logger>(XLOG_DEF_LOGGER_NAME, consoleSink);
    logger->set_level(spdlog::level::debug);
    spdlog::register_logger(logger);
    return true;
}