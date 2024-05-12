#include "fractions.h"
#include "../math/math.h"

#include <iostream>

// Move-assignment operator.
Fraction &Fraction::operator=(Fraction &&other) noexcept
{
    std::swap(d_num, other.d_num);
    std::swap(d_den, other.d_den);
    other.d_num = 1; // Leave the temporary
    other.d_den = 1; // object in a valid state.

    return *this;
}

// Insert Fraction (l-value) into stream.
std::ostream &operator<<(std::ostream &out, Fraction const &obj)
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
    sInt sign = 1;
    if (d_num < 0)
    {
        d_num = -d_num;
        sign = -1;
    }
    // Compute the gcd and multiply by the sign.
    sInt const factor = math::gcd(d_num, d_den);

    d_num = sign * d_num / factor;
    d_den = d_den / factor;
}
