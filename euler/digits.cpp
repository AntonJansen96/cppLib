#include "../math/math.h"
#include "euler.h"

namespace euler
{

// Returns the number of digits of a number.
uInt numDigits(uInt num)
{
    return math::intlog10(num) + 1;
}

// Returns the sum of the digits of num.
uInt sumDigits(uInt num)
{
    uInt count = 0;

    while (num)
    {
        count += num % 10;
        num /= 10;
    }
    return count;
}

// Returns the number of of occurances of digit in num.
uInt countDigits(uInt num, uInt digit)
{
    if (num == 0 && digit == 0) // edge case.
        return 1;

    uInt count = 0;

    while (num)
    {
        if (num % 10 == digit)
            ++count;

        num /= 10;
    }
    return count;
}

// Returns the nth digit of a number (starting at least significant digit).
uInt nthDigit(uInt num, uInt n)
{
    if (n == 0) // edge case.
        return 0;

    while (--n > 0)
        num /= 10;

    return num % 10;
}

// Returns the first N digits from a number.
uInt firstNdigits(uInt num, uInt N)
{
    while (num >= math::fastpow(10, N))
        num /= 10;

    return num;
}

// Returns the first N digits from base^exp.
uInt firstNdigits(uInt base, uInt exp, uInt N)
{
    double num = exp * log10(base);
    num -= floor(num);
    num = std::pow(10, num);

    return static_cast<uInt>(std::floor(std::pow(10, N - 1) * num));
}

// Returns the last N digits from a number.
uInt lastNdigits(uInt num, uInt N)
{
    return (num % math::fastpow(10, N));
}

// Reverse a number. Example: 1234 -> 4321.
uInt reverseNumber(uInt num)
{
    uInt reversed = 0;

    while (num)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

} // namespace euler.
