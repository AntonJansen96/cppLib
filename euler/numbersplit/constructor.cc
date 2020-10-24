#include "numbersplit.h"
#include "../euler.h" // circular reference

// Constructor
euler::NumberSplit::NumberSplit(size_t number)
:
    d_number(number),
    d_length(numDigits(number) - 1),    // hekje paaltje met komma's
    d_total(1 << d_length)              // 2**d_length
{}
