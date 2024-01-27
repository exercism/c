#include "pop_count.h"

int egg_count(int value)
{
   int count = 0;
   while (value != 0) {
      count += value & 1;
      value = value >> 1;
   }
   return count;
}
