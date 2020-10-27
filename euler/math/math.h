#ifndef MATH_H
#define MATH_H

#include "fractions/fractions.h"

namespace euler::math {

// Returns (a * b) % m.
size_t mulmod(size_t a, size_t b, size_t m);

// Returns (a^b) % m.
size_t powmod(size_t a, size_t b, size_t m);

// Returns the modular inverse (ax = 1 (mod m)).
unsigned int modinverse(unsigned int a, unsigned int m);

// Exponentiate num [0, 10] with power.
size_t fastpow(size_t n, size_t m);

// Returns the integer part of log10.
int intlog10(size_t num);

// Returns the factorial of a number.
double factorial(int num);

// Returns the binomial coefficient of N and n.
double binomCoeff(int N, int n);

} // Namespace.

#endif
