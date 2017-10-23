#include "../src/collatz_conjecture.h"

#include "vendor/unity.h"

void test_zero_steps_for_one(void)
{
   TEST_ASSERT_EQUAL(0, steps(1));
}

void test_divide_if_even(void)
{
   TEST_ASSERT_EQUAL(4, steps(16));
}

void test_even_and_odd_steps(void)
{
   TEST_ASSERT_EQUAL(9, steps(12));
}

void test_large_number_of_even_and_odd_steps(void)
{
   TEST_ASSERT_EQUAL(152, steps(1000000));
}

void test_zero_is_an_error(void)
{
   TEST_ASSERT_EQUAL(ERROR_VALUE, steps(0));
}

void test_negative_value_is_an_error(void)
{
   TEST_ASSERT_EQUAL(ERROR_VALUE, steps(-15));
}

int main(void)
{
   UnityBegin("collatz_conjecture.c");

   RUN_TEST(test_zero_steps_for_one);
   RUN_TEST(test_divide_if_even);
   RUN_TEST(test_even_and_odd_steps);
   RUN_TEST(test_large_number_of_even_and_odd_steps);
   RUN_TEST(test_zero_is_an_error);
   RUN_TEST(test_negative_value_is_an_error);

   UnityEnd();
   return 0;
}
