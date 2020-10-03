#include "primetools.h"
// #include <iostream>
// #include "../../easy/easy.h"

void euler::Primetools::expand()
{   // debug
    // std::cout << "expand called, d_max old =" << d_max << ", d_max new = " << 4*d_max << '\n';

    d_max *= 4; // use 4 because roo(4) = 2 is factor to increase primes with
    int next = d_primes.back();

    while (next < fastRoot(d_max) + 1)
    {
        for (int prime : d_primes)
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
    // easy::print(d_primes); // debug
}
