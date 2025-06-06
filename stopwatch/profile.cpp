#include "../math/math.h"
#include "stopwatch.h"
#include <iostream>
#include <vector>

namespace stopwatch
{

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(std::function<void()> func, size_t cycles)
{ // We use std::function from <functional> instead of a raw (function)
    // pointer because it is more flexible and can be used with lambdas.
    using namespace std::chrono;

    cycles == 0 ? cycles = 1 : cycles; // Cannot be 0.

    std::vector<size_t> values(cycles);

    for (size_t idx = 0; idx != cycles; ++idx)
    {
        auto const start = high_resolution_clock::now();
        func();
        auto const end = high_resolution_clock::now();
        values[idx] = duration_cast<nanoseconds>(end - start).count();
    }

    double const mean = math::mean(values);
    double const sdev = math::sdev(values);

    std::cout << "profile: average execution time is " << Stopwatch::format(mean)
              << " ± " << Stopwatch::format(sdev) << " (" << cycles << " cycles).\n";
    return static_cast<size_t>(mean);
}

} // Namespace stopwatch
