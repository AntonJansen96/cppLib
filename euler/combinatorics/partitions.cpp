#include "../euler.h"

namespace
{

void genPartitionsHelper(euler::uInt n, std::vector<euler::uInt> &part, euler::uInt max,
                         std::vector<std::vector<euler::uInt>> &result)
{
    if (n == 0)
    {
        result.push_back(part);
        return;
    }

    for (euler::uInt i = std::min(max, n); i >= 1; i--)
    {
        part.push_back(i);
        genPartitionsHelper(n - i, part, i, result);
        part.pop_back();
    }
}

} // anonymous namespace

namespace euler
{

// Returns the number of partitions of a number.
uInt numpartitions(uInt money)
{
    std::vector<uInt> coins;
    for (uInt num = 1; num <= money; ++num)
        coins.push_back(num);

    std::vector<uInt> ways(money + 1);
    ways[0] = 1;

    for (uInt ii = 0; ii < coins.size(); ++ii)
        for (uInt jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Returns the number of partitions of a number using a coinvector.
uInt numpartitions(uInt money, std::vector<uInt> const &coins)
{
    std::vector<uInt> ways(money + 1);
    ways[0] = 1;

    for (uInt ii = 0; ii < coins.size(); ++ii)
        for (uInt jj = coins[ii]; jj <= money; ++jj)
            ways[jj] += ways[jj - coins[ii]];

    return ways[money];
}

// Generates all partitions of a number.
std::vector<std::vector<uInt>> genpartitions(uInt n)
{
    std::vector<std::vector<uInt>> result;
    std::vector<uInt> part;
    genPartitionsHelper(n, part, n, result);
    return result;
}

} // namespace euler
