#include "sequences.h"

namespace euler::sequences
{

// Returns the Pisano period for the Fibonacci sequence modulo n
uInt pisanoperiod(uInt n)
{
    uInt a = 0;
    uInt b = 1;
    uInt c;

    for (uInt i = 0; i != n * n; ++i)
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
