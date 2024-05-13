#!/bin/bash

# Run for entire repository.
# find . -iname \*.cpp -o -iname \*.h | xargs clang-format -i

# Run for just the modified files.
git diff --name-only '*.cpp' '*.h' | xargs clang-format -i
