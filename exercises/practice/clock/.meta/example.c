#include <stdio.h>
#include "clock.h"

static const char CLOCK_FORMAT[] = "%02d:%02d";

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

static void to_int(clock_t clock, int *hour, int *minute)
{
   sscanf(clock.text, CLOCK_FORMAT, hour, minute);
}

clock_t clock_create(int hour, int minute)
{
   clock_t clock = { { 0 } };
   normalize_clock(&hour, &minute);
   snprintf(clock.text, MAX_STR_LEN, CLOCK_FORMAT, hour, minute);
   return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
   int hour = 0, minute = 0;
   to_int(clock, &hour, &minute);
   minute += minute_add;
   return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
   int hour = 0, minute = 0;
   to_int(clock, &hour, &minute);
   minute -= minute_subtract;
   return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b)
{
   int ah = 0, am = 0, bh = 0, bm = 0;
   to_int(a, &ah, &am);
   to_int(b, &bh, &bm);
   normalize_clock(&ah, &am);
   normalize_clock(&bh, &bm);
   return (ah == bh) && (am == bm);
}
