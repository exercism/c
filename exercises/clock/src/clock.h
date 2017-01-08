#ifndef CLOCK_H
#define CLOCK_H

#define MAX_STR_LEN (5 + 1)     // "##:##\0"

typedef char time_text_t[MAX_STR_LEN];

void clock(time_text_t time_text, int hour, int minute);
void clock_add(time_text_t time_text, int minute_offset);

#endif
