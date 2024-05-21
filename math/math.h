#ifndef CPPLIB_MATH_H
#define CPPLIB_MATH_H

#include "templates.h"
#include <cstdint>

namespace math
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Integer part of the square root. Returns 0 for negative numbers.
uInt isqrt(sInt n);

// Returns (a * b) % m.
uInt mulmod(uInt a, uInt b, uInt m);

// Returns (a^b) % m.
uInt powmod(uInt a, uInt b, uInt m);

// Returns the modular inverse (ax = 1 (mod m)).
uInt modinverse(uInt a, uInt m);

// Returns n^m where n and m are positive integers.
uInt fastpow(uInt n, uInt m);

// Returns the integer part of log10.
uInt intlog10(uInt num);

// Returns factorial of number.
double factorial(uInt num);

// Returns the binomial coefficient of N and n.
uInt binom(uInt N, uInt n);

// Euclidian algorithm. Returns the greatest common denominator of a, b.
uInt gcd(uInt a, uInt b);

} // namespace math

#endif
