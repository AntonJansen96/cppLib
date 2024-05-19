#include "../math/math.h"
#include "euler.h"

#include <algorithm>
#include <cmath>

namespace euler
{

// Check if a number is automorphic.
// Automorphic means that the square of the number ends with the number itself.
bool isAutomorphic(uInt num)
{
    uInt square = num * num;
    // Start from the last digit of num and square, and compare digits
    while (num > 0)
    {
        // If last digits of num and square are not same
        if (num % 10 != square % 10)
            return false;
        // Move to the next digit
        num /= 10;
        square /= 10;
    }
    return true;
}

// Checks whether two numbers a and b are coprime.
bool isCoprime(uInt a, uInt b)
{
    if (((a | b) & 1) == 0) // Reject if both are even (gcd(a,b) >= 2).
        return false;

    return math::gcd(a, b) == 1;
}

// Checks whether a number is juf.
bool isJuf(uInt num)
{
    return (num % 7 == 0 || std::to_string(num).contains('7') ||
            (isPalindrome(num) && num > 10));
}

// Check whether a number is a palindrome.
bool isPalindrome(uInt num)
{
    uInt tmp = num, invnum = 0;

    while (tmp)
    {
        invnum = invnum * 10 + (tmp % 10);
        tmp /= 10;
    }

    return invnum == num;
}

// Check whether num is a perfect number.
bool isPerfect(uInt num)
{
    if (num == 6 or num == 28 or num == 496 or num == 8128 or num == 33550336 or
        num == 8589869056 or num == 137438691328 or
        num == 2305843008139952128 // next one is larger than uInt so stop.
    )
        return true;

    return false;
}

namespace
{

uInt fingerPrint(uInt num)
{
    uInt digit, result = 0;
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
bool isPermutationOf(uInt a, uInt b)
{
    return fingerPrint(a) == fingerPrint(b);
}

// Return #partitions of a number.
uInt partition(uInt money)
{
    std::vector<uInt> coins;
    for (uInt num = 1; num <= money; ++num)
        coins.push_back(num);

    std::vector<uInt> ways(money + 1);
    ways[0] = 1;

    for (uInt ii = 0; ii < coins.size(); ++ii)
        for (uInt jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Check whether num is a square.
bool isSquare(uInt num)
{
    uInt h = num & 0xF; // Last hexadecimal "digit".

    if (h > 9)
        return false; // Return immediately in 6/16 cases.

    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        uInt root = std::floor(std::sqrt(num) + 0.5);
        return (root * root == num); // Take square root if you must.
    }

    return false;
}

// Returns #ways money can be divided by coins in listed in coinvector.
uInt partition(uInt money, std::vector<uInt> const &coins)
{
    std::vector<uInt> ways(money + 1);
    ways[0] = 1;

    for (uInt ii = 0; ii < coins.size(); ++ii)
        for (uInt jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Generate all numbers that are a to b pandigital.
std::vector<uInt> genPandigital(uInt a, uInt b)
{
    std::vector<uInt> digits;
    for (uInt digit = a; digit <= b; ++digit)
        digits.push_back(digit);

    Permutations perm(digits);

    std::vector<uInt> pandigitals;
    while (not perm.done())
    {
        uInt num = perm.yieldnumber();

        if (numDigits(num) == b - a + 1)
            pandigitals.push_back(num);
    }

    return pandigitals;
}

// Converts a decimal number to a specified radix.
std::string radix(uInt value, uInt radix)
{
    std::string accumulate; // Stores the converted number.

    do
    {
        uInt ch = value % radix; // Get the last digit.
        value /= radix;          // Cut off the last digit.

        ch += ch < 10 ? '0' : 'a' - 10; // Convert ch to char.

        accumulate.insert(0, 1, ch); // Insert digit before other digit.
    } while (value);

    return accumulate;
}

// Returns the least common multiple of a and b.
// The smallest positive integer that is divisble by both a and b.
uInt lcm(uInt a, uInt b)
{
    return a * (b / math::gcd(a, b));
}

} // namespace euler
