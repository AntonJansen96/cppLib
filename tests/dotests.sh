#!/bin/bash

set -e

if [ ! -f "build/CMakeCache.txt" ]; then
  cmake -B build -DSINGLE=OFF -DDEBUG=OFF || { echo "cmake failed"; rm -rf build; exit 1; }
fi

make -j -C build

./build/test_main
