#include "../math/math.h"
#include <cstddef>

namespace euler
{

// Returns the number of digits of a number.
int numDigits(size_t num)
{
    return math::intlog10(num) + 1;
}

// Returns the sum of the digits of num.
int sumDigits(size_t num)
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
int countDigits(size_t num, size_t digit)
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

// Returns the nth digit of a number (starting at least significant digit).
int nthDigit(size_t num, int n)
{
    while (--n > 0)
        num /= 10;

    return num % 10;
}

// Returns the first N digits from a number.
size_t firstNdigits(size_t num, int N)
{
    while (num >= math::fastpow(10, N))
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
size_t lastNdigits(size_t num, int N)
{
    return (num % math::fastpow(10, N));
}

// Reverse a number. Example: 1234 -> 4321.
size_t reverseNumber(size_t num)
{
    size_t reversed = 0;

    while (num)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

} // namespace euler.
