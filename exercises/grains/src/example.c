#include "grains.h"

#define NUMBER_OF_SQUARES   (64)

uint64_t square(uint8_t index)
{
   if ((!index) || (index > NUMBER_OF_SQUARES)) {
      return 0;
   }

   return (uint64_t) 1 << (index - 1);
}

uint64_t total(void)
{
   uint64_t result = 0;

   for (uint8_t i = 1; i <= NUMBER_OF_SQUARES; i++) {
      result += square(i);
   }

   return result;
}
