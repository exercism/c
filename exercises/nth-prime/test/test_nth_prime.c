#include "vendor/unity.h"
#include "../src/nth_prime.h"

void test_first_prime(void)
{
   TEST_ASSERT_EQUAL_UINT32(2, nth(1));
}

void test_second_prime(void)
{
   TEST_ASSERT_EQUAL_UINT32(3, nth(2));
}

void test_sixth_prime(void)
{
   TEST_ASSERT_EQUAL_UINT32(13, nth(6));
}

void test_large_prime(void)
{
   TEST_ASSERT_EQUAL_UINT32(104743, nth(10001));
}

void test_weird_case(void)
{
   TEST_ASSERT_EQUAL_UINT32(0, nth(0));
}

int main(void)
{
   UnityBegin("test/test_nth_prime.c");

   RUN_TEST(test_first_prime);
   RUN_TEST(test_second_prime);
   RUN_TEST(test_sixth_prime);
   RUN_TEST(test_large_prime);
   RUN_TEST(test_weird_case);

   UnityEnd();
   return 0;
}
