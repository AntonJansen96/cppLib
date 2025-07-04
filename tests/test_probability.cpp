#include "probability/probability.h"
#include <cassert>

int main()
{
    probability::Random rand; // different seed
    auto x1 = rand.random();
    auto x2 = rand.random();
    assert(x1 != x2);
    assert(0.0 <= x1 && x1 < 1.0);
    assert(0.0 <= x2 && x2 < 1.0);

    probability::Random rand1(123); // same seed
    probability::Random rand2(123);
    auto x3 = rand1.random();
    auto x4 = rand2.random();
    assert(x3 == x4);

    probability::Random r;
    std::vector<int> array = {1, 4, 9, 16, 25};
    r.randint(1, 3);      // seems good.
    r.uniform(0.3, 0.6);  // seems good.
    r.choice(array);      // seems good.
    r.choices(array, 20); // seems good.
    r.sample(array, 3);   // seems good.
    r.shuffle(array);     // seems good.
}
