#include "primetools.h"

// Construct Primetools object with specified d_max.
// Use this with concurrency as this->expand() is not thread-safe.
euler::Primetools::Primetools(size_t setMax)
{
    while (d_max < setMax)
        this->expand();
}
