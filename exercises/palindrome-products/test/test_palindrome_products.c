#include "vendor/unity.h"
#include "../src/palindrome_products.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void check_factors(factor_t * actual, int depth, factor_t expected[])
{
   if (depth == 0) {
      TEST_ASSERT_EQUAL_PTR(NULL, actual);
      return;
   }
   int i;
   int count_ok = 0;
   for (i = 0; i < depth; i++) {
      if (actual == NULL)
         break;
      if ((actual->factor_a == expected[i].factor_a) &&
          (actual->factor_b == expected[i].factor_b))
         count_ok++;
      actual = actual->next;
   }
   TEST_ASSERT_EQUAL_PTR(NULL, actual);
   TEST_ASSERT_EQUAL_INT(depth, count_ok);
}

void test_smallest_palindrome_from_single_digit_factors(void)
{
   product_t *product = get_palindrome_product(1, 9);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(1, product->smallest);

   factor_t expected_sm[] = { {1, 1, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

void test_largest_palindrome_from_single_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(1, 9);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(9, product->largest);

   factor_t expected_lg[] = { {3, 3, NULL}, {1, 9, NULL} };
   check_factors(product->factors_lg, 2, expected_lg);

   free_product(product);
}

void test_smallest_palindrome_from_double_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(10, 99);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(121, product->smallest);

   factor_t expected_sm[] = { {11, 11, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

void test_largest_palindrome_from_double_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(10, 99);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(9009, product->largest);

   factor_t expected_lg[] = { {91, 99, NULL} };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_smallest_palindrome_from_triple_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(100, 999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(10201, product->smallest);

   factor_t expected_sm[] = { {101, 101, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

void test_largest_palindrome_from_triple_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(100, 999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(906609, product->largest);

   factor_t expected_lg[] = { {913, 993, NULL} };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_smallest_palindrome_from_four_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(1000, 9999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(1002001, product->smallest);

   factor_t expected_sm[] = { {1001, 1001, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

void test_largest_palindrome_from_four_digit_factors(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(1000, 9999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(99000099, product->largest);

   factor_t expected_lg[] = { {9901, 9999, NULL} };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_empty_result_for_smallest_if_no_palindrome_in_the_range(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(1002, 1003);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected =
       "no palindrome with factors in the range 1002 to 1003";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

void test_empty_result_for_largest_if_no_palindrome_in_the_range(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(15, 15);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "no palindrome with factors in the range 15 to 15";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

void test_error_result_for_smallest_if_min_is_more_than_max(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(10000, 1);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "invalid input: min is 10000 and max is 1";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

void test_error_result_for_largest_if_min_is_more_than_max(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t *product = get_palindrome_product(2, 1);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "invalid input: min is 2 and max is 1";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

int main(void)
{
   UnityBegin("test/test_palindrome_products.c");

   RUN_TEST(test_smallest_palindrome_from_single_digit_factors);
   RUN_TEST(test_largest_palindrome_from_single_digit_factors);

   RUN_TEST(test_smallest_palindrome_from_double_digit_factors);
   RUN_TEST(test_largest_palindrome_from_double_digit_factors);

   RUN_TEST(test_smallest_palindrome_from_triple_digit_factors);
   RUN_TEST(test_largest_palindrome_from_triple_digit_factors);

   RUN_TEST(test_smallest_palindrome_from_four_digit_factors);
   RUN_TEST(test_largest_palindrome_from_four_digit_factors);

   RUN_TEST(test_empty_result_for_smallest_if_no_palindrome_in_the_range);
   RUN_TEST(test_empty_result_for_largest_if_no_palindrome_in_the_range);

   RUN_TEST(test_error_result_for_smallest_if_min_is_more_than_max);
   RUN_TEST(test_error_result_for_largest_if_min_is_more_than_max);

   UnityEnd();
   return 0;
}
