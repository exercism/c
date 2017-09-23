#!/bin/sh
#
# Indents all .c and .h files in the project that are not vendor code (ie: Unity).
#

INDENT=""

if [ -x "$(command -v gindent)" ]; then
  INDENT=gindent
elif [ "$OSTYPE" = "darwin"* ]; then
  echo "ERROR:  Install gnu-indent using home brew to run this script."
  exit 126
elif [ -x "$(command -v indent)" ]; then
  INDENT=indent
else
  echo "ERROR:  Install indent to run this script."
  exit 126
fi

for f in $(find exercises/ -not -path '*/vendor/*' -name '*.c' -or -not -path '*/vendor/*' -name '*.h'); do
  $INDENT -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $f
  rm $f~ 2> /dev/null
done
