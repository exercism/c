#include "vendor/unity.h"
#include "../src/gigasecond.h"

static inline size_t is_leap_year(int year)
{
   if (year % 400 == 0)
      return 1;
   if (year % 100 == 0)
      return 0;
   if (year % 4 == 0)
      return 1;
   return 0;
}

static inline time_t days_from_1ad(int year)
{
   --year;                      // The gegorian calander is without a year 0. This is years from 1AD.
   // Little complex, add a day for all of the leap years
   // This is a quarter of the days since 0 execpt one in a hundred are lost except 1 in 400 are gained ... simple.
   return 365 * year + (year / 400) - (year / 100) + (year / 4);
}

time_t construct_date(int year, int month, int day, int hour, int min, int sec)
{
   static const time_t seconds_in_day = 86400;  // 60 * 60 * 24
   static const time_t days[2][12] = {
      {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
      {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
   };

   time_t days_since_epoch =
       (days_from_1ad(year) - days_from_1ad(1970)) +
       days[is_leap_year(year)][(month - 1)] + (day - 1);
   time_t result =
       (seconds_in_day * days_since_epoch) + (60 * ((hour * 60) + min) + sec);

   return result;
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_date(void)
{
   time_t expected = construct_date(2043, 1, 1, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(2011, 4, 25, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_another_date(void)
{
   TEST_IGNORE();               // delete this line to run test
   time_t expected = construct_date(2009, 2, 19, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(1977, 6, 13, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_third_date(void)
{
   TEST_IGNORE();
   time_t expected = construct_date(1991, 3, 27, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(1959, 7, 19, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_date_and_time(void)
{
   TEST_IGNORE();
   time_t expected = construct_date(2046, 10, 2, 23, 46, 40);
   time_t actual = gigasecond_after(construct_date(2015, 1, 24, 22, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_date_and_time_with_day_rollover(void)
{
   TEST_IGNORE();
   time_t expected = construct_date(2046, 10, 3, 1, 46, 39);
   time_t actual = gigasecond_after(construct_date(2015, 1, 24, 23, 59, 59));
   TEST_ASSERT(expected == actual);
}

/*
void test_your_birthday(void)
{
   time_t birthday = construct_date(1989, 1, 1, 1, 1, 1);
   time_t gigday = gigasecond_after(birthday);
   printf("%s", ctime(&gigday));
}
*/

int main(void)
{
   UnityBegin("test/test_gigasecond.c");

   RUN_TEST(test_date);
   RUN_TEST(test_another_date);
   RUN_TEST(test_third_date);
   RUN_TEST(test_date_and_time);
   RUN_TEST(test_date_and_time_with_day_rollover);
   //RUN_TEST(test_your_birthday);

   UnityEnd();
   return 0;
}
