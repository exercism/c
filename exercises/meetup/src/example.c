#include <string.h>
#include "meetup.h"

#define BAD_DATE_REQUESTED (0)

typedef struct {
   const char *text;
   int number;
} textToIntLookup_t;

static int daysInMonth(int year, int month)
{
   int numberOfDays = 31;

   switch (month) {
   case 4:
   case 6:
   case 9:
   case 11:
      numberOfDays = 30;
      break;
   case 2:
      if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) {
         numberOfDays = 29;
      } else {
         numberOfDays = 28;
      }
      break;
   }
   return numberOfDays;
}

static int getNumberGivenText(const char *text, textToIntLookup_t * lookup,
                              size_t numberEntries)
{
   int matchNumber = -1;

   for (size_t index = 0; index < numberEntries; index++) {
      if (0 == strcmp(text, lookup[index].text)) {
         matchNumber = lookup[index].number;
         break;
      }
   }
   return matchNumber;
}

static int getDayOfWeek(unsigned int year, unsigned int month, unsigned int day)
{
   struct tm firstDayOfTestMonth;
   time_t midnightFirstDayofTestMonth;

   firstDayOfTestMonth.tm_year = year - 1900;
   firstDayOfTestMonth.tm_mon = month - 1;
   firstDayOfTestMonth.tm_mday = day;
   firstDayOfTestMonth.tm_hour = 0;
   firstDayOfTestMonth.tm_min = 0;
   firstDayOfTestMonth.tm_sec = 0;
   firstDayOfTestMonth.tm_isdst = 0;
   midnightFirstDayofTestMonth = mktime(&firstDayOfTestMonth);

   return (localtime(&midnightFirstDayofTestMonth)->tm_wday);
}

int meetupDayOfMonth(unsigned int year, unsigned int month, const char *week,
                     const char *dayOfWeek)
{
   int dayOfMonth = BAD_DATE_REQUESTED;

   textToIntLookup_t dayLookup[] = {
      {"Sunday", 0},
      {"Monday", 1},
      {"Tuesday", 2},
      {"Wednesday", 3},
      {"Thursday", 4},
      {"Friday", 5},
      {"Saturday", 6}
   };

   textToIntLookup_t whichWeekOfMonthLookup[] = {
      {"first", 1},
      {"second", 2},
      {"third", 3},
      {"fourth", 4},
      {"fifth", 5},
      {"last", 6},
      {"teenth", 7}
   };

   int baselineDayOfWeek;
   int daysInTestMonth = daysInMonth(year, month);
   int dayOffset;
   int referenceDay = 1;        // used to calculate a baseline day of week given a target date.

   int whichWeekOfMonth = getNumberGivenText(week, &whichWeekOfMonthLookup[0],
                                             sizeof(whichWeekOfMonthLookup) /
                                             sizeof(textToIntLookup_t));
   int targetDayInWeek = getNumberGivenText(dayOfWeek, &dayLookup[0],
                                            sizeof(dayLookup) /
                                            sizeof(textToIntLookup_t));

   // check for valid lookup...
   if ((whichWeekOfMonth >= 0) && (targetDayInWeek >= 0)) {
      // first - fifth Xday of month
      if (whichWeekOfMonth <= 5) {
         dayOffset = 1 + ((whichWeekOfMonth - 1) * 7);
      } else {
         // code for last Xday of month
         if (6 == whichWeekOfMonth) {
            referenceDay = daysInTestMonth - 6; // use the last unique day near end of month as reference
         } else {
            referenceDay = 13;  // use first teenth day as reference
         }
         dayOffset = referenceDay;
      }
      baselineDayOfWeek = getDayOfWeek(year, month, referenceDay);
      dayOfMonth = dayOffset + ((targetDayInWeek + 7 - baselineDayOfWeek) % 7);
   }

   if (dayOfMonth > daysInTestMonth) {
      dayOfMonth = BAD_DATE_REQUESTED;
   }
   return dayOfMonth;
}
