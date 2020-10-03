#include "easy/easy.h"
#include "euler/euler.h"
#include <iostream>
#include <omp.h>
#include <atomic>
#include <set>

// What a typical recursive divide algorithm looks like:

bool test1(size_t NumberToBeSplit, size_t SomeVictoryCondition)
{
    if (NumberToBeSplit < SomeVictoryCondition) // Try to find one or more very 
        return false; // general conditions that return false for speedup.
    
    // Apply split for upper most round, usually some sort of if/while loop e.g.
    int numdig = euler::numDigits(NumberToBeSplit);
    
    for (int i = 1; i != numdig; ++i)
    {   // Actual algorithm/splitting:
        size_t a = euler::firstNdigits(NumberToBeSplit, i);
        size_t b = euler::lastNdigits(NumberToBeSplit, numdig - i);

        if (a + b == SomeVictoryCondition)  // Return true if conditon is met.
            return true;

        if (test1(b, SomeVictoryCondition - a) and (SomeVictoryCondition > a)) 
            return true; // Recurse and maybe add additional conditions.
    }

    return false; // Return false if after all recursion nothing was found.
}

// Another example:
bool test2(size_t NumberToBeSplit, size_t SomeVictoryCondition)
{
    if (NumberToBeSplit < SomeVictoryCondition) // Try to find one or more very 
        return false; // general conditions that return false for speedup.

    if (NumberToBeSplit == SomeVictoryCondition)
        return true; // Return true if conditon is met.
    
    size_t factor = 10;
    while (factor < NumberToBeSplit)
    {   // Actual algorithm/splitting
        size_t a = NumberToBeSplit % factor;
        size_t b = NumberToBeSplit / factor;
        
        if (test2(b, SomeVictoryCondition - a) and (a <= SomeVictoryCondition))
            return true; // Recurse and maybe add additional conditions.

        factor *= 10;
    }

    return false; // Return false if after all recursion nothing was found.
}

// bool check(size_t num, size_t k)
// {
//     size_t prod = num;
//     size_t sum  = num;

//     while (prod != 0)
//     {
//         auto facs = p.facs(100)
//         num /= 
//     }
    
//     return false;
// }

int main()
{
    euler::Primetools p;

    std::set<size_t> minims = {1, 1, 2, 3};

    // for (size_t k = 2; k <= 6; ++k)
    // {

    // }

    auto facs = p.factors(120);
    std::cout << facs[facs.size() - 1] << '\n';

    std::cout << easy::sum(minims) << '\n';
}
