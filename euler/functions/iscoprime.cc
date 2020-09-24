#include "../euler.h"

// Checks whether two numbers a and b are coprime.
bool euler::isCoprime(size_t a, size_t b)
{
    return gcd(a, b) == 1;
}
