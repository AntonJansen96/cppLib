#ifndef FASTMATH_H
#define FASTMATH_H

#include <iosfwd>

namespace fastMath
{

// Check whether num is a power of 2.
bool isPowerOf2(size_t num);

// Returns the integer part of log10.
int log10(size_t num);

// Exponentiate num [0, 10] with power.
size_t pow(size_t n, size_t m);

// Modulo multiplication
template <class Type> Type mul_mod(Type a, Type b, Type m)
{
    if (m == 0)
        return a * b;

    Type num = Type();

    while (a > 0)
    {
        if (a & 1 and (num += b) > m)
            num %= m;
        
        a >>= 1;
        
        if ((b <<= 1) > m)
            b %= m;
    }

    return num;
}

// Modulo exponentiation
template <class Type> Type pow_mod(Type a, Type n, Type m)
{
    Type num = 1;

    while (n > 0)
    {
        if (n & 1)
            num = mul_mod(num, a, m);
        
        a = mul_mod(a, a, m);
        
        n >>= 1;
    }
    
    return num;
}

} // Namespace fastMath.

#endif
