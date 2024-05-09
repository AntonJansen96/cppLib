#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock> timePoint;

// Additional function that maybe be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(size_t iterations, void (*func)());

class Stopwatch
{
    timePoint   d_start;            // Stores starting time.
    size_t      d_diff;             // Stores elapsed time.
    std::string d_description;      // Optional descriptor.
    bool        d_stopped = true;   // Stopwatch running or not?

    public:
        Stopwatch();                          // Constructors.
        explicit Stopwatch(std::string const &description);
        Stopwatch(Stopwatch const &other);    // Copy constructor.
        Stopwatch(Stopwatch &&tmp) noexcept;  // Move constructor.

        void start();                // Start Stopwatch.
        void stop();                 // Stop Stopwatch.
        void reset();                // Reset Stopwatch.
        std::string &description();  // Return/edit optional descriptor.
        bool isrunning() const;      // Check whether Stopwatch is running.
        std::string time(std::ostream &out = std::cout); // Return elapsed time as formatted string.
        size_t rawtime() const;      // Return elapsed time as the number of ns.

        Stopwatch &operator=(Stopwatch const &other);    // Copy-assignment.
        Stopwatch &operator=(Stopwatch &&tmp) noexcept;  // Move-assignment.

        // Insert formatted time into stream (l-value).
        friend std::ostream &operator<<(std::ostream &out, Stopwatch &obj);
        // Insert formatted time into stream (r-value).
        friend std::ostream &operator<<(std::ostream &out, Stopwatch &&obj);

        Stopwatch &operator+=(Stopwatch const &rhs);  // Add Stopwatches. 
        Stopwatch &operator-=(Stopwatch const &rhs);  // Subtract Stopwatches.
        
        Stopwatch &operator*=(size_t scalar); // Multiply by scalar.
        Stopwatch &operator/=(size_t scalar); // Divide by scalar.

        bool operator==(Stopwatch const &other) const;  // Compare w. Stopwatch.
        bool operator!=(Stopwatch const &other) const;  // Compare w. Stopwatch.
        bool operator<(Stopwatch const &other) const;   // Compare w. Stopwatch.
        bool operator>(Stopwatch const &other) const;   // Compare w. Stopwatch.
        bool operator<=(Stopwatch const &other) const;  // Compare w. Stopwatch.
        bool operator>=(Stopwatch const &other) const;  // Compare w. Stopwatch.

    private:
        void swap(Stopwatch &other);  // Dedicated swap member.
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

// Stop Stopwatch and return raw time (value of d_diff) in ns.
inline size_t Stopwatch::rawtime() const
{
    return d_diff;
}

// Add Stopwatch objects (times).
inline Stopwatch operator+(Stopwatch const &lhs, Stopwatch const &rhs)
{
    return Stopwatch{lhs} += rhs;
}

// Subtract Stopwatch objects (times).
inline Stopwatch operator-(Stopwatch const &lhs, Stopwatch const &rhs)
{
    return Stopwatch{lhs} -= rhs;
}

// Multiply Stopwatch object's time by scalar.
inline Stopwatch operator*(Stopwatch const &lhs, size_t scalar)
{
    return Stopwatch{lhs} *= scalar;
}

// Multiply Stopwatch object's time by scalar.
inline Stopwatch operator*(size_t scalar, Stopwatch const &rhs)
{
    return Stopwatch{rhs} *= scalar;
}

// Divide Stopwatch object's time by scalar.
inline Stopwatch operator/(Stopwatch const &lhs, size_t scalar)
{
    return Stopwatch{lhs} /= scalar;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator==(Stopwatch const &other) const
{
    return d_diff == other.d_diff ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator!=(Stopwatch const &other) const
{
    return d_diff != other.d_diff ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<(Stopwatch const &other) const
{
    return d_diff < other.d_diff ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>(Stopwatch const &other) const
{
    return d_diff > other.d_diff ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<=(Stopwatch const &other) const
{
    return d_diff <= other.d_diff ? true : false;
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>=(Stopwatch const &other) const
{
    return d_diff >= other.d_diff ? true : false;
}

#endif
