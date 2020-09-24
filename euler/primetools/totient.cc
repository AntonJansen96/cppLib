#include "primetools.h"
#include <cmath>

// Compute the totient of a number.
size_t euler::Primetools::totient(size_t num) const
{
    size_t totient = num;

    if (((num >> 1) << 1) == num)           // If num % 2 == 0,
    {
        totient -= totient / 2;
        
        while (((num >> 1) << 1) == num)    // If num % 2 == 0,
            num >>= 1;                      // divide num by 2.
    }
    
    size_t prime, idx = 0;
    while (d_primes[idx] <= sqrt(num))
    {
        prime = d_primes[idx];

        if (num % prime == 0)
        {
            totient -= totient / prime;
            
            while (num % prime == 0)
                num /= prime;
        }
        ++idx;
    }

    if (num > 2)  
        totient -= totient / num;

    return totient;
}
