#include "square_root.h"

uint16_t squareRoot(uint16_t radicand)
{
   uint16_t result = 0;
   uint16_t bit = 1 << 14;

   while (bit > radicand)
      bit >>= 2;

   while (bit != 0) {
      if (radicand >= result + bit) {
         radicand -= result + bit;
         result = (result >> 1) + bit;
      } else {
         result >>= 1;
      }
      bit >>= 2;
   }
   return result;
}
