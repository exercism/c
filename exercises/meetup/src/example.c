#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "meetup.h"

#define BAD_DATE_REQUESTED (0)

typedef struct {
   const char *text;
   int number;
} text_to_int_lookup_t;

static bool is_leap_year(int year)
{
   return ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0));
}

static int days_in_month(int year, int month)
{
   int number_of_days = 31;

   switch (month) {
   case 4:
   case 6:
   case 9:
   case 11:
      number_of_days = 30;
      break;
   case 2:
      if (is_leap_year(year)) {
         number_of_days = 29;
      } else {
         number_of_days = 28;
      }
      break;
   }
   return number_of_days;
}

static int get_number_given_text(const char *text,
                                 text_to_int_lookup_t * lookup,
                                 size_t number_entries)
{
   int match_number = -1;

   for (size_t index = 0; index < number_entries; index++) {
      if (0 == strcmp(text, lookup[index].text)) {
         match_number = lookup[index].number;
         break;
      }
   }
   return match_number;
}

static int get_day_of_week_from_date(unsigned int year, unsigned int month,
                                     unsigned int day)
{
   struct tm first_day_of_test_month;
   time_t midnight_first_day_of_test_month;

   first_day_of_test_month.tm_year = year - 1900;
   first_day_of_test_month.tm_mon = month - 1;
   first_day_of_test_month.tm_mday = day;
   first_day_of_test_month.tm_hour = 0;
   first_day_of_test_month.tm_min = 0;
   first_day_of_test_month.tm_sec = 0;
   first_day_of_test_month.tm_isdst = 0;
   midnight_first_day_of_test_month = mktime(&first_day_of_test_month);

   return (localtime(&midnight_first_day_of_test_month)->tm_wday);
}

static int get_week_of_month(const char *week)
{
   text_to_int_lookup_t which_week_of_month_lookup[] = {
      {"first", 1},
      {"second", 2},
      {"third", 3},
      {"fourth", 4},
      {"fifth", 5},
      {"last", 6},
      {"teenth", 7}
   };

   return get_number_given_text(week, &which_week_of_month_lookup[0],
                                sizeof(which_week_of_month_lookup) /
                                sizeof(text_to_int_lookup_t));
}

static int get_requested_day_of_week(const char *day_of_week)
{
   text_to_int_lookup_t day_lookup[] = {
      {"Sunday", 0},
      {"Monday", 1},
      {"Tuesday", 2},
      {"Wednesday", 3},
      {"Thursday", 4},
      {"Friday", 5},
      {"Saturday", 6}
   };

   return get_number_given_text(day_of_week, &day_lookup[0],
                                sizeof(day_lookup) /
                                sizeof(text_to_int_lookup_t));
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
   int day_of_month = BAD_DATE_REQUESTED;
   int days_in_test_month = days_in_month(year, month);

   int which_week_of_month = get_week_of_month(week);
   int target_day_in_week = get_requested_day_of_week(day_of_week);

   // check for valid lookup...
   if ((which_week_of_month >= 0) && (target_day_in_week >= 0)) {
      int day_offset;
      int reference_day = 1;    // used to calculate a baseline day of week given a target date.
      // first - fifth Xday of month
      if (which_week_of_month <= 5) {
         day_offset = 1 + ((which_week_of_month - 1) * 7);
      } else {
         // code for last Xday of month
         if (6 == which_week_of_month) {
            reference_day = days_in_test_month - 6;     // use the last unique day near end of month as reference
         } else {
            reference_day = 13; // use first teenth day as reference
         }
         day_offset = reference_day;
      }
      int baseline_day_of_week =
          get_day_of_week_from_date(year, month, reference_day);
      day_of_month =
          day_offset + ((target_day_in_week + 7 - baseline_day_of_week) % 7);
   }

   if (day_of_month > days_in_test_month) {
      day_of_month = BAD_DATE_REQUESTED;
   }
   return day_of_month;
}
