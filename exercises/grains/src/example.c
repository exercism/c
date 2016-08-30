#include "grains.h"

#define NUMBER_OF_SQUARES   (64)

unsigned long square(int index) {
  return 1ul << (index - 1);
}

unsigned long total(void) {
  unsigned long result = 0;
  int i;

  for(i = 1; i <= NUMBER_OF_SQUARES; i++) {
    result += square(i);
  }

  return result;
}
