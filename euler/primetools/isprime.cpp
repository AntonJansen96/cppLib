#include "../../math/math.h"
#include "primetools.h"
#include <iostream>

namespace euler
{

// Check whether a number is prime using the classical method.
bool Primetools::isPrime(uInt num)
{
    if ((num & 1) == 0)    // If num is even
        return (num == 2); // only even prime is 2

    uInt idx = 1;
    while (d_primes[idx] <= math::isqrt(num))
    {                                 // If divisble by a prime, smaller than
        if (num % d_primes[idx] == 0) // the root of num, num is not prime.
            return false;

        ++idx;

        if (idx == d_nPrimes) // If we have reached the end of the
            this->expand();   // current d_primes vector, call
    } // expand() (i.e. double the vector).

    return (num > 1); // No number smaller than 2 is prime.
}

} // namespace euler
