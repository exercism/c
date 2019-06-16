#include "vendor/unity.h"
#include "../src/leap.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_a_known_leap_year(void)
{
   TEST_ASSERT_TRUE(is_leap_year(1996));
}

static void test_any_old_year(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FALSE(is_leap_year(1997));
}

static void test_turn_of_the_20th_century(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_leap_year(1900));
}

static void test_turn_of_the_21st_century(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_leap_year(2000));
}

static void test_turn_of_the_25th_century(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_leap_year(2400));
}

int main(void)
{
   UnityBegin("test/test_leap.c");

   RUN_TEST(test_a_known_leap_year);
   RUN_TEST(test_any_old_year);
   RUN_TEST(test_turn_of_the_20th_century);
   RUN_TEST(test_turn_of_the_21st_century);
   RUN_TEST(test_turn_of_the_25th_century);

   return UnityEnd();
}
