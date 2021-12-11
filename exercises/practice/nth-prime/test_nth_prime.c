#include "test-framework/unity.h"
#include "nth_prime.h"

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
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL_UINT32(3, nth(2));
}

static void test_sixth_prime(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT32(13, nth(6));
}

static void test_big_prime(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT32(104743, nth(10001));
}

static void test_there_is_no_zeroth_prime(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT32(0, nth(0));
}

int main(void)
{
   UnityBegin("test_nth_prime.c");

   RUN_TEST(test_first_prime);
   RUN_TEST(test_second_prime);
   RUN_TEST(test_sixth_prime);
   RUN_TEST(test_big_prime);
   RUN_TEST(test_there_is_no_zeroth_prime);

   return UnityEnd();
}
