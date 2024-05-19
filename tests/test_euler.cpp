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
    std::vector<std::array<uInt, 3>> triple1 = genPrimTriples(50);
    std::vector<std::array<uInt, 3>> triple2 = {{3, 4, 5}, {15, 8, 17}, {5, 12, 13}};
    assert(triple1 == triple2);

    // SEQUENCES
    assert(sequences::pisanoperiod(10) == 60); // https://oeis.org/A001175
    std::vector<uInt> const seq_pisano = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    assert(sequences::fibonacci(35) == seq_pisano);

    // EULER FUNCTIONS
    for (uInt num : {0, 1, 5, 6, 25, 76, 376, 625, 9376})
        assert(isAutomorphic(num) == true);
    assert(isAutomorphic(123) == false);

    assert(isCoprime(0, 0) == false);
    assert(isCoprime(1, 1) == true);
    assert(isCoprime(2, 2) == false);
    assert(isCoprime(9, 2) == true);

    assert(isPalindrome(0) == true);
    assert(isPalindrome(13531) == true);
    assert(isPalindrome(12345) == false);

    assert(isJuf(8) == false);
    assert(isJuf(11) == true);
    assert(isJuf(21) == true);
    assert(isJuf(27) == true);

    assert(isPermutationOf(123, 132) == true);
    assert(isPermutationOf(1234, 1325) == false);

    for (uInt num : {0, 1, 4, 9, 16, 25, 36, 49, 64}) // https://oeis.org/A000290
        assert(isSquare(num) == true);
    for (uInt num : {2, 3, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 17, 101})
        assert(isSquare(num) == false);

    std::vector<uInt> const pandigitals = {123, 132, 213, 231, 312, 321};
    assert(genPandigital(1, 3) == pandigitals);

    assert(lcm(0, 0) == 0);
    assert(lcm(0, 1) == 0);
    assert(lcm(1, 1) == 1);
    assert(lcm(123, 15) == 615);

    // PARTITIONING
    assert(numpartitions(50) == 204226);
    assert(numpartitions(200, {1, 2, 5, 10, 20, 50, 100, 200}) == 73682);
    std::vector<std::vector<uInt>> par = {{4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}};
    assert(genpartitions(4) == par);
}
