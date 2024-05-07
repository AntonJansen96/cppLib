#include "math.h"

#include <algorithm>    // For std::swap
#include <vector>       // For std::vector
#include <stdexcept>    // For std::logic_error

namespace math {

// Returns (a * b) % m
size_t mulmod(size_t a, size_t b, size_t m)
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

// Returns (a^b) % m
size_t powmod(size_t a, size_t b, size_t m)
{
    size_t result = 1;
    while (b > 0)
    {
        if (b & 1)              // Odd b ? a^b = a*a^(b-1).
            result = mulmod(result, a, m);
        
        a = mulmod(a, a, m);    // Even b ? a^b = (a*b)^(b/2).
        
        b >>= 1;
    }

    return result;
}

unsigned long modinverse(unsigned long a, unsigned long m)
{
    auto const orig = m;

    long s = 0;      // Note: s and t can be negative inside the loop.
    long t = 1;
    while (a > 1)
    {
        auto tmp = m;
        auto quotient = a / m;
        m = a % m;
        a = tmp;

        auto tmp2 = s;
        s = t - quotient * s;
        t = tmp2;
    }

    return t < 0 ? t + orig : t;    // Avoid negative result.
}

namespace {

static const std::vector<size_t> power2 = 
{
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
    65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,
    33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648,
    4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472,
    274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104,
    8796093022208, 17592186044416, 35184372088832, 70368744177664, 
    140737488355328, 281474976710656, 562949953421312, 1125899906842624,
    2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984,
    36028797018963968, 72057594037927936, 144115188075855872, 
    288230376151711744, 576460752303423488, 1152921504606846976,
    2305843009213693952, 4611686018427387904
};

static const std::vector<size_t> power3 = 
{
    1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441,
    1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467,
    3486784401, 10460353203, 31381059609, 94143178827, 282429536481, 
    847288609443, 2541865828329, 7625597484987, 22876792454961, 68630377364883,
    205891132094649, 617673396283947, 1853020188851841, 5559060566555523,
    16677181699666569, 50031545098999707, 150094635296999121, 
    450283905890997363, 1350851717672992089, 4052555153018976267
};

static const std::vector<size_t> power4 = 
{
    1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304,
    16777216, 67108864, 268435456, 1073741824, 4294967296, 17179869184,
    68719476736, 274877906944, 1099511627776, 4398046511104, 17592186044416,
    70368744177664, 281474976710656, 1125899906842624, 4503599627370496,
    18014398509481984, 72057594037927936, 288230376151711744, 
    1152921504606846976, 4611686018427387904
};

static const std::vector<size_t> power5 = 
{
    1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125,
    244140625, 1220703125, 6103515625, 30517578125, 152587890625, 762939453125,
    3814697265625, 19073486328125, 95367431640625, 476837158203125,
    2384185791015625, 11920928955078125, 59604644775390625, 298023223876953125,
    1490116119384765625, 7450580596923828125
};

static const std::vector<size_t> power6 = 
{
    1, 6, 36, 216, 1296, 7776, 46656, 279936, 1679616, 10077696, 60466176,
    362797056, 2176782336, 13060694016, 78364164096, 470184984576, 
    2821109907456, 16926659444736, 101559956668416, 609359740010496, 
    3656158440062976, 21936950640377856, 131621703842267136, 789730223053602816,
    4738381338321616896
};

static const std::vector<size_t> power7 = 
{
    1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249,
    1977326743, 13841287201, 96889010407, 678223072849, 4747561509943,
    33232930569601, 232630513987207, 1628413597910449, 11398895185373143,
    79792266297612001, 558545864083284007, 3909821048582988049 
};

static const std::vector<size_t> power8 = 
{
    1, 8, 64, 512, 4096, 32768, 262144, 2097152, 16777216, 134217728, 
    1073741824, 8589934592, 68719476736, 549755813888, 4398046511104,
    35184372088832, 281474976710656, 2251799813685248, 18014398509481984,
    144115188075855872, 1152921504606846976
};

static const std::vector<size_t> power9 = 
{
    1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489, 
    3486784401, 31381059609, 282429536481, 2541865828329, 22876792454961,
    205891132094649, 1853020188851841, 16677181699666569, 150094635296999121, 
    1350851717672992089
};

static const std::vector<size_t> power10 = 
{
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 
    10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000,
    1000000000000000, 10000000000000000, 100000000000000000, 
    1000000000000000000
};

} // Namespace.

// Exponentiate num [0, 10] with power.
size_t fastpow(size_t n, size_t m)
{
    switch (n)
    {
        case 0:
            return 0;
        
        case 1:
            return 1;

        case 2:
            return (m < 63) ? power2[m] : 0;

        case 3:
            return (m < 40) ? power3[m] : 0;
        
        case 4:
            return (m < 32) ? power4[m] : 0;

        case 5:
            return (m < 28) ? power5[m] : 0;

        case 6:
            return (m < 25) ? power6[m] : 0;

        case 7:
            return (m < 23) ? power7[m] : 0;
        
        case 8:
            return (m < 21) ? power8[m] : 0;

        case 9:
            return (m < 20) ? power9[m] : 0;

        case 10:
            return (m < 19) ? power10[m] : 0;

        default:
            throw(std::logic_error("fastpow : 0 < n > 10"));
    }
}

// Returns the integer part of log10.
int intlog10(size_t num)
{
    int n = 0;
    while (num >= 10'000'000'000'000'000){n += 16; num /= 10'000'000'000'000'000;}
    if (num >= 100'000'000){n += 8; num /= 100'000'000;}
    if (num >= 10'000){n += 4; num /= 10'000;}
    if (num >= 100){n += 2; num /= 100;}
    if (num >= 10){++n; num /= 10;}
    return n;       
}

// Returns factorial of number.
double factorial(int num)
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

// Returns binomial coefficient of N and n.
double binomCoeff(int N, int n)
{
    return factorial(N) / (factorial(n) * factorial(N - n));
}

} // Namespace math.
