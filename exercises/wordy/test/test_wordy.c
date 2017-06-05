#include "vendor/unity.h"
#include "../src/wordy.h"

void test_addition(void)
{
   TEST_ASSERT_EQUAL(2, wordy("What is 1 plus 1?"));
}

void test_more_addition(void)
{
   TEST_ASSERT_EQUAL(55, wordy("What is 53 plus 2?"));
}

void test_addition_with_negative_numbers(void)
{
   TEST_ASSERT_EQUAL(-11, wordy("What is -1 plus -10?"));
}

void test_large_addition(void)
{
   TEST_ASSERT_EQUAL(45801, wordy("What is 123 plus 45678?"));
}

void test_subtraction(void)
{
   TEST_ASSERT_EQUAL(16, wordy("What is 4 minus -12?"));
}

void test_multiplication(void)
{
   TEST_ASSERT_EQUAL(-75, wordy("What is -3 multiplied by 25?"));
}

void test_division(void)
{
   TEST_ASSERT_EQUAL(-11, wordy("What is 33 divided by -3?"));
}

void test_addition_and_subtraction(void)
{
   TEST_ASSERT_EQUAL(8, wordy("What is 1 plus 5 minus -2?"));
}

void test_multiple_subtraction(void)
{
   TEST_ASSERT_EQUAL(3, wordy("What is 20 minus 4 minus 13?"));
}

void test_subtraction_then_addition(void)
{
   TEST_ASSERT_EQUAL(14, wordy("What is 17 minus 6 plus 3?"));
}

void test_multiple_multiplication(void)
{
   TEST_ASSERT_EQUAL(-12, wordy("What is 2 multiplied by -2 multiplied by 3?"));
}

void test_addition_and_multiplication(void)
{
   TEST_ASSERT_EQUAL(-8, wordy("What is -3 plus 7 multiplied by -2?"));
}

void test_multiple_division(void)
{
   TEST_ASSERT_EQUAL(2, wordy("What is -12 divided by 2 divided by -3?"));
}

void test_unknown_operation(void)
{
   TEST_ASSERT_EQUAL(NULL, wordy("What is 52 cubed?"));
}

void test_non_math_question(void)
{
   TEST_ASSERT_EQUAL(NULL, wordy("Who is the President of the United States?"));
}

void test_handle_exponentials(void)
{
   TEST_ASSERT_EQUAL(32, wordy("What is 2 raised to the 5th?"));
}

int main()
{
   UnityBegin("test/test_wordy.c");
   RUN_TEST(test_addition);
   RUN_TEST(test_more_addition);
   RUN_TEST(test_addition_with_negative_numbers);
   RUN_TEST(test_large_addition);
   RUN_TEST(test_subtraction);
   RUN_TEST(test_multiplication);
   RUN_TEST(test_division);
   RUN_TEST(test_addition_and_subtraction);
   RUN_TEST(test_multiple_subtraction);
   RUN_TEST(test_subtraction_then_addition);
   RUN_TEST(test_multiple_multiplication);
   RUN_TEST(test_addition_and_multiplication);
   RUN_TEST(test_multiple_division);
   RUN_TEST(test_unknown_operation);
   RUN_TEST(test_non_math_question);
   RUN_TEST(test_handle_exponentials);
   UnityEnd();
}
