#include "primetools.h"

// Compute the totient of a number.
size_t euler::Primetools::totient(size_t num)
{
    size_t totient = num;

    if (((num >> 1) << 1) == num)           // num % 2 == 0
    {
        totient -= totient / 2;
        
        while (((num >> 1) << 1) == num)    // while num % 2 == 0
            num >>= 1;                      // num /= 2
    }
    
    size_t prime; int idx = 1;
    while (d_primes[idx] <= fastRoot(num))
    {
        prime = d_primes[idx];

        if (num % prime == 0)
        {
            totient -= totient / prime;
            
            while (num % prime == 0)
                num /= prime;
        }

        ++idx;

        if (idx == d_nPrimes)           // If we have reached the end of the
            this->expand();             // current d_primes vector, call        
    }                                   // expand() (i.e. double the vector).

    if (num > 2)  
        totient -= totient / num;

    return totient;
}
