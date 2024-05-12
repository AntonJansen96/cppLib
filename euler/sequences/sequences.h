#ifndef CPPLIB_EULER_SEQUENCES_H
#define CPPLIB_EULER_SEQUENCES_H

#include <cstdint>
#include <vector>

namespace euler::sequences
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Returns the Pisano period for the Fibonacci sequence modulo n
uInt pisanoperiod(uInt n);

// Generate all Fibonacci numbers smaller than uplim.
std::vector<uInt> fibonacci(uInt uplim);

} // namespace euler::sequences.

#endif
