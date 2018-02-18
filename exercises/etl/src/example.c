#include "etl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static int compare(const void *a, const void *b)
{
   new_map *p = (new_map *) a;
   new_map *q = (new_map *) b;
   return (p->key - q->key);
}

int convert(const legacy_map * input, const size_t input_len, new_map ** output)
{
   if (input == NULL || input_len <= 0)
      return 0;

   int len = 0;
   for (size_t i = 0; i < input_len; i++) {
      len += strlen(input[i].keys);
   }

   *output = malloc(len * sizeof(new_map));
   if (*output == NULL) {
      fprintf(stderr, "Memory error!\n");
      return -1;
   }

   int pos = 0;
   for (size_t i = 0; i < input_len; i++) {
      char *tmp = (char *)input[i].keys;
      while (*tmp) {
         (*output)[pos].key = tolower(*tmp);
         (*output)[pos].value = input[i].value;
         tmp++;
         pos++;
      }
   }

   qsort(*output, len, sizeof(new_map), compare);

   return len;
}
