#include "math.h"

// Returns (a * b) % m
size_t euler::math::mulmod(size_t a, size_t b, size_t m)
{   
    a %= m;                     // (a * b) % m = a % m) * (b % m) % m.
    b %= m;

    if (a <= 0xFFFFFFF and b <= 0xFFFFFFF)  
        return (a * b) % m;     // Fast path.

#ifdef __x86_64__

    size_t asmResult;           // Use GCC inline assembler.
    __asm__
    (
        "mulq %2\n"             // Result in rdx:rax.
        "divq %3"               // Quotient in rax, remainder in rdx.
        : "=&d" (asmResult), "+%a" (a)
        : "rm" (b), "rm" (m)
        : "cc"                  // Clear conditions.
    );

    return asmResult;

#else

    if (b > a)                  // We might encounter overflows (slow path).
        std::swap(a ,b);        // The number of loops depends on b, 
                                // therefore try to minimize b.
    size_t result = 0;          // Bitwise multiplication.
    while (a > 0 and b > 0)
    {
        if (b & 1)              // b is odd ? a*b = a + a*(b-1).
        {
            result += a;
            if (result >= m)    // Skip b-- because the bit-shift at the
                result -= m;    // end will remove the lowest bit anyway.
        }   

        a <<= 1;
        if (a >= m)             // b is even ? a*b = (2*a)(b/2).
            a -= m;
        
        b >>= 1;                // Next bit.
    }
    
    return result;

#endif
}
