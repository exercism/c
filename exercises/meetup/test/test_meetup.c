#include "vendor/unity.h"
#include "../src/meetup.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_monteenth_of_May_2013(void)
{
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 5, "teenth", "Monday"));
}

static void test_monteenth_of_August_2013(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 8, "teenth", "Monday"));
}

static void test_monteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 9, "teenth", "Monday"));
}

static void test_tuesteenth_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 3, "teenth", "Tuesday"));
}

static void test_tuesteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 4, "teenth", "Tuesday"));
}

static void test_tuesteenth_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 8, "teenth", "Tuesday"));
}

static void test_wednesteenth_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 1, "teenth", "Wednesday"));
}

static void test_wednesteenth_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 2, "teenth", "Wednesday"));
}

static void test_wednesteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 6, "teenth", "Wednesday"));
}

static void test_thursteenth_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 5, "teenth", "Thursday"));
}

static void test_thursteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 6, "teenth", "Thursday"));
}

static void test_thursteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 9, "teenth", "Thursday"));
}

static void test_friteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 4, "teenth", "Friday"));
}

static void test_friteenth_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 4, "teenth", "Friday"));
}

static void test_friteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 9, "teenth", "Friday"));
}

static void test_saturteenth_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 2, "teenth", "Saturday"));
}

static void test_saturteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 4, "teenth", "Saturday"));
}

static void test_saturteenth_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 10, "teenth", "Saturday"));
}

static void test_sunteenth_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 5, "teenth", "Sunday"));
}

static void test_sunteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 6, "teenth", "Sunday"));
}

static void test_sunteenth_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 10, "teenth", "Sunday"));
}

static void test_first_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 3, "first", "Monday"));
}

static void test_first_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 4, "first", "Monday"));
}

static void test_first_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 5, "first", "Tuesday"));
}

static void test_first_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 6, "first", "Tuesday"));
}

static void test_first_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 7, "first", "Wednesday"));
}

static void test_first_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 8, "first", "Wednesday"));
}

static void test_first_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 9, "first", "Thursday"));
}

static void test_first_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 10, "first", "Thursday"));
}

static void test_first_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 11, "first", "Friday"));
}

static void test_first_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(6, meetup_day_of_month(2013, 12, "first", "Friday"));
}

static void test_first_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 1, "first", "Saturday"));
}

static void test_first_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(2, meetup_day_of_month(2013, 2, "first", "Saturday"));
}

static void test_first_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 3, "first", "Sunday"));
}

static void test_first_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 4, "first", "Sunday"));
}

static void test_second_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 3, "second", "Monday"));
}

static void test_second_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 4, "second", "Monday"));
}

static void test_second_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 5, "second", "Tuesday"));
}

static void test_second_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 6, "second", "Tuesday"));
}

static void test_second_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 7, "second", "Wednesday"));
}

static void test_second_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14,
                         meetup_day_of_month(2013, 8, "second", "Wednesday"));
}

static void test_second_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 9, "second", "Thursday"));
}

static void test_second_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 10, "second", "Thursday"));
}

static void test_second_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 11, "second", "Friday"));
}

static void test_second_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 12, "second", "Friday"));
}

static void test_second_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 1, "second", "Saturday"));
}

static void test_second_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(9, meetup_day_of_month(2013, 2, "second", "Saturday"));
}

static void test_second_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10, meetup_day_of_month(2013, 3, "second", "Sunday"));
}

static void test_second_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 4, "second", "Sunday"));
}

static void test_third_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 3, "third", "Monday"));
}

static void test_third_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 4, "third", "Monday"));
}

static void test_third_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 5, "third", "Tuesday"));
}

static void test_third_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 6, "third", "Tuesday"));
}

static void test_third_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 7, "third", "Wednesday"));
}

static void test_third_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21,
                         meetup_day_of_month(2013, 8, "third", "Wednesday"));
}

static void test_third_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 9, "third", "Thursday"));
}

static void test_third_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 10, "third", "Thursday"));
}

static void test_third_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 11, "third", "Friday"));
}

static void test_third_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(20, meetup_day_of_month(2013, 12, "third", "Friday"));
}

static void test_third_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 1, "third", "Saturday"));
}

static void test_third_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 2, "third", "Saturday"));
}

static void test_third_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17, meetup_day_of_month(2013, 3, "third", "Sunday"));
}

static void test_third_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 4, "third", "Sunday"));
}

static void test_fourth_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "fourth", "Monday"));
}

