#ifndef CPPLIB_STOPWATCH_H
#define CPPLIB_STOPWATCH_H

#include <chrono>
#include <iostream>

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(size_t cycles, void (*func)());

// Additional Stopwatch function. Sleeps (the current thread) for #seconds.
void sleep(float seconds);

class Stopwatch
{
    using timePoint = std::chrono::time_point<std::chrono::system_clock>;

    timePoint d_start;         // Stores starting time.
    size_t d_diff;             // Stores elapsed time.
    std::string d_description; // Optional descriptor.
    bool d_stopped;            // Stopwatch running or not?

  public:
    Stopwatch(); // Constructors.
    explicit Stopwatch(std::string const &description);
    Stopwatch(Stopwatch const &other);   // Copy constructor.
    Stopwatch(Stopwatch &&tmp) noexcept; // Move constructor.

    void start();               // Start Stopwatch.
    void stop();                // Stop Stopwatch.
    void reset();               // Reset Stopwatch.
    std::string &description(); // Return/edit optional descriptor.
    bool isrunning() const;     // Check whether Stopwatch is running.
    size_t rawtime() const;     // Return elapsed time as the number of ns.
    static std::string format(size_t rawtime); // Format raw time into a string.
    void time(std::ostream &out = std::cout); // Return formatted elapsed time.

    Stopwatch &operator=(Stopwatch const &other);   // Copy-assignment.
    Stopwatch &operator=(Stopwatch &&tmp) noexcept; // Move-assignment.

    // Insert formatted time into stream (l-value).
    friend std::ostream &operator<<(std::ostream &out, Stopwatch const &obj);
    // Insert formatted time into stream (r-value).
    friend std::ostream &operator<<(std::ostream &out, Stopwatch &&obj);

    Stopwatch &operator+=(Stopwatch const &rhs); // Add Stopwatches.
    Stopwatch &operator-=(Stopwatch const &rhs); // Subtract Stopwatches.

    bool operator==(Stopwatch const &other) const; // Compare w. Stopwatch.
    bool operator!=(Stopwatch const &other) const; // Compare w. Stopwatch.
    bool operator<(Stopwatch const &other) const;  // Compare w. Stopwatch.
    bool operator>(Stopwatch const &other) const;  // Compare w. Stopwatch.
    bool operator<=(Stopwatch const &other) const; // Compare w. Stopwatch.
    bool operator>=(Stopwatch const &other) const; // Compare w. Stopwatch.

  private:
    void swap(Stopwatch &other) noexcept; // Dedicated swap member.
};

// Return/edit Stopwatch description.
inline std::string &Stopwatch::description()
{
    return d_description;
}

// Check whether Stopwatch is running.
inline bool Stopwatch::isrunning() const
{
    return !d_stopped;
}

// Get Stopwatch elapsed time in ns.
inline size_t Stopwatch::rawtime() const
{
    if (not d_stopped)
    {
        Stopwatch::timePoint const currtime = std::chrono::system_clock::now();
        return d_diff + (currtime - d_start).count();
    }

    return d_diff;
}

inline void Stopwatch::time(std::ostream &out)
{
    out << Stopwatch::format(rawtime()) << std::endl;
}

// Add Stopwatch objects.
inline Stopwatch operator+(Stopwatch const &lhs, Stopwatch const &rhs)
{
    return Stopwatch{lhs} += rhs;
}

// Subtract Stopwatch objects.
inline Stopwatch operator-(Stopwatch const &lhs, Stopwatch const &rhs)
{
    return Stopwatch{lhs} -= rhs;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator==(Stopwatch const &other) const
{
    return rawtime() == other.rawtime() ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator!=(Stopwatch const &other) const
{
    return rawtime() != other.rawtime() ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<(Stopwatch const &other) const
{
    return rawtime() < other.rawtime() ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>(Stopwatch const &other) const
{
    return rawtime() > other.rawtime() ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<=(Stopwatch const &other) const
{
    return rawtime() <= other.rawtime() ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>=(Stopwatch const &other) const
{
    return rawtime() >= other.rawtime() ? true : false;
}

#endif
