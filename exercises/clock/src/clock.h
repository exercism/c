#ifndef CLOCK_H
#define CLOCK_H

#include<stdbool.h>

#define MAX_STR_LEN (5 + 1)     // "##:##\0"

typedef char clock_text_t[MAX_STR_LEN];
typedef struct {
   int hour;
   int minute;
} clock_t;

void clock_create(clock_text_t clock_text, clock_t clock);
void clock_add(clock_text_t clock_text, int minute_offset);
void clock_subtract(clock_text_t clock_text, int minute_offset);
bool clock_is_equal(clock_t a, clock_t b);

#endif
