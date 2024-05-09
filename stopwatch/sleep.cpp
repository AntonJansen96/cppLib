#include "stopwatch.h"
#include <thread>

// Additional Stopwatch function. Sleeps (the current thread) for #seconds.
void sleep(float seconds)
{
    // Convert float to an integer representing the value in microseconds.
    int64_t const ms = static_cast<int64_t>(1'000'000 * seconds);
    // Sleep for the specified number of microseconds.
    std::this_thread::sleep_for(std::chrono::microseconds(ms));
}
