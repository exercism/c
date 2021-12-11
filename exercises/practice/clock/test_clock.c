#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "test-framework/unity.h"
#include "clock.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// test helper functions that test expected results
static void test_create(clock_t expected, int hour, int minute)
{
   clock_t actual = clock_create(hour, minute);
   TEST_ASSERT_EQUAL_STRING(expected.text, actual.text);
}

static void test_add(clock_t expected, int hour, int minute, int minute_add)
{
   clock_t actual = clock_create(hour, minute);
   actual = clock_add(actual, minute_add);
   TEST_ASSERT_EQUAL_STRING(expected.text, actual.text);
}

static void test_subtract(clock_t expected, int hour, int minute,
                          int minute_subtract)
{
   clock_t actual = clock_create(hour, minute);
   actual = clock_subtract(actual, minute_subtract);
   TEST_ASSERT_EQUAL_STRING(expected.text, actual.text);
}

static void test_compare(bool expected, int a_hour, int a_minute, int b_hour,
                         int b_minute)
{
   clock_t a = clock_create(a_hour, a_minute);
   clock_t b = clock_create(b_hour, b_minute);
   bool actual = clock_is_equal(a, b);

   if (expected) {
      TEST_ASSERT_TRUE(actual);
   } else {
      TEST_ASSERT_FALSE(actual);
   }
}

// the tests
static void test_on_the_hour(void)
{
   int hour = 8, minute = 0;
   clock_t expected = { "08:00" };

   test_create(expected, hour, minute);
}

static void test_past_the_hour(void)
{
   TEST_IGNORE();   // delete this line to run test
   int hour = 11, minute = 9;
   clock_t expected = { "11:09" };

   test_create(expected, hour, minute);
}

static void test_midnight_is_zero_hours(void)
{
   TEST_IGNORE();
   int hour = 24, minute = 0;
   clock_t expected = { "00:00" };

   test_create(expected, hour, minute);
}

static void test_hour_rolls_over(void)
{
   TEST_IGNORE();
   int hour = 25, minute = 0;
   clock_t expected = { "01:00" };

   test_create(expected, hour, minute);
}

static void test_hour_rolls_over_continuously(void)
{
   TEST_IGNORE();
   int hour = 100, minute = 0;
   clock_t expected = { "04:00" };

   test_create(expected, hour, minute);
}

static void test_sixty_minutes_is_next_hour(void)
{
   TEST_IGNORE();
   int hour = 1, minute = 60;
   clock_t expected = { "02:00" };

   test_create(expected, hour, minute);
}

static void test_minutes_roll_over(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 160;
   clock_t expected = { "02:40" };

   test_create(expected, hour, minute);
}

static void test_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 1723;
   clock_t expected = { "04:43" };

   test_create(expected, hour, minute);
}

static void test_hour_and_minutes_roll_over(void)
{
   TEST_IGNORE();
   int hour = 25, minute = 160;
   clock_t expected = { "03:40" };

   test_create(expected, hour, minute);
}

static void test_hour_and_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   int hour = 201, minute = 3001;
   clock_t expected = { "11:01" };

   test_create(expected, hour, minute);
}

static void test_hour_and_minutes_roll_over_to_exactly_midnight(void)
{
   TEST_IGNORE();
   int hour = 72, minute = 8640;
   clock_t expected = { "00:00" };

   test_create(expected, hour, minute);
}

static void test_negative_hour(void)
{
   TEST_IGNORE();
   int hour = -1, minute = 15;
   clock_t expected = { "23:15" };

   test_create(expected, hour, minute);
}

static void test_negative_hour_rolls_over(void)
{
   TEST_IGNORE();
   int hour = -25, minute = 0;
   clock_t expected = { "23:00" };

   test_create(expected, hour, minute);
}

static void test_negative_hour_rolls_over_continuously(void)
{
   TEST_IGNORE();
   int hour = -91, minute = 0;
   clock_t expected = { "05:00" };

   test_create(expected, hour, minute);
}

static void test_negative_minutes(void)
{
   TEST_IGNORE();
   int hour = 1, minute = -40;
   clock_t expected = { "00:20" };

   test_create(expected, hour, minute);
}

static void test_negative_minutes_roll_over(void)
{
   TEST_IGNORE();
   int hour = 1, minute = -160;
   clock_t expected = { "22:20" };

   test_create(expected, hour, minute);
}

static void test_negative_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   int hour = 1, minute = -4820;
   clock_t expected = { "16:40" };

   test_create(expected, hour, minute);
}

static void test_negative_sixty_minutes_is_previous_hour(void)
{
   TEST_IGNORE();
   int hour = 2, minute = -60;
   clock_t expected = { "01:00" };

   test_create(expected, hour, minute);
}

