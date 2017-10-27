#include "collatz_conjecture.h"
#include <stdbool.h>

int steps(int start)
{
   int step = 0;
   int number = start;

   if (start <= 0) {
      return ERROR_VALUE;
   }

   while (number != 1) {
      step++;

      if (number % 2 == 0) {
         number /= 2;
      } else {
         number = (number * 3) + 1;
      }
   }
   return step;
}
