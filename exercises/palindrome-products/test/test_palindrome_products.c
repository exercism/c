#include "vendor/unity.h"
#include "../src/palindrome_products.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_palindromes_list(void)
{
   product_t product = get_palindrome_product(1, 9);
   TEST_ASSERT_EQUAL_INT(1, product.smallest);
   TEST_ASSERT_EQUAL_INT(9, product.largest);
}

void test_palindromes_list2(void)
{
   TEST_IGNORE();               // delete this line to run test
   product_t product = get_palindrome_product(10, 99);
   TEST_ASSERT_EQUAL_INT(121, product.smallest);
   TEST_ASSERT_EQUAL_INT(9009, product.largest);
}

int main(void)
{
   UnityBegin("test/test_palindrome_products.c");

   RUN_TEST(test_palindromes_list);
   RUN_TEST(test_palindromes_list2);

   UnityEnd();
   return 0;
}
