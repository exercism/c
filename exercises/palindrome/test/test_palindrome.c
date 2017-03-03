#include "vendor/unity.h"
#include "../src/palindrome.h"


void test_palindrome_even(void){
   TEST_ASSERT_EQUAL_INT(0,isPalindrome(91,99));
}

void test_palindrome_even_fail(void){
   TEST_ASSERT_EQUAL_INT(1,isPalindrome(5,7));
}
void test_palindrome_odd(void){
  TEST_ASSERT_EQUAL_INT(0,isPalindrome(11,11));
}

void test_palindrome_odd_fail(void){
  TEST_ASSERT_EQUAL_INT(1,isPalindrome(10,12));
}


int main(void)
{
   UnityBegin("test/test_space_age.c");
   RUN_TEST(test_palindrome_even);
   RUN_TEST(test_palindrome_even_fail);
   RUN_TEST(test_palindrome_odd);
   RUN_TEST(test_palindrome_odd_fail);
   UnityEnd();
   return 0;
}
