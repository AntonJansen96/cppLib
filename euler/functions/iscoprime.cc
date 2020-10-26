#include "../euler.h"

// Checks whether two numbers a and b are coprime.
bool euler::isCoprime(int a, int b)
{
    if (((a | b) & 1) == 0) // Reject if both are even (gcd(a,b) >= 2).
        return false;
    
    return (gcd(a, b) == 1);
}
