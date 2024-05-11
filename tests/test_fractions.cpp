#include "fractions/fractions.h"
#include <iostream>

int main()
{
    auto frac1 = Fraction(1, 1);
    auto frac2 = Fraction(-2, 4);
    std::cout << Fraction(1, 3) << '\n';
    ;
    std::cout << Fraction(1, 3).approx() << '\n';
    ;
    std::cout << Fraction(2, 4) << '\n';
    ;
    std::cout << Fraction(-1, 3) << '\n';
    ;
    std::cout << Fraction(1, -3) << '\n';
    ;
    std::cout << Fraction(-1, -3) << '\n';
    ;
    std::cout << Fraction(-1, 0) << '\n';
    ;

    std::cout << frac1 + frac2 << '\n';
    std::cout << frac1 - frac2 << '\n';
    std::cout << frac1 * frac2 << '\n';
    std::cout << frac1 / frac2 << '\n';

    std::cout << 4 + frac2 << '\n';
    ;
    std::cout << -4 + frac2 << '\n';
    ;
    std::cout << 4 - frac2 << '\n';
    ;
    std::cout << -4 - frac2 << '\n';
    ;
    std::cout << 4 * frac2 << '\n';
    ;
    std::cout << -4 * frac2 << '\n';
    ;

    std::cout << 4 / frac2 << '\n';
    ; // should return -8
    std::cout << -4 / frac2 << '\n';
    ; // should return 8
    std::cout << frac2 / 4 << '\n';
    ; // should return -1/8
    std::cout << frac2 / -4 << '\n';
    ; // should return 1/8
    std::cout << (frac2 /= -4) << '\n';
    ; // should return 1/8

    std::cout << (frac1 < frac2) << '\n';
    ;
    std::cout << (frac1 > frac2) << '\n';
    ;
    std::cout << (frac1 == frac2) << '\n';
    ;
    std::cout << (frac1 != frac2) << '\n';
    ;
    std::cout << (frac1 >= frac2) << '\n';
    ;
    std::cout << (frac1 <= frac2) << '\n';
    ;
}