static void test_negative_hour_and_minutes_both_roll_over(void)
{
   TEST_IGNORE();
   int hour = -25, minute = -160;
   clock_t expected = { "20:20" };

   test_create(expected, hour, minute);
}

static void test_negative_hour_and_minutes_both_roll_over_continuously(void)
{
   TEST_IGNORE();
   int hour = -121, minute = -5810;
   clock_t expected = { "22:10" };

   test_create(expected, hour, minute);
}

static void test_add_minutes(void)
{
   TEST_IGNORE();
   int hour = 10, minute = 0, minute_add = 3;
   clock_t expected = { "10:03" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_no_minutes(void)
{
   TEST_IGNORE();
   int hour = 6, minute = 41, minute_add = 0;
   clock_t expected = { "06:41" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_to_next_hour(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 45, minute_add = 40;
   clock_t expected = { "01:25" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_more_than_one_hour(void)
{
   TEST_IGNORE();
   int hour = 10, minute = 0, minute_add = 61;
   clock_t expected = { "11:01" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_more_than_two_hours_with_carry(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 45, minute_add = 160;
   clock_t expected = { "03:25" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_across_midnight(void)
{
   TEST_IGNORE();
   int hour = 23, minute = 59, minute_add = 2;
   clock_t expected = { "00:01" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_more_than_one_day(void)
{
   TEST_IGNORE();
   int hour = 5, minute = 32, minute_add = 1500;
   clock_t expected = { "06:32" };

   test_add(expected, hour, minute, minute_add);
}

static void test_add_more_than_two_days(void)
{
   TEST_IGNORE();
   int hour = 1, minute = 1, minute_add = 3500;
   clock_t expected = { "11:21" };

   test_add(expected, hour, minute, minute_add);
}

static void test_subtract_minutes(void)
{
   TEST_IGNORE();
   int hour = 10, minute = 3, minute_subtract = 3;
   clock_t expected = { "10:00" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_to_previous_hour(void)
{
   TEST_IGNORE();
   int hour = 10, minute = 3, minute_subtract = 30;
   clock_t expected = { "09:33" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_more_than_an_hour(void)
{
   TEST_IGNORE();
   int hour = 10, minute = 3, minute_subtract = 70;
   clock_t expected = { "08:53" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_across_midnight(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 3, minute_subtract = 4;
   clock_t expected = { "23:59" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_more_than_two_hours(void)
{
   TEST_IGNORE();
   int hour = 0, minute = 0, minute_subtract = 160;
   clock_t expected = { "21:20" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_more_than_two_hours_with_borrow(void)
{
   TEST_IGNORE();
   int hour = 6, minute = 15, minute_subtract = 160;
   clock_t expected = { "03:35" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_more_than_one_day(void)
{
   TEST_IGNORE();
   int hour = 5, minute = 32, minute_subtract = 1500;
   clock_t expected = { "04:32" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_subtract_more_than_two_days(void)
{
   TEST_IGNORE();
   int hour = 2, minute = 20, minute_subtract = 3000;
   clock_t expected = { "00:20" };

   test_subtract(expected, hour, minute, minute_subtract);
}

static void test_compare_clocks_with_same_time(void)
{
   TEST_IGNORE();
   int a_hour = 15, a_minute = 37;
   int b_hour = 15, b_minute = 37;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_a_minute_apart(void)
{
   TEST_IGNORE();
   int a_hour = 15, a_minute = 36;
   int b_hour = 15, b_minute = 37;
   bool expected = false;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_an_hour_apart(void)
{
   TEST_IGNORE();
   int a_hour = 14, a_minute = 37;
   int b_hour = 15, b_minute = 37;
   bool expected = false;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_hour_overflow(void)
{
   TEST_IGNORE();
   int a_hour = 10, a_minute = 37;
   int b_hour = 34, b_minute = 37;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_hour_overflow_by_several_days(void)
{
   TEST_IGNORE();
   int a_hour = 3, a_minute = 11;
   int b_hour = 99, b_minute = 11;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_hour(void)
{
   TEST_IGNORE();
   int a_hour = 22, a_minute = 40;
   int b_hour = -2, b_minute = 40;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_hour_that_wraps(void)
{
   TEST_IGNORE();
   int a_hour = 17, a_minute = 3;
   int b_hour = -31, b_minute = 3;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void
test_compare_clocks_with_negative_hour_that_wraps_multiple_times(void)
{
   TEST_IGNORE();
   int a_hour = 13, a_minute = 49;
   int b_hour = -83, b_minute = 49;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_minute_overflow(void)
{
   TEST_IGNORE();
   int a_hour = 0, a_minute = 1;
   int b_hour = 0, b_minute = 1441;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_minute_overflow_by_several_days(void)
{
   TEST_IGNORE();
   int a_hour = 2, a_minute = 2;
   int b_hour = 2, b_minute = 4322;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_minute(void)
{
   TEST_IGNORE();
   int a_hour = 2, a_minute = 40;
   int b_hour = 3, b_minute = -20;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_minute_that_wraps(void)
{
   TEST_IGNORE();
   int a_hour = 4, a_minute = 10;
   int b_hour = 5, b_minute = -1490;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void
test_compare_clocks_with_negative_minute_that_wraps_multiple_times(void)
{
   TEST_IGNORE();
   int a_hour = 6, a_minute = 15;
   int b_hour = 6, b_minute = -4305;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_hours_and_minute(void)
{
   TEST_IGNORE();
   int a_hour = 7, a_minute = 32;
   int b_hour = -12, b_minute = -268;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_clocks_with_negative_hours_and_minute_that_wrap(void)
{
   TEST_IGNORE();
   int a_hour = 18, a_minute = 7;
   int b_hour = -54, b_minute = -11513;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

static void test_compare_full_clock_and_zeroed_clock(void)
{
   TEST_IGNORE();
   int a_hour = 24, a_minute = 0;
   int b_hour = 0, b_minute = 0;
   bool expected = true;

   test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

int main(void)
{
   UnityBegin("test_clock.c");

   RUN_TEST(test_on_the_hour);
   RUN_TEST(test_past_the_hour);
   RUN_TEST(test_midnight_is_zero_hours);
   RUN_TEST(test_hour_rolls_over);
   RUN_TEST(test_hour_rolls_over_continuously);
   RUN_TEST(test_sixty_minutes_is_next_hour);
   RUN_TEST(test_minutes_roll_over);
   RUN_TEST(test_minutes_roll_over_continuously);
   RUN_TEST(test_hour_and_minutes_roll_over);
   RUN_TEST(test_hour_and_minutes_roll_over_continuously);
   RUN_TEST(test_hour_and_minutes_roll_over_to_exactly_midnight);
   RUN_TEST(test_negative_hour);
   RUN_TEST(test_negative_hour_rolls_over);
   RUN_TEST(test_negative_hour_rolls_over_continuously);
   RUN_TEST(test_negative_minutes);
   RUN_TEST(test_negative_minutes_roll_over);
   RUN_TEST(test_negative_minutes_roll_over_continuously);
   RUN_TEST(test_negative_sixty_minutes_is_previous_hour);
   RUN_TEST(test_negative_hour_and_minutes_both_roll_over);
   RUN_TEST(test_negative_hour_and_minutes_both_roll_over_continuously);
   RUN_TEST(test_add_minutes);
   RUN_TEST(test_add_no_minutes);
   RUN_TEST(test_add_to_next_hour);
   RUN_TEST(test_add_more_than_one_hour);
   RUN_TEST(test_add_more_than_two_hours_with_carry);
   RUN_TEST(test_add_across_midnight);
   RUN_TEST(test_add_more_than_one_day);
   RUN_TEST(test_add_more_than_two_days);
   RUN_TEST(test_subtract_minutes);
   RUN_TEST(test_subtract_to_previous_hour);
   RUN_TEST(test_subtract_more_than_an_hour);
   RUN_TEST(test_subtract_across_midnight);
   RUN_TEST(test_subtract_more_than_two_hours);
   RUN_TEST(test_subtract_more_than_two_hours_with_borrow);
   RUN_TEST(test_subtract_more_than_one_day);
   RUN_TEST(test_subtract_more_than_two_days);
   RUN_TEST(test_compare_clocks_with_same_time);
   RUN_TEST(test_compare_clocks_a_minute_apart);
   RUN_TEST(test_compare_clocks_an_hour_apart);
   RUN_TEST(test_compare_clocks_with_hour_overflow);
   RUN_TEST(test_compare_clocks_with_hour_overflow_by_several_days);
   RUN_TEST(test_compare_clocks_with_negative_hour);
   RUN_TEST(test_compare_clocks_with_negative_hour_that_wraps);
   RUN_TEST(test_compare_clocks_with_negative_hour_that_wraps_multiple_times);
   RUN_TEST(test_compare_clocks_with_minute_overflow);
   RUN_TEST(test_compare_clocks_with_minute_overflow_by_several_days);
   RUN_TEST(test_compare_clocks_with_negative_minute);
   RUN_TEST(test_compare_clocks_with_negative_minute_that_wraps);
   RUN_TEST(test_compare_clocks_with_negative_minute_that_wraps_multiple_times);
   RUN_TEST(test_compare_clocks_with_negative_hours_and_minute);
   RUN_TEST(test_compare_clocks_with_negative_hours_and_minute_that_wrap);
   RUN_TEST(test_compare_full_clock_and_zeroed_clock);

   return UnityEnd();
}
