#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t colors[])
{
   resistor_value_t resistor = { 0, 0 };
   uint16_t digits = ((uint16_t) colors[0]) * 10 + colors[1];
   uint64_t total = ((uint64_t) pow(10, colors[2])) * digits;

   while (total / 1000 >= 1) {
      ++resistor.unit;
      total /= 1000;
   }

   resistor.value = total;
   return resistor;
}
