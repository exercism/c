#include "variable_length_quantity.h"

int encode(uint64_t *integers, int integers_len, uint8_t *output)
{
   // write to `output`, return final output's length
   // `output` buffer should be enough to hold the full result
}

int decode(uint8_t *buffer, int buffer_len, uint64_t *output)
{
   // write to `output`, return final output's length
   // return -1 if error
   // `output` buffer should be enough to hold the full result
}
