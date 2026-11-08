#include "test-framework/unity.h"
#include "meetup.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void
test_when_teenth_monday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 5, "teenth", "Monday"));
}

static void
test_when_teenth_monday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 8, "teenth", "Monday"));
}

static void
test_when_teenth_monday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 9, "teenth", "Monday"));
}

static void
test_when_teenth_tuesday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 3, "teenth", "Tuesday"));
}

static void
test_when_teenth_tuesday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 4, "teenth", "Tuesday"));
}

static void
test_when_teenth_tuesday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 8, "teenth", "Tuesday"));
}

static void
test_when_teenth_wednesday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 1, "teenth", "Wednesday"));
}

static void
test_when_teenth_wednesday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 2, "teenth", "Wednesday"));
}

static void
test_when_teenth_wednesday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 6, "teenth", "Wednesday"));
}

static void
test_when_teenth_thursday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 5, "teenth", "Thursday"));
}

static void
test_when_teenth_thursday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 6, "teenth", "Thursday"));
}

static void
test_when_teenth_thursday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 9, "teenth", "Thursday"));
}

static void
test_when_teenth_friday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 4, "teenth", "Friday"));
}

static void
test_when_teenth_friday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 8, "teenth", "Friday"));
}

static void
test_when_teenth_friday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 9, "teenth", "Friday"));
}

static void
test_when_teenth_saturday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 2, "teenth", "Saturday"));
}

static void
test_when_teenth_saturday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 4, "teenth", "Saturday"));
}

static void
test_when_teenth_saturday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 10, "teenth", "Saturday"));
}

static void
test_when_teenth_sunday_is_the_19th_the_last_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 5, "teenth", "Sunday"));
}

static void
test_when_teenth_sunday_is_some_day_in_the_middle_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 6, "teenth", "Sunday"));
}

static void
test_when_teenth_sunday_is_the_13th_the_first_day_of_the_teenth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 10, "teenth", "Sunday"));
}

static void
test_when_first_monday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 3, "first", "Monday"));
}

static void
test_when_first_monday_is_the_1st_the_first_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 4, "first", "Monday"));
}

static void
test_when_first_tuesday_is_the_7th_the_last_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 5, "first", "Tuesday"));
}

static void
test_when_first_tuesday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 6, "first", "Tuesday"));
}

static void
test_when_first_wednesday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 7, "first", "Wednesday"));
}

static void
test_when_first_wednesday_is_the_7th_the_last_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 8, "first", "Wednesday"));
}

static void
test_when_first_thursday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 9, "first", "Thursday"));
}

static void
test_when_first_thursday_is_another_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 10, "first", "Thursday"));
}

static void
test_when_first_friday_is_the_1st_the_first_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 11, "first", "Friday"));
}

static void
test_when_first_friday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(6, meetup_day_of_month(2013, 12, "first", "Friday"));
}

static void
test_when_first_saturday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 1, "first", "Saturday"));
}

static void
test_when_first_saturday_is_another_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(2, meetup_day_of_month(2013, 2, "first", "Saturday"));
}

static void
test_when_first_sunday_is_some_day_in_the_middle_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 3, "first", "Sunday"));
}

static void
test_when_first_sunday_is_the_7th_the_last_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 4, "first", "Sunday"));
}

static void
test_when_second_monday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 3, "second", "Monday"));
}

static void
test_when_second_monday_is_the_8th_the_first_day_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 4, "second", "Monday"));
}

static void
test_when_second_tuesday_is_the_14th_the_last_day_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 5, "second", "Tuesday"));
}

static void
test_when_second_tuesday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 6, "second", "Tuesday"));
}

static void
test_when_second_wednesday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 7, "second", "Wednesday"));
}

static void
test_when_second_wednesday_is_the_14th_the_last_day_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14,
                         meetup_day_of_month(2013, 8, "second", "Wednesday"));
}

static void
test_when_second_thursday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 9, "second", "Thursday"));
}

static void
test_when_second_thursday_is_another_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 10, "second", "Thursday"));
}

static void
test_when_second_friday_is_the_8th_the_first_day_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 11, "second", "Friday"));
}

static void
test_when_second_friday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 12, "second", "Friday"));
}

static void
test_when_second_saturday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 1, "second", "Saturday"));
}

static void
test_when_second_saturday_is_another_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(9, meetup_day_of_month(2013, 2, "second", "Saturday"));
}

static void
test_when_second_sunday_is_some_day_in_the_middle_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10, meetup_day_of_month(2013, 3, "second", "Sunday"));
}

static void
test_when_second_sunday_is_the_14th_the_last_day_of_the_second_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 4, "second", "Sunday"));
}

static void
test_when_third_monday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 3, "third", "Monday"));
}

static void
test_when_third_monday_is_the_15th_the_first_day_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 4, "third", "Monday"));
}

static void
test_when_third_tuesday_is_the_21st_the_last_day_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 5, "third", "Tuesday"));
}

static void
test_when_third_tuesday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 6, "third", "Tuesday"));
}

