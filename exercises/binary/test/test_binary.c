#include "vendor/unity.h"
#include "../src/binary.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_b0_is_decimal_0(void)
{
   TEST_ASSERT_EQUAL(0, convert("0"));
}

void test_b1_is_decimal_1(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL(1, convert("1"));
}

void test_b10_is_decimal_2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(2, convert("10"));
}

void test_b11_is_decimal_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(3, convert("11"));
}

void test_b100_is_decimal_4(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(4, convert("100"));
}

void test_b1001_is_decimal_9(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(9, convert("1001"));
}

void test_b10001101000_is_decimal_1128(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1128, convert("10001101000"));
}

void test_b11010_is_decimal_26(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(26, convert("11010"));
}

void test_binary_ignores_leading_zeros(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(31, convert("00000000011111"));
}

void test_2_is_not_a_valid_binary_digit(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("2"));
}

void test_a_number_containing_a_non_binary_digit_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("1002001"));
}

void test_a_number_with_trailing_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("10nope"));
}

void test_a_number_with_leading_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("nope10"));
}

void test_a_number_with_internal_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("10nope10"));
}

void test_a_number_and_a_word_whitespace_spearated_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("001 nope"));
}

int main(void)
{
   UnityBegin("test/test_binary.c");
   RUN_TEST(test_b0_is_decimal_0);
   RUN_TEST(test_b1_is_decimal_1);
   RUN_TEST(test_b10_is_decimal_2);
   RUN_TEST(test_b11_is_decimal_3);
   RUN_TEST(test_b100_is_decimal_4);
   RUN_TEST(test_b1001_is_decimal_9);
   RUN_TEST(test_b11010_is_decimal_26);
   RUN_TEST(test_b10001101000_is_decimal_1128);
   RUN_TEST(test_binary_ignores_leading_zeros);
   RUN_TEST(test_2_is_not_a_valid_binary_digit);
   RUN_TEST(test_a_number_containing_a_non_binary_digit_is_invalid);
   RUN_TEST(test_a_number_with_trailing_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_with_leading_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_with_internal_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_and_a_word_whitespace_spearated_is_invalid);
   UnityEnd();
   return 0;
}
