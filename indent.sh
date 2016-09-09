#!/bin/sh
#
# Indents all .c and .h files in the project that are not vendor code (ie: Unity).
#

for f in $(find exercises/ -not -path '*/vendor/*' -name '*.c' -or -not -path '*/vendor/*' -name '*.h'); do
  indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1 $f
  rm $f~ 2> /dev/null
done
