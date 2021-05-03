#include "test-framework/unity.h"
#include "luhn.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_single_digit_strings_can_not_be_valid(void)
{
   TEST_ASSERT_FALSE(luhn("1"));
}

static void test_a_single_zero_is_invalid(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FALSE(luhn("0"));
}

static void test_a_simple_valid_SIN_that_remains_valid_if_reversed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("059"));
}

static void test_a_simple_valid_SIN_that_becomes_invalid_if_reversed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("59"));
}

static void test_a_valid_Canadian_SIN(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("055 444 285"));
}

static void test_invalid_Canadian_SIN(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055 444 286"));
}

static void test_invalid_credit_card(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("8273 1232 7352 0569"));
}

static void test_invalid_long_number_with_an_even_remainder(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("1 2345 6789 1234 5678 9012"));
}

static void test_valid_number_with_an_even_number_of_digits(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("095 245 88"));
}

static void test_valid_number_with_an_odd_number_of_spaces(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("234 567 891 234"));
}

static void
test_valid_string_with_a_non_digit_added_at_the_end_to_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("059a"));
}

static void test_valid_strings_with_punctuation_included_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055-444-285"));
}

static void test_valid_strings_with_symbols_included_become_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055£ 444$ 285"));
}

static void test_single_zero_with_space_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn(" 0"));
}

static void test_more_than_a_single_zero_is_valid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("0000 0"));
}

static void test_input_digit_9_is_correctly_converted_to_output_digit_9(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(luhn("091"));
}

static void test_ascii_value_for_non_doubled_non_digit_isnt_allowed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("055b 444 285"));
}

static void test_ascii_value_for_doubled_non_digit_isnt_allowed(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn(":9"));
}

static void
    test_non_numeric_non_space_char_in_middle_with_sum_divisible_by_10_isnt_allowed
    (void) {
   TEST_IGNORE();
   TEST_ASSERT_FALSE(luhn("59%59"));
}

int main(void)
{
   UnityBegin("test_luhn.c");

   RUN_TEST(test_single_digit_strings_can_not_be_valid);
   RUN_TEST(test_a_single_zero_is_invalid);
   RUN_TEST(test_a_simple_valid_SIN_that_remains_valid_if_reversed);
   RUN_TEST(test_a_simple_valid_SIN_that_becomes_invalid_if_reversed);
   RUN_TEST(test_a_valid_Canadian_SIN);
   RUN_TEST(test_invalid_Canadian_SIN);
   RUN_TEST(test_invalid_credit_card);
   RUN_TEST(test_invalid_long_number_with_an_even_remainder);
   RUN_TEST(test_valid_number_with_an_even_number_of_digits);
   RUN_TEST(test_valid_number_with_an_odd_number_of_spaces);
   RUN_TEST
       (test_valid_string_with_a_non_digit_added_at_the_end_to_become_invalid);
   RUN_TEST(test_valid_strings_with_punctuation_included_become_invalid);
   RUN_TEST(test_valid_strings_with_symbols_included_become_invalid);
   RUN_TEST(test_single_zero_with_space_is_invalid);
   RUN_TEST(test_more_than_a_single_zero_is_valid);
   RUN_TEST(test_input_digit_9_is_correctly_converted_to_output_digit_9);
   RUN_TEST(test_ascii_value_for_non_doubled_non_digit_isnt_allowed);
   RUN_TEST(test_ascii_value_for_doubled_non_digit_isnt_allowed);
   RUN_TEST
       (test_non_numeric_non_space_char_in_middle_with_sum_divisible_by_10_isnt_allowed);

   return UnityEnd();
}
