#ifndef CPPLIB_RANDOM_H
#define CPPLIB_RANDOM_H

#include <algorithm> // for std::shuffle
#include <cstdint>   // for int_fast64_t
#include <random>    // for std::random_device, std::mt19937

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
using genT = std::mt19937;  // 32-bit Mersenne Twister.
#else
using sInt = int_fast64_t;    // Signed 64-bit integer.
using uInt = uint_fast64_t;   // Unsigned 64-bit integer.
using genT = std::mt19937_64; // 64-bit Mersenne Twister.
#endif

namespace probability
{

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

    // Returns a random double N such that a ≤ N ≤ b.
    double uniform(double a, double b);

    // Returns a random element from a non-empty sequence.
    template <typename Container>
    auto choice(const Container &container) -> typename Container::value_type;

    // Returns a list of k elements chosen with replacement.
    template <typename Container>
    std::vector<typename Container::value_type> choices(Container const &population,
                                                        uInt k);

    // Returns a list of k unique elements chosen without replacement.
    template <typename Container>
    std::vector<typename Container::value_type> sample(Container const &population,
                                                       uInt k);

    // Shuffles the sequence in the container in place.
    template <typename Type> void shuffle(Type &container);
};

// Returns a random element from a non-empty sequence.
template <typename Container>
inline auto Random::choice(const Container &container) -> typename Container::value_type
{
    size_t const idx = this->randint(0, container.size() - 1);
    return container[idx];
}

// Returns a list of k elements chosen with replacement.
template <typename Container>
inline std::vector<typename Container::value_type>
Random::choices(Container const &population, uInt k)
{
    std::vector<typename Container::value_type> result;
    result.reserve(k);
    for (size_t i = 0; i < k; ++i)
        result.push_back(this->choice(population));
    return result;
}

// Returns a list of k unique elements chosen without replacement.
template <typename Container>
std::vector<typename Container::value_type> inline Random::sample(
    const Container &population, uInt k)
{
    using T = typename Container::value_type;
    if (k > population.size())
        k = population.size();

    // Make a copy to shuffle.
    std::vector<T> pool(population.begin(), population.end());
    this->shuffle(pool);

    // Take the first k elements.
    return std::vector<T>(pool.begin(), pool.begin() + k);
}

// Shuffles the sequence in the container in place.
template <typename Type> inline void Random::shuffle(Type &container)
{
    std::shuffle(container.begin(), container.end(), d_gen);
}

} // namespace probability

#endif // CPPLIB_RANDOM_H
