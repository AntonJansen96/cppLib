#ifndef CPPLIB_RANDOM_H
#define CPPLIB_RANDOM_H

#include <cstdint>

namespace probability
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Test function
void hellofromprobability();

} // namespace probability

#endif // CPPLIB_RANDOM_H
