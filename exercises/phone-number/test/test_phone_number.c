#include "vendor/unity.h"
#include "../src/phone_number.h"
#include <stdlib.h>

void test_phone_number_clean(const char *input, const char *expected)
{
   char *result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

void test_cleans_parens_dashes_and_spaces_from_the_number(void)
{
   const char input[] = "(123) 456-7890";
   const char expected[] = "1234567890";

   test_phone_number_clean(input, expected);
}

void test_cleans_numbers_with_dots(void)
{
   const char input[] = "123.456.7890";
   const char expected[] = "1234567890";

   test_phone_number_clean(input, expected);
}

void test_valid_when_11_digits_and_first_digit_is_1(void)
{
   const char input[] = "11234567890";
   const char expected[] = "1234567890";

   test_phone_number_clean(input, expected);
}

void test_invalid_when_11_digits(void)
{
   const char input[] = "21234567890";
   const char expected[] = "0000000000";

   test_phone_number_clean(input, expected);
}

void test_invalid_when_9_digits(void)
{
   const char input[] = "123456789";
   const char expected[] = "0000000000";

   test_phone_number_clean(input, expected);
}

void test_returns_area_code(void)
{
   const char input[] = "5024567890";
   const char expected[] = "502";
   char *result;

   result = phone_number_get_area_code(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

void test_formats_a_number(void)
{
   const char input[] = "1234567890";
   const char expected[] = "(123) 456-7890";
   char *result;

   result = phone_number_format(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

void test_cleans_number_before_formatting(void)
{
   const char input[] = "123-456-7890";
   const char expected[] = "(123) 456-7890";
   char *result;

   result = phone_number_format(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

int main(void)
{
   UnityBegin("test/test_phone_number.c");

   RUN_TEST(test_cleans_parens_dashes_and_spaces_from_the_number);
   RUN_TEST(test_cleans_numbers_with_dots);
   RUN_TEST(test_valid_when_11_digits_and_first_digit_is_1);
   RUN_TEST(test_invalid_when_11_digits);
   RUN_TEST(test_invalid_when_9_digits);
   RUN_TEST(test_returns_area_code);
   RUN_TEST(test_formats_a_number);
   RUN_TEST(test_cleans_number_before_formatting);

   UnityEnd();
   return 0;
}
