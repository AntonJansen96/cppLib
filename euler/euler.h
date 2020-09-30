#ifndef EULER_H
#define EULER_H

#include "permutations/permutations.h"
#include "combinations/combinations.h"
#include "primetools/primetools.h"

#include <string>
#include <vector>
#include <tuple>

namespace euler {

// NUMBERS AND DIGITS **********************************************************

// Returns the number of digits of a number.
int numDigits(size_t num);

// Returns the sum of the digits of number.
int sumDigits(size_t num);

// Returns the first N digits from a number.
size_t firstNdigits(size_t num, int N);

// Returns the first N digits from base^exp.
size_t firstNdigits(int base, int exp, int N);

// Returns the last N digits from a number.
size_t lastNdigits(size_t num, int N);

// CHECKS FOR CERTAIN PROPERTIES ***********************************************

// Checks whether number is a perfect square.
bool isSquare(size_t num);

// Checks whether two numbers a and b are coprime.
bool isCoprime(size_t a, size_t b);

// Checkss whether number is a perfect number.
bool isPerfect(size_t num);

// Checks whether number is juf.
bool isJuf(size_t num);

// Checks whether number is a palindrome.
bool isPalindrome(size_t num);

// PARTITIONING ****************************************************************

// Returns #partitions of a number.
double partition(size_t money);

// Returns #ways money can be divided by coins in listed in coinvector.
double partition(size_t money, std::vector<size_t> const &coins);

// GENERATORS ******************************************************************

// Generates all Fibonacci numbers smaller than uplim.
std::vector<size_t> genFibonnaci(size_t uplim);

// Generates all numbers that are a to b pandigital.
std::vector<size_t> genPandigital(int a, int b);

// Generates primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
genPrimTriples(size_t perimLim);

// Generates all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
genTriples(size_t perimLim);

// CERTAIN CONVERSIONS *********************************************************

// Converts a decimal number to a specified radix.
std::string radix(size_t value, size_t radix);

// Converts a decimal number to a Roman numeral.
std::string dec2roman(int dec);

// Converts a Roman numeral to a decimal number.
int roman2dec(std::string const &numeral);

// MISCELLANEOUS FUNCTIONS *****************************************************

// Euclidean algorithm. Returns the greatest common denominator of a and b.
int gcd(int a, int b);

// Returns the factorial of number.
double factorial(int num);

// Returns the binomial coefficient of N and n.
double binomCoeff(int N, int n);

} // Namespace.

#endif
