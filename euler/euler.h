#ifndef EULER_H
#define EULER_H

#include "permutations/permutations.h"
#include "combinations/combinations.h"
#include "primetools/primetools.h"

#include <string>
#include <vector>
#include <tuple>

namespace euler {

// Generate all Fibonacci numbers smaller than uplim.
std::vector<size_t> genFibonnaci(size_t uplim);

// Euclidean algorithm. Returns greatest common denominator of a and b.
int gcd(int a, int b);

// Check whether a number is a palindrome.
bool isPalindrome(size_t num);

// Return the number of digits of a number.
size_t numDigits(double num);

// Generate all numbers that are a to b pandigital.
std::vector<size_t> genPandigital(size_t a, size_t b);

// Returns factorial of number.
double factorial(int num);

// Returns binomial coefficient of N and n.
double binomCoeff(int N, int n);

// Checks whether a number is juf.
bool isJuf(size_t num);

// Generate primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
genPrimTriples(size_t perimLim);

// Generate all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
genTriples(size_t perimLim);

// Returns #ways money can be divided by coins in listed in coinvector.
double partition(size_t money, std::vector<size_t> const &coins);

// Return #partitions of a number.
double partition(size_t money);

// Returns the first N digits from base^exp.
size_t firstNdigits(int base, int exp, int N);

// Returns the sum of the digits of num.
int sumDigits(size_t num);

// Check whether num is a square.
bool isSquare(size_t num);

// Check whether two numbers a and b are coprime.
bool isCoprime(size_t a, size_t b);

// Check whether num is a perfect number.
bool isPerfect(size_t num);

// Converts a decimal number to a specified radix.
std::string radix(size_t value, size_t radix);

// Converts a decimal number to a Roman numeral.
std::string dec2roman(int dec);

// Converts a Roman numeral to a decimal number.
int roman2dec(std::string const &numeral);

} // Namespace.

#endif
