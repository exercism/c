#include "vendor/unity.h"
#include "../src/palindrome.h"

// palindromeFactors tests
void test_palindromes_list(void)
{
   PalindromeProduct *palind = getPalindromeProduct(1, 9);
   /* smallest palindrome */
   TEST_ASSERT_EQUAL_INT(1, palind[0].palindrome);
   TEST_ASSERT_EQUAL_INT(1, palind[0].factors[0].a);
   TEST_ASSERT_EQUAL_INT(1, palind[0].factors[0].b);
   /* largest palindrome */
   TEST_ASSERT_EQUAL_INT(9, palind[1].palindrome);
   TEST_ASSERT_EQUAL_INT(1, palind[1].factors[0].a);
   TEST_ASSERT_EQUAL_INT(9, palind[1].factors[0].b);
}

int main(void)
{
   UnityBegin("test/test_space_age.c");
   RUN_TEST(test_palindromes_list);
   UnityEnd();
   return 0;
}
