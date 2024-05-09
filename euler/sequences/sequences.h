#ifndef CPPLIB_EULER_SEQUENCES_H
#define CPPLIB_EULER_SEQUENCES_H

#include <cstddef>
#include <vector>

namespace euler::sequences
{

// Returns the Pisano period for the Fibonacci sequence modulo n
size_t pisanoperiod(size_t n);

// Generate all Fibonacci numbers smaller than uplim.
std::vector<size_t> fibonacci(size_t uplim);

} // namespace euler::sequences.

#endif
