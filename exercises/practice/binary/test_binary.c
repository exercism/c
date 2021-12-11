#include "test-framework/unity.h"
#include "binary.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_binary_0_is_decimal_0(void)
{
   TEST_ASSERT_EQUAL(0, convert("0"));
}

static void test_binary_1_is_decimal_1(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL(1, convert("1"));
}

static void test_binary_10_is_decimal_2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(2, convert("10"));
}

static void test_binary_11_is_decimal_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(3, convert("11"));
}

static void test_binary_100_is_decimal_4(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(4, convert("100"));
}

static void test_binary_1001_is_decimal_9(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(9, convert("1001"));
}

static void test_binary_11010_is_decimal_26(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(26, convert("11010"));
}

static void test_binary_10001101000_is_decimal_1128(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1128, convert("10001101000"));
}

static void test_binary_ignores_leading_zeros(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(31, convert("000011111"));
}

static void test_2_is_not_a_valid_binary_digit(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("2"));
}

static void test_a_number_containing_a_non_binary_digit_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("01201"));
}

static void test_a_number_with_trailing_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("10nope"));
}

static void test_a_number_with_leading_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("nope10"));
}

static void test_a_number_with_internal_non_binary_characters_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("10nope10"));
}

static void test_a_number_and_a_word_whitespace_separated_is_invalid(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(INVALID, convert("001 nope"));
}

int main(void)
{
   UnityBegin("test_binary.c");

   RUN_TEST(test_binary_0_is_decimal_0);
   RUN_TEST(test_binary_1_is_decimal_1);
   RUN_TEST(test_binary_10_is_decimal_2);
   RUN_TEST(test_binary_11_is_decimal_3);
   RUN_TEST(test_binary_100_is_decimal_4);
   RUN_TEST(test_binary_1001_is_decimal_9);
   RUN_TEST(test_binary_11010_is_decimal_26);
   RUN_TEST(test_binary_10001101000_is_decimal_1128);
   RUN_TEST(test_binary_ignores_leading_zeros);
   RUN_TEST(test_2_is_not_a_valid_binary_digit);
   RUN_TEST(test_a_number_containing_a_non_binary_digit_is_invalid);
   RUN_TEST(test_a_number_with_trailing_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_with_leading_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_with_internal_non_binary_characters_is_invalid);
   RUN_TEST(test_a_number_and_a_word_whitespace_separated_is_invalid);

   return UnityEnd();
}
