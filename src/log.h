#include <string>
#include <syncstream>
#include <iostream>

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
        buffer << '[' << toString(level) << "] ";
        if (!prefix.empty())
        {
            buffer << prefix << ": ";
        }
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

const char *toString(Level level);