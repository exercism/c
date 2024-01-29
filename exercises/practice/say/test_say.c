#include "test-framework/unity.h"
#include "say.h"
#include <stdlib.h>

static char *ans = NULL;

void setUp(void)
{
}

void tearDown(void)
{
   if (ans)
      free(ans);
   ans = NULL;
}

static void test_zero(void)
{
   int res = say(0, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("zero", ans);
}

static void test_one(void)
{
   TEST_IGNORE();   // delete this line to run test
   int res = say(1, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one", ans);
}

static void test_fourteen(void)
{
   TEST_IGNORE();
   int res = say(14, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("fourteen", ans);
}

static void test_twenty(void)
{
   TEST_IGNORE();
   int res = say(20, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("twenty", ans);
}

static void test_twenty_two(void)
{
   TEST_IGNORE();
   int res = say(22, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("twenty-two", ans);
}

static void test_thirty(void)
{
   TEST_IGNORE();
   int res = say(30, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("thirty", ans);
}

static void test_ninety_nine(void)
{
   TEST_IGNORE();
   int res = say(99, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("ninety-nine", ans);
}

static void test_one_hundred(void)
{
   TEST_IGNORE();
   int res = say(100, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one hundred", ans);
}

static void test_one_hundred_twenty_three(void)
{
   TEST_IGNORE();
   int res = say(123, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one hundred twenty-three", ans);
}

static void test_two_hundred(void)
{
   TEST_IGNORE();
   int res = say(200, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("two hundred", ans);
}

static void test_nine_hundred_ninety_nine(void)
{
   TEST_IGNORE();
   int res = say(999, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("nine hundred ninety-nine", ans);
}

static void test_one_thousand(void)
{
   TEST_IGNORE();
   int res = say(1000, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one thousand", ans);
}

static void test_one_thousand_two_hundred_thirty_four(void)
{
   TEST_IGNORE();
   int res = say(1234, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one thousand two hundred thirty-four", ans);
}

static void test_one_million(void)
{
   TEST_IGNORE();
   int res = say(1000000, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one million", ans);
}

static void test_one_million_two_thousand_three_hundred_forty_five(void)
{
   TEST_IGNORE();
   int res = say(1002345, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one million two thousand three hundred "
                            "forty-five",
                            ans);
}

static void test_one_billion(void)
{
   TEST_IGNORE();
   int res = say(1000000000, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("one billion", ans);
}

static void test_a_big_number(void)
{
   TEST_IGNORE();
   int res = say(987654321123, &ans);
   TEST_ASSERT_EQUAL_INT(0, res);
   TEST_ASSERT_EQUAL_STRING("nine hundred eighty-seven billion six hundred "
                            "fifty-four million three hundred twenty-one "
                            "thousand one hundred twenty-three",
                            ans);
}

static void test_numbers_below_zero_are_out_of_range(void)
{
   TEST_IGNORE();
   int res = say(-1, &ans);
   TEST_ASSERT_EQUAL_INT(-1, res);
}

static void test_numbers_above_999_999_999_999_are_out_of_range(void)
{
   TEST_IGNORE();
   int res = say(1000000000000, &ans);
   TEST_ASSERT_EQUAL_INT(-1, res);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_zero);
   RUN_TEST(test_one);
   RUN_TEST(test_fourteen);
   RUN_TEST(test_twenty);
   RUN_TEST(test_twenty_two);
   RUN_TEST(test_thirty);
   RUN_TEST(test_ninety_nine);
   RUN_TEST(test_one_hundred);
   RUN_TEST(test_one_hundred_twenty_three);
   RUN_TEST(test_two_hundred);
   RUN_TEST(test_one_thousand);
   RUN_TEST(test_nine_hundred_ninety_nine);
   RUN_TEST(test_one_thousand_two_hundred_thirty_four);
   RUN_TEST(test_one_million);
   RUN_TEST(test_one_million_two_thousand_three_hundred_forty_five);
   RUN_TEST(test_one_billion);
   RUN_TEST(test_a_big_number);
   RUN_TEST(test_numbers_below_zero_are_out_of_range);
   RUN_TEST(test_numbers_above_999_999_999_999_are_out_of_range);

   return UNITY_END();
}
