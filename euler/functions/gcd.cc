#include "../euler.h"

// Euclidean algorithm. Returns greatest common denominator of a and b.
int euler::gcd(int a, int b)
{
    while (b) 
        b ^= a ^= b ^= a %= b;
    
    return a;
}

// This is just as fast if not faster as the code below.

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
