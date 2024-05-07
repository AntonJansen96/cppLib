#include "primetools.h"

// Check whether a number is amicable.
bool euler::Primetools::isAmicable(size_t num)
{
    size_t const pds1 = this->divisorSumProper(num);
    size_t const pds2 = this->divisorSumProper(pds1);

    // Condition for num being amicable:
    return (pds1 != pds2 && num == pds2) ? true : false;
}
