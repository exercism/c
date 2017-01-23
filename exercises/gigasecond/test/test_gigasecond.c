#include "vendor/unity.h"
#include "../src/gigasecond.h"

// Constructs a time_t type from the given date settings
time_t construct_date(int year, int month, int day, int hour, int min, int sec)
{
   struct tm date;
   date.tm_year = year - 1900;
   date.tm_mon = month - 1;
   date.tm_mday = day;
   date.tm_hour = hour;
   date.tm_min = min;
   date.tm_sec = sec;
   date.tm_isdst = 0;
   return mktime(&date);
}

void test_date(void)
{
   time_t expected = construct_date(2043, 1, 1, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(2011, 4, 25, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_another_date(void)
{
   time_t expected = construct_date(2009, 2, 19, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(1977, 6, 13, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_third_date(void)
{
   time_t expected = construct_date(1991, 3, 27, 1, 46, 40);
   time_t actual = gigasecond_after(construct_date(1959, 7, 19, 0, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_date_and_time(void)
{
   time_t expected = construct_date(2046, 10, 2, 23, 46, 40);
   time_t actual = gigasecond_after(construct_date(2015, 1, 24, 22, 0, 0));
   TEST_ASSERT(expected == actual);
}

void test_date_and_time_with_day_rollover(void)
{
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
