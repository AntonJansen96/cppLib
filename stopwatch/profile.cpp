#include "stopwatch.h"

// Additional function that maybe be used for profiling functions/lambdas.
size_t profile(size_t iterations, void (*func)())
{
    Stopwatch clock;

    clock.start();
    for (size_t idx = 0; idx != iterations; ++idx)
        func();
    clock.stop();
    
    clock /= iterations;
    clock.time();
    return clock.rawtime();
}
