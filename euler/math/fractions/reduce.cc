#include "fractions.h"
#include "../../euler.h" // circular reference.

namespace euler::math {

Fraction Fraction::reduce() const
{
    if (d_num == 0)
        return Fraction(d_num, 1);

    auto gcd = euler::gcd(d_num, d_den);

    if (gcd == 1)
        return *this;

    return Fraction(d_num / gcd, d_den / gcd);
}

} // Namespace.
