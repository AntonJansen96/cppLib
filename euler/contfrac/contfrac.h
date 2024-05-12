#ifndef CPPLIB_EULER_CONTFRAC_H
#define CPPLIB_EULER_CONTFRAC_H

#include "contfrac.h"
#include "../../fractions/fractions.h" // TODO This is a problem when installing.
#include <vector>

namespace euler::contfrac
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(Fraction const &frac);

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(uInt p, uInt q);

// Converts a continued fraction back to a fraction p/q.
Fraction tofrac(std::vector<uInt> const &cf);

// Converts a square root N to a continued fraction representation.
// The optional lim is a limit for the number of coefficients in the continued fraction.
// If set to zero, will compute until full period is found.
std::vector<uInt> fromsqrt(uInt N, uInt lim = 0);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a decimal value.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
double tosqrt_dec(std::vector<uInt> const &cf, uInt iter = 2);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a Fraction.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
Fraction tosqrt_frac(std::vector<uInt> const &cf, uInt iter = 2);

} // namespace euler::contfrac

#endif
