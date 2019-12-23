#include "circular_buffer.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>

struct circular_buffer_t {
   size_t head;
   size_t tail;
   size_t count;
   size_t capacity;
   buffer_value_t values[];
};

static inline bool is_empty(circular_buffer_t * buffer)
{
   return (buffer->count == 0);
}

static inline bool is_full(circular_buffer_t * buffer)
{
   return (buffer->count >= buffer->capacity);
}

static inline size_t increment_index(size_t index, size_t capacity)
{
   return (index + 1) % capacity;
}

static int16_t optional_overwrite(circular_buffer_t * buffer,
                                  buffer_value_t value, bool writeover)
{
   if (!buffer) {
      errno = EINVAL;
      return EXIT_FAILURE;
   }

   if (is_full(buffer)) {
      if (!writeover) {
         errno = ENOBUFS;
         return EXIT_FAILURE;
      } else {
         buffer->tail = increment_index(buffer->tail, buffer->capacity);
      }
   } else {
      ++buffer->count;
   }

   buffer->values[buffer->head] = value;
   buffer->head = increment_index(buffer->head, buffer->capacity);
   return EXIT_SUCCESS;
}

circular_buffer_t *new_circular_buffer(size_t capacity)
{
   circular_buffer_t *buffer =
       malloc(sizeof(*buffer) + sizeof(buffer_value_t) * capacity);

   if (buffer) {
      clear_buffer(buffer);
      buffer->capacity = capacity;
   }

   return buffer;
}

int16_t read(circular_buffer_t * buffer, buffer_value_t * value)
{
   if (!buffer) {
      errno = EINVAL;
      return EXIT_FAILURE;
   }

   if (is_empty(buffer)) {
      errno = ENODATA;
      return EXIT_FAILURE;
   }

   *value = buffer->values[buffer->tail];
   buffer->tail = increment_index(buffer->tail, buffer->capacity);
   --buffer->count;
   return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t * buffer, buffer_value_t value)
{
   return optional_overwrite(buffer, value, false);
}

int16_t overwrite(circular_buffer_t * buffer, buffer_value_t value)
{
   return optional_overwrite(buffer, value, true);
}

void clear_buffer(circular_buffer_t * buffer)
{
   buffer->head = 0;
   buffer->tail = 0;
   buffer->count = 0;
}

void delete_buffer(circular_buffer_t * buffer)
{
   free(buffer);
}
