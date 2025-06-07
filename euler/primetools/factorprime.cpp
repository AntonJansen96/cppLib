#include "../../math/math.h"
#include "primetools.h"

// Generate prime pFactors of a number.
std::vector<size_t> euler::Primetools::factorPrime(size_t num)
{
    if (num < 2)
        return std::vector<size_t>{}; // 0, 1 have no prime factors.

    std::vector<size_t> pFactors;
    size_t prime;
    int idx = 1;                     // Start at second prime in d_primes
                                     // (3) because we already checked 2.
    while (((num >> 1) << 1) == num) // while num % 2 == 0
    {
        pFactors.push_back(2);
        num >>= 1; // num /= 2
    }
    // Only have to check up until root of
    while (d_primes[idx] <= math::isqrt(num))
    { // num.
        prime = d_primes[idx];

        while (num % prime == 0) // While num is divisible by prime ...
        {
            pFactors.push_back(prime); // ... add that prime to pFactors,
            num /= prime;              // and divide.
        }

        ++idx;

        if (idx == d_nPrimes) // If we have reached the end of the
            this->expand();   // current d_primes vector, call
    } // expand() (i.e. double the vector).

    if (num > 2)                 // If at the end we're left with a
        pFactors.push_back(num); // number larger than two, it must be
                                 // a prime so add to PFactors.
    return pFactors;
}
