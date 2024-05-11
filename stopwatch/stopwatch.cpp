#include "stopwatch.h"

// Construct Stopwatch object and start.
Stopwatch::Stopwatch()
    : d_start(std::chrono::high_resolution_clock::time_point())
    , d_diff(0)
    , d_description("''")
    , d_stopped(true)
{
}

// Construct Stopwatch object, specify description and start.
Stopwatch::Stopwatch(std::string const &description)
    : d_start(std::chrono::high_resolution_clock::time_point())
    , d_diff(0)
    , d_description(description)
    , d_stopped(true)
{
}

// Copy constructor.
Stopwatch::Stopwatch(Stopwatch const &other)
    : d_start(other.d_start)
    , d_diff(other.d_diff)
    , d_description(other.d_description)
    , d_stopped(other.d_stopped)
{
}

// Move constructor.
Stopwatch::Stopwatch(Stopwatch &&tmp) noexcept
    : d_start(tmp.d_start)
    , d_diff(tmp.d_diff)
    , d_description(tmp.d_description)
    , d_stopped(tmp.d_stopped)
{
}

// Start Stopwatch.
void Stopwatch::start()
{
    if (d_stopped)
    {
        d_stopped = false;
        d_start = std::chrono::high_resolution_clock::now();
    }
    else
        std::cerr << "warning: tried to call start() on running "
                  << "Stopwatch object (" << d_description << ")\n";
}

// Stop Stopwatch.
void Stopwatch::stop()
{
    if (not d_stopped)
    {
        auto const stoptime = std::chrono::high_resolution_clock::now();
        d_stopped = true;
        d_diff += (stoptime - d_start).count();
    }
}

// Reset Stopwatch.
void Stopwatch::reset()
{
    d_start = std::chrono::high_resolution_clock::time_point();
    d_diff = 0;
}

// Copy-assignment.
Stopwatch &Stopwatch::operator=(Stopwatch const &other)
{
    return *this = Stopwatch{other};
}

// Move-assignment.
Stopwatch &Stopwatch::operator=(Stopwatch &&tmp) noexcept
{
    swap(tmp);
    return *this;
}

// Insert Stopwatch time into stream (l-value).
std::ostream &operator<<(std::ostream &out, Stopwatch const &obj)
{
    out << Stopwatch::format(obj.rawtime());
    return out;
}

// Insert Stopwatch time into stream (r-value).
std::ostream &operator<<(std::ostream &out, Stopwatch &&obj)
{
    out << Stopwatch::format(obj.rawtime());
    return out;
}

// Add Stopwatch elapsed times.
Stopwatch &Stopwatch::operator+=(Stopwatch const &rhs)
{
    d_diff += rhs.rawtime();
    return *this;
}

// Subtract Stopwatch elapsed times.
Stopwatch &Stopwatch::operator-=(Stopwatch const &rhs)
{
    d_diff -= rhs.rawtime();
    return *this;
}

// Dedicated swap member.
void Stopwatch::swap(Stopwatch &other) noexcept
{
    std::swap(d_start, other.d_start);
    std::swap(d_diff, other.d_diff);
    std::swap(d_description, other.d_description);
    std::swap(d_stopped, other.d_stopped);
}
