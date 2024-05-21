#include "math/math.h"
#include <cassert>
#include <vector>

int main()
{
    assert(math::isqrt(5) == 2);
    assert(math::isqrt(0) == 0);
    assert(math::isqrt(-3) == 0); // should be 0 for negative numbers.

    assert(math::mulmod(0, 0, 0) == 0); // should return 0 if m == 0.
    assert(math::mulmod(0, 0, 1) == 0);
    assert(math::mulmod(123, 8, 5) == 4);
    assert(math::mulmod(87654321, 12345678, 12345) == 9558);

    assert(math::powmod(0, 0, 0) == 0); // should return 0 if m == 0.
    assert(math::powmod(5, 3, 7) == 6);
    assert(math::powmod(1234, 78, 120) == 16);

    assert(math::modinverse(0, 5) == 0); // Edge case: a is 0
    assert(math::modinverse(5, 0) == 0); // Edge case: m is 0
    assert(math::modinverse(4, 2) == 0); // Edge case: a and m are not coprime
    assert(math::modinverse(15, 26) == 7);

    assert(math::fastpow(0, 0) == 1);
    assert(math::fastpow(0, 1) == 0);
    assert(math::fastpow(1, 1) == 1);
    assert(math::fastpow(1, 0) == 1);
    assert(math::fastpow(7, 5) == 16807);
    assert(math::fastpow(13, 5) == 371293); // fall back on man multiplication.

    assert(math::intlog10(9) == 0);
    assert(math::intlog10(11) == 1);
    assert(math::intlog10(1412411) == 6);

    assert(math::factorial(0) == 1);
    assert(math::factorial(1) == 1);
    assert(math::factorial(5) == 120);
    double const result = math::factorial(80);
    double const expected = 7.15695e+118;
    assert(std::abs((result - expected) / expected) < 1e-5);

    assert(math::binom(5, 2) == 10);
    assert(math::binom(18, 7) == 31824);

    assert(math::gcd(123, 456) == 3);
    assert(math::gcd(23142, 155) == 1);

    // TEMPLATES
    std::vector<int> empty;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    assert(math::mean(empty) == 0.0);
    assert(math::mean(vec) == 3.0);
    assert(math::sdev(empty) == 0.0);
    assert(math::sdev(vec) == 1.4142135623730951);
    assert(math::median(empty) == 0.0);
    assert(math::median(vec) == 3);
}
