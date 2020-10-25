#include "../euler.h"

// Euclidean algorithm. Returns greatest common denominator of a and b.
int euler::gcd(int a, int b)
{
#ifdef __GNUC__   // This is around 60% faster using specific CPU instructions.
                  // Source https://euler.stephan-brumme.com/toolbox/
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    // MSVC++: _BitScanForward intrinsic instead
    auto shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        
        b -= a;
    } while (b != 0);

    return a << shift;

#else
    // standard GCD
    while (b) 
        b ^= a ^= b ^= a %= b;
    
    return a;

#endif
}

// Old fastest gcd:

// int euler::gcd(int a, int b)
// {
//     while (b) 
//         b ^= a ^= b ^= a %= b;
    
//     return a;
// }

// The function above is also significantly faster than 
// https://en.wikipedia.org/wiki/Binary_GCD_algorithm.

// This is just as fast if not faster as the code below:

// int euler::gcd(int a, int b)
// {
//     int temp;
    
//     while (b != 0)
//     {
//         temp = a;
//         a = b; b = temp % b;
//     }

//     return a;
// }
