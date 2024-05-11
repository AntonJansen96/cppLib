#include "math/math.h"
#include <iostream>

int main()
{
    std::cout << math::isqrt(5) << '\n';
    std::cout << math::isqrt(0) << '\n';
    std::cout << math::mulmod(130, 15, 2) << '\n';
    std::cout << math::mulmod(130, 15, 0) << '\n';
    std::cout << math::powmod(15, 6, 6) << '\n';
    std::cout << math::powmod(15, 6, 0) << '\n';
    std::cout << math::modinverse(13, 2) << '\n';
    std::cout << math::modinverse(13, 0) << '\n';
    std::cout << math::fastpow(7, 5) << '\n';
    std::cout << math::fastpow(13, 5) << '\n';
    std::cout << math::intlog10(1412411) << '\n';
    std::cout << math::factorial(5) << '\n';
    std::cout << math::factorial(0) << '\n';
    std::cout << math::factorial(-2) << '\n';
    std::cout << math::binom(18, 7) << '\n'; // should be 31824
    std::cout << math::gcd(23142, 155) << '\n';
}
