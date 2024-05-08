#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <vector>

namespace euler {

// Object for generating the (lexicographic) combinations from a vector.
class Combinations
{
    std::vector<int> d_someSet;  // Cannot be const because we need to sort.
    std::vector<bool> d_mask;    // Permutate this to generate combinations.
    size_t const d_masksize;
    size_t const d_total;
    size_t const d_k;
    bool d_reverse;

    std::vector<int> d_comb;     // To hold the combination to be yielded.
    size_t d_count = 0;

    public:
        // Initialize combinations object.
        Combinations(std::vector<int> const &input, size_t k, bool reverse = false);

        // This object is not meant to be copied or moved.
        Combinations(Combinations const &other) = delete;
        Combinations(Combinations &&temp) = delete;

        // Yields the next combination as a vector.
        std::vector<int> yield();

        // Yield the next combination as an integer.
        // This is only possible when all elements are digits.
        size_t yieldnumber();

        // Returns true when all combinations were yielded.
        bool done() const;

        // Returns total number of combinations.
        size_t numCombs() const;

        // Resets everything.
        void reset();
    
    private:
        // Transforms a vector of digits into an integer.
        size_t vector2number(std::vector<int> const &input);
};

} // Namespace.

// Returns true when all combinations were yielded.
inline bool euler::Combinations::done() const
{
    return d_count == d_total ? true : false;
}

// Returns total number of combinations.
inline size_t euler::Combinations::numCombs() const
{
    return d_total;
}

#endif
