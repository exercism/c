#include "vendor/unity.h"
#include <stddef.h>
#include <stdint.h>
#include "../src/all_your_base.h"

#include <stdio.h>

#define LENGTH(A) (sizeof(A)/sizeof(A[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

void copy_array(int8_t src[], int8_t dest[DIGITS_ARRAY_SIZE], size_t n)
{
   if (n > DIGITS_ARRAY_SIZE)
      return;
   for (size_t i = 0; i < n; ++i)
      dest[i] = src[i];
}

void test_rebase(int16_t input_base, int8_t input_digits[],
                 size_t input_length, int16_t output_base,
                 int8_t expected_digits[], size_t expected_length)
{
   int8_t digits[DIGITS_ARRAY_SIZE] = { 0 };
   int8_t ex_digits[DIGITS_ARRAY_SIZE] = { 0 };

   copy_array(input_digits, digits, input_length);
   copy_array(expected_digits, ex_digits, expected_length);

   size_t actual_length = rebase(digits, input_base, output_base, input_length);

   TEST_ASSERT_EQUAL_INT32(expected_length, actual_length);

   if (expected_length > 0)
      TEST_ASSERT_EQUAL_INT8_ARRAY(ex_digits, digits, expected_length);
}

void test_single_bit_to_decimal(void)
{
   int8_t input[] = { 1 };
   int8_t expected[] = { 1 };
   test_rebase(2, input, LENGTH(input), 10, expected, LENGTH(expected));
}

void test_binary_to_single_decimal(void)
{
   TEST_IGNORE();               // delete this line to run test
   int8_t input[] = { 1, 0, 1 };
   int8_t expected[] = { 5 };
   test_rebase(2, input, LENGTH(input), 10, expected, LENGTH(expected));
}

void test_single_decimal_to_binary(void)
{
   TEST_IGNORE();
   int8_t input[] = { 5 };
   int8_t expected[] = { 1, 0, 1 };
   test_rebase(10, input, LENGTH(input), 2, expected, LENGTH(expected));
}

void test_binary_to_multiple_decimal(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1, 0, 1, 0, 1, 0 };
   int8_t expected[] = { 4, 2 };
   test_rebase(2, input, LENGTH(input), 10, expected, LENGTH(expected));
}

void test_decimal_to_binary(void)
{
   TEST_IGNORE();
   int8_t input[] = { 4, 2 };
   int8_t expected[] = { 1, 0, 1, 0, 1, 0 };
   test_rebase(10, input, LENGTH(input), 2, expected, LENGTH(expected));
}

void test_trinary_to_hex(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1, 1, 2, 0 };
   int8_t expected[] = { 2, 10 };
   test_rebase(3, input, LENGTH(input), 16, expected, LENGTH(expected));
}

void test_hex_to_trinary(void)
{
   TEST_IGNORE();
   int8_t input[] = { 2, 10 };
   int8_t expected[] = { 1, 1, 2, 0 };
   test_rebase(16, input, LENGTH(input), 3, expected, LENGTH(expected));
}

void test_15_bit_integer(void)
{
   TEST_IGNORE();
   int8_t input[] = { 3, 46, 60 };
   int8_t expected[] = { 6, 10, 45 };
   test_rebase(97, input, LENGTH(input), 73, expected, LENGTH(expected));
}

void test_single_zero(void)
{
   TEST_IGNORE();
   int8_t input[] = { 0 };
   int8_t expected[] = { 0 };
   test_rebase(2, input, LENGTH(input), 10, expected, 0);
}

void test_multiple_zeros(void)
{
   TEST_IGNORE();
   int8_t input[] = { 0, 0, 0 };
   int8_t expected[] = { 0 };
   test_rebase(10, input, LENGTH(input), 2, expected, 0);
}

void test_leading_zeros(void)
{
   TEST_IGNORE();
   int8_t input[] = { 0, 6, 0 };
   int8_t expected[] = { 0 };
   test_rebase(7, input, LENGTH(input), 10, expected, 0);
}

void test_first_base_is_one(void)
{
   TEST_IGNORE();
   int8_t input[] = { 0 };
   int8_t expected[] = { 0 };
   test_rebase(1, input, LENGTH(input), 10, expected, 0);
}

void test_first_base_is_zero(void)
{
   TEST_IGNORE();
   int8_t input[] = { 0 };
   int8_t expected[] = { 0 };
   test_rebase(0, input, LENGTH(input), 10, expected, 0);
}

void test_first_base_is_negative(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1 };
   int8_t expected[] = { 0 };
   test_rebase(-2, input, LENGTH(input), 10, expected, 0);
}

void test_negative_digit(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1, -1, 1, 0, 1, 0 };
   int8_t expected[] = { 0 };
   test_rebase(2, input, LENGTH(input), 10, expected, 0);
}

void test_invalid_positive_digit(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1, 2, 1, 0, 1, 0 };
   int8_t expected[] = { 0 };
   test_rebase(2, input, LENGTH(input), 10, expected, 0);
}

void test_second_base_is_one(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1, 0, 1, 0, 1, 0 };
   int8_t expected[] = { 0 };
   test_rebase(2, input, LENGTH(input), 1, expected, 0);
}

void test_second_base_is_zero(void)
{
   TEST_IGNORE();
   int8_t input[] = { 7 };
   int8_t expected[] = { 0 };
   test_rebase(10, input, LENGTH(input), 0, expected, 0);
}

void test_second_base_is_negative(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1 };
   int8_t expected[] = { 0 };
   test_rebase(2, input, LENGTH(input), -7, expected, 0);
}

void test_both_bases_are_negative(void)
{
   TEST_IGNORE();
   int8_t input[] = { 1 };
   int8_t expected[] = { 0 };
   test_rebase(-2, input, LENGTH(input), -7, expected, 0);
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
