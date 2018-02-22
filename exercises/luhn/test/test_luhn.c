#include "vendor/unity.h"
#include "../src/luhn.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_single_digit_strings_can_not_be_valid(void)
{
   TEST_ASSERT_FALSE(luhn("1"));
}

void test_a_single_zero_is_invalid(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FALSE(luhn("0"));
}

void test_a_simple_valid_SIN_that_remains_valid_if_reversed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("059"));
}

void test_a_simple_valid_SIN_that_becomes_invalid_if_reversed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("59"));
}

void test_a_valid_Canadian_SIN(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("055 444 285"));
}

void test_invalid_Canadian_SIN(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055 444 286"));
}

void test_invalid_credit_card(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("8273 1232 7352 0569"));
}

void test_valid_strings_with_a_non_digit_included_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055a 444 285"));
}

void test_valid_strings_with_punctuation_included_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055-444-285"));
}

void test_valid_strings_with_symbols_included_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055£ 444$ 285"));
}

void test_single_zero_with_space_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn(" 0"));
}

void test_more_than_a_single_zero_is_valid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("0000 0"));
}

void test_input_digit_9_is_correctly_converted_to_output_digit_9(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("091"));
}

int main(void)
{
   UnityBegin("test/test_luhn.c");

   RUN_TEST(test_single_digit_strings_can_not_be_valid);
   RUN_TEST(test_a_single_zero_is_invalid);
   RUN_TEST(test_a_simple_valid_SIN_that_remains_valid_if_reversed);
   RUN_TEST(test_a_simple_valid_SIN_that_becomes_invalid_if_reversed);
   RUN_TEST(test_a_valid_Canadian_SIN);
   RUN_TEST(test_invalid_Canadian_SIN);
   RUN_TEST(test_invalid_credit_card);
   RUN_TEST(test_valid_strings_with_a_non_digit_included_become_invalid);
   RUN_TEST(test_valid_strings_with_punctuation_included_become_invalid);
   RUN_TEST(test_valid_strings_with_symbols_included_become_invalid);
   RUN_TEST(test_single_zero_with_space_is_invalid);
   RUN_TEST(test_more_than_a_single_zero_is_valid);
   RUN_TEST(test_input_digit_9_is_correctly_converted_to_output_digit_9);

   UnityEnd();
   return 0;
}
