#include "primetools.h"
#include <cmath>

// Construct Primetools object by specifying largest number to be analyzed.
// Default is sizeof(32-bit integer) but can be set accordingly.
euler::Primetools::Primetools(size_t uplim)
:
    d_uplim(uplim),
    d_primes(sieve(sqrt(uplim) + 2))
{}
