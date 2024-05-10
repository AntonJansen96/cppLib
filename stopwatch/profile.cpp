#include "../math/math.h"
#include "../pythonlike/pythonlike.h"
#include "stopwatch.h"
#include <vector>

using namespace pythonlike;

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(size_t cycles, void (*func)())
{
    using timePoint = std::chrono::time_point<std::chrono::system_clock>;
    std::vector<size_t> values(cycles);

    for (size_t idx = 0; idx != cycles; ++idx)
    {
        timePoint const start = std::chrono::system_clock::now();
        func();
        timePoint const end = std::chrono::system_clock::now();
        values[idx] = (end - start).count();
    }

    double const mean = math::mean(values);
    double const sdev = math::sdev(values);

    print(fs("profile: average execution time is {} ± {} ({} cycles).", Stopwatch::format(mean),
             Stopwatch::format(sdev), cycles));
    return static_cast<size_t>(mean);
}
