#ifndef CPPLIB_EULER_NUMBERSPLIT_H
#define CPPLIB_EULER_NUMBERSPLIT_H

#include <iosfwd>
#include <vector>

namespace euler {

// Object for generating all possible sets of splits from a number.
// E.g. 1234 --> 1234, 12 34, 1 234, 123 4, 1 23 4, 1 2 3 4.
class NumberSplit
{
    size_t const d_number;
    size_t const d_length;
    size_t const d_total;

    std::vector<size_t> d_set;
    size_t d_count = 0;
    size_t d_mem;

    public:
        // Constructor
        explicit NumberSplit(size_t number);

        // This object is not meant to be copied or moved.
        NumberSplit(NumberSplit const &other) = delete;
        NumberSplit(NumberSplit &&temp) = delete;        

        // Yield the next set.
        std::vector<size_t> yieldNext();

        // Check whether we have yielded all possible sets.
        bool done() const;

        // Return the number of possible combinations.
        size_t numCombs() const;

        // Reset object.
        void reset();
};

} // Namespace.

// Check whether we have yielded all possible sets.
inline bool euler::NumberSplit::done() const
{
    return (d_count == d_total ? true : false);
}

// Return the number of possible combinations.
inline size_t euler::NumberSplit::numCombs() const
{
    return d_total;
}

// Reset object.
inline void euler::NumberSplit::reset()
{
    d_count = 0;
}

#endif
