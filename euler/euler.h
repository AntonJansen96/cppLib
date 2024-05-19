#ifndef CPPLIB_EULER_H
#define CPPLIB_EULER_H

#include "combinatorics/combinations.h"
#include "combinatorics/numbersplit.h"
#include "combinatorics/permutations.h"
#include "primetools/primetools.h"
#include "sequences/sequences.h"

#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace euler
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Returns the number of digits of a number.
uInt numDigits(uInt num);

// Returns the sum of the digits of number.
uInt sumDigits(uInt num);

// Returns the number of of occurances of digit in num.
uInt countDigits(uInt num, uInt digit);

// Returns the nth digit of a number (starting at least significant digit).
uInt nthDigit(uInt num, uInt n);

// Returns the first N digits from a number.
uInt firstNdigits(uInt num, uInt N);

// Returns the first N digits from base^exp.
uInt firstNdigits(uInt base, uInt exp, uInt N);

// Returns the last N digits from a number.
uInt lastNdigits(uInt num, uInt N);

// Reverse a number. Example: 1234 -> 4321.
uInt reverseNumber(uInt num);

// CHECKS FOR CERTAIN PROPERTIES ***********************************************

// Check if a number is automorphic.
// Automorphic means that the square of the number ends with the number itself.
bool isAutomorphic(uInt num);

// Checks whether two numbers a and b are coprime.
bool isCoprime(uInt a, uInt b);

// Checks whether number is juf.
bool isJuf(uInt num);

// Checks whether number is a palindrome.
bool isPalindrome(uInt num);

// Checkss whether number is a perfect number.
bool isPerfect(uInt num);

// Check whether the number a is a digit permutation of number b.
bool isPermutationOf(uInt a, uInt b);

// Checks whether number is a perfect square.
bool isSquare(uInt num);

// PARTITIONING ****************************************************************

// Returns #partitions of a number.
uInt partition(uInt money);

// Returns #ways money can be divided by coins in listed in coinvector.
uInt partition(uInt money, std::vector<uInt> const &coins);

// GENERATORS ******************************************************************

// Generates all numbers that are a to b pandigital.
std::vector<uInt> genPandigital(uInt a, uInt b);

// Generates primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::vector<std::array<uInt, 3>> genPrimTriples(uInt perimLim);

// Generates all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::vector<std::array<uInt, 3>> genTriples(uInt perimLim);

// CERTAIN CONVERSIONS *********************************************************

// Converts a decimal number to a specified radix.
std::string radix(uInt value, uInt radix);

// Converts a decimal number to a Roman numeral.
std::string dec2roman(uInt dec);

// Converts a Roman numeral to a decimal number.
uInt roman2dec(std::string const &numeral);

// MISCELLANEOUS FUNCTIONS *****************************************************

// Returns the least common multiple of a and b.
// The smallest positive integer that is divisble by both a and b.
uInt lcm(uInt a, uInt b);

} // namespace euler

#endif
