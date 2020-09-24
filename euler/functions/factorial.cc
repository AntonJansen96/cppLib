#include "../euler.h"

// Returns factorial of number.
double euler::factorial(double num)
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}
