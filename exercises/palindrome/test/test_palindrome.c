#include "vendor/unity.h"
#include "../src/palindrome.h"

// isPalindrome tests
void test_palindrome_even(void)
{
   TEST_ASSERT_EQUAL_INT(0, isPalindrome(91, 99));
}

void test_palindrome_even_fail(void)
{
   TEST_ASSERT_EQUAL_INT(1, isPalindrome(5, 7));
}

void test_palindrome_odd(void)
{
   TEST_ASSERT_EQUAL_INT(0, isPalindrome(11, 11));
}

void test_palindrome_odd_fail(void)
{
   TEST_ASSERT_EQUAL_INT(1, isPalindrome(10, 12));
}

// palindromeFactors tests
void test_palindromes_list(void)
{

   PalindromeProduct *palind = getPalindromeProduct(1, 9);

   TEST_ASSERT_EQUAL_INT(1, palind[0].palindrome);
   TEST_ASSERT_EQUAL_INT(1, palind[0].factors[0].a);
   TEST_ASSERT_EQUAL_INT(1, palind[0].factors[0].b);

   TEST_ASSERT_EQUAL_INT(9, palind[1].palindrome);
   TEST_ASSERT_EQUAL_INT(1, palind[1].factors[0].a);
   TEST_ASSERT_EQUAL_INT(9, palind[1].factors[0].b);
}

int main(void)
{
   UnityBegin("test/test_space_age.c");
   RUN_TEST(test_palindrome_even);
   RUN_TEST(test_palindrome_even_fail);
   RUN_TEST(test_palindrome_odd);
   RUN_TEST(test_palindrome_odd_fail);
   RUN_TEST(test_palindromes_list);
   UnityEnd();
   return 0;
}
