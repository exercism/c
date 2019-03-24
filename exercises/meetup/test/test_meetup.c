#include "vendor/unity.h"
#include "../src/meetup.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_monteenth_of_May_2013(void)
{
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 5, "teenth", "Monday"));
}

void test_monteenth_of_August_2013(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 8, "teenth", "Monday"));
}

void test_monteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 9, "teenth", "Monday"));
}

void test_tuesteenth_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 3, "teenth", "Tuesday"));
}

void test_tuesteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 4, "teenth", "Tuesday"));
}

void test_tuesteenth_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 8, "teenth", "Tuesday"));
}

void test_wednesteenth_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 1, "teenth", "Wednesday"));
}

void test_wednesteenth_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 2, "teenth", "Wednesday"));
}

void test_wednesteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 6, "teenth", "Wednesday"));
}

void test_thursteenth_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 5, "teenth", "Thursday"));
}

void test_thursteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 6, "teenth", "Thursday"));
}

void test_thursteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 9, "teenth", "Thursday"));
}

void test_friteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 4, "teenth", "Friday"));
}

void test_friteenth_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 4, "teenth", "Friday"));
}

void test_friteenth_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 9, "teenth", "Friday"));
}

void test_saturteenth_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16,
                         meetup_day_of_month(2013, 2, "teenth", "Saturday"));
}

void test_saturteenth_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13,
                         meetup_day_of_month(2013, 4, "teenth", "Saturday"));
}

void test_saturteenth_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19,
                         meetup_day_of_month(2013, 10, "teenth", "Saturday"));
}

void test_sunteenth_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 5, "teenth", "Sunday"));
}

void test_sunteenth_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 6, "teenth", "Sunday"));
}

void test_sunteenth_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 10, "teenth", "Sunday"));
}

void test_first_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 3, "first", "Monday"));
}

void test_first_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 4, "first", "Monday"));
}

void test_first_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 5, "first", "Tuesday"));
}

void test_first_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, meetup_day_of_month(2013, 6, "first", "Tuesday"));
}

void test_first_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 7, "first", "Wednesday"));
}

void test_first_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 8, "first", "Wednesday"));
}

void test_first_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 9, "first", "Thursday"));
}

void test_first_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 10, "first", "Thursday"));
}

void test_first_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, meetup_day_of_month(2013, 11, "first", "Friday"));
}

void test_first_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(6, meetup_day_of_month(2013, 12, "first", "Friday"));
}

void test_first_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(5, meetup_day_of_month(2013, 1, "first", "Saturday"));
}

void test_first_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(2, meetup_day_of_month(2013, 2, "first", "Saturday"));
}

void test_first_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, meetup_day_of_month(2013, 3, "first", "Sunday"));
}

void test_first_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2013, 4, "first", "Sunday"));
}

void test_second_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 3, "second", "Monday"));
}

void test_second_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 4, "second", "Monday"));
}

void test_second_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 5, "second", "Tuesday"));
}

void test_second_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(11, meetup_day_of_month(2013, 6, "second", "Tuesday"));
}

void test_second_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 7, "second", "Wednesday"));
}

void test_second_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14,
                         meetup_day_of_month(2013, 8, "second", "Wednesday"));
}

void test_second_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 9, "second", "Thursday"));
}

void test_second_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10,
                         meetup_day_of_month(2013, 10, "second", "Thursday"));
}

void test_second_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(8, meetup_day_of_month(2013, 11, "second", "Friday"));
}

void test_second_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(13, meetup_day_of_month(2013, 12, "second", "Friday"));
}

void test_second_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(12,
                         meetup_day_of_month(2013, 1, "second", "Saturday"));
}

void test_second_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(9, meetup_day_of_month(2013, 2, "second", "Saturday"));
}

void test_second_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(10, meetup_day_of_month(2013, 3, "second", "Sunday"));
}

void test_second_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(14, meetup_day_of_month(2013, 4, "second", "Sunday"));
}

void test_third_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 3, "third", "Monday"));
}

void test_third_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 4, "third", "Monday"));
}

void test_third_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 5, "third", "Tuesday"));
}

