#!/bin/bash

find . -name 'cmake_install.cmake' | while read i; do rm $i; done
find . -name '*.a' | while read i; do rm $i; done
