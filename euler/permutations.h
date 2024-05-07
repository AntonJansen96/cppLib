#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <vector>

namespace euler {

// Object for generating the (lexicographic) permutations of a vector.
class Permutations
{
    std::vector<int> d_someSet;
    size_t d_count = 0;
    size_t const d_total;
    bool d_reverse;

    public:
        // Initialize Permutations object.
        Permutations(std::vector<int> const &input, bool reverse = false);

        // This object is not meant to be copied or moved.
        Permutations(Permutations const &other) = delete;
        Permutations(Permutations &&temp) = delete;

        // Yields the next permutation as a vector.
        std::vector<int> yield();
        
        // Yield the next permutation as an integer.
        // This is only possible when all elements are digits.
        size_t yieldnumber();

        // Returns true when all permutations were yielded.
        bool done() const;

        // Returns total number of permutations.
        size_t numPerms() const;

        // Resets everything.
        void reset();

    private:
        // Transforms a vector of digits into an integer.
        size_t vector2number(std::vector<int> const &input);
    
        // Factorial for calculating the amount of permutations.
        double factorial(double num) const;
};

} // Namespace.

// Returns true when all permutations were yielded.
inline bool euler::Permutations::done() const
{
    return d_count == d_total ? true : false;
}

// Returns total number of permutations.
inline size_t euler::Permutations::numPerms() const
{
    return d_total;
}

#endif
