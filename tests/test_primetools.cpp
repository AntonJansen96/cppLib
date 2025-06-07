#include "euler/euler.h"
#include <algorithm>
#include <cassert>

using namespace euler;

int main()
{
    Primetools p;
    std::vector<uInt> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                                43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    // Check sieve.
    assert(p.sieve(100) == primes);

    // Check isPrime, miller_rabin
    for (size_t num = 0; num != 100; ++num)
    {
        bool inprimes = std::find(primes.begin(), primes.end(), num) != primes.end();
        assert(p.isPrime(num) == inprimes);
        assert(p.miller_rabin(num) == inprimes);
    }

    // Check primePi
    assert(p.primePi(0) == 0);
    assert(p.primePi(2) == 1);
    assert(p.primePi(100) == 25);
    assert(p.primePi(123456789) == 7027260);

    // Check factorPrime
    std::vector<uInt> const f1 = {2, 2, 3, 5};
    std::vector<uInt> const f2 = {2, 2, 2, 2, 2, 2, 3, 643};
    assert(p.factorPrime(0) == std::vector<uInt>{});
    assert(p.factorPrime(2) == std::vector<uInt>{2});
    assert(p.factorPrime(60) == f1);
    assert(p.factorPrime(123456) == f2);

    // Check factorPrimeSingle
    std::vector<uInt> const f3 = {2, 3, 5};
    std::vector<uInt> const f4 = {2, 3, 643};
    assert(p.factorPrimeSingle(0) == std::vector<uInt>{});
    assert(p.factorPrimeSingle(2) == std::vector<uInt>{2});
    assert(p.factorPrimeSingle(60) == f3);
    assert(p.factorPrimeSingle(123456) == f4);

    // Check factorAll
    std::vector<uInt> const f5 = {1, 2};
    std::vector<uInt> const f6 = {1, 5, 3, 15, 2, 10, 6, 30, 4, 20, 12, 60};
    std::vector<uInt> const f7 = {
        1,  643,   3,  1929,  2,  1286,  6,  3858,  4,  2572,  12, 7716,  8,   5144,
        24, 15432, 16, 10288, 48, 30864, 32, 20576, 96, 61728, 64, 41152, 192, 123456};
    assert(p.factorAll(0) == std::vector<uInt>{});
    assert(p.factorAll(1) == std::vector<uInt>{1});
    assert(p.factorAll(2) == f5);
    assert(p.factorAll(60) == f6);
    assert(p.factorAll(123456) == f7);

    // Check divisorSum
    assert(p.divisorSum(0, 1) == 0);
    assert(p.divisorSum(1, 1) == 1);
    assert(p.divisorSum(2, 1) == 3);
    assert(p.divisorSum(60, 1) == 168);
    assert(p.divisorSum(60, 0) == f6.size());
    assert(p.divisorSum(123456, 1) == 327152);

    // Check divisorSumProper
    // This is one is for free / guaranteed correct if divisorSum is correct.

    // Check largestFactor
    assert(p.largestFactor(0) == 0);
    assert(p.largestFactor(1) == 0);
    assert(p.largestFactor(2) == 1);
    assert(p.largestFactor(60) == 60 / 2);
    assert(p.largestFactor(97) == 97 / 97);
    assert(p.largestFactor(123456) == 123456 / 2);

    // Check totient
    assert(p.totient(0) == 0);
    assert(p.totient(1) == 1);
    assert(p.totient(100) == 40);
    assert(p.totient(123456789) == 82260072);

    // Check isAmicable
    std::vector<size_t> ami = {220, 284, 1184, 1210}; // A063990.
    for (size_t num = 0; num != 1211; ++num)
    {
        bool inami = std::find(ami.begin(), ami.end(), num) != ami.end();
        assert(p.isAmicable(num) == inami);
    }
}
