#include "vendor/unity.h"
#include "../src/phone_number.h"
#include <stdlib.h>

static char *result = NULL;

void setUp(void)
{
}

void tearDown(void)
{
   free(result);
   result = NULL;
}

void test_cleans_parens_dashes_and_spaces_from_the_number(void)
{
   const char input[] = "(223) 456-7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_cleans_numbers_with_dots(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char input[] = "223.456.7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_cleans_numbers_with_multiple_spaces(void)
{
   TEST_IGNORE();
   const char input[] = "223 456   7890   ";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_when_9_digits(void)
{
   TEST_IGNORE();
   const char input[] = "123456789";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_valid_when_11_digits_and_first_digit_is_1(void)
{
   TEST_IGNORE();
   const char input[] = "12234567890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_when_11_digits_and_first_digit_not_1(void)
{
   TEST_IGNORE();
   const char input[] = "21234567890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_valid_when_11_digits_and_first_digit_is_1_even_with_punctuation(void)
{
   TEST_IGNORE();
   const char input[] = "+1 (223) 456-7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_when_more_than_11_digits(void)
{
   TEST_IGNORE();
   const char input[] = "321234567890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_with_letters(void)
{
   TEST_IGNORE();
   const char input[] = "123-abc-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_with_punctuations(void)
{
   TEST_IGNORE();
   const char input[] = "123-@:!-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_with_right_number_of_digits_but_letters_mixed_in(void)
{
   TEST_IGNORE();
   const char input[] = "1a2b3c4d5e6f7g8h9i0j";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_if_area_code_does_not_start_with_2_to_9(void)
{
   TEST_IGNORE();
   const char input[] = "(123) 456-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_invalid_if_exchange_code_does_not_start_with_2_to_9(void)
{
   TEST_IGNORE();
   const char input[] = "(223) 056-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

int main(void)
{
   UnityBegin("test/test_phone_number.c");

   RUN_TEST(test_cleans_parens_dashes_and_spaces_from_the_number);
   RUN_TEST(test_cleans_numbers_with_dots);
   RUN_TEST(test_cleans_numbers_with_multiple_spaces);
   RUN_TEST(test_invalid_when_9_digits);
   RUN_TEST(test_valid_when_11_digits_and_first_digit_is_1);
   RUN_TEST(test_invalid_when_11_digits_and_first_digit_not_1);
   RUN_TEST
       (test_valid_when_11_digits_and_first_digit_is_1_even_with_punctuation);
   RUN_TEST(test_invalid_when_more_than_11_digits);
   RUN_TEST(test_invalid_with_letters);
   RUN_TEST(test_invalid_with_punctuations);
   RUN_TEST(test_invalid_with_right_number_of_digits_but_letters_mixed_in);
   RUN_TEST(test_invalid_if_area_code_does_not_start_with_2_to_9);
   RUN_TEST(test_invalid_if_exchange_code_does_not_start_with_2_to_9);

   UnityEnd();
   return 0;
}
