#ifndef CPPLIBMATH_H
#define CPPLIBMATH_H

#include <cstdint>

namespace math {

using sInt = int64_t;   // Signed 64-bit integer.
using uInt = uint64_t;  // Unsigned 64-bit integer.

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

// Returns the factorial of a number.
uInt factorial(uInt num);

// Returns the binomial coefficient of N and n.
uInt binom(uInt N, uInt n);

} // Namespace.

#endif
