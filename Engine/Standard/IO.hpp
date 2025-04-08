#pragma once

#include <fmt/core.h>
#include <fmt/color.h>
#include <mutex>

namespace io {

    enum class LogLevel {
        INFO,
        WARNING,
        ERROR,
        DEBUG,
        INLINE
    };

    void log(LogLevel level, fmt::string_view format, fmt::format_args args);

    template <typename... Args>
    void printerr(LogLevel level, fmt::format_string<Args...> format, Args&&... args) {
        log(level, format, fmt::make_format_args(args...));
    }

    template <typename... Args>
    void println(fmt::format_string<Args...> format, Args&&... args) {
        log(LogLevel::INFO, format, fmt::make_format_args(args...));
    }

    template <typename... Args>
    void print(fmt::format_string<Args...> format, Args&&... args) {
        log(LogLevel::INLINE, format, fmt::make_format_args(args...));
    }

}