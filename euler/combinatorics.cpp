#include "../math/math.h"
#include "../utility/utility.h"
#include "euler.h"
#include <set>

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

// Number of unique permutations of an array.
// This is n! / (n1! * n2! * ... * nk!).
double numUniquePerms(std::vector<uInt> const &array)
{
    double n = math::factorial(array.size());

    for (auto const &element : std::set<uInt>(array.begin(), array.end()))
        n /= math::factorial(std::count(array.begin(), array.end(), element));

    return n;
}

// Generate all unique permutations of an array.
std::generator<std::vector<uInt>> genUniquePerms(std::vector<uInt> array)
{
    std::sort(array.begin(), array.end());
    do
    {
        co_yield array;
    } while (std::next_permutation(array.begin(), array.end()));
}

// Number of combinations for an array. This is binom(len(array), r).
uInt numCombs(std::vector<uInt> const &array, uInt r)
{
    return math::binom(array.size(), r);
}

// Generate combinations of an array.
std::generator<std::vector<uInt>> genCombs(std::vector<uInt> array, uInt r)
{
    std::sort(array.begin(), array.end());
    std::vector<bool> mask(array.size() - r, false);
    mask.resize(array.size(), true);
    do
    {
        std::vector<uInt> combination;

        for (uInt i = 0; i < array.size(); ++i)
            if (mask[i])
                combination.push_back(array[i]);

        co_yield combination;
    } while (std::next_permutation(mask.begin(), mask.end()));
}

// Generate all combinations of an array.
// Does not return the empty (identity) element.
std::generator<std::vector<uInt>> genAllCombs(std::vector<uInt> const array)
{
    for (uInt r = 0; r != array.size() + 1; ++r)
        for (auto const &comb : genCombs(array, r))
            co_yield comb;
}

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

// Split a number into all possible combinations of numbers.
std::generator<std::vector<uInt>> numbersplit(uInt number)
{
    std::vector<uInt> n = utility::num2vec(number);
    std::vector<uInt> result;
    std::vector<uInt> temp;

    for (int ii = 0; ii != 1 << (n.size() - 1); ++ii)
    {
        result.clear();
        temp = {n[0]};

        for (size_t jj = 0; jj != n.size() - 1; ++jj)
        {
            if ((ii >> jj) & 1)
            {
                result.push_back(utility::vec2num(temp));
                temp = {n[jj + 1]};
            }
            else
                temp.push_back(n[jj + 1]);
        }

        result.push_back(utility::vec2num(temp));
        co_yield result;
    }
}

} // namespace euler.
