#include "stopwatch.h"

// Construct Stopwatch object and start.
Stopwatch::Stopwatch()
:
    d_start(std::chrono::system_clock::now())
{}

// Construct Stopwatch object, specify description and start.
Stopwatch::Stopwatch(std::string const &description)
:
    d_start(std::chrono::system_clock::now()),
    d_description(description)
{}

// Copy constructor.
Stopwatch::Stopwatch(Stopwatch const &other)
:
    d_start(other.d_start),
    d_diff(other.d_diff),
    d_description(other.d_description),
    d_stopped(other.d_stopped)
{
}

// Move constructor.
Stopwatch::Stopwatch(Stopwatch &&tmp) noexcept
:
    d_start(tmp.d_start),
    d_diff(tmp.d_diff),
    d_description(tmp.d_description),
    d_stopped(tmp.d_stopped)        
{
}

// Start Stopwatch.
void Stopwatch::start()
{
    if (d_stopped)
    {
        d_stopped = false;
        d_start = std::chrono::system_clock::now();
    }
}

// Stop Stopwatch.
void Stopwatch::stop()
{
    if (not d_stopped)
    {
        timePoint const stoptime = std::chrono::system_clock::now();
        d_stopped = true;
        d_diff += (stoptime - d_start).count();
    }
}

// Reset Stopwatch.
void Stopwatch::reset()
{
    d_start = std::chrono::system_clock::time_point();
    d_diff  = 0;
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
std::ostream &operator<<(std::ostream &out, Stopwatch &obj)
{
    obj.time(out);
    return out;
}

// Insert Stopwatch time into stream (r-value).
std::ostream &operator<<(std::ostream &out, Stopwatch &&obj)
{
    obj.time(out);
    return out;
}

// Add Stopwatch elapsed times.
Stopwatch &Stopwatch::operator+=(Stopwatch const &rhs)
{
    if ((not d_stopped) || (not rhs.d_stopped))
        std::cout << "cannot add running Stopwatch" << std::endl;
    
    d_diff += rhs.d_diff;

    return *this;
}

// Subtract Stopwatch elapsed times.
Stopwatch &Stopwatch::operator-=(Stopwatch const &rhs)
{
    if ((not d_stopped) || (not rhs.d_stopped))
        std::cout << "cannot subtract running Stopwatch" << std::endl;
    
    d_diff -= rhs.d_diff;

    return *this;
}

// Multiply Stopwatch time by scalar.
Stopwatch &Stopwatch::operator*=(size_t scalar)
{
    if (not d_stopped)
        std::cout << "cannot multiply running Stopwatch" << std::endl;
    
    d_diff *= scalar;
    return *this;
}

// Divide Stopwatch time by scalar.
Stopwatch &Stopwatch::operator/=(size_t scalar)
{
    std::cout << "cannot divide running Stopwatch" << std::endl;
    
    d_diff /= scalar;
    return *this;
}

// Dedicated swap member.
void Stopwatch::swap(Stopwatch &other)
{
    std::swap(d_start, other.d_start);
    std::swap(d_diff, other.d_diff);
    std::swap(d_description, other.d_description);
    std::swap(d_stopped, other.d_stopped);
}
