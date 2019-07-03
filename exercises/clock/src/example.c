#include <stdio.h>
#include "clock.h"

static void normalize_clock(clock_t * clock)
{
   while (clock->minute < 0) {
      clock->minute += 60;
      clock->hour -= 1;
   }
   clock->hour += clock->minute / 60;
   while (clock->hour < 0) {
      clock->hour += 24;
   }
   clock->hour %= 24;
   clock->minute %= 60;
}

void clock_create(clock_text_t clock_text, clock_t clock)
{
   normalize_clock(&clock);
   sprintf(clock_text, "%02d:%02d", clock.hour, clock.minute);
}

void clock_add(clock_text_t clock_text, int minute_offset)
{
   clock_t clock = { 0, 0 };
   sscanf(clock_text, "%02d:%02d", &clock.hour, &clock.minute);
   clock.minute += minute_offset;
   clock_create(clock_text, clock);
}

void clock_subtract(clock_text_t clock_text, int minute_offset)
{
   clock_t clock = { 0, 0 };
   sscanf(clock_text, "%02d:%02d", &clock.hour, &clock.minute);
   clock.minute -= minute_offset;
   clock_create(clock_text, clock);
}

bool clock_is_equal(clock_t a, clock_t b)
{
   normalize_clock(&a);
   normalize_clock(&b);
   return (a.hour == b.hour) && (a.minute == b.minute);
}
