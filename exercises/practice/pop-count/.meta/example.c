#include "pop_count.h"

unsigned int egg_count(unsigned int value)
{
   unsigned int count = 0;
   while (value != 0) {
      count += value & 1;
      value = value >> 1;
   }
   return count;
}
