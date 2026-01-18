#pragma once


#ifndef SPDLOG_ACTIVE_LEVEL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif 
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>

bool log_init_def();
#define XLOG_DEF_LOGGER_NAME "default"
#define XLOG_TRACE(...) SPDLOG_LOGGER_TRACE(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define XLOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define XLOG_INFO(...)  SPDLOG_LOGGER_INFO (spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define XLOG_WARN(...)  SPDLOG_LOGGER_WARN (spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define XLOG_ERROR(...) SPDLOG_LOGGER_ERROR(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define XLOG_CRIT(...)  SPDLOG_LOGGER_CRITICAL(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
