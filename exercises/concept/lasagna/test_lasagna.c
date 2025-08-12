#include "test-framework/unity.h"
#include "lasagna.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_expected_minutes_in_oven(void)
{
   TEST_ASSERT_EQUAL_INT(40, expected_minutes_in_oven);
}

static void test_remaining_minutes_in_oven(void)
{
   TEST_ASSERT_EQUAL_INT(15, remaining_minutes_in_oven(25));
}

static void test_preparation_time_in_oven_for_one_layer(void)
{
   TEST_ASSERT_EQUAL_INT(2, preparation_time_in_minutes(1));
}

static void test_preparation_time_in_minutes_for_multiple_layers(void)
{
   TEST_ASSERT_EQUAL_INT(8, preparation_time_in_minutes(4));
}

static void test_elapsed_time_in_minutes_for_one_layer(void)
{
   TEST_ASSERT_EQUAL_INT(32, elapsed_time_in_minutes(1, 30));
}

static void test_elapsed_time_in_minutes_for_multiple_layers(void)
{
   TEST_ASSERT_EQUAL_INT(16, elapsed_time_in_minutes(4, 8));
}

int main(void)
{
   UnityBegin("test_lucians_luscious_lasagna.c");

   RUN_TEST(test_expected_minutes_in_oven);
   RUN_TEST(test_remaining_minutes_in_oven);
   RUN_TEST(test_preparation_time_in_oven_for_one_layer);
   RUN_TEST(test_preparation_time_in_minutes_for_multiple_layers);
   RUN_TEST(test_elapsed_time_in_minutes_for_one_layer);
   RUN_TEST(test_elapsed_time_in_minutes_for_multiple_layers);

   return UnityEnd();
}