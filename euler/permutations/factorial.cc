#include "permutations.h"

double euler::Permutations::factorial(double num) const
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}
