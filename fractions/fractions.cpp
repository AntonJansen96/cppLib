#include "fractions.h"

#include <iostream>

// Move-assignment operator.
Fraction &Fraction::operator=(Fraction &&other) noexcept
{
    std::swap(d_num, other.d_num);
    std::swap(d_den, other.d_den);
    other.d_num = 1;    // Leave the temporary 
    other.d_den = 1;    // object in a valid state.

    return *this;
}

// Insert Fraction (l-value) into stream.
std::ostream &operator<<(std::ostream &out, Fraction &obj)
{
    return out << obj.num() << '/' << obj.denom();
}

// Insert Fraction (r-value) into stream.
std::ostream &operator<<(std::ostream &out, Fraction &&obj)
{
    return out << obj.num() << '/' << obj.denom();
}

// Normalize fraction. This does the following:
// 1. If the denom = 0, set denom = 1.
// 2. If num > 0 and denom < 0, set num = -num and denom = -denom.
// 3. If num < 0 and denom < 0, set num = -num and denom = -denom.
// 4. Reduce num and denom using the Euclidian algorithm.
void Fraction::normalize()
{
    std::cout << "normalize called\n"; // debug

    // 1.
    if (d_den == 0)
        d_den = 1;

    // 2 and 3.
    if (d_den < 0)
    {
        d_num = -d_num;
        d_den = -d_den;
    }

    // 4. At this point, we either have a/b or -a/b.
    // gcd only works for a/b, so always make a positive and remember the sign.
    Type sign = 1;
    if (d_num < 0)
    {
        d_num = -d_num;
        sign = -1;
    }
    // Compute the gcd and multiply by the sign.
    Type const factor = gcd(d_num, d_den);

    d_num = sign * d_num / factor;
    d_den = d_den / factor;
}

// Euclidean algorithm. Returns greatest common denominator of a and b.
Type Fraction::gcd(Type a, Type b) const
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
