#include "primetools.h"

void euler::Primetools::expand()
{
    d_max *= 4; // use 4 because root(4) = 2 is factor to increase primes with.
    unsigned int next = d_primes.back();

    while (next < fastRoot(d_max) + 1)
    {
        for (unsigned int const prime : d_primes)
        {
            if (next % prime == 0)
                break;

            if (prime > fastRoot(next))
            {
                d_primes.push_back(next);
                break;
            }
        }
        next += 2;
    }

    d_nPrimes = d_primes.size();
}
