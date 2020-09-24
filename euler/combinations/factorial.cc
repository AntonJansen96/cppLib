#include "combinations.h"

// Private functions to compute the factorial.
double euler::Combinations::factorial(double num) const
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}
