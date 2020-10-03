#include "primetools.h"
#include <cmath>
#include <iostream>

// Check whether a number is prime.
bool euler::Primetools::isPrime(size_t num)
{
    if (num < 2)                        // No number smaller than 2 is prime.
        return false;
    
    int idx = 0;                        
    while (d_primes[idx] <= fastRoot(num))
    {                                   // If divisble by a prime, smaller than 
        if (num % d_primes[idx] == 0)   // the root of num, num is not prime.
            return false;

        ++idx;

        if (idx == d_nPrimes)           // If we have reached the end of the
            this->expand();             // current d_primes vector, call
    }                                   // expand() (i.e. double the vector).

    return true;                        // If we have not found any primes
}                                       // (below sqrt) that divide...
