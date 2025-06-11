#include "probability.h"

namespace probability
{

// Construct Random object and use a random seed.
Random::Random()
    : d_rd()
    , d_gen(d_rd())
{
}

// Construct Random object using specific seed.
Random::Random(uInt seed)
    : d_rd()
    , d_gen(seed)
{
}

// Returns a random number in the range [0.0, 1.0).
double Random::random()
{
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(d_gen);
}

// Returns a random integer N such that a ≤ N ≤ b.
uInt Random::randint(uInt a, uInt b)
{
    std::uniform_int_distribution<uInt> dist(a, b);
    return dist(d_gen);
}

// Returns a random double N such that a ≤ N ≤ b.
double Random::uniform(double a, double b)
{
    std::uniform_real_distribution<double> dist(a, b);
    return dist(d_gen);
}

} // namespace probability
