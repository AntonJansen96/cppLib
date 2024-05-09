#include "sequences.h"

namespace euler::sequences
{

// Returns the Pisano period for the Fibonacci sequence modulo n
size_t pisanoperiod(size_t n)
{
    size_t a = 0;
    size_t b = 1;
    size_t c;

    for (size_t i = 0; i != n * n; ++i)
    {
        c = (a + b) % n;
        a = b;
        b = c;

        if (a == 0 && b == 1)
            return i + 1;
    }
    return 0; // Should never reach here.
}

} // namespace euler::sequences.
