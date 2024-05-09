#include "stopwatch.h"

namespace {
enum : size_t
{   // Number of iterations for determining the internal time.
    INTERNAL_ITER = 1'000'000 
};
}

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(size_t cycles, void (*func)())
{
    Stopwatch clock1; // For internal time.
    Stopwatch clock2; // For execution time.
    
    for (size_t idx = 0; idx != INTERNAL_ITER; ++idx)
    {
        clock1.start();
        clock1.stop();
    }

    clock2.start();
    for (size_t idx = 0; idx != cycles; ++idx)
        func();
    clock2.stop();

    size_t const internaltime = clock1.rawtime() / INTERNAL_ITER;
    size_t const exectime = (clock2.rawtime() - internaltime) / cycles;

    std::cout << "profile: average execution time is " << exectime
        << " (" << cycles << " cycles).\n";

    return exectime;
}
