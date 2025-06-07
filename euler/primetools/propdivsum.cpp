#include "../../math/math.h"
#include "primetools.h"

namespace euler
{

// Returns the sum of the proper factors (divisors) of a number.
uInt Primetools::divisorSumProper(uInt num, uInt order)
{
    switch (order)
    {
        case (0):
            return this->divisorSum(num, order) - 1;

        case (1):
            return this->divisorSum(num, order) - num;

        case (2):
            return this->divisorSum(num, order) - num * num;

        case (3):
            return this->divisorSum(num, order) - num * num * num;

        default:
            return this->divisorSum(num, order) - math::fastpow(num, order);
    }
}

} // namespace euler
