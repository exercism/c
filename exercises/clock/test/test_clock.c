#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "vendor/unity.h"
#include "../src/clock.h"

clock_text_t actual_clock_text;

void setUp(void)
{
}

void tearDown(void)
{
}

// test helper functions that test expected results
static void test_expected_value(const char *expected_clock_text, clock_t clock)
{
   memset(actual_clock_text, '\0', sizeof(actual_clock_text));
   clock_create(actual_clock_text, clock);
   TEST_ASSERT_EQUAL_STRING(expected_clock_text, actual_clock_text);
}

static void test_clock_add_expected_value(const char *expected_clock_text,
                                          clock_t clock, int minute_offset)
{
   memset(actual_clock_text, '\0', sizeof(actual_clock_text));
   clock_create(actual_clock_text, clock);
   clock_add(actual_clock_text, minute_offset);
   TEST_ASSERT_EQUAL_STRING(expected_clock_text, actual_clock_text);
}

static void test_clock_subtract_expected_value(const char *expected_clock_text,
                                               clock_t clock, int minute_offset)
{
   memset(actual_clock_text, '\0', sizeof(actual_clock_text));
   clock_create(actual_clock_text, clock);
   clock_subtract(actual_clock_text, minute_offset);
   TEST_ASSERT_EQUAL_STRING(expected_clock_text, actual_clock_text);
}

// the tests
static void test_on_the_hour(void)
{
   clock_t clock = { 8, 0 };
   char *expected_clock_text = "08:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_past_the_hour(void)
{
   TEST_IGNORE();               // delete this line to run test
   clock_t clock = { 11, 9 };
   char *expected_clock_text = "11:09";

   test_expected_value(expected_clock_text, clock);
}

static void test_midnight_is_zero_hours(void)
{
   TEST_IGNORE();
   clock_t clock = { 24, 0 };
   char *expected_clock_text = "00:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_hour_rolls_over(void)
{
   TEST_IGNORE();
   clock_t clock = { 25, 0 };
   char *expected_clock_text = "01:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_hour_rolls_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { 100, 0 };
   char *expected_clock_text = "04:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_sixty_minutes_is_next_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 1, 60 };
   char *expected_clock_text = "02:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_minutes_roll_over(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 160 };
   char *expected_clock_text = "02:40";

   test_expected_value(expected_clock_text, clock);
}

static void test_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 1723 };
   char *expected_clock_text = "04:43";

   test_expected_value(expected_clock_text, clock);
}

static void test_hour_and_minutes_roll_over(void)
{
   TEST_IGNORE();
   clock_t clock = { 25, 160 };
   char *expected_clock_text = "03:40";

   test_expected_value(expected_clock_text, clock);
}

static void test_hour_and_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { 201, 3001 };
   char *expected_clock_text = "11:01";

   test_expected_value(expected_clock_text, clock);
}

