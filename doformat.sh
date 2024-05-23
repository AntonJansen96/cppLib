#!/bin/bash

# Run for entire repository.
# find . -iname \*.cpp -o -iname \*.h | xargs clang-format -i

# Run clang-format for modified, but not deleted files.
git diff --name-only --diff-filter=d '*.cpp' '*.h' | xargs clang-format -i

# Run clang-format for untracked (new) files.
git ls-files --others --exclude-standard '*.cpp' '*.h' | xargs clang-format -i
