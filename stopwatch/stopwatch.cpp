#include "stopwatch.h"
#include <iomanip>

// Additional function that maybe be used for profiling functions/lambdas.
void profile(size_t iterations, void (*func)())
{
    Stopwatch timer1; timer1.stop(); timer1.reset();
    Stopwatch timer2; timer2.stop(); timer2.reset();

    for (size_t idx = 0; idx != iterations; ++idx)
    {
        // Log execution time of func + calling .start() and .stop().
        timer1.start(); func(); timer1.stop();

        // Log execution time of just calling .start() and .stop().
        timer2.start(); timer2.stop();        
    }
    // Subtract to get execution time of just func.
    ((timer1 - timer2) /= iterations).time();
}

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
    d_stop(other.d_stop),
    d_diff(other.d_diff),
    d_description(other.d_description),
    d_stopped(other.d_stopped)
{
    if (not other.d_stopped)
        throw(std::logic_error("cannot initialize Stopwatch with a running one"));
}

// Move constructor.
Stopwatch::Stopwatch(Stopwatch &&tmp)
:
    d_start(tmp.d_start),
    d_stop(tmp.d_stop),
    d_diff(tmp.d_diff),
    d_description(tmp.d_description),
    d_stopped(tmp.d_stopped)        
{
    if (not tmp.d_stopped)
        throw(std::logic_error("cannot initialize Stopwatch with a running one"));
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
        d_stop = std::chrono::system_clock::now();
        d_stopped = true;
        d_diff += (d_stop - d_start).count();
    }
}

// Reset Stopwatch.
void Stopwatch::reset()
{
    d_start = std::chrono::system_clock::now();
    d_diff  = 0;
}

// Insert (current) Stopwatch time into stream (default std::cout).
void Stopwatch::time(std::ostream &out)
{
    this->stop();                   // Stop Stopwatch (if not already).

    if (not d_description.empty())  // If description was specified, print.
        out << d_description << " took ";

    double diff = d_diff / std::chrono::nanoseconds(std::chrono::seconds(1)).count();

    if (diff < 1 && diff >= 0.001) // ms
        out << std::setprecision(3) << diff * 1'000 << "ms\n";
    
    else if (diff < 0.001 && diff >= 0.000001) // us
        out << std::setprecision(3) << diff * 1'000'000 << "us\n";

    else if (diff < 3600 && diff >= 60) // m+s
    {
        size_t min = static_cast<size_t>(diff / 60);
        size_t sec = diff - min * 60;

        out << min << 'm' << sec << "s\n";
    }
    
    else if (diff >= 3600) // h + m + s
    {
        size_t hrs = static_cast<size_t>(diff / 3600);
        size_t min = static_cast<size_t>((diff - hrs * 3600) / 60);
        size_t sec = diff - hrs * 3600 - min * 60;

        out << hrs << 'h' << min << 'm' << sec << "s\n";
    }

    else // s
        out << std::setprecision(4) << diff << "s\n";
}

// Add Stopwatch times.
Stopwatch &Stopwatch::operator+=(Stopwatch const &rhs)
{
    if ((not d_stopped) || (not rhs.d_stopped))
        throw(std::logic_error("cannot add running Stopwatch"));
    
    d_diff += rhs.d_diff;

    return *this;
}

// Subtract Stopwatch times.
Stopwatch &Stopwatch::operator-=(Stopwatch const &rhs)
{
    if ((not d_stopped) || (not rhs.d_stopped))
        throw(std::logic_error("cannot subtract running Stopwatch"));
    
    d_diff -= rhs.d_diff;

    return *this;
}

// Multiply Stopwatch object's time by scalar.
Stopwatch &Stopwatch::operator*=(size_t scalar)
{
    if (not d_stopped)
        throw(std::logic_error("cannot multiply running Stopwatch"));
    
    d_diff *= scalar;
    return *this;
}

// Divide Stopwatch object's time by scalar.
Stopwatch &Stopwatch::operator/=(size_t scalar)
{
    if (not d_stopped)
        throw(std::logic_error("cannot divide running Stopwatch"));
    
    d_diff /= scalar;
    return *this;
}

// Insert Stopwatch time into stream.
std::ostream &operator<<(std::ostream &out, Stopwatch &obj)
{
    obj.time(out);
    return out;
}

// Insert Stopwatch time into stream.
std::ostream &operator<<(std::ostream &out, Stopwatch &&obj)
{   // We need this one for rvalue references.
    obj.time(out);
    return out;
}

// Copy assignment.
Stopwatch &Stopwatch::operator=(Stopwatch const &other)
{
    return *this = Stopwatch{other};
}

// Move assignment.
Stopwatch &Stopwatch::operator=(Stopwatch &&tmp)
{
    if (not tmp.d_stopped)
        throw(std::logic_error("cannot move running Stopwatch"));
    
    swap(tmp);
    return *this;
}

// Dedicated swap member.
void Stopwatch::swap(Stopwatch &other)
{
    std::swap(d_start, other.d_start);
    std::swap(d_stop, other.d_stop);
    std::swap(d_diff, other.d_diff);
    std::swap(d_description, other.d_description);
    std::swap(d_stopped, other.d_stopped);
}
