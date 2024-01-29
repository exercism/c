#include "test-framework/unity.h"
#include "phone_number.h"
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

static void test_cleans_the_number(void)
{
   const char input[] = "(223) 456-7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_cleans_numbers_with_dots(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char input[] = "223.456.7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_cleans_numbers_with_multiple_spaces(void)
{
   TEST_IGNORE();
   const char input[] = "223 456   7890   ";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_when_9_digits(void)
{
   TEST_IGNORE();
   const char input[] = "123456789";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_when_11_digits_does_not_start_with_a_1(void)
{
   TEST_IGNORE();
   const char input[] = "22234567890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_valid_when_11_digits_and_starting_with_1(void)
{
   TEST_IGNORE();
   const char input[] = "12234567890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void
test_valid_when_11_digits_and_starting_with_1_even_with_punctuation(void)
{
   TEST_IGNORE();
   const char input[] = "+1 (223) 456-7890";
   const char expected[] = "2234567890";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_when_more_than_11_digits(void)
{
   TEST_IGNORE();
   const char input[] = "321234567890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_with_letters(void)
{
   TEST_IGNORE();
   const char input[] = "523-abc-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_with_punctuations(void)
{
   TEST_IGNORE();
   const char input[] = "523-@:!-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_if_area_code_starts_with_0(void)
{
   TEST_IGNORE();
   const char input[] = "(023) 456-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_if_area_code_starts_with_1(void)
{
   TEST_IGNORE();
   const char input[] = "(123) 456-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_if_exchange_code_starts_with_0(void)
{
   TEST_IGNORE();
   const char input[] = "(223) 056-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_invalid_if_exchange_code_starts_with_1(void)
{
   TEST_IGNORE();
   const char input[] = "(223) 156-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void
test_invalid_if_area_code_starts_with_0_on_valid_11_digit_number(void)
{
   TEST_IGNORE();
   const char input[] = "1 (023) 456-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void
test_invalid_if_area_code_starts_with_1_on_valid_11_digit_number(void)
{
   TEST_IGNORE();
   const char input[] = "1 (123) 456-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void
test_invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number(void)
{
   TEST_IGNORE();
   const char input[] = "1 (223) 056-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void
test_invalid_if_exchange_code_starts_with_1_on_valid_11_digit_number(void)
{
   TEST_IGNORE();
   const char input[] = "1 (123) 156-7890";
   const char expected[] = "0000000000";

   result = phone_number_clean(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_cleans_the_number);
   RUN_TEST(test_cleans_numbers_with_dots);
   RUN_TEST(test_cleans_numbers_with_multiple_spaces);
   RUN_TEST(test_invalid_when_9_digits);
   RUN_TEST(test_invalid_when_11_digits_does_not_start_with_a_1);
   RUN_TEST(test_valid_when_11_digits_and_starting_with_1);
   RUN_TEST(
       test_valid_when_11_digits_and_starting_with_1_even_with_punctuation);
   RUN_TEST(test_invalid_when_more_than_11_digits);
   RUN_TEST(test_invalid_with_letters);
   RUN_TEST(test_invalid_with_punctuations);
   RUN_TEST(test_invalid_if_area_code_starts_with_0);
   RUN_TEST(test_invalid_if_area_code_starts_with_1);
   RUN_TEST(test_invalid_if_exchange_code_starts_with_0);
   RUN_TEST(test_invalid_if_exchange_code_starts_with_1);
   RUN_TEST(test_invalid_if_area_code_starts_with_0_on_valid_11_digit_number);
   RUN_TEST(test_invalid_if_area_code_starts_with_1_on_valid_11_digit_number);
   RUN_TEST(
       test_invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number);
   RUN_TEST(
       test_invalid_if_exchange_code_starts_with_1_on_valid_11_digit_number);

   return UNITY_END();
}
