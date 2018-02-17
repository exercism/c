#ifndef ETL_H
#define ETL_H

typedef struct {
   int value;
   const char *keys;
} legacy_map;

typedef struct {
   char key;
   int value;
} new_map;

int convert(legacy_map * input, int input_len, new_map ** output);

#endif
