#!/usr/bin/env bash
#
# Formats all .c and .h files in the project that are not vendor code (ie: Unity).
#

if ! [ -x "$(command -v clang-format)" ]; then
  echo "ERROR:  Install clang-format version 10.0.0 or greater to run this script."
  exit 126
fi

echo "INFO:  clang-format version 10.0.0 or greater is recommended to run this script"

find exercises/practice/ -path 'exercises/practice/*/test-framework' -prune -o \
  \( -iname '*.h' -o -iname '*.c' \) -print0 |\
  xargs --null clang-format -i
