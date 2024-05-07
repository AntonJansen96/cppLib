#!/bin/bash

find . -name 'CMakeFiles' | xargs rm -rf
find . -name 'cmake_install.cmake' | xargs rm -f
find . -name '*.a' | xargs rm -f
