#include "stopwatch.h"

// Reset Stopwatch.
void Stopwatch::reset()
{
    d_start = timeNow;
    d_diff = 0;
}
