#include "primetools.h"
#include "../math/math.h"

// Check whether a number is prime using the Miller-Rabin test.
// Deterministic for all 64 bit numbers.
bool euler::Primetools::miller_rabin(size_t num) const
{   // Trivial cases:
    size_t const bitmaskPrimes2to31 = (1 <<  2) | (1 <<  3) | (1 <<  5) | (1 <<  7) |
                                      (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) |
                                      (1 << 23) | (1 << 29); // = 0x208A2Ac

    if (num < 31)
        return (bitmaskPrimes2to31 & (1 << num)) != 0;
    
    if  // Divisble by a small prime.
    (
        num %  2 == 0 || num %  3 == 0 || num %  5 == 0 || num % 7 == 0 ||
        num % 11 == 0 || num % 13 == 0 || num % 17 == 0
    )
        return false;
    
    if (num < 17 * 19) // We filtered all composite numbers < 17 * 19, all 
        return true;   // others below 17 * 19 must be prime.
    
    // Test num against those numbers ("whitnesses").
    // Good bases can be found at http://miller-rabin.appspot.com/.
    size_t const STOP = 0;
    size_t const TestAgainst1[] = { 377687, STOP };
    size_t const TestAgainst2[] = { 31, 73, STOP };
    size_t const TestAgainst3[] = { 2, 7, 61, STOP };
    // First three sequences are good up to 2^32.
    size_t const TestAgainst4[] = { 2, 13, 1662803, STOP };
    size_t const TestAgainst7[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022, STOP };

    // Good up to 2^64.
    size_t const *testAgainst = TestAgainst7;   
    if (num < 5329)                           // Use less tests if feasible...
        testAgainst = TestAgainst1;
    else if (num < 9080191)
        testAgainst = TestAgainst2;
    else if (num < 4759123141ULL)
        testAgainst = TestAgainst3;
    else if (num < 1122004669633ULL)
        testAgainst = TestAgainst4;
    
    size_t d = num - 1, shift = 0;            // Find num - 1 = d * 2^j.
    d >>= 1;
    while ((d & 1) == 0)
    {
        ++shift;
        d >>= 1;
    }

    do {                                    // Test num against all bases.
        auto x = math::powmod(*testAgainst++, d, num);
        
        if (x == 1 || x == num - 1)         // Is test^d % num == 1 || -1 ?
            continue;
        
        bool maybePrime = false;            // Now either prime or strong 
        for (size_t r = 0; r < shift; ++r)  // pseudo-prime. Check test^(d*2^r)
        {                                   // for 0 <= r < shift:
            x = math::mulmod(x, x, num);    // x^2 % num (initial x was test^d)
            
            if (x == 1)                     // If x % num == 1 => not prime.
                return false;
            
            if (x == num - 1)               // If x % num == -1 => not prime or 
            {                               // an even stronger pseudo-prime.
                maybePrime = true;
                break;                      // Next iteration.
            }
        }

        if (not maybePrime)                 // Not prime.
            return false;

    } while (*testAgainst != STOP);
    
    return true;                            // Prime.
}
