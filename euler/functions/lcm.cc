#include "../euler.h"

// Returns the least common multiple of a and b.
// The smallest positive integer that is divisble by both a and b.
int euler::lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}