void test_third_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(18, meetup_day_of_month(2013, 6, "third", "Tuesday"));
}

void test_third_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 7, "third", "Wednesday"));
}

void test_third_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21,
                         meetup_day_of_month(2013, 8, "third", "Wednesday"));
}

void test_third_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 9, "third", "Thursday"));
}

void test_third_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17,
                         meetup_day_of_month(2013, 10, "third", "Thursday"));
}

void test_third_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(15, meetup_day_of_month(2013, 11, "third", "Friday"));
}

void test_third_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(20, meetup_day_of_month(2013, 12, "third", "Friday"));
}

void test_third_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(19, meetup_day_of_month(2013, 1, "third", "Saturday"));
}

void test_third_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(16, meetup_day_of_month(2013, 2, "third", "Saturday"));
}

void test_third_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(17, meetup_day_of_month(2013, 3, "third", "Sunday"));
}

void test_third_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(21, meetup_day_of_month(2013, 4, "third", "Sunday"));
}

void test_fourth_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "fourth", "Monday"));
}

void test_fourth_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 4, "fourth", "Monday"));
}

void test_fourth_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "fourth", "Tuesday"));
}

void test_fourth_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "fourth", "Tuesday"));
}

void test_fourth_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 7, "fourth", "Wednesday"));
}

void test_fourth_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28,
                         meetup_day_of_month(2013, 8, "fourth", "Wednesday"));
}

void test_fourth_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 9, "fourth", "Thursday"));
}

void test_fourth_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24,
                         meetup_day_of_month(2013, 10, "fourth", "Thursday"));
}

void test_fourth_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2013, 11, "fourth", "Friday"));
}

void test_fourth_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "fourth", "Friday"));
}

void test_fourth_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26,
                         meetup_day_of_month(2013, 1, "fourth", "Saturday"));
}

void test_fourth_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23,
                         meetup_day_of_month(2013, 2, "fourth", "Saturday"));
}

void test_fourth_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(24, meetup_day_of_month(2013, 3, "fourth", "Sunday"));
}

void test_fourth_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "fourth", "Sunday"));
}

void test_last_Monday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 3, "last", "Monday"));
}

void test_last_Monday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 4, "last", "Monday"));
}

void test_last_Tuesday_of_May_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 5, "last", "Tuesday"));
}

void test_last_Tuesday_of_June_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(25, meetup_day_of_month(2013, 6, "last", "Tuesday"));
}

void test_last_Wednesday_of_July_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 7, "last", "Wednesday"));
}

void test_last_Wednesday_of_August_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 8, "last", "Wednesday"));
}

void test_last_Thursday_of_September_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 9, "last", "Thursday"));
}

void test_last_Thursday_of_October_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 10, "last", "Thursday"));
}

void test_last_Friday_of_November_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2013, 11, "last", "Friday"));
}

void test_last_Friday_of_December_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(27, meetup_day_of_month(2013, 12, "last", "Friday"));
}

void test_last_Saturday_of_January_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(26, meetup_day_of_month(2013, 1, "last", "Saturday"));
}

void test_last_Saturday_of_February_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(23, meetup_day_of_month(2013, 2, "last", "Saturday"));
}

void test_last_Sunday_of_March_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31, meetup_day_of_month(2013, 3, "last", "Sunday"));
}

void test_last_Sunday_of_April_2013(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(28, meetup_day_of_month(2013, 4, "last", "Sunday"));
}

void test_last_Wednesday_of_February_2012(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(29, meetup_day_of_month(2012, 2, "last", "Wednesday"));
}

void test_last_Wednesday_of_December_2014(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(31,
                         meetup_day_of_month(2014, 12, "last", "Wednesday"));
}

void test_last_Sunday_of_February_2015(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(22, meetup_day_of_month(2015, 2, "last", "Sunday"));
}

void test_first_Friday_of_December_2012(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(7, meetup_day_of_month(2012, 12, "first", "Friday"));
}

void test_fifth_Friday_of_December_2016(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(30, meetup_day_of_month(2016, 12, "fifth", "Friday"));
}

void test_fifth_Friday_of_February_2013(void)
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
