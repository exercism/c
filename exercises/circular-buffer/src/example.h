#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

typedef int16_t buffer_value_t;
typedef struct circular_buffer_t circular_buffer_t;

// constructs a new buffer
circular_buffer_t *new_circular_buffer(size_t capacity);

// read next value from buffer
int16_t read(circular_buffer_t * buffer, buffer_value_t * value);

// write a value to the buffer
int16_t write(circular_buffer_t * buffer, buffer_value_t value);

// write a value to the buffer
// overwrites the oldest value if the buffer is already full
int16_t overwrite(circular_buffer_t * buffer, buffer_value_t value);

// clear the buffer
void clear_buffer(circular_buffer_t * buffer);

// destroy the entire buffer
// buffer will be a dangling pointer after calling this method on it
void delete_buffer(circular_buffer_t * buffer);

#endif
