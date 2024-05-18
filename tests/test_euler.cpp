#include "euler/euler.h"
#include "pythonlike/pythonlike.h" // debug only
#include <cassert>

using namespace euler;      // remove at end?
using namespace pythonlike; // debug only

int main()
{
    // DIGITS
    assert(numDigits(0 == 1));
    assert(numDigits(9 == 1));
    assert(numDigits(10 == 2));
    assert(numDigits(123456789 == 9));

    assert(sumDigits(0) == 0);
    assert(sumDigits(9) == 9);
    assert(sumDigits(12345) == 15);

    assert(countDigits(0, 0) == 1);
    assert(countDigits(0, 1) == 0);
    assert(countDigits(55555, 5) == 5);

    assert(nthDigit(12345, 0) == 0); // edge case
    assert(nthDigit(12345, 7) == 0); // edge case
    assert(nthDigit(12345, 1) == 5);
    assert(nthDigit(12345, 5) == 1);

    assert(firstNdigits(12345, 0) == 0);
    assert(firstNdigits(12345, 7) == 12345);
    assert(firstNdigits(12345, 3) == 123);
    assert(firstNdigits(15, 25, 4) == 2525);

    assert(lastNdigits(12345, 3) == 345);

    assert(reverseNumber(0) == 0);
    assert(reverseNumber(12345) == 54321);

    // ROMAN NUMERALS
    for (size_t num = 0; num != 5000; ++num)
        assert(num == roman2dec(dec2roman(num)));

    // PYTHAGOREAN TRIPLES
    std::vector<std::tuple<int, int, int>> x = {{3, 4, 5}, {6, 8, 10}, {5, 12, 13}};
    print(x); // print fails because it can't print tuples
    // std::tuple<int, int, int> y = {3, 4, 5};
    // print(y);
    // for (auto const &triple : genTriples(100))
        // print(triple);
}
