#include "test-framework/unity.h"
#include "collatz_conjecture.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_zero_steps_for_one(void)
{
   TEST_ASSERT_EQUAL(0, steps(1));
}

static void test_divide_if_even(void)
{
   TEST_ASSERT_EQUAL(4, steps(16));
}

static void test_even_and_odd_steps(void)
{
   TEST_ASSERT_EQUAL(9, steps(12));
}

static void test_large_number_of_even_and_odd_steps(void)
{
   TEST_ASSERT_EQUAL(152, steps(1000000));
}

static void test_zero_is_an_error(void)
{
   TEST_ASSERT_EQUAL(ERROR_VALUE, steps(0));
}

static void test_negative_value_is_an_error(void)
{
   TEST_ASSERT_EQUAL(ERROR_VALUE, steps(-15));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_zero_steps_for_one);
   RUN_TEST(test_divide_if_even);
   RUN_TEST(test_even_and_odd_steps);
   RUN_TEST(test_large_number_of_even_and_odd_steps);
   RUN_TEST(test_zero_is_an_error);
   RUN_TEST(test_negative_value_is_an_error);

   return UNITY_END();
}
