set (MATH_SOURCES
    factorial.cpp
    mulmod.cpp
    intlog10.cpp
    fastpow.cpp
    gcd.cpp
    powmod.cpp
    binom.cpp
    isqrt.cpp
    modinverse.cpp
)

add_library(math ${MATH_SOURCES})
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