static void test_fourth_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 4, "fourth", "Monday"));
}

static void test_fourth_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "fourth", "Tuesday"));
}

static void test_fourth_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "fourth", "Tuesday"));
}

static void test_fourth_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 7, "fourth", "Wednesday"));
}

static void test_fourth_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28,
                         meetup_day_of_month(2013, 8, "fourth", "Wednesday"));
}

static void test_fourth_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 9, "fourth", "Thursday"));
}

static void test_fourth_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 10, "fourth", "Thursday"));
}

static void test_fourth_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 11, "fourth", "Friday"));
}

static void test_fourth_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "fourth", "Friday"));
}

static void test_fourth_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 1, "fourth", "Saturday"));
}

static void test_fourth_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23,
                         meetup_day_of_month(2013, 2, "fourth", "Saturday"));
}

static void test_fourth_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24, meetup_day_of_month(2013, 3, "fourth", "Sunday"));
}

static void test_fourth_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "fourth", "Sunday"));
}

static void test_last_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "last", "Monday"));
}

static void test_last_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 4, "last", "Monday"));
}

static void test_last_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "last", "Tuesday"));
}

static void test_last_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "last", "Tuesday"));
}

static void test_last_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 7, "last", "Wednesday"));
}

static void test_last_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 8, "last", "Wednesday"));
}

static void test_last_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 9, "last", "Thursday"));
}

static void test_last_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 10, "last", "Thursday"));
}

static void test_last_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 11, "last", "Friday"));
}

static void test_last_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "last", "Friday"));
}

static void test_last_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 1, "last", "Saturday"));
}

static void test_last_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23, meetup_day_of_month(2013, 2, "last", "Saturday"));
}

static void test_last_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 3, "last", "Sunday"));
}

static void test_last_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "last", "Sunday"));
}

static void test_last_Wednesday_of_February_2012(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2012, 2, "last", "Wednesday"));
}

static void test_last_Wednesday_of_December_2014(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31,
                         meetup_day_of_month(2014, 12, "last", "Wednesday"));
}

static void test_last_Sunday_of_February_2015(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2015, 2, "last", "Sunday"));
}

static void test_first_Friday_of_December_2012(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2012, 12, "first", "Friday"));
}

static void test_fifth_Friday_of_December_2016(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(30, meetup_day_of_month(2016, 12, "fifth", "Friday"));
}

static void test_fifth_Friday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(0, meetup_day_of_month(2013, 02, "fifth", "Friday"));
}

