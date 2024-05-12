#include "fractions/fractions.h"
#include <cassert>

using namespace fractions;

int main()
{
    // Test whether normalize() works properly.
    assert(Fraction(2, 4) == Fraction(1, 2));
    assert(Fraction(-2, -4) == Fraction(1, 2));
    assert(Fraction(2, -4) == Fraction(-1, 2));

    // Test approximation.
    assert(Fraction(1, 3).approx() == 0.3333333333333333);

    // Test addition, subtraction, multiplication, and division.
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);
    assert(frac1 + frac2 == Fraction(5, 4));
    assert(frac1 - frac2 == Fraction(-1, 4));
    assert(frac1 * frac2 == Fraction(3, 8));
    assert(frac1 / frac2 == Fraction(2, 3));
    assert(frac1 + 2 == Fraction(5, 2));
    assert(frac1 - 2 == Fraction(-3, 2));
    assert(5 * frac1 == Fraction(5, 2));
    assert(4 / frac2 == Fraction(16, 3));
    assert(frac2 / 4 == Fraction(3, 16));

    // Test comparison operators.
    assert((Fraction(1, 2) < Fraction(3, 4)) == true);
    assert((Fraction(1, 2) > Fraction(3, 4)) == false);
    assert((Fraction(1, 2) == Fraction(3, 4)) == false);
    assert((Fraction(1, 2) != Fraction(3, 4)) == true);
    assert((Fraction(1, 2) >= Fraction(3, 4)) == false);
    assert((Fraction(1, 2) <= Fraction(3, 4)) == true);

    // Test continued fractions.
    for (uInt p = 1; p != 11; ++p)
        for (uInt q = 1; q != 11; ++q)
            assert(tofrac(fromfrac(p, q)) == Fraction(p, q));

    // Test square roots.
    for (uInt n = 4; n != 101; ++n)
        assert(tosqrt_dec(fromsqrt(n)) - static_cast<double>(n) < 1e-4);
}
