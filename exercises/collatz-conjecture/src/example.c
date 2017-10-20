#include "collatz_conjecture.h"
#include <stdbool.h>

static bool is_even(int number)
{
   if (number % 2) {
      return false;
   }

   return true;
}

int steps(int start)
{
   int step = 0;
   int number = start;

   if (start <= 0) {
      return ERROR_VALUE;
   }

   while (number != 1) {
      step++;

      if (is_even(number)) {
         number /= 2;
      } else {
         number = (number * 3) + 1;
      }
   }
   return step;
}
