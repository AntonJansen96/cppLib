#include "primetools.h"

// Check whether a number is amicable.
bool euler::Primetools::isAmicable(size_t num) const
{
    size_t propdivsum1 = 0, propdivsum2 = 0;

    for (size_t fac : factors(num))
        propdivsum1 += fac;

    propdivsum1 -= num;
    
    for (size_t fac : factors(propdivsum1))
        propdivsum2 += fac;

    propdivsum2 -= propdivsum1;
    
    return (propdivsum1 != propdivsum2 && num == propdivsum2) ? true : false;
}
