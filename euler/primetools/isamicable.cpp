#include "primetools.h"

// Check whether a number is amicable.
bool euler::Primetools::isAmicable(uInt num)
{
    if (num < 220)
        return false; // First term is 220, see A063990.

    uInt const pds1 = this->divisorSumProper(num);
    uInt const pds2 = this->divisorSumProper(pds1);

    return pds1 != pds2 && num == pds2; // Amicable condition.
}
