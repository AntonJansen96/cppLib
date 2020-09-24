#include "../euler.h"

// Return #partitions of a number.
double euler::partition(size_t money)
{
    std::vector<size_t> coins;
    for (size_t num = 1; num <= money; ++num)
        coins.push_back(num);
    
    std::vector<double> ways(money + 1);
    ways[0] = 1;

    for (size_t ii = 0; ii < coins.size(); ++ii)
        for (size_t jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];
    
    return ways[money];    
}
