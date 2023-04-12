#include "test-framework/unity.h"
#include "largest_series_product.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_finds_the_largest_product_if_span_equals_length(void)
{
   TEST_ASSERT_EQUAL(18, largest_series_product("29", 2));
}

static void test_can_find_the_largest_product_of_2_with_numbers_in_order(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL(72, largest_series_product("0123456789", 2));
}

static void test_can_find_the_largest_product_of_2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(48, largest_series_product("576802143", 2));
}

static void test_can_find_the_largest_product_of_3_with_numbers_in_order(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(504, largest_series_product("0123456789", 3));
}

static void test_can_find_the_largest_product_of_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(270, largest_series_product("1027839564", 3));
}

static void test_can_find_the_largest_product_of_5_with_numbers_in_order(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(15120, largest_series_product("0123456789", 5));
}

static void test_can_get_the_largest_product_of_a_big_number(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(
       23520, largest_series_product(
                  "73167176531330624919225119674426574742355349194934", 6));
}

static void test_reports_zero_if_the_only_digits_are_zero(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, largest_series_product("0000", 2));
}

static void test_reports_zero_if_all_spans_include_zero(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, largest_series_product("99099", 3));
}

static void test_rejects_span_longer_than_string_length(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, largest_series_product("123", 4));
}

static void test_rejects_empty_string_and_nonzero_span(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, largest_series_product("", 1));
}

static void test_rejects_invalid_character_in_digits(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, largest_series_product("123a5", 2));
}

static void test_rejects_negative_span(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, largest_series_product("12345", -1));
}

int main(void)
{
   UnityBegin("test_largest_series_product.c");

   RUN_TEST(test_finds_the_largest_product_if_span_equals_length);
   RUN_TEST(test_can_find_the_largest_product_of_2_with_numbers_in_order);
   RUN_TEST(test_can_find_the_largest_product_of_2);
   RUN_TEST(test_can_find_the_largest_product_of_3_with_numbers_in_order);
   RUN_TEST(test_can_find_the_largest_product_of_3);
   RUN_TEST(test_can_find_the_largest_product_of_5_with_numbers_in_order);
   RUN_TEST(test_can_get_the_largest_product_of_a_big_number);
   RUN_TEST(test_reports_zero_if_the_only_digits_are_zero);
   RUN_TEST(test_reports_zero_if_all_spans_include_zero);
   RUN_TEST(test_rejects_span_longer_than_string_length);
   RUN_TEST(test_rejects_empty_string_and_nonzero_span);
   RUN_TEST(test_rejects_invalid_character_in_digits);
   RUN_TEST(test_rejects_negative_span);

   return UnityEnd();
}
