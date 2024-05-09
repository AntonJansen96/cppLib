#include "stopwatch.h"

// Additional function that may be be used for profiling functions/lambdas.
// Make sure to inline the function to be tested.
size_t profile(size_t iterations, void (*func)())
{
    Stopwatch clock1;   // For subtracting the time it takes 
    clock1.start();     // to start and stop the clock itself.
    clock1.stop();
    size_t internaltime = clock1.rawtime();

    Stopwatch clock2;
    clock2.start();
    for (size_t idx = 0; idx != iterations; ++idx)
        func();
    clock2.stop();

    return (clock2.rawtime() - internaltime) / iterations;
}
