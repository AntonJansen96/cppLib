#include "primetools.h"

// Returns the sum of the proper factors (divisors) of a number.
size_t euler::Primetools::divisorSumProper(size_t num, int order)
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
            return this->divisorSum(num, order) - std::pow(num, order);
    }
}
