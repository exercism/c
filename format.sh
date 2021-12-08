#!/usr/bin/env bash
#
# Formats all .c and .h files in the project that are not vendor code (ie: Unity).
#

find exercises/practice/ -path '*/test-framework' -prune -o \
  \( -iname '*.h' -o -iname '*.c' \) -print0 |\
  xargs --null clang-format -i
