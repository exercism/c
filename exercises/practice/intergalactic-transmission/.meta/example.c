#include "intergalactic_transmission.h"

int transmit_sequence(uint8_t *buffer, const uint8_t *message,
                      int message_length)
{
   uint8_t cur = 0;
   int parity = 0;
   int byte_count = 0;
   int bit_count = 0;
   // go over each input byte
   for (int i = 0; i < message_length; ++i) {
      // read bits of input byte, starting from most significant bit
      for (int j = 0; j < 8; ++j) {
         uint8_t const bit = (message[i] >> (7 - j)) & 1;
         // keep track of number of set bits
         parity += bit;
         // set bit in output byte and shift to make room for next bit
         cur = (cur | bit) << 1;
         // if 7 bits have been written, output byte is ready
         if (++bit_count == 7) {
            // set parity bit
            cur |= parity & 1;
            // and write to output buffer
            buffer[byte_count++] = cur;
            // reset state for next output byte
            parity = 0;
            bit_count = 0;
            cur = 0;
         }
      }
   }
   // make sure to write remaining state
   if (bit_count > 0) {
      // shift to the left to fill up with zero bits
      cur <<= 7 - bit_count;
      // set parity bit
      cur |= parity & 1;
      // and write to output buffer
      buffer[byte_count++] = cur;
   }
   return byte_count;
}

int decode_message(uint8_t *buffer, const uint8_t *message, int message_length)
{
   uint8_t cur_dec = 0;
   int num_bits_left = 8;
   int num_decoded = 0;
   // iterate over input message: each byte has 7 bits payload and parity bit
   for (int i = 0; i < message_length; ++i) {
      uint8_t const payload = message[i] >> 1;
      uint8_t const parity = message[i] & 1;
      // check parity bit and return early if mismatch found
      if ((__builtin_popcount(payload) & 1) != parity)
         return WRONG_PARITY;
      // write payload bits to current output byte, starting from MSB
      for (int j = 6; j >= 0; --j) {
         // read bit
         uint8_t const bit = (payload >> j) & 1;
         // write bit to currently decoded byte
         cur_dec |= bit << (num_bits_left - 1);
         // bits left?
         if (--num_bits_left == 0) {
            // no bits left, write decoded byte to buffer
            buffer[num_decoded++] = cur_dec;
            // reset state
            cur_dec = 0;
            num_bits_left = 8;
         }
      }
   }
   return num_decoded;
}
