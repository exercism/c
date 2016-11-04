#include <stdio.h>
#include "clock.h"

static void normalize_clock(int *hour, int *minute)
{
   while (*minute < 0) {
      *minute += 60;
      *hour -= 1;
   }
   *hour += *minute / 60;
   while (*hour < 0) {
      *hour += 24;
   }
   *hour %= 24;
   *minute %= 60;
}

void clock(char time_text[MAX_STR_LEN], int hour, int minute)
{
   normalize_clock(&hour, &minute);
   sprintf(time_text, "%02d:%02d", hour, minute);
}

void clock_add(char time_text[MAX_STR_LEN], int minute_offset)
{
   int hour;
   int minute;
   sscanf(time_text, "%02d:%02d", &hour, &minute);
   minute += minute_offset;
   clock(time_text, hour, minute);
}