static void
test_when_third_wednesday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 7, "third", "Wednesday"));
}

static void
test_when_third_wednesday_is_the_21st_the_last_day_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21,
                         meetup_day_of_month(2013, 8, "third", "Wednesday"));
}

static void
test_when_third_thursday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 9, "third", "Thursday"));
}

static void
test_when_third_thursday_is_another_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 10, "third", "Thursday"));
}

static void
test_when_third_friday_is_the_15th_the_first_day_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 11, "third", "Friday"));
}

static void
test_when_third_friday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(20, meetup_day_of_month(2013, 12, "third", "Friday"));
}

static void
test_when_third_saturday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 1, "third", "Saturday"));
}

static void
test_when_third_saturday_is_another_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 2, "third", "Saturday"));
}

static void
test_when_third_sunday_is_some_day_in_the_middle_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17, meetup_day_of_month(2013, 3, "third", "Sunday"));
}

static void
test_when_third_sunday_is_the_21st_the_last_day_of_the_third_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 4, "third", "Sunday"));
}

static void
test_when_fourth_monday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "fourth", "Monday"));
}

static void
test_when_fourth_monday_is_the_22nd_the_first_day_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 4, "fourth", "Monday"));
}

static void
test_when_fourth_tuesday_is_the_28th_the_last_day_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "fourth", "Tuesday"));
}

static void
test_when_fourth_tuesday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "fourth", "Tuesday"));
}

static void
test_when_fourth_wednesday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 7, "fourth", "Wednesday"));
}

static void
test_when_fourth_wednesday_is_the_28th_the_last_day_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28,
                         meetup_day_of_month(2013, 8, "fourth", "Wednesday"));
}

static void
test_when_fourth_thursday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 9, "fourth", "Thursday"));
}

static void
test_when_fourth_thursday_is_another_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 10, "fourth", "Thursday"));
}

static void
test_when_fourth_friday_is_the_22nd_the_first_day_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 11, "fourth", "Friday"));
}

static void
test_when_fourth_friday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "fourth", "Friday"));
}

static void
test_when_fourth_saturday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 1, "fourth", "Saturday"));
}

static void
test_when_fourth_saturday_is_another_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23,
                         meetup_day_of_month(2013, 2, "fourth", "Saturday"));
}

static void
test_when_fourth_sunday_is_some_day_in_the_middle_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24, meetup_day_of_month(2013, 3, "fourth", "Sunday"));
}

static void
test_when_fourth_sunday_is_the_28th_the_last_day_of_the_fourth_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "fourth", "Sunday"));
}

static void test_last_monday_in_a_month_with_four_mondays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "last", "Monday"));
}

static void test_last_monday_in_a_month_with_five_mondays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 4, "last", "Monday"));
}

static void test_last_tuesday_in_a_month_with_four_tuesdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "last", "Tuesday"));
}

static void test_last_tuesday_in_another_month_with_four_tuesdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "last", "Tuesday"));
}

static void test_last_wednesday_in_a_month_with_five_wednesdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 7, "last", "Wednesday"));
}

static void test_last_wednesday_in_a_month_with_four_wednesdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 8, "last", "Wednesday"));
}

static void test_last_thursday_in_a_month_with_four_thursdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 9, "last", "Thursday"));
}

static void test_last_thursday_in_a_month_with_five_thursdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 10, "last", "Thursday"));
}

static void test_last_friday_in_a_month_with_five_fridays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 11, "last", "Friday"));
}

static void test_last_friday_in_a_month_with_four_fridays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "last", "Friday"));
}

static void test_last_saturday_in_a_month_with_four_saturdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 1, "last", "Saturday"));
}

static void test_last_saturday_in_another_month_with_four_saturdays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23, meetup_day_of_month(2013, 2, "last", "Saturday"));
}

static void test_last_sunday_in_a_month_with_five_sundays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 3, "last", "Sunday"));
}

static void test_last_sunday_in_a_month_with_four_sundays(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "last", "Sunday"));
}

static void
test_when_last_wednesday_in_february_in_a_leap_year_is_the_29th(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2012, 2, "last", "Wednesday"));
}

static void
test_last_wednesday_in_december_that_is_also_the_last_day_of_the_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31,
                         meetup_day_of_month(2014, 12, "last", "Wednesday"));
}

static void
test_when_last_sunday_in_february_in_a_non_leap_year_is_not_the_29th(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2015, 2, "last", "Sunday"));
}

