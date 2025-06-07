#include "euler/euler.h"
#include "pythonlike/pythonlike.h"
#include <cassert>

using namespace euler;
using namespace pythonlike;

int main()
{
    Primetools p;
    std::vector<size_t> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
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
