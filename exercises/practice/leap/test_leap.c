#include "test-framework/unity.h"
#include "leap.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_year_not_divisible_by_4_in_common_year(void)
{
   TEST_ASSERT_FALSE(leap_year(2015));
}

static void test_year_divisible_by_2_not_divisible_by_4_in_common_year(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FALSE(leap_year(1970));
}

static void test_year_divisible_by_4_not_divisible_by_100_in_leap_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(leap_year(1996));
}

static void test_year_divisible_by_4_and_5_is_still_a_leap_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(leap_year(1960));
}

static void test_year_divisible_by_100_not_divisible_by_400_in_common_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(leap_year(2100));
}

static void
test_year_divisible_by_100_but_not_by_3_is_still_not_a_leap_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(leap_year(1900));
}

static void test_year_divisible_by_400_in_leap_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(leap_year(2000));
}

static void test_year_divisible_by_400_but_not_by_125_is_still_a_leap_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(leap_year(2400));
}

static void test_year_divisible_by_200_not_divisible_by_400_in_common_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(leap_year(1800));
}

int main(void)
{
   UnityBegin("test_leap.c");

   RUN_TEST(test_year_not_divisible_by_4_in_common_year);
   RUN_TEST(test_year_divisible_by_2_not_divisible_by_4_in_common_year);
   RUN_TEST(test_year_divisible_by_4_not_divisible_by_100_in_leap_year);
   RUN_TEST(test_year_divisible_by_4_and_5_is_still_a_leap_year);
   RUN_TEST(test_year_divisible_by_100_not_divisible_by_400_in_common_year);
   RUN_TEST(test_year_divisible_by_100_but_not_by_3_is_still_not_a_leap_year);
   RUN_TEST(test_year_divisible_by_400_in_leap_year);
   RUN_TEST(test_year_divisible_by_400_but_not_by_125_is_still_a_leap_year);
   RUN_TEST(test_year_divisible_by_200_not_divisible_by_400_in_common_year);

   return UnityEnd();
}
