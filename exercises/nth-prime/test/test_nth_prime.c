#include "vendor/unity.h"
#include "../src/nth_prime.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_first_prime(void)
{
   TEST_ASSERT_EQUAL_UINT32(2, nth(1));
}

static void test_second_prime(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL_UINT32(3, nth(2));
}

static void test_sixth_prime(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT32(13, nth(6));
}

static void test_large_prime(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT32(104743, nth(10001));
}

static void test_weird_case(void)
{
   TEST_IGNORE();
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

   return UnityEnd();
}
