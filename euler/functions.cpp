#include "euler.h"

#include <cmath>
#include <tuple>
#include <algorithm>
#include <map>

// Returns the number of digits of a number.
int euler::numDigits(size_t num)
{
    return math::intlog10(num) + 1;
}

// Returns the sum of the digits of num.
int euler::sumDigits(size_t num)
{
    int count = 0;
    
    while (num)
    {
        count += num % 10;
        num /= 10;
    }
    return count;
}

// Returns the number of of occurances of digit in num.
int euler::countDigits(size_t num, size_t digit)
{
    size_t count = 0;
    
    while (num)
    {
        if (num % 10 == digit)
            ++count;

        num /= 10;
    }
    return count;    
}

// Returns the nth digit of a number (starting at least significant digit)
int euler::nthDigit(size_t num, int n)
{
    while (--n > 0)
        num /= 10;
        
    return num % 10;
}

// Returns the first N digits from a number.
size_t euler::firstNdigits(size_t num, int N)
{
    while(num >= math::fastpow(10, N))
        num /= 10;
    
    return num;
}

// Returns the first N digits from base^exp.
size_t firstNdigits(int base, int exp, int N)
{
    double num = exp * log10(base);
    num -= floor(num);
    num = std::pow(10, num);
    
    return static_cast<size_t>(std::floor(std::pow(10, N - 1) * num));
}

// Returns the last N digits from a number.
size_t euler::lastNdigits(size_t num, int N)
{
    return (num % math::fastpow(10, N));
}

// Check whether num is a square.
bool euler::isSquare(size_t num)
{
    size_t h = num & 0xF;           // Last hexadecimal "digit".
    
    if (h > 9)
        return false;               // Return immediately in 6/16 cases.

    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        size_t root = std::floor(std::sqrt(num) + 0.5);
        return (root * root == num);  // Take square root if you must.
    }
    
    return false;
}

// Checks whether two numbers a and b are coprime.
bool euler::isCoprime(int a, int b)
{
    if (((a | b) & 1) == 0) // Reject if both are even (gcd(a,b) >= 2).
        return false;
    
    return (gcd(a, b) == 1);
}

// Check whether num is a perfect number.
bool euler::isPerfect(size_t num)
{   
    if
    (
        num == 6 or
        num == 28 or 
        num == 496 or
        num == 8128 or
        num == 33550336 or
        num == 8589869056 or
        num == 137438691328 or
        num == 2305843008139952128 // next one is larger than size_t so stop.
    )
        return true;

    return false;
}

// Checks whether a number is juf.
bool euler::isJuf(size_t num)
{
    return
    (
        num % 7 == 0
        ||
        std::to_string(num).find('7') != std::string::npos
        ||
        (euler::isPalindrome(num) && num > 10)
    )
        ? true : false;
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

namespace {

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

// Generate all Fibonacci numbers smaller than uplim.
std::vector<size_t> euler::genFibonnaci(size_t uplim)
{
    std::vector<size_t> numbers = {1};
    size_t idx = 1, next = 1;
    
    while (next <= uplim)
    {
        numbers.push_back(next);
        next = numbers[idx - 1] + numbers[idx];
        ++idx;
    }

    return numbers;
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

// Generate primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
euler::genPrimTriples(size_t perimLim)
{
    std::vector<size_t> A, B, C;
    size_t a, b, c;

    for (size_t m = 1; m < sqrt(perimLim); ++m)
        for (size_t n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n*n - m*m;
                b = 2 * m * n;
                c = n*n + m*m;

                if (a + b + c <= perimLim)
                {
                    A.push_back(a);
                    B.push_back(b);
                    C.push_back(c);
                }
            }
    
    return std::tuple{A, B, C};
}

// Generate all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
euler::genTriples(size_t perimLim)
{
    std::vector<size_t> A, B, C;
    size_t a, b, c, k;

    for (size_t m = 1; m < sqrt(perimLim); ++m)
        for (size_t n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n*n - m*m;
                b = 2 * m * n;
                c = n*n + m*m;

                k = 1;
                while (k * (a + b + c) <= perimLim)
                {
                    A.push_back(k * a);
                    B.push_back(k * b);
                    C.push_back(k * c);

                    ++k;
                }
            }

    return std::tuple{A, B, C};
}

// Converts a number to a vector of digits.
std::vector<size_t> euler::num2vec(size_t num)
{
    std::vector<size_t> numbers;
    
    while (num)
    {
        numbers.push_back(num % 10);
        num /= 10;
    }

    std::reverse(numbers.begin(), numbers.end());

    return numbers;
}

// Converts a decimal number to a specified radix.
std::string euler::radix(size_t value, size_t radix)
{
    std::string accumulate;                 // Stores the converted number.

    do
    {
        size_t ch = value % radix;          // Get the last digit.
        value /= radix;                     // Cut off the last digit.

        ch += ch < 10 ? '0' : 'a' - 10;     // Convert ch to char.

        accumulate.insert(0, 1, ch);        // Insert digit before other digit.
    }
    while (value);

    return accumulate;
}

namespace {

static std::string const M[] = {"", "M", "MM", "MMM", "MMMM"};
static std::string const H[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static std::string const T[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static std::string const O[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

} // End of namespace.

// Converts a decimal number to a Roman numeral.
std::string euler::dec2roman(int dec)
{
    return M[dec / 1000] + H[dec % 1000 / 100] + T[dec % 100 / 10] + O[dec % 10];
}

namespace {

static std::map<char, int> dict =
{ 
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

} // Namespace.

// Converts a Roman numeral to a decimal number.
int euler::roman2dec(std::string const &roman)
{
    size_t decimal = 0; 
  
    for (size_t idx = 0; idx < roman.length(); ++idx)
    { 
        if (idx + 1 < roman.length()) 
        { 
            if (dict[roman[idx]] >= dict[roman[idx + 1]]) 
                decimal += dict[roman[idx]];
            else
            { 
                decimal += (dict[roman[idx + 1]] - dict[roman[idx]]);
                ++idx;
            } 
        } 
        else
            decimal += dict[roman[idx]]; 
    } 
    return decimal; 
} 

// Euclidean algorithm. Returns greatest common denominator of a and b.
int euler::gcd(int a, int b)
{
#ifdef __GNUC__   // This is around 60% faster using specific CPU instructions.
                  // Source https://euler.stephan-brumme.com/toolbox/
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    // MSVC++: _BitScanForward intrinsic instead
    auto shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        
        b -= a;
    } while (b != 0);

    return a << shift;

#else
    // standard GCD
    while (b) 
        b ^= a ^= b ^= a %= b;
    
    return a;

#endif
}

// Returns the least common multiple of a and b.
// The smallest positive integer that is divisble by both a and b.
int euler::lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}
