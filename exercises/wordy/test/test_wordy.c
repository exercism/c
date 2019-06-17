#include "vendor/unity.h"
#include "../src/wordy.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_answer_addition(void)
{
   const char *question = "What is 1 plus 1?";
   const int expected = 2;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_more_addition(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char *question = "What is 53 plus 2?";
   const int expected = 55;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_addition_with_negative_numbers(void)
{
   TEST_IGNORE();
   const char *question = "What is -1 plus -10?";
   const int expected = -11;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_large_addition(void)
{
   TEST_IGNORE();
   const char *question = "What is 123 plus 45678?";
   const int expected = 45801;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_subtraction(void)
{
   TEST_IGNORE();
   const char *question = "What is 4 minus -12?";
   const int expected = 16;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_multiplication(void)
{
   TEST_IGNORE();
   const char *question = "What is -3 multiplied by 25?";
   const int expected = -75;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_division(void)
{
   TEST_IGNORE();
   const char *question = "What is 33 divided by -3?";
   const int expected = -11;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_multiple_additions(void)
{
   TEST_IGNORE();
   const char *question = "What is 1 plus 1 plus 1?";
   const int expected = 3;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_addition_and_subtraction(void)
{
   TEST_IGNORE();
   const char *question = "What is 1 plus 5 minus -2?";
   const int expected = 8;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_multiple_subtraction(void)
{
   TEST_IGNORE();
   const char *question = "What is 20 minus 4 minus 13?";
   const int expected = 3;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_subtraction_then_addition(void)
{
   TEST_IGNORE();
   const char *question = "What is 17 minus 6 plus 3?";
   const int expected = 14;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_multiple_multiplication(void)
{
   TEST_IGNORE();
   const char *question = "What is 2 multiplied by -2 multiplied by 3?";
   const int expected = -12;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_addition_and_multiplication(void)
{
   TEST_IGNORE();
   const char *question = "What is -3 plus 7 multiplied by -2?";
   const int expected = -8;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_multiple_division(void)
{
   TEST_IGNORE();
   const char *question = "What is -12 divided by 2 divided by -3?";
   const int expected = 2;
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_TRUE(success);
   TEST_ASSERT_EQUAL_INT(expected, result);
}

static void test_answer_unknown_operation(void)
{
   TEST_IGNORE();
   const char *question = "What is 52 cubed?";
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_FALSE(success);
}

static void test_answer_non_math_question(void)
{
   TEST_IGNORE();
   const char *question = "Who is the President of the United States?";
   int result;
   bool success = answer(question, &result);
   TEST_ASSERT_FALSE(success);
}

int main(void)
{
   UnityBegin("test/test_wordy.c");

   RUN_TEST(test_answer_addition);
   RUN_TEST(test_answer_more_addition);
   RUN_TEST(test_answer_addition_with_negative_numbers);
   RUN_TEST(test_answer_large_addition);
   RUN_TEST(test_answer_subtraction);
   RUN_TEST(test_answer_multiplication);
   RUN_TEST(test_answer_division);
   RUN_TEST(test_answer_multiple_additions);
   RUN_TEST(test_answer_addition_and_subtraction);
   RUN_TEST(test_answer_multiple_subtraction);
   RUN_TEST(test_answer_subtraction_then_addition);
   RUN_TEST(test_answer_multiple_multiplication);
   RUN_TEST(test_answer_addition_and_multiplication);
   RUN_TEST(test_answer_multiple_division);
   RUN_TEST(test_answer_unknown_operation);
   RUN_TEST(test_answer_non_math_question);

   return UnityEnd();
}
