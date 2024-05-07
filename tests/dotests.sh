#!/bin/bash

rm -rf build
cmake -B build
make -j -C build
./build/tests
