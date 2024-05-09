# cpplib

This is a collection of C++ libraries that I have written over the years.
The libraries are mostly related to number theory and project Euler, but 
there are also some general purpose libraries.

---

## euler

Library containing a number of classes and functions related to number
theory and project Euler. It includes functionality for things like 
partitioning numbers, prime checking, generation of combinations and
permutations of sets, generation of Pythagorean triples, etc. It also
contains a math sub-library that is used by a number of functions and
classes.

## fractions

Library for working with fractions.

## math

Library containing math-related functions.

## pythonlike

Header-only library which provides templates to make some functionality in
C++ more Python-like. This library currently includes template functions such
as sum(), max(), min(), sorted(), isorted(), reverse(), ireverse(), round(),
as well as a print() function that takes an arbitrary number of arbitrarily-typed
arguments and prints them to the console. The library also includes slice(),
view(), and range() functions.

## stopwatch

A class that can be used to time and profile C++ code. This class is
more or less a wrapper for some functionality of the std::chrono library.

- [x]  build system
- [ ]  euler
- [x]  fractions
- [x]  math
- [x]  stopwatch
- [x]  pythonlike
- [x]  utility
- [ ]  unit and integration tests
- [ ]  allow setting of fractions type (32bit or 64bit integer) in cmake.
