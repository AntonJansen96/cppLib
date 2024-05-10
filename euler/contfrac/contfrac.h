#ifndef CPPLIB_EULER_CONTFRAC_H
#define CPPLIB_EULER_CONTFRAC_H

#include "../../fractions/fractions.h"
#include <vector>

namespace euler::contfrac
{

// Converts a fraction p/q to a continued fraction representation.
std::vector<size_t> fromfrac(Fraction const &frac);

// Converts a fraction p/q to a continued fraction representation.
std::vector<size_t> fromfrac(size_t p, size_t q);

// Converts a continued fraction back to a fraction p/q.
Fraction tofrac(std::vector<size_t> const &cf);

// Converts a square root N to a continued fraction representation.
// The optional lim is a limit for the number of coefficients in the continued fraction.
// If set to zero, will compute until full period is found.
std::vector<size_t> fromsqrt(size_t N, size_t lim = 0);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a decimal value.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
double tosqrt_dec(std::vector<size_t> const &cf, size_t iter = 2);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a Fraction.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
Fraction tosqrt_frac(std::vector<size_t> const &cf, size_t iter = 2);

} // namespace euler::contfrac

# endif
