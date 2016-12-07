#include "vendor/unity.h"
#include "../src/meetup.h"

// Using XMacros to create the tests
#define EXPAND_MEETUP_TEST_AS_TEST(test_name, year, month, week, dayOfWeek, dayOfMonth)\
   void test_name(void)\
   {\
   int actualDayOfMonth = meetupDayOfMonth(year, month, week, dayOfWeek);\
   \
   TEST_ASSERT_EQUAL_INT(dayOfMonth, actualDayOfMonth);\
   }\


// below expands to multiple routines...that are all designed to test the returned day of month
// the fields are:
//    text - test name, int year, int month, char *week, char *dayofWeek, int dayOfMonthExpecte (0=invalid)

#define MEETUP_TESTS(ENTRY) \
   ENTRY(test_monteenth_of_May_2013, 2013, 5, "teenth", "Monday", 13)\
   ENTRY(test_monteenth_of_August_2013, 2013, 8, "teenth", "Monday", 19)\
   ENTRY(test_monteenth_of_September_2013, 2013, 9, "teenth", "Monday", 16)\
   ENTRY(test_tuesteenth_of_March_2013, 2013, 3, "teenth", "Tuesday", 19)\
   ENTRY(test_tuesteenth_of_April_2013, 2013, 4, "teenth", "Tuesday", 16)\
   ENTRY(test_tuesteenth_of_August_2013, 2013, 8, "teenth", "Tuesday", 13)\
   ENTRY(test_wednesteenth_of_January_2013, 2013, 1, "teenth", "Wednesday", 16)\
   ENTRY(test_wednesteenth_of_February_2013, 2013, 2, "teenth", "Wednesday", 13)\
   ENTRY(test_wednesteenth_of_June_2013, 2013, 6, "teenth", "Wednesday", 19)\
   ENTRY(test_thursteenth_of_May_2013, 2013, 5, "teenth", "Thursday", 16)\
   ENTRY(test_thursteenth_of_June_2013, 2013, 6, "teenth", "Thursday", 13)\
   ENTRY(test_thursteenth_of_September_2013, 2013, 9, "teenth", "Thursday", 19)\
   ENTRY(test_friteenth_of_April_2013, 2013, 4, "teenth", "Friday", 19)\
   ENTRY(test_friteenth_of_August_2013, 2013, 8, "teenth", "Friday", 16)\
   ENTRY(test_friteenth_of_September_2013, 2013, 9, "teenth", "Friday", 13)\
   ENTRY(test_saturteenth_of_February_2013, 2013, 2, "teenth", "Saturday", 16)\
   ENTRY(test_saturteenth_of_April_2013, 2013, 4, "teenth", "Saturday", 13)\
   ENTRY(test_saturteenth_of_October_2013, 2013, 10, "teenth", "Saturday", 19)\
   ENTRY(test_sunteenth_of_May_2013, 2013, 5, "teenth", "Sunday", 19)\
   ENTRY(test_sunteenth_of_June_2013, 2013, 6, "teenth", "Sunday", 16)\
   ENTRY(test_sunteenth_of_October_2013, 2013, 10, "teenth", "Sunday", 13)\
   ENTRY(test_first_Monday_of_March_2013, 2013, 3, "first", "Monday", 4)\
   ENTRY(test_first_Monday_of_April_2013, 2013, 4, "first", "Monday", 1)\
   ENTRY(test_first_Tuesday_of_May_2013, 2013, 5, "first", "Tuesday", 7)\
   ENTRY(test_first_Tuesday_of_June_2013, 2013, 6, "first", "Tuesday", 4)\
   ENTRY(test_first_Wednesday_of_July_2013, 2013, 7, "first", "Wednesday", 3)\
   ENTRY(test_first_Wednesday_of_August_2013, 2013, 8, "first", "Wednesday", 7)\
   ENTRY(test_first_Thursday_of_September_2013, 2013, 9, "first", "Thursday", 5)\
   ENTRY(test_first_Thursday_of_October_2013, 2013, 10, "first", "Thursday", 3)\
   ENTRY(test_first_Friday_of_November_2013, 2013, 11, "first", "Friday", 1)\
   ENTRY(test_first_Friday_of_December_2013, 2013, 12, "first", "Friday", 6)\
   ENTRY(test_first_Saturday_of_January_2013, 2013, 1, "first", "Saturday", 5)\
   ENTRY(test_first_Saturday_of_February_2013, 2013, 2, "first", "Saturday", 2)\
   ENTRY(test_first_Sunday_of_March_2013, 2013, 3, "first", "Sunday", 3)\
   ENTRY(test_first_Sunday_of_April_2013, 2013, 4, "first", "Sunday", 7)\
   ENTRY(test_second_Monday_of_March_2013, 2013, 3, "second", "Monday", 11)\
   ENTRY(test_second_Monday_of_April_2013, 2013, 4, "second", "Monday", 8)\
   ENTRY(test_second_Tuesday_of_May_2013, 2013, 5, "second", "Tuesday", 14)\
   ENTRY(test_second_Tuesday_of_June_2013, 2013, 6, "second", "Tuesday", 11)\
   ENTRY(test_second_Wednesday_of_July_2013, 2013, 7, "second", "Wednesday", 10)\
   ENTRY(test_second_Wednesday_of_August_2013, 2013, 8, "second", "Wednesday", 14)\
   ENTRY(test_second_Thursday_of_September_2013, 2013, 9, "second", "Thursday", 12)\
   ENTRY(test_second_Thursday_of_October_2013, 2013, 10, "second", "Thursday", 10)\
   ENTRY(test_second_Friday_of_November_2013, 2013, 11, "second", "Friday", 8)\
   ENTRY(test_second_Friday_of_December_2013, 2013, 12, "second", "Friday", 13)\
   ENTRY(test_second_Saturday_of_January_2013, 2013, 1, "second", "Saturday", 12)\
   ENTRY(test_second_Saturday_of_February_2013, 2013, 2, "second", "Saturday", 9)\
   ENTRY(test_second_Sunday_of_March_2013, 2013, 3, "second", "Sunday", 10)\
   ENTRY(test_second_Sunday_of_April_2013, 2013, 4, "second", "Sunday", 14)\
   ENTRY(test_third_Monday_of_March_2013, 2013, 3, "third", "Monday", 18)\
   ENTRY(test_third_Monday_of_April_2013, 2013, 4, "third", "Monday", 15)\
   ENTRY(test_third_Tuesday_of_May_2013, 2013, 5, "third", "Tuesday", 21)\
   ENTRY(test_third_Tuesday_of_June_2013, 2013, 6, "third", "Tuesday", 18)\
   ENTRY(test_third_Wednesday_of_July_2013, 2013, 7, "third", "Wednesday", 17)\
   ENTRY(test_third_Wednesday_of_August_2013, 2013, 8, "third", "Wednesday", 21)\
   ENTRY(test_third_Thursday_of_September_2013, 2013, 9, "third", "Thursday", 19)\
   ENTRY(test_third_Thursday_of_October_2013, 2013, 10, "third", "Thursday", 17)\
   ENTRY(test_third_Friday_of_November_2013, 2013, 11, "third", "Friday", 15)\
   ENTRY(test_third_Friday_of_December_2013, 2013, 12, "third", "Friday", 20)\
   ENTRY(test_third_Saturday_of_January_2013, 2013, 1, "third", "Saturday", 19)\
   ENTRY(test_third_Saturday_of_February_2013, 2013, 2, "third", "Saturday", 16)\
   ENTRY(test_third_Sunday_of_March_2013, 2013, 3, "third", "Sunday", 17)\
   ENTRY(test_third_Sunday_of_April_2013, 2013, 4, "third", "Sunday", 21)\
   ENTRY(test_fourth_Monday_of_March_2013, 2013, 3, "fourth", "Monday", 25)\
   ENTRY(test_fourth_Monday_of_April_2013, 2013, 4, "fourth", "Monday", 22)\
   ENTRY(test_fourth_Tuesday_of_May_2013, 2013, 5, "fourth", "Tuesday", 28)\
   ENTRY(test_fourth_Tuesday_of_June_2013, 2013, 6, "fourth", "Tuesday", 25)\
   ENTRY(test_fourth_Wednesday_of_July_2013, 2013, 7, "fourth", "Wednesday", 24)\
   ENTRY(test_fourth_Wednesday_of_August_2013, 2013, 8, "fourth", "Wednesday", 28)\
   ENTRY(test_fourth_Thursday_of_September_2013, 2013, 9, "fourth", "Thursday", 26)\
   ENTRY(test_fourth_Thursday_of_October_2013, 2013, 10, "fourth", "Thursday", 24)\
   ENTRY(test_fourth_Friday_of_November_2013, 2013, 11, "fourth", "Friday", 22)\
   ENTRY(test_fourth_Friday_of_December_2013, 2013, 12, "fourth", "Friday", 27)\
   ENTRY(test_fourth_Saturday_of_January_2013, 2013, 1, "fourth", "Saturday", 26)\
   ENTRY(test_fourth_Saturday_of_February_2013, 2013, 2, "fourth", "Saturday", 23)\
   ENTRY(test_fourth_Sunday_of_March_2013, 2013, 3, "fourth", "Sunday", 24)\
   ENTRY(test_fourth_Sunday_of_April_2013, 2013, 4, "fourth", "Sunday", 28)\
   ENTRY(test_last_Monday_of_March_2013, 2013, 3, "last", "Monday", 25)\
   ENTRY(test_last_Monday_of_April_2013, 2013, 4, "last", "Monday", 29)\
   ENTRY(test_last_Tuesday_of_May_2013, 2013, 5, "last", "Tuesday", 28)\
   ENTRY(test_last_Tuesday_of_June_2013, 2013, 6, "last", "Tuesday", 25)\
   ENTRY(test_last_Wednesday_of_July_2013, 2013, 7, "last", "Wednesday", 31)\
   ENTRY(test_last_Wednesday_of_August_2013, 2013, 8, "last", "Wednesday", 28)\
   ENTRY(test_last_Thursday_of_September_2013, 2013, 9, "last", "Thursday", 26)\
   ENTRY(test_last_Thursday_of_October_2013, 2013, 10, "last", "Thursday", 31)\
   ENTRY(test_last_Friday_of_November_2013, 2013, 11, "last", "Friday", 29)\
   ENTRY(test_last_Friday_of_December_2013, 2013, 12, "last", "Friday", 27)\
   ENTRY(test_last_Saturday_of_January_2013, 2013, 1, "last", "Saturday", 26)\
   ENTRY(test_last_Saturday_of_February_2013, 2013, 2, "last", "Saturday", 23)\
   ENTRY(test_last_Sunday_of_March_2013, 2013, 3, "last", "Sunday", 31)\
   ENTRY(test_last_Sunday_of_April_2013, 2013, 4, "last", "Sunday", 28)\
   ENTRY(test_last_Wednesday_of_February_2012, 2012, 2, "last", "Wednesday", 29)\
   ENTRY(test_last_Wednesday_of_December_2014, 2014, 12, "last", "Wednesday", 31)\
   ENTRY(test_last_Sunday_of_February_2015, 2015, 2, "last", "Sunday", 22)\
   ENTRY(test_first_Friday_of_December_2012, 2012, 12, "first", "Friday", 7)\
   ENTRY(test_fifth_Friday_of_December_2016, 2016, 12, "fifth", "Friday", 30)\
   ENTRY(test_fifth_Friday_of_February_2013, 2013, 02, "fifth", "Friday", 0)\

MEETUP_TESTS(EXPAND_MEETUP_TEST_AS_TEST)

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

   UnityEnd();
   return 0;
}
