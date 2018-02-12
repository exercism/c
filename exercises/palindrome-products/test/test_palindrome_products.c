#include "vendor/unity.h"
#include "../src/palindrome_products.h"

product_t *product;

void setUp(void)
{
}

void tearDown(void)
{
}

void check_factors(factor_t * actual, int depth, factor_t expected[])
{
   if (depth == 0) {
      TEST_ASSERT_EQUAL_INT(actual, 0);
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
   TEST_ASSERT_EQUAL_INT(count_ok, depth);
}

void test_palindromes_simple_case(void)
{
   product = get_palindrome_product(1, 9);
   TEST_ASSERT_EQUAL_INT(1, product->smallest);
   TEST_ASSERT_EQUAL_INT(9, product->largest);

   factor_t expected_sm[] = { {1, 1, NULL} };
   factor_t expected_lg[] = { {3, 3, NULL}, {1, 9, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);
   check_factors(product->factors_lg, 2, expected_lg);

   free_product(product);
}

void test_palindromes_case2(void)
{
   TEST_IGNORE();               // delete this line to run test
   product = get_palindrome_product(10, 99);
   TEST_ASSERT_EQUAL_INT(121, product->smallest);
   TEST_ASSERT_EQUAL_INT(9009, product->largest);

   factor_t expected_sm[] = { {11, 11, NULL} };
   factor_t expected_lg[] = { {91, 99, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_palindromes_case3(void)
{
   TEST_IGNORE();               // delete this line to run test
   product = get_palindrome_product(123, 234);
   TEST_ASSERT_EQUAL_INT(18081, product->smallest);
   TEST_ASSERT_EQUAL_INT(52425, product->largest);

   factor_t expected_sm[] = { {123, 147, NULL} };
   factor_t expected_lg[] = { {225, 233, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_palindromes_one_minus(void)
{
   TEST_IGNORE();               // delete this line to run test
   product = get_palindrome_product(-22, 5);
   TEST_ASSERT_EQUAL_INT(-88, product->smallest);
   TEST_ASSERT_EQUAL_INT(323, product->largest);

   factor_t expected_sm[] = { {-22, 4, NULL} };
   factor_t expected_lg[] = { {-19, -17, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_palindromes_both_minus(void)
{
   TEST_IGNORE();               // delete this line to run test
   product = get_palindrome_product(-12, -22);
   TEST_ASSERT_EQUAL_INT(252, product->smallest);
   TEST_ASSERT_EQUAL_INT(323, product->largest);

   factor_t expected_sm[] = { {-18, -14, NULL}, {-21, -12, NULL} };
   factor_t expected_lg[] = { {-19, -17, NULL} };
   check_factors(product->factors_sm, 2, expected_sm);
   check_factors(product->factors_lg, 1, expected_lg);

   free_product(product);
}

void test_palindromes_corner_case(void)
{
   TEST_IGNORE();               // delete this line to run test
   product = get_palindrome_product(123, 145);
   TEST_ASSERT_EQUAL_INT(19591, product->smallest);
   TEST_ASSERT_EQUAL_INT(0, product->largest);

   factor_t expected_sm[] = { {137, 143, NULL} };
   factor_t expected_lg[] = { {0, 0, NULL} };
   check_factors(product->factors_sm, 1, expected_sm);
   check_factors(product->factors_lg, 0, expected_lg);

   free_product(product);
}

int main(void)
{
   UnityBegin("test/test_palindrome_products.c");

   RUN_TEST(test_palindromes_simple_case);
   RUN_TEST(test_palindromes_case2);
   RUN_TEST(test_palindromes_case3);
   RUN_TEST(test_palindromes_one_minus);
   RUN_TEST(test_palindromes_both_minus);
   RUN_TEST(test_palindromes_corner_case);

   UnityEnd();
   return 0;
}
