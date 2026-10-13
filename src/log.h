#include <string>
#include <syncstream>
#include <iostream>
#include <chrono>
#include <format>
#include <thread>

enum Level
{
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

const char *toString(Level level);

class LogMessage
{
public:
    LogMessage(Level level, const std::string &prefix)
    {
        buffer << timestamp() << "; " << toString(level) << "; ";
        if (!prefix.empty())
        {
            buffer << prefix;
        }
        buffer << "(" << std::this_thread::get_id() << "): ";
    }
    template <typename T>
    explicit LogMessage(Level level, const std::string &prefix, const T &first) : LogMessage(level, prefix)
    {
        buffer << first;
    }
    ~LogMessage()
    {
        buffer << "\n";
    }

    LogMessage(const LogMessage &log) = delete;
    LogMessage(LogMessage &&) = delete;
    LogMessage &operator=(const LogMessage &) = delete;
    LogMessage &operator=(LogMessage &&) = delete;

    template <typename T>
    LogMessage &operator<<(const T &value)
    {
        buffer << value;
        return *this;
    }

private:
    std::string timestamp();
    std::osyncstream buffer{std::cout};
};

class Logger
{
public:
    explicit Logger(const std::string &pref) : prefix(pref) {}

    LogMessage operator()(Level level) const
    {
        return LogMessage(level, prefix);
    }

    template <typename T>
    LogMessage operator<<(const T &value) const
    {
        return LogMessage(Level::INFO, prefix, value);
    }

private:
    std::string prefix;
};

Logger getLogger(const std::string &func);
Logger getLogger();