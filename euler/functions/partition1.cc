#include "../euler.h"

// Returns #ways money can be divided by coins in listed in coinvector.
double euler::partition(size_t money, std::vector<size_t> const &coins)
{
    std::vector<double> ways(money + 1);
    ways[0] = 1;

    for (size_t ii = 0; ii < coins.size(); ++ii)
        for (size_t jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];
    
    return ways[money];
}

// Using int instead of size_t does not make this faster.
