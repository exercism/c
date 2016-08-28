#include <time.h>

#include "vendor/unity.h"
#include "../src/gigasecond.h"

/* Convert a date string in the format "YYYY-MM-DD HH:MM:SS +NNNN"
 * (date, time, offset from UTC) into a time_t (seconds since Unix
 * epoch).
 */
time_t parse_date(const char *const str) {
  struct tm date;
  strptime(str, "%F %T %z", &date);
  return mktime(&date);
}

void test_date(void) {
  time_t expected = parse_date("2043-01-01 01:46:40 +0000");
  time_t actual = gigasecond_after(parse_date("2011-04-25 00:00:00 +0000"));
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_another_date(void) {
  time_t expected = parse_date("2009-02-19 01:46:40 +0000");
  time_t actual = gigasecond_after(parse_date("1977-06-13 00:00:00 +0000"));
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_third_date(void) {
  time_t expected = parse_date("1991-03-27 01:46:40 +0000");
  time_t actual = gigasecond_after(parse_date("1959-07-19 00:00:00 +0000"));
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_date_and_time(void) {
  time_t expected = parse_date("2046-10-02 23:46:40 +0000");
  time_t actual = gigasecond_after(parse_date("2015-01-24 22:00:00 +0000"));
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_date_and_time_with_day_rollover(void) {
  time_t expected = parse_date("2046-10-03 01:46:39 +0000");
  time_t actual = gigasecond_after(parse_date("2015-01-24 23:59:59 +0000"));
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

/*
void test_your_birthday(void) {
  time_t expected = parse_date("");
  time_t actual = gigasecond_after(parse_date(""));
  TEST_ASSERT_EQUAL_INT(expected, actual);
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
