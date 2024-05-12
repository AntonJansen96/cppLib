#ifndef CPPLIB_EULER_COMBINATIONS_H
#define CPPLIB_EULER_COMBINATIONS_H

#include <cstdint>
#include <vector>

namespace euler
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Object for generating the (lexicographic) combinations from a vector.
class Combinations
{
    std::vector<uInt> d_someSet; // Cannot be const because we need to sort.
    std::vector<bool> d_mask;    // Permutate this to generate combinations.
    uInt const d_masksize;
    uInt const d_total;
    uInt const d_k;
    bool d_reverse;

    std::vector<uInt> d_comb; // To hold the combination to be yielded.
    uInt d_count = 0;

  public:
    // Initialize combinations object.
    Combinations(std::vector<uInt> const &input, uInt k, bool reverse = false);

    // This object is not meant to be copied or moved.
    Combinations(Combinations const &other) = delete;
    Combinations(Combinations &&temp) = delete;

    // Yields the next combination as a vector.
    std::vector<uInt> yield();

    // Yield the next combination as an integer.
    // This is only possible when all elements are digits.
    uInt yieldnumber();

    // Returns true when all combinations were yielded.
    bool done() const;

    // Returns total number of combinations.
    uInt numCombs() const;

    // Resets everything.
    void reset();
};

// Returns true when all combinations were yielded.
inline bool Combinations::done() const
{
    return d_count == d_total;
}

// Returns total number of combinations.
inline uInt Combinations::numCombs() const
{
    return d_total;
}

} // namespace euler

#endif