static void test_hour_and_minutes_roll_over_to_exactly_midnight(void)
{
   TEST_IGNORE();
   clock_t clock = { 72, 8640 };
   char *expected_clock_text = "00:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { -1, 15 };
   char *expected_clock_text = "23:15";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_hour_rolls_over(void)
{
   TEST_IGNORE();
   clock_t clock = { -25, 0 };
   char *expected_clock_text = "23:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_hour_rolls_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { -91, 0 };
   char *expected_clock_text = "05:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_minutes(void)
{
   TEST_IGNORE();
   clock_t clock = { 1, -40 };
   char *expected_clock_text = "00:20";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_minutes_roll_over(void)
{
   TEST_IGNORE();
   clock_t clock = { 1, -160 };
   char *expected_clock_text = "22:20";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_minutes_roll_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { 1, -4820 };
   char *expected_clock_text = "16:40";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_sixty_minutes_is_previous_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 2, -60 };
   char *expected_clock_text = "01:00";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_hour_and_minutes_both_roll_over(void)
{
   TEST_IGNORE();
   clock_t clock = { -25, -160 };
   char *expected_clock_text = "20:20";

   test_expected_value(expected_clock_text, clock);
}

static void test_negative_hour_and_minutes_both_roll_over_continuously(void)
{
   TEST_IGNORE();
   clock_t clock = { -121, -5810 };
   char *expected_clock_text = "22:10";

   test_expected_value(expected_clock_text, clock);
}

static void test_add_minutes(void)
{
   TEST_IGNORE();
   clock_t clock = { 10, 0 };
   int minute_offset = 3;
   char *expected_clock_text = "10:03";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_no_minutes(void)
{
   TEST_IGNORE();
   clock_t clock = { 6, 41 };
   int minute_offset = 0;
   char *expected_clock_text = "06:41";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_to_next_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 45 };
   int minute_offset = 40;
   char *expected_clock_text = "01:25";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_more_than_one_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 10, 0 };
   int minute_offset = 61;
   char *expected_clock_text = "11:01";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_more_than_two_hours_with_carry(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 45 };
   int minute_offset = 160;
   char *expected_clock_text = "03:25";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_across_midnight(void)
{
   TEST_IGNORE();
   clock_t clock = { 23, 59 };
   int minute_offset = 2;
   char *expected_clock_text = "00:01";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_more_than_one_day(void)
{
   TEST_IGNORE();
   clock_t clock = { 5, 32 };
   int minute_offset = 1500;
   char *expected_clock_text = "06:32";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_add_more_than_two_days(void)
{
   TEST_IGNORE();
   clock_t clock = { 1, 1 };
   int minute_offset = 3500;
   char *expected_clock_text = "11:21";

   test_clock_add_expected_value(expected_clock_text, clock, minute_offset);
}

static void test_subtract_minutes(void)
{
   TEST_IGNORE();
   clock_t clock = { 10, 3 };
   int minute_offset = 3;
   char *expected_clock_text = "10:00";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_to_previous_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 10, 3 };
   int minute_offset = 30;
   char *expected_clock_text = "09:33";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_more_than_an_hour(void)
{
   TEST_IGNORE();
   clock_t clock = { 10, 3 };
   int minute_offset = 70;
   char *expected_clock_text = "08:53";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_across_midnight(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 3 };
   int minute_offset = 4;
   char *expected_clock_text = "23:59";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_more_than_two_hours(void)
{
   TEST_IGNORE();
   clock_t clock = { 0, 0 };
   int minute_offset = 160;
   char *expected_clock_text = "21:20";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_more_than_two_hours_with_borrow(void)
{
   TEST_IGNORE();
   clock_t clock = { 6, 15 };
   int minute_offset = 160;
   char *expected_clock_text = "03:35";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_more_than_one_day(void)
{
   TEST_IGNORE();
   clock_t clock = { 5, 32 };
   int minute_offset = 1500;
   char *expected_clock_text = "04:32";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_subtract_more_than_two_days(void)
{
   TEST_IGNORE();
   clock_t clock = { 2, 20 };
   int minute_offset = 3000;
   char *expected_clock_text = "00:20";

   test_clock_subtract_expected_value(expected_clock_text, clock,
                                      minute_offset);
}

static void test_compare_clocks_with_same_time(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 15, 37 };
   clock_t clock2 = { 15, 37 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_a_minute_apart(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 15, 36 };
   clock_t clock2 = { 15, 37 };

   TEST_ASSERT_FALSE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_an_hour_apart(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 14, 37 };
   clock_t clock2 = { 15, 37 };

   TEST_ASSERT_FALSE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_hour_overflow(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 10, 37 };
   clock_t clock2 = { 34, 37 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_hour_overflow_by_several_days(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 3, 11 };
   clock_t clock2 = { 99, 11 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_hour(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 22, 40 };
   clock_t clock2 = { -2, 40 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_hour_that_wraps(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 17, 3 };
   clock_t clock2 = { -31, 3 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void
test_compare_clocks_with_negative_hour_that_wraps_multiple_times(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 13, 49 };
   clock_t clock2 = { -83, 49 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_minute_overflow(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 0, 1 };
   clock_t clock2 = { 0, 1441 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_minute_overflow_by_several_days(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 2, 2 };
   clock_t clock2 = { 2, 4322 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_minute(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 2, 40 };
   clock_t clock2 = { 3, -20 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_minute_that_wraps(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 4, 10 };
   clock_t clock2 = { 5, -1490 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void
test_compare_clocks_with_negative_minute_that_wraps_multiple_times(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 6, 15 };
   clock_t clock2 = { 6, -4305 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_hours_and_minute(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 7, 32 };
   clock_t clock2 = { -12, -268 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_clocks_with_negative_hours_and_minute_that_wrap(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 18, 7 };
   clock_t clock2 = { -54, -11513 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

static void test_compare_full_clock_and_zeroed_clock(void)
{
   TEST_IGNORE();
   clock_t clock1 = { 24, 0 };
   clock_t clock2 = { 0, 0 };

   TEST_ASSERT_TRUE(clock_is_equal(clock1, clock2));
}

int main(void)
{
   UnityBegin("clock.c");

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
