#include "test-framework/unity.h"
#include "palindrome_products.h"

#include <stdbool.h>
#include <stddef.h>

void setUp(void)
{
}

void tearDown(void)
{
}

/* factor_t_are_equal compares the values of the factors
 * that are stored in the passed f1, f2 factor_t structs
 * regardless of their order in the said structs. Returns
 * true if the values are equal, false otherwise.
 *
 *
 * Examples:
 *
 * factor_t_are_equal(&{1, 9}, &{1, 9}) returns true
 * factor_t_are_equal(&{1, 9}, &{9, 1}) returns true
 * factor_t_are_equal(&{1, 9}, &{1, 8}) returns false
 * */
static bool factor_t_are_equal(const factor_t *const f1,
                               const factor_t *const f2)
{
   return ((f1->factor_a == f2->factor_a) && (f1->factor_b == f2->factor_b)) ||
          ((f1->factor_a == f2->factor_b) && (f1->factor_b == f2->factor_a));
}

/* contains_factor checks if the `factor` variable is stored
 * in the `factors` linked-list. The function traverses the
 * `factors` list, until it finds the desired element, in which case
 * it returns true. If the function gets to the end of the list or
 * exceeds the number of checked elements (passed as the `depth` variable),
 * it returns false.
 * */
static bool contains_factor(factor_t *factors, const factor_t *const factor,
                            const size_t depth)
{
   size_t current_depth = 0;
   factor_t *current_factor = factors;
   while ((current_factor != NULL) && (current_depth != depth)) {
      if (factor_t_are_equal(current_factor, factor)) {
         return true;
      }
      current_factor = current_factor->next;
      current_depth += 1;
   }
   return false;
}

/* check_factors checks if all the factor_t elements that are
 * passed in the `expected` variable are present in the `actual`
 * variable that contains a linked list of factor_t elements from
 * the student's solution. For every element of `expected` found in
 * `actual` the `found_count` variable is incremented. In the end
 * `found_count` is compared with the expected number of the found
 * elements passed in the `depth` variable.
 * */
static void check_factors(factor_t *actual, size_t depth, factor_t expected[])
{
   if (depth == 0) {
      TEST_ASSERT_EQUAL_PTR(NULL, actual);
      return;
   }
   int found_count = 0;
   for (size_t i = 0; i < depth; ++i) {
      if (!contains_factor(actual, &expected[i], depth)) {
         break;
      }
      found_count += 1;
   }
   TEST_ASSERT_EQUAL_INT_MESSAGE(
       depth, found_count,
       "Not every expected factor found in the actual result.");
}

static void test_smallest_palindrome_from_single_digit_factors(void)
{
   product_t *product = get_palindrome_product(1, 9);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(1, product->smallest);

   factor_t expected_sm[] = { { 1, 1, NULL } };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

static void test_largest_palindrome_from_single_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(1, 9);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(9, product->largest);

   factor_t expected_lg[] = { { 3, 3, NULL }, { 1, 9, NULL } };
   check_factors(product->factors_lg, 2, expected_lg);

   free_product(product);
}

static void test_smallest_palindrome_from_double_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(10, 99);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(121, product->smallest);

   factor_t expected_sm[] = { { 11, 11, NULL } };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

static void test_largest_palindrome_from_double_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(10, 99);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(9009, product->largest);

   factor_t expected_lg[] = { { 91, 99, NULL } };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

static void test_smallest_palindrome_from_triple_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(100, 999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(10201, product->smallest);

   factor_t expected_sm[] = { { 101, 101, NULL } };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

static void test_largest_palindrome_from_triple_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(100, 999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(906609, product->largest);

   factor_t expected_lg[] = { { 913, 993, NULL } };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

static void test_smallest_palindrome_from_four_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(1000, 9999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(1002001, product->smallest);

   factor_t expected_sm[] = { { 1001, 1001, NULL } };
   check_factors(product->factors_sm, 1, expected_sm);

   free_product(product);
}

static void test_largest_palindrome_from_four_digit_factors(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(1000, 9999);
   TEST_ASSERT_NOT_NULL(product);
   TEST_ASSERT_EQUAL_INT(99000099, product->largest);

   factor_t expected_lg[] = { { 9901, 9999, NULL } };
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

static void test_empty_result_for_smallest_if_no_palindrome_in_the_range(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(1002, 1003);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected =
       "no palindrome with factors in the range 1002 to 1003";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

static void test_empty_result_for_largest_if_no_palindrome_in_the_range(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(15, 15);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "no palindrome with factors in the range 15 to 15";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

static void test_error_result_for_smallest_if_min_is_more_than_max(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(10000, 1);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "invalid input: min is 10000 and max is 1";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

static void test_error_result_for_largest_if_min_is_more_than_max(void)
{
   TEST_IGNORE();   // delete this line to run test
   product_t *product = get_palindrome_product(2, 1);
   TEST_ASSERT_NOT_NULL(product);
   const char *expected = "invalid input: min is 2 and max is 1";
   TEST_ASSERT_EQUAL_STRING(expected, product->error);

   free_product(product);
}

int main(void)
{
   UnityBegin("test_palindrome_products.c");

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

   return UnityEnd();
}
