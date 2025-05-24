#include "variable_length_quantity.h"

#include <string.h>

#define I_BUF_SIZE 5

#define SQLite_VARINT 0

int encode(uint64_t *integers, int integers_len, uint8_t *output)
{
   int output_index = 0;
   uint8_t buf[I_BUF_SIZE];
   for (int i = 0; i < integers_len; i++) {
      uint64_t integer = integers[i];
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

int decode(uint8_t *buffer, int buffer_len, uint64_t *output)
{
   int output_index = 0;
   int buffer_index = 0;
   uint64_t cur = 0;
   int cur_count = 0;
   while (buffer_index < buffer_len) {
      uint8_t byte = buffer[buffer_index++];
      cur_count++;
#if SQLite_VARINT == 1
      /*
         The exercise and test data, as they stand, only handle 32-bit
         integers.
         This is a specific use case to decode SQLite Varints, which are
         64-bit and truncated to 9 bytes when encoded.
         When decoding, the 9th byte, if there is one, uses the full 8 bits for
         the value.
         Finding the 9th byte also marks the end of an integer.
      */
      if (cur_count == 9) {
         cur <<= 8;
         cur |= byte;
         output[output_index++] = cur;
         cur = 0;
         cur_count = 0;
         continue;
      }
#endif
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
