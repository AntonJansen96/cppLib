#ifndef CPPLIB_EULER_NUMBERSPLIT_H
#define CPPLIB_EULER_NUMBERSPLIT_H

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

// Object for generating all possible sets of splits from a number.
// E.g. 1234 --> 1234, 12 34, 1 234, 123 4, 1 23 4, 1 2 3 4.
class NumberSplit
{
    uInt const d_number;
    uInt const d_length;
    uInt const d_total;

    std::vector<uInt> d_set;
    uInt d_count = 0;
    uInt d_mem;

  public:
    // Constructor
    explicit NumberSplit(uInt number);

    // This object is not meant to be copied or moved.
    NumberSplit(NumberSplit const &other) = delete;
    NumberSplit(NumberSplit &&temp) = delete;

    // Yield the next set.
    std::vector<uInt> yieldNext();

    // Check whether we have yielded all possible sets.
    bool done() const;

    // Return the number of possible combinations.
    uInt numCombs() const;

    // Reset object.
    void reset();
};

// Check whether we have yielded all possible sets.
inline bool NumberSplit::done() const
{
    return d_count == d_total;
}

// Return the number of possible combinations.
inline uInt NumberSplit::numCombs() const
{
    return d_total;
}

// Reset object.
inline void NumberSplit::reset()
{
    d_count = 0;
}

} // namespace euler

#endif
