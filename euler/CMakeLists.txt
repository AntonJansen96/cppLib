set(EULER_SOURCES
    combinatorics/numbersplit.cpp
    combinatorics/permutations.cpp
    combinatorics/combinations.cpp
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
    digits.cpp
    functions.cpp
    roman.cpp
    triples.cpp
)

add_library(euler ${EULER_SOURCES})
target_include_directories(euler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(euler math utility)
