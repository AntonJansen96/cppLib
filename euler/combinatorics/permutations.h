#ifndef CPPLIB_EULER_PERMUTATIONS_H
#define CPPLIB_EULER_PERMUTATIONS_H

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

// Object for generating the (lexicographic) permutations of a vector.
class Permutations
{
    std::vector<uInt> d_someSet;
    uInt d_count = 0;
    uInt const d_total;
    bool d_reverse;

  public:
    // Initialize Permutations object.
    Permutations(std::vector<uInt> const &input, bool reverse = false);

    // This object is not meant to be copied or moved.
    Permutations(Permutations const &other) = delete;
    Permutations(Permutations &&temp) = delete;

    // Yields the next permutation as a vector.
    std::vector<uInt> yield();

    // Yield the next permutation as an integer.
    // This is only possible when all elements are digits.
    uInt yieldnumber();

    // Returns true when all permutations were yielded.
    bool done() const;

    // Returns total number of permutations.
    uInt numPerms() const;

    // Resets everything.
    void reset();
};

// Returns true when all permutations were yielded.
inline bool Permutations::done() const
{
    return d_count == d_total;
}

// Returns total number of permutations.
inline uInt Permutations::numPerms() const
{
    return d_total;
}

} // namespace euler

#endif
