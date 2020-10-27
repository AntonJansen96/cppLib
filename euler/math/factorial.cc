#include "math.h"

// Returns factorial of number.
double euler::math::factorial(int num)
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}
