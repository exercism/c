#ifndef VLQ_H
#define VLQ_H

#include <stdint.h>

// return output_len
int encode(uint64_t *integers, int integers_len, uint8_t *output);

// return output_len, -1 on error
int decode(uint8_t *buffer, int buffer_len, uint64_t *output);

#endif
