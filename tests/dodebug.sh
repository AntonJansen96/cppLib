#!/bin/bash

set -e

if [ ! -f "build/CMakeCache.txt" ]; then
  cmake -B build -DSINGLE=OFF -DDEBUG=ON
fi

make -j -C build

./build/debug
