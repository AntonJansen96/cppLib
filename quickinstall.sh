#!/bin/bash

C=/opt/homebrew/bin/gcc-13
CXX=/opt/homebrew/bin/g++-13
FLAGS="-Wall -std=c++23 -O3 -march=native -funroll-loops -ffast-math -flto"

rm -rf build
cmake -B build -DCMAKE_C_COMPILER=$C -DCMAKE_CXX_COMPILER=$CXX -DCMAKE_CXX_FLAGS="$FLAGS"
make -j -C build
make -C build install
