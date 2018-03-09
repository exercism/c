#include "flatten_array.h"
#include <stdlib.h>
#include <stdio.h>

enum modes { READ, WRITE };

static size_t flat_array_pos;
static int *flat_array = NULL;

static void parse_array(item_t * head, enum modes mode)
{
   if (head->type == ELEMENT) {
      if (mode == WRITE) {
         flat_array[flat_array_pos] = head->value;
      }
      flat_array_pos++;
   }

   if (head->array_elements != NULL)
      parse_array(head->array_elements, mode);

   if (head->next != NULL)
      parse_array(head->next, mode);
}

int *flatten(item_t * head)
{
   if (head == NULL)
      return NULL;

   flat_array_pos = 0;
   parse_array(head, READ);
   const size_t flat_array_len = flat_array_pos;

   if (flat_array_len == 0)
      return 0;

   flat_array = malloc(sizeof(*flat_array) * flat_array_len);
   if (flat_array == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   flat_array_pos = 0;
   parse_array(head, WRITE);

   return flat_array;
}