int main(void)
{
   UnityBegin("test/test_meetup.c");

   RUN_TEST(test_monteenth_of_May_2013);
   RUN_TEST(test_monteenth_of_August_2013);
   RUN_TEST(test_monteenth_of_September_2013);
   RUN_TEST(test_tuesteenth_of_March_2013);
   RUN_TEST(test_tuesteenth_of_April_2013);
   RUN_TEST(test_tuesteenth_of_August_2013);
   RUN_TEST(test_wednesteenth_of_January_2013);
   RUN_TEST(test_wednesteenth_of_February_2013);
   RUN_TEST(test_wednesteenth_of_June_2013);
   RUN_TEST(test_thursteenth_of_May_2013);
   RUN_TEST(test_thursteenth_of_June_2013);
   RUN_TEST(test_thursteenth_of_September_2013);
   RUN_TEST(test_friteenth_of_April_2013);
   RUN_TEST(test_friteenth_of_August_2013);
   RUN_TEST(test_friteenth_of_September_2013);
   RUN_TEST(test_saturteenth_of_February_2013);
   RUN_TEST(test_saturteenth_of_April_2013);
   RUN_TEST(test_saturteenth_of_October_2013);
   RUN_TEST(test_sunteenth_of_May_2013);
   RUN_TEST(test_sunteenth_of_June_2013);
   RUN_TEST(test_sunteenth_of_October_2013);
   RUN_TEST(test_first_Monday_of_March_2013);
   RUN_TEST(test_first_Monday_of_April_2013);
   RUN_TEST(test_first_Tuesday_of_May_2013);
   RUN_TEST(test_first_Tuesday_of_June_2013);
   RUN_TEST(test_first_Wednesday_of_July_2013);
   RUN_TEST(test_first_Wednesday_of_August_2013);
   RUN_TEST(test_first_Thursday_of_September_2013);
   RUN_TEST(test_first_Thursday_of_October_2013);
   RUN_TEST(test_first_Friday_of_November_2013);
   RUN_TEST(test_first_Friday_of_December_2013);
   RUN_TEST(test_first_Saturday_of_January_2013);
   RUN_TEST(test_first_Saturday_of_February_2013);
   RUN_TEST(test_first_Sunday_of_March_2013);
   RUN_TEST(test_first_Sunday_of_April_2013);
   RUN_TEST(test_second_Monday_of_March_2013);
   RUN_TEST(test_second_Monday_of_April_2013);
   RUN_TEST(test_second_Tuesday_of_May_2013);
   RUN_TEST(test_second_Tuesday_of_June_2013);
   RUN_TEST(test_second_Wednesday_of_July_2013);
   RUN_TEST(test_second_Wednesday_of_August_2013);
   RUN_TEST(test_second_Thursday_of_September_2013);
   RUN_TEST(test_second_Thursday_of_October_2013);
   RUN_TEST(test_second_Friday_of_November_2013);
   RUN_TEST(test_second_Friday_of_December_2013);
   RUN_TEST(test_second_Saturday_of_January_2013);
   RUN_TEST(test_second_Saturday_of_February_2013);
   RUN_TEST(test_second_Sunday_of_March_2013);
   RUN_TEST(test_second_Sunday_of_April_2013);
   RUN_TEST(test_third_Monday_of_March_2013);
   RUN_TEST(test_third_Monday_of_April_2013);
   RUN_TEST(test_third_Tuesday_of_May_2013);
   RUN_TEST(test_third_Tuesday_of_June_2013);
   RUN_TEST(test_third_Wednesday_of_July_2013);
   RUN_TEST(test_third_Wednesday_of_August_2013);
   RUN_TEST(test_third_Thursday_of_September_2013);
   RUN_TEST(test_third_Thursday_of_October_2013);
   RUN_TEST(test_third_Friday_of_November_2013);
   RUN_TEST(test_third_Friday_of_December_2013);
   RUN_TEST(test_third_Saturday_of_January_2013);
   RUN_TEST(test_third_Saturday_of_February_2013);
   RUN_TEST(test_third_Sunday_of_March_2013);
   RUN_TEST(test_third_Sunday_of_April_2013);
   RUN_TEST(test_fourth_Monday_of_March_2013);
   RUN_TEST(test_fourth_Monday_of_April_2013);
   RUN_TEST(test_fourth_Tuesday_of_May_2013);
   RUN_TEST(test_fourth_Tuesday_of_June_2013);
   RUN_TEST(test_fourth_Wednesday_of_July_2013);
   RUN_TEST(test_fourth_Wednesday_of_August_2013);
   RUN_TEST(test_fourth_Thursday_of_September_2013);
   RUN_TEST(test_fourth_Thursday_of_October_2013);
   RUN_TEST(test_fourth_Friday_of_November_2013);
   RUN_TEST(test_fourth_Friday_of_December_2013);
   RUN_TEST(test_fourth_Saturday_of_January_2013);
   RUN_TEST(test_fourth_Saturday_of_February_2013);
   RUN_TEST(test_fourth_Sunday_of_March_2013);
   RUN_TEST(test_fourth_Sunday_of_April_2013);
   RUN_TEST(test_last_Monday_of_March_2013);
   RUN_TEST(test_last_Monday_of_April_2013);
   RUN_TEST(test_last_Tuesday_of_May_2013);
   RUN_TEST(test_last_Tuesday_of_June_2013);
   RUN_TEST(test_last_Wednesday_of_July_2013);
   RUN_TEST(test_last_Wednesday_of_August_2013);
   RUN_TEST(test_last_Thursday_of_September_2013);
   RUN_TEST(test_last_Thursday_of_October_2013);
   RUN_TEST(test_last_Friday_of_November_2013);
   RUN_TEST(test_last_Friday_of_December_2013);
   RUN_TEST(test_last_Saturday_of_January_2013);
   RUN_TEST(test_last_Saturday_of_February_2013);
   RUN_TEST(test_last_Sunday_of_March_2013);
   RUN_TEST(test_last_Sunday_of_April_2013);
   RUN_TEST(test_last_Wednesday_of_February_2012);
   RUN_TEST(test_last_Wednesday_of_December_2014);
   RUN_TEST(test_last_Sunday_of_February_2015);
   RUN_TEST(test_first_Friday_of_December_2012);
   RUN_TEST(test_fifth_Friday_of_December_2016);
   RUN_TEST(test_fifth_Friday_of_February_2013);

   return UnityEnd();
}
