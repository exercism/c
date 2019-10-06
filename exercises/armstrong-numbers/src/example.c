#include "armstrong_numbers.h"
#include <math.h>

static uint16_t get_digit_count(uint32_t candidate)
{
   uint16_t digit_count = 0;
   while (candidate > 0) {
      candidate /= 10;
      ++digit_count;
   }
   return digit_count;
}

bool is_armstrong_number(uint32_t candidate)
{
   bool result = false;
   if (candidate < 10) {
      result = true;
   } else if (candidate >= 100) {
      uint16_t digit_count = get_digit_count(candidate);
      uint32_t sum = 0, n = candidate;
      while (n > 0 && sum <= candidate) {
         uint16_t r = n % 10;
         sum += pow(r, digit_count);
         n /= 10;
      }
      result = candidate == sum;
   }
   return result;
}
