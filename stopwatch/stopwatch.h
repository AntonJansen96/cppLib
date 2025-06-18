#ifndef CPPLIB_STOPWATCH_H
#define CPPLIB_STOPWATCH_H

#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

namespace stopwatch
{

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(std::function<void()> func, size_t cycles = 1);

// Additional Stopwatch function. Sleeps (the current thread) for #seconds.
void sleep(float seconds);

class Stopwatch
{ // Stores starting time.
    std::chrono::time_point<std::chrono::high_resolution_clock> d_start;
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
    void time(std::ostream &out = std::cout);  // Return formatted elapsed time.

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
    using namespace std::chrono;
    if (not d_stopped)
    {
        time_point<high_resolution_clock> const currtime = high_resolution_clock::now();
        return d_diff + (currtime - d_start).count();
    }

    return d_diff;
}

inline void Stopwatch::time(std::ostream &out)
{
    out << Stopwatch::format(rawtime()) << '\n';
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
    return rawtime() == other.rawtime();
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator!=(Stopwatch const &other) const
{
    return rawtime() != other.rawtime();
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<(Stopwatch const &other) const
{
    return rawtime() < other.rawtime();
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>(Stopwatch const &other) const
{
    return rawtime() > other.rawtime();
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator<=(Stopwatch const &other) const
{
    return rawtime() <= other.rawtime();
}

// Compare two Stopwatch objects.
inline bool Stopwatch::operator>=(Stopwatch const &other) const
{
    return rawtime() >= other.rawtime();
}

class ProgressReport
{
    size_t const d_total;
    size_t const d_update;
    std::atomic<size_t> d_progress{0};
    Stopwatch d_timer;
    std::thread d_progress_thread;

  public:
    // Construct ProgressReport object.
    explicit ProgressReport(size_t total);
    // Construct ProgressReport object.
    ProgressReport(size_t total, size_t update);
    // Destructor.
    ~ProgressReport();
    // Delete copy and move constructors, since we have an std::thread member.
    ProgressReport(const ProgressReport &) = delete;
    ProgressReport(ProgressReport &&) = delete;
    // Delete copy and move assignment, since we have an std::thread member.
    ProgressReport &operator=(const ProgressReport &) = delete;
    ProgressReport &operator=(ProgressReport &&) = delete;
    // Increments the progress count (from any thread (threadsafe)).
    void tick(size_t n = 1);
    // Finish the progress count (join the progress thread).
    void join();

  private:
    // Start and run the progress counter thread (main code).
    void run();
    // Format user update.
    void progformat(double percent, size_t rawtime) const;
};

// Construct ProgressReport object.
inline ProgressReport::ProgressReport(size_t total)
    : d_total(total)
    , d_update(100) // default update every 100ms.
{
    run();
}

// Construct ProgressReport object.
inline ProgressReport::ProgressReport(size_t total, size_t update)
    : d_total(total)
    , d_update(update)
{
    run();
}

// Destructor.
inline ProgressReport::~ProgressReport()
{
    this->join();
}

// Increments the progress count (from any thread (threadsafe)).
inline void ProgressReport::tick(size_t n)
{
    for (size_t ii = 0; ii != n; ++ii)
        ++d_progress;
}

// Finish the progress count (join the progress thread).
inline void ProgressReport::join()
{
    if (d_progress_thread.joinable())
        d_progress_thread.join();
}

} // namespace stopwatch

#endif

// EXAMPLE CODE FOR USING THE PROGRESSREPORT CLASS.
// int main()
// {
//     size_t start = 0;
//     size_t stop = 20;
//     stopwatch::ProgressReport progress(stop - start);

//     #pragma omp parallel for schedule(dynamic, 1)
//     for (size_t ii = start; ii != stop; ++ii)
//     {
//         stopwatch::sleep(1);
//         progress.tick();
//     }
//     progress.join();

//     std::cout << "Finished loop." << std::endl;
// }
