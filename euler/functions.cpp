#include "../math/math.h"
#include "euler.h"

#include <algorithm>
#include <cmath>

// Check whether num is a square.
bool euler::isSquare(size_t num)
{
    size_t h = num & 0xF; // Last hexadecimal "digit".

    if (h > 9)
        return false; // Return immediately in 6/16 cases.

    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        size_t root = std::floor(std::sqrt(num) + 0.5);
        return (root * root == num); // Take square root if you must.
    }

    return false;
}

// Checks whether two numbers a and b are coprime.
bool euler::isCoprime(int a, int b)
{
    if (((a | b) & 1) == 0) // Reject if both are even (gcd(a,b) >= 2).
        return false;

    return (math::gcd(a, b) == 1);
}

// Check whether num is a perfect number.
bool euler::isPerfect(size_t num)
{
    if (num == 6 or num == 28 or num == 496 or num == 8128 or num == 33550336 or
        num == 8589869056 or num == 137438691328 or
        num == 2305843008139952128 // next one is larger than size_t so stop.
    )
        return true;

    return false;
}

// Checks whether a number is juf.
bool euler::isJuf(size_t num)
{
    return (num % 7 == 0 || std::to_string(num).find('7') != std::string::npos ||
            (euler::isPalindrome(num) && num > 10))
               ? true
               : false;
}

// Check whether a number is a palindrome.
bool euler::isPalindrome(size_t num)
{
    size_t tmp = num, invnum = 0;

    while (tmp)
    {
        invnum = invnum * 10 + (tmp % 10);
        tmp /= 10;
    }

    return invnum == num ? true : false;
}

namespace
{

size_t fingerPrint(size_t num)
{
    size_t digit, result = 0;
    while (num > 0)
    {
        digit = num % 10;
        num /= 10;

        result += 1ULL << (5 * digit);
    }

    return result;
}

} // Namespace.

// Check whether the number a is a digit permutation of number b.
bool euler::isPermutationOf(size_t a, size_t b)
{
    return (fingerPrint(a) == fingerPrint(b)) ? true : false;
}

// Return #partitions of a number.
double euler::partition(size_t money)
{
    std::vector<size_t> coins;
    for (size_t num = 1; num <= money; ++num)
        coins.push_back(num);

    std::vector<double> ways(money + 1);
    ways[0] = 1;

    for (size_t ii = 0; ii < coins.size(); ++ii)
        for (size_t jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Returns #ways money can be divided by coins in listed in coinvector.
double euler::partition(size_t money, std::vector<size_t> const &coins)
{
    std::vector<double> ways(money + 1);
    ways[0] = 1;

    for (size_t ii = 0; ii < coins.size(); ++ii)
        for (size_t jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Generate all numbers that are a to b pandigital.
std::vector<size_t> euler::genPandigital(int a, int b)
{
    std::vector<int> digits;
    for (int digit = a; digit <= b; ++digit)
        digits.push_back(digit);

    Permutations perm(digits);

    std::vector<size_t> pandigitals;
    while (not perm.done())
    {
        size_t num = perm.yieldnumber();

        if (numDigits(num) == b - a + 1)
            pandigitals.push_back(num);
    }

    return pandigitals;
}

// Converts a decimal number to a specified radix.
std::string euler::radix(size_t value, size_t radix)
{
    std::string accumulate; // Stores the converted number.

    do
    {
        size_t ch = value % radix; // Get the last digit.
        value /= radix;            // Cut off the last digit.

        ch += ch < 10 ? '0' : 'a' - 10; // Convert ch to char.

        accumulate.insert(0, 1, ch); // Insert digit before other digit.
    } while (value);

    return accumulate;
}

// Returns the least common multiple of a and b.
// The smallest positive integer that is divisble by both a and b.
int euler::lcm(int a, int b)
{
    return a * (b / math::gcd(a, b));
}
