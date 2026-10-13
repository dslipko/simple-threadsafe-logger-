#include "log.h"

const char *toString(Level level)
{
    switch (level)
    {
    case Level::INFO:
        return "INFO";
    case Level::WARNING:
        return "WARNING";
    case Level::ERROR:
        return "ERROR";
    case Level::DEBUG:
        return "DEBUG";
    }
    return "UNKNOWN";
}

std::string LogMessage::timestamp()
{
    const auto now = std::chrono::floor<std::chrono::seconds>(
        std::chrono::system_clock::now());
    return std::format("{:%Y-%m-%d %H:%M:%S}", now);
}

Logger getLogger(const std::string &function)
{
    return Logger(function);
}

Logger getLogger()
{
    return Logger("");
}
