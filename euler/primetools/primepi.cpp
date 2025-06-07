#include "../../math/math.h"
#include "primetools.h"
#include <algorithm>

namespace
{

using uInt = euler::uInt;
static std::vector<uInt> primes; // Will contain all primes up to
                                 // sqrt(num).
} // Namespace.

namespace euler
{

// Returns number of primes up to (and including) num.
uInt euler::Primetools::primePi(uInt num) const
{
    if (num < 2)
        return 0; // Below 2 all primepi are zero.

    // If primes[] contains enough elements then run a fast binary search:
    if (not primes.empty() and primes.back() > num)
    { // Find smallest number larger than num:
        auto nextPrime = std::upper_bound(primes.begin(), primes.end(), num);
        return std::distance(primes.begin(), nextPrime);
    }

    uInt v = math::isqrt(num);
    // About sqrt(num) * 12 bytes, for num = 10^12 => 12 MByte plus primes[].
    std::vector<uInt> higher(v + 2, 0);
    std::vector<uInt> lower(v + 2, 0);
    std::vector<bool> used(v + 2, false);

    uInt result = num - 1; // Assume all numbers are primes.
    // The remaining lines subtract composites until result contains #primes.

    for (uInt p = 2; p <= v; ++p) // set up lower and upper bound.
    {
        lower[p] = p - 1;
        higher[p] = num / p - 1;
    }

    for (uInt p = 2; p <= v; ++p)
    {
        if (lower[p] == lower[p - 1]) // Composite?
            continue;

        if (primes.empty() or p > primes.back()) // Store prime numbers (if
            primes.push_back(p);                 // not already existing).

        auto temp = lower[p - 1]; // Remove more composites.
        result -= higher[p] - temp;

        auto pSquare = (uInt)p * p;
        auto end = std::min<uInt>(v, num / pSquare);

        auto j = 1 + (p & 1); // Alternate between 1 and 2.

        for (auto i = p + j; i <= end + 1; i += j)
        { // Adjust upper bound.
            if (used[i])
                continue;

            auto d = i * p;
            if (d <= v)
                higher[i] -= higher[d] - temp;
            else
                higher[i] -= lower[num / d] - temp;
        }

        for (auto i = v; i >= pSquare; i--) // Adjust lower bound.
            lower[i] -= lower[i / p] - temp;
        // Cross off multiples.
        for (auto i = pSquare; i <= end; i += p * j)
            used[i] = true;
    }

    return result;
}

} // namespace euler
