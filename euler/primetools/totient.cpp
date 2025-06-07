#include "../../math/math.h"
#include "primetools.h"

namespace euler
{

// Compute the totient of a number.
uInt Primetools::totient(uInt num)
{
    if (num == 0) // Otherwise, 0 is not handled correctly.
        return 0;

    uInt totient = num;

    if (((num >> 1) << 1) == num) // num % 2 == 0
    {
        totient -= totient / 2;

        while (((num >> 1) << 1) == num) // while num % 2 == 0
            num >>= 1;                   // num /= 2
    }

    uInt prime;
    uInt idx = 1;
    while (d_primes[idx] <= math::isqrt(num))
    {
        prime = d_primes[idx];

        if (num % prime == 0)
        {
            totient -= totient / prime;

            while (num % prime == 0)
                num /= prime;
        }

        ++idx;

        if (idx == d_nPrimes) // If we have reached the end of the current d_primes
            this->expand();   //  vector, call // expand() (i.e. double the vector).
    }

    if (num > 2)
        totient -= totient / num;

    return totient;
}

} // namespace euler
