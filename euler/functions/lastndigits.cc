#include "../euler.h"

// Returns the last N digits from a number.
size_t euler::lastNdigits(size_t num, int N)
{
    return (num % math::fastpow(10, N));
}
