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

// Reduce fraction.
Fraction Fraction::reduce() const
{
    if (d_num == 0)
        return Fraction(d_num, 1);

    Type thegcd = gcd(d_num, d_den);

    if (thegcd == 1)
        return *this;

    return Fraction(d_num / thegcd, d_den / thegcd);
}

// Euclidean algorithm. Returns greatest common denominator of a and b.
Type Fraction::gcd(Type a, Type b) const
{
    // GCD does not work if we have a negative numerator.
    // Therefore, we make the numerator positive and remember the sign.
    Type sign = 1;
    if (a < 0)
    {
        a = -a;
        sign = -1;
    }

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

    return sign * (a << shift);

#else
    // standard GCD
    while (b) 
        b ^= a ^= b ^= a %= b;
    
    return sign * a;

#endif
}
