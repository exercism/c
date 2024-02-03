#include "test-framework/unity.h"
#include "eliuds_eggs.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_0_eggs(void)
{
   const unsigned int expected = 0;
   TEST_ASSERT_EQUAL_UINT(expected, egg_count(0));
}

static void test_1_eggs(void)
{
   TEST_IGNORE();
   const unsigned int expected = 1;
   TEST_ASSERT_EQUAL_UINT(expected, egg_count(16));
}

static void test_4_eggs(void)
{
   TEST_IGNORE();
   const unsigned int expected = 4;
   TEST_ASSERT_EQUAL_UINT(expected, egg_count(89));
}

static void test_13_eggs(void)
{
   TEST_IGNORE();
   const unsigned int expected = 13;
   TEST_ASSERT_EQUAL_UINT(expected, egg_count(2000000000));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_0_eggs);
   RUN_TEST(test_1_eggs);
   RUN_TEST(test_4_eggs);
   RUN_TEST(test_13_eggs);

   return UNITY_END();
}
