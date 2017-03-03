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

void test_palindromes_list(void){

  Paire* factors = palindromeFactors(1,9);
  int i, length = sizeof(factors)/sizeof(factors[0]);
  for( i =0; i<length; i++){
    TEST_ASSERT_EQUAL_INT(0,isPalindrome( factors[i].a , factors[i].b ));
  }
  
   TEST_ASSERT_EQUAL_INT(0,isPalindrome( 1, factors[0].a ));
   TEST_ASSERT_EQUAL_INT(0,isPalindrome( 1, factors[0].b ));

   TEST_ASSERT_EQUAL_INT(0,isPalindrome( 1, factors[0].a ));
   TEST_ASSERT_EQUAL_INT(0,isPalindrome( 1, factors[0].b ));
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
