#include "stopwatch.h"

// Start Stopwatch.
void Stopwatch::start()
{
    if (d_stopped)
    {
        d_stopped = false;
        d_start = timeNow;
    }
}