static void
test_when_first_friday_is_the_7th_the_last_day_of_the_first_week(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2012, 12, "first", "Friday"));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(
       test_when_teenth_monday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_monday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_monday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_tuesday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_tuesday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_tuesday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_wednesday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_wednesday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_wednesday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_thursday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_thursday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_thursday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_friday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_friday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_friday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_saturday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_saturday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_saturday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_sunday_is_the_19th_the_last_day_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_sunday_is_some_day_in_the_middle_of_the_teenth_week);
   RUN_TEST(
       test_when_teenth_sunday_is_the_13th_the_first_day_of_the_teenth_week);
   RUN_TEST(test_when_first_monday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(test_when_first_monday_is_the_1st_the_first_day_of_the_first_week);
   RUN_TEST(test_when_first_tuesday_is_the_7th_the_last_day_of_the_first_week);
   RUN_TEST(
       test_when_first_tuesday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(
       test_when_first_wednesday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(
       test_when_first_wednesday_is_the_7th_the_last_day_of_the_first_week);
   RUN_TEST(
       test_when_first_thursday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(
       test_when_first_thursday_is_another_day_in_the_middle_of_the_first_week);
   RUN_TEST(test_when_first_friday_is_the_1st_the_first_day_of_the_first_week);
   RUN_TEST(test_when_first_friday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(
       test_when_first_saturday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(
       test_when_first_saturday_is_another_day_in_the_middle_of_the_first_week);
   RUN_TEST(test_when_first_sunday_is_some_day_in_the_middle_of_the_first_week);
   RUN_TEST(test_when_first_sunday_is_the_7th_the_last_day_of_the_first_week);
   RUN_TEST(
       test_when_second_monday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_monday_is_the_8th_the_first_day_of_the_second_week);
   RUN_TEST(
       test_when_second_tuesday_is_the_14th_the_last_day_of_the_second_week);
   RUN_TEST(
       test_when_second_tuesday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_wednesday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_wednesday_is_the_14th_the_last_day_of_the_second_week);
   RUN_TEST(
       test_when_second_thursday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_thursday_is_another_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_friday_is_the_8th_the_first_day_of_the_second_week);
   RUN_TEST(
       test_when_second_friday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_saturday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_saturday_is_another_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_sunday_is_some_day_in_the_middle_of_the_second_week);
   RUN_TEST(
       test_when_second_sunday_is_the_14th_the_last_day_of_the_second_week);
   RUN_TEST(test_when_third_monday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(test_when_third_monday_is_the_15th_the_first_day_of_the_third_week);
   RUN_TEST(test_when_third_tuesday_is_the_21st_the_last_day_of_the_third_week);
   RUN_TEST(
       test_when_third_tuesday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(
       test_when_third_wednesday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(
       test_when_third_wednesday_is_the_21st_the_last_day_of_the_third_week);
   RUN_TEST(
       test_when_third_thursday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(
       test_when_third_thursday_is_another_day_in_the_middle_of_the_third_week);
   RUN_TEST(test_when_third_friday_is_the_15th_the_first_day_of_the_third_week);
   RUN_TEST(test_when_third_friday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(
       test_when_third_saturday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(
       test_when_third_saturday_is_another_day_in_the_middle_of_the_third_week);
   RUN_TEST(test_when_third_sunday_is_some_day_in_the_middle_of_the_third_week);
   RUN_TEST(test_when_third_sunday_is_the_21st_the_last_day_of_the_third_week);
   RUN_TEST(
       test_when_fourth_monday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_monday_is_the_22nd_the_first_day_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_tuesday_is_the_28th_the_last_day_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_tuesday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_wednesday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_wednesday_is_the_28th_the_last_day_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_thursday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_thursday_is_another_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_friday_is_the_22nd_the_first_day_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_friday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_saturday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_saturday_is_another_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_sunday_is_some_day_in_the_middle_of_the_fourth_week);
   RUN_TEST(
       test_when_fourth_sunday_is_the_28th_the_last_day_of_the_fourth_week);
   RUN_TEST(test_last_monday_in_a_month_with_four_mondays);
   RUN_TEST(test_last_monday_in_a_month_with_five_mondays);
   RUN_TEST(test_last_tuesday_in_a_month_with_four_tuesdays);
   RUN_TEST(test_last_tuesday_in_another_month_with_four_tuesdays);
   RUN_TEST(test_last_wednesday_in_a_month_with_five_wednesdays);
   RUN_TEST(test_last_wednesday_in_a_month_with_four_wednesdays);
   RUN_TEST(test_last_thursday_in_a_month_with_four_thursdays);
   RUN_TEST(test_last_thursday_in_a_month_with_five_thursdays);
   RUN_TEST(test_last_friday_in_a_month_with_five_fridays);
   RUN_TEST(test_last_friday_in_a_month_with_four_fridays);
   RUN_TEST(test_last_saturday_in_a_month_with_four_saturdays);
   RUN_TEST(test_last_saturday_in_another_month_with_four_saturdays);
   RUN_TEST(test_last_sunday_in_a_month_with_five_sundays);
   RUN_TEST(test_last_sunday_in_a_month_with_four_sundays);
   RUN_TEST(test_when_last_wednesday_in_february_in_a_leap_year_is_the_29th);
   RUN_TEST(
       test_last_wednesday_in_december_that_is_also_the_last_day_of_the_year);
   RUN_TEST(
       test_when_last_sunday_in_february_in_a_non_leap_year_is_not_the_29th);
   RUN_TEST(test_when_first_friday_is_the_7th_the_last_day_of_the_first_week);

   return UNITY_END();
}
