#pragma once


#ifndef SPDLOG_ACTIVE_LEVEL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif 
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>

bool log_init_def();
#define XLOG_DEF_LOGGER_NAME "default"
#define xlog_trace(...) SPDLOG_LOGGER_TRACE(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define xlog_debug(...) SPDLOG_LOGGER_DEBUG(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define xlog_info(...)  SPDLOG_LOGGER_INFO (spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define xlog_warr(...)  SPDLOG_LOGGER_WARN (spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define xlog_err(...) SPDLOG_LOGGER_ERROR(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
#define xlog_crit(...)  SPDLOG_LOGGER_CRITICAL(spdlog::get(XLOG_DEF_LOGGER_NAME), __VA_ARGS__)
