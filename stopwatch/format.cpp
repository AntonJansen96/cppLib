#include "stopwatch.h"
#include <iomanip>

namespace stopwatch
{

enum Time : size_t
{
    MICROSECOND = 1000,
    MILLISECOND = 1000000,
    SECOND = 1000000000,
    MINUTE = 60000000000,
    HOUR = 3600000000000,
    DAY = 86400000000000
};

std::string Stopwatch::format(size_t rawtime)
{
    std::ostringstream oss;

    if (rawtime < MICROSECOND) // less than 1us
    {
        oss << "< 1us";
    }
    else if (rawtime < MILLISECOND) // less than 1ms
    {
        oss << rawtime / static_cast<float>(MICROSECOND) << "us";
    }
    else if (rawtime < SECOND) // less than 1s
    {
        oss << std::fixed << std::setprecision(2)
            << rawtime / static_cast<float>(MILLISECOND) << "ms";
    }
    else // 1s or more
    {
        if (rawtime >= DAY) // 1d or more
        {
            size_t days = rawtime / DAY;
            size_t hours = (rawtime % DAY) / HOUR;
            size_t minutes = ((rawtime % DAY) % HOUR) / MINUTE;
            float seconds =
                (((rawtime % DAY) % HOUR) % MINUTE) / static_cast<float>(SECOND);
            oss << days << "d" << hours << "h" << minutes << "m" << std::fixed
                << std::setprecision(0) << seconds << "s";
        }
        else if (rawtime >= HOUR) // 1h or more
        {
            size_t hours = rawtime / HOUR;
            size_t minutes = (rawtime % HOUR) / MINUTE;
            float seconds = ((rawtime % HOUR) % MINUTE) / static_cast<float>(SECOND);
            oss << hours << "h" << minutes << "m" << std::fixed << std::setprecision(0)
                << seconds << "s";
        }
        else if (rawtime >= MINUTE) // 1m or more
        {
            size_t minutes = rawtime / MINUTE;
            float seconds = (rawtime % MINUTE) / static_cast<float>(SECOND);
            oss << minutes << "m" << std::fixed << std::setprecision(0) << seconds
                << "s";
        }
        else // less than 1m
        {
            oss << std::fixed << std::setprecision(2)
                << rawtime / static_cast<float>(SECOND) << "s";
        }
    }
    return oss.str();
}

} // namespace stopwatch
