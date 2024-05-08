#include "math.h"

#include <algorithm> // For std::min.
#include <vector>

namespace math
{

uInt binom(uInt n, uInt k)
{
    if (k > n)
        return 0;

    std::vector<std::vector<uInt>> C(n + 1, std::vector<uInt>(k + 1, 0));

    // Calculate value of Binomial Coefficient in bottom up manner.
    for (uInt i = 0; i <= n; i++)
    {
        for (uInt j = 0; j <= std::min(i, k); j++)
        {
            // Base Cases.
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously stored values.
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

} // Namespace math.
