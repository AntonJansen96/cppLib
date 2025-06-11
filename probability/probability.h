#ifndef CPPLIB_RANDOM_H
#define CPPLIB_RANDOM_H

#include <cstdint>
#include <random>

namespace probability
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
using genT = std::mt19937;  // 32-bit Mersenne Twister.
#else
using sInt = int_fast64_t;    // Signed 64-bit integer.
using uInt = uint_fast64_t;   // Unsigned 64-bit integer.
using genT = std::mt19937_64; // 64-bit Mersenne Twister.
#endif

// Test function
void hellofromprobability();

class Random
{
    std::random_device d_rd;
    genT d_gen;

  public:
    // Construct Random object and use a random seed.
    Random();

    // Construct Random object using specific seed.
    explicit Random(uInt seed);

    // Returns a random number in the range [0.0, 1.0).
    double random();

    // Returns a random integer N such that a ≤ N ≤ b.
    uInt randint(uInt a, uInt b);

    // Returns a random float N such that a ≤ N ≤ b.
    double uniform(double a, double b);

    // Returns a random element from a non-empty sequence.
    template <typename Type>
    auto choice(Type const &container) -> decltype(container[0]);

    // To be implemented.
    // 5. choices(population, weights=None, k=1) — Returns a list of k elements chosen
    // with replacement.
    // 6. sample(population, k) — Returns a list of k unique elements chosen without
    // replacement.
    // 7. shuffle(x) — Shuffles the sequence x in place.
};

// Construct Random object and use a random seed.
inline Random::Random()
    : d_rd()
    , d_gen(d_rd())
{
}

// Construct Random object using specific seed.
inline Random::Random(uInt seed)
    : d_rd()
    , d_gen(seed)
{
}

// Returns a random number in the range [0.0, 1.0).
inline double Random::random()
{
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(d_gen);
}

// Returns a random integer N such that a ≤ N ≤ b.
inline uInt Random::randint(uInt a, uInt b)
{
    std::uniform_int_distribution<uInt> dist(a, b);
    return dist(d_gen);
}

// Returns a random float N such that a ≤ N ≤ b.
inline double Random::uniform(double a, double b)
{
    std::uniform_int_distribution<uInt> dist(a, b);
    return dist(d_gen);
}

// Returns a random element from a non-empty sequence.
template <typename Type>
auto Random::choice(Type const &container) -> decltype(container[0])
{
    size_t const idx = this->randint(0, container.size() - 1);
    return container[idx];
}

} // namespace probability

#endif // CPPLIB_RANDOM_H
