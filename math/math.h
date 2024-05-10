#ifndef CPPLIB_MATH_H
#define CPPLIB_MATH_H

#include "templates.h"
#include <cstdint>

namespace math
{

using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.

// Integer part of the square root.
uInt isqrt(uInt n);

// Returns (a * b) % m.
uInt mulmod(uInt a, uInt b, uInt m);

// Returns (a^b) % m.
uInt powmod(uInt a, uInt b, uInt m);

// Returns the modular inverse (ax = 1 (mod m)).
uInt modinverse(uInt a, uInt m);

// Returns n^m where n and m are positive integers.
// If tabulated value is not available, fall back on pow in <cmath>.
uInt fastpow(uInt n, uInt m);

// Returns the integer part of log10.
uInt intlog10(uInt num);

// Returns factorial of number (0 if 64-bit overflow).
uInt factorial(uInt num);

// Returns the binomial coefficient of N and n.
uInt binom(uInt N, uInt n);

// Euclidian algorithm. Returns the greatest common denominator of a, b.
uInt gcd(uInt a, uInt b);

} // namespace math

#endif
