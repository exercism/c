#include "vendor/unity.h"
#include <stddef.h>
#include <stdint.h>
#include "../src/all_your_base.h"

#include <stdio.h>

void fill_array(int16_t data[], size_t data_length, int16_t array[],
                size_t array_length)
{
   /* array expected to be longer than data */
   for (size_t i = 1; i <= data_length; ++i)
      array[array_length - i] = data[data_length - i];
}

void test_rebase(uint16_t input_base, int16_t input_digits[],
                 size_t input_length, uint16_t output_base,
                 int16_t expected_digits[], size_t expected_length)
{
   int16_t digits[DIGITS_ARRAY_SIZE] = { 0 };
   int16_t ex_digits[DIGITS_ARRAY_SIZE] = { 0 };

   fill_array(input_digits, input_length, digits, DIGITS_ARRAY_SIZE);
   fill_array(expected_digits, expected_length, ex_digits, DIGITS_ARRAY_SIZE);

   size_t actual_length = rebase(digits, input_base, output_base, input_length);

   TEST_ASSERT_EQUAL_INT32(expected_length, actual_length);

   if (expected_length > 0)
      TEST_ASSERT_EQUAL_INT16_ARRAY(ex_digits, digits, expected_length);
}

void test_single_bit_to_decimal(void)
{
   int16_t input[] = { 1 };
   int16_t expected[] = { 1 };
   test_rebase(2, input, 1, 10, expected, 1);
}

void test_binary_to_single_decimal(void)
{
   int16_t input[] = { 1, 0, 1 };
   int16_t expected[] = { 5 };
   test_rebase(2, input, 3, 10, expected, 1);
}

void test_single_decimal_to_binary(void)
{
   int16_t input[] = { 5 };
   int16_t expected[] = { 1, 0, 1 };
   test_rebase(10, input, 1, 2, expected, 3);
}

void test_binary_to_multiple_decimal(void)
{
   int16_t input[] = { 1, 0, 1, 0, 1, 0 };
   int16_t expected[] = { 4, 2 };
   test_rebase(2, input, 6, 10, expected, 2);
}

void test_decimal_to_binary(void)
{
   int16_t input[] = { 4, 2 };
   int16_t expected[] = { 1, 0, 1, 0, 1, 0 };
   test_rebase(10, input, 2, 2, expected, 6);
}

void test_trinary_to_hex(void)
{
   int16_t input[] = { 1, 1, 2, 0 };
   int16_t expected[] = { 2, 10 };
   test_rebase(3, input, 4, 16, expected, 2);
}

void test_hex_to_trinary(void)
{
   int16_t input[] = { 2, 10 };
   int16_t expected[] = { 1, 1, 2, 0 };
   test_rebase(16, input, 2, 3, expected, 4);
}

void test_15_bit_integer(void)
{
   int16_t input[] = { 3, 46, 60 };
   int16_t expected[] = { 6, 10, 45 };
   test_rebase(97, input, 3, 73, expected, 3);
}

void test_single_zero(void)
{
   int16_t input[] = { 0 };
   int16_t expected[] = { 0 };
   test_rebase(2, input, 1, 10, expected, 0);
}

void test_multiple_zeros(void)
{
   int16_t input[] = { 0, 0, 0 };
   int16_t expected[] = { 0 };
   test_rebase(10, input, 3, 2, expected, 0);
}

void test_leading_zeros(void)
{
   int16_t input[] = { 0, 6, 0 };
   int16_t expected[] = { 0 };
   test_rebase(7, input, 3, 10, expected, 0);
}

void test_first_base_is_one(void)
{
   int16_t input[] = { 0 };
   int16_t expected[] = { 0 };
   test_rebase(1, input, 1, 10, expected, 0);
}

void test_first_base_is_zero(void)
{
   int16_t input[] = { 0 };
   int16_t expected[] = { 0 };
   test_rebase(0, input, 1, 10, expected, 0);
}

void test_first_base_is_negative(void)
{
   int16_t input[] = { 1 };
   int16_t expected[] = { 0 };
   test_rebase(-2, input, 1, 10, expected, 0);
}

void test_negative_digit(void)
{
   int16_t input[] = { 1 };
   int16_t expected[] = { 0 };
   test_rebase(-2, input, 1, 10, expected, 0);
}

void test_invalid_positive_digit(void)
{
   int16_t input[] = { 1, 2, 1, 0, 1, 0 };
   int16_t expected[] = { 0 };
   test_rebase(2, input, 6, 10, expected, 0);
}

void test_second_base_is_one(void)
{
   int16_t input[] = { 1, 0, 1, 0, 1, 0 };
   int16_t expected[] = { 0 };
   test_rebase(2, input, 6, 1, expected, 0);
}

void test_second_base_is_zero(void)
{
   int16_t input[] = { 7 };
   int16_t expected[] = { 0 };
   test_rebase(10, input, 1, 0, expected, 0);
}

void test_second_base_is_negative(void)
{
   int16_t input[] = { 1 };
   int16_t expected[] = { 0 };
   test_rebase(2, input, 1, -7, expected, 0);
}

void test_both_bases_are_negative(void)
{
   int16_t input[] = { 1 };
   int16_t expected[] = { 0 };
   test_rebase(-2, input, 1, -7, expected, 0);
}

int main(void)
{
   UnityBegin("test/test_all_your_base.c");

   RUN_TEST(test_single_bit_to_decimal);
   RUN_TEST(test_binary_to_single_decimal);
   RUN_TEST(test_single_decimal_to_binary);
   RUN_TEST(test_binary_to_multiple_decimal);
   RUN_TEST(test_trinary_to_hex);
   RUN_TEST(test_hex_to_trinary);
   RUN_TEST(test_15_bit_integer);
   RUN_TEST(test_single_zero);
   RUN_TEST(test_multiple_zeros);
   RUN_TEST(test_leading_zeros);
   RUN_TEST(test_first_base_is_one);
   RUN_TEST(test_first_base_is_zero);
   RUN_TEST(test_first_base_is_negative);
   RUN_TEST(test_negative_digit);
   RUN_TEST(test_invalid_positive_digit);
   RUN_TEST(test_second_base_is_one);
   RUN_TEST(test_second_base_is_zero);
   RUN_TEST(test_second_base_is_negative);
   RUN_TEST(test_both_bases_are_negative);

   UnityEnd();
   return 0;
}
