#include "vendor/unity.h"
#include "../src/palindrome_products.h"

void test_palindromes_list(void)
{
   Pair palind = getPalindromeProduct(1, 9);
   TEST_ASSERT_EQUAL_INT(1, palind.small_palind);
   TEST_ASSERT_EQUAL_INT(9, palind.larg_palind);
}

void test_palindromes_list2(void)
{
   TEST_IGNORE();               // delete this line to run test
   Pair palind = getPalindromeProduct(10, 99);
   TEST_ASSERT_EQUAL_INT(121, palind.small_palind);
   TEST_ASSERT_EQUAL_INT(9009, palind.larg_palind);
}

int main(void)
{
   UnityBegin("test/test_palindrome_products.c");
   RUN_TEST(test_palindromes_list);
   RUN_TEST(test_palindromes_list2);
   UnityEnd();
   return 0;
}
