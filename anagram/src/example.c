#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "anagram.h"

char *lowercase(char *p) {
  int len = strlen(p)+1;
  char *lower = (char *)malloc(len);
  memcpy(lower, p, len);
  p = lower;
  while (*p) {
    *p = tolower(*p);
    p++;
  }

  return lower;
}

int compare(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

struct Vector anagrams_for(char *in, struct Vector vin) {
  struct Vector vout = {
    malloc(MAX_STR_LEN * sizeof(char*)),
    0
  };
  char (*vout_vecp)[MAX_STR_LEN] = vout.vec;

  char *lower = lowercase(in);
  char *sorted = malloc(strlen(in));
  memcpy(sorted, lower, strlen(in));
  qsort(sorted, strlen(sorted), 1, compare);

  char (*vecp)[MAX_STR_LEN] = vin.vec;
  for (int x = 0; x < vin.size; x++) {
    char *input_lower = lowercase((char *)vecp);
    if (strcmp(input_lower, lower) != 0) {
      char *input_sorted = input_lower;
      qsort(input_sorted, strlen(input_sorted), 1, compare);
      if (strcmp(sorted, input_sorted) == 0) {
        strcpy(*vout_vecp, *vecp);
        vout_vecp++;
        vout.size++;
      }
    }
    free(input_lower);
    vecp++;
  }

  free(lower);
  free(sorted);
  return vout;
}
