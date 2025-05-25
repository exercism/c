#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int output_index = 0;

   for (size_t i = 0; i < integers_len; i++) {
      uint32_t integer = integers[i];
      uint8_t mask = 0;
      uint8_t buf[5];   // lifo
      int buf_idx = 0;
      // push
      do {
         uint8_t part = (uint8_t)(integer & 0x7f);
         integer >>= 7;
         buf[buf_idx++] = part | mask;
         mask |= 0x80;
      } while (integer);
      // pop
      while (buf_idx--) {
         output[output_index++] = buf[buf_idx];
      }
   }
   return output_index;
}

int decode(const uint8_t *bytes, size_t bytes_len, uint32_t *output)
{
   int output_index = 0;
   size_t bytes_index = 0;
   uint32_t cur = 0;
   int cur_count = 0;

   while (bytes_index < bytes_len) {
      uint8_t byte = bytes[bytes_index++];

      cur_count++;
      cur <<= 7;
      cur |= byte & 0x7f;

      if (!(byte & 0x80)) {
         output[output_index++] = cur;
         cur = 0;
         cur_count = 0;
         continue;
      }
   }

   if (cur_count || cur)
      return -1;
   return output_index;
}
