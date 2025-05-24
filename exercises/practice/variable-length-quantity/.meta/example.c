#include "variable_length_quantity.h"

#include <string.h>

#define I_BUF_SIZE 5

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int output_index = 0;
   uint8_t buf[I_BUF_SIZE];
   for (size_t i = 0; i < integers_len; i++) {
      uint32_t integer = integers[i];
      uint8_t mask = 0;
      int buf_idx = I_BUF_SIZE;
      do {
         uint8_t part = (uint8_t)(integer & 0x7f);
         integer >>= 7;
         buf[--buf_idx] = part | mask;
         mask |= 0x80;
      } while (integer);
      int buf_len = I_BUF_SIZE - buf_idx;
      memcpy(output + output_index, buf + buf_idx, buf_len);
      output_index += buf_len;
   }
   return output_index;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   int output_index = 0;
   size_t buffer_index = 0;
   uint32_t cur = 0;
   int cur_count = 0;
   while (buffer_index < buffer_len) {
      uint8_t byte = buffer[buffer_index++];
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

