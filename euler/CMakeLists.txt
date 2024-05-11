set(EULER_SOURCES
    contfrac/fromfrac.cpp
    contfrac/tofrac.cpp
    contfrac/fromsqrt.cpp
    contfrac/tosqrt.cpp
    triples.cpp
    primetools/isamicable.cpp
    primetools/propdivsum.cpp
    primetools/isprime.cpp
    primetools/sieve.cpp
    primetools/constructor.cpp
    primetools/totient.cpp
    primetools/largestfactor.cpp
    primetools/miller_rabin.cpp
    primetools/divisorsum.cpp
    primetools/factorprimesingle.cpp
    primetools/primepi.cpp
    primetools/factorprime.cpp
    primetools/expand.cpp
    primetools/factorall.cpp
    sequences/fibonacci.cpp
    sequences/pisano.cpp
    combinatorics/numbersplit.cpp
    combinatorics/permutations.cpp
    combinatorics/combinations.cpp
    digits.cpp
    functions.cpp
    roman.cpp
)

add_library(euler ${EULER_SOURCES})
target_include_directories(euler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
