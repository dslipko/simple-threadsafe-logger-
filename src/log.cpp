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

Logger getLogger(const std::string &function)
{
    return Logger(function);
}

Logger getLogger()
{
    return Logger("");
}
