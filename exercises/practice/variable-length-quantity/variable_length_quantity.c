#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   // write to `output`, return final output's length
   // `output` buffer should be enough to hold the full result
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   // write to `output`, return final output's length
   // return -1 if error
   // `output` buffer should be enough to hold the full result
}
