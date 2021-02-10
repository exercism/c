#include "test-framework/unity.h"
#include "matching_brackets.h"
#include <stdbool.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_paired_square_brackets(void)
{
   const char *input = "[]";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_empty_string(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char *input = "";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_unpaired_brackets(void)
{
   TEST_IGNORE();
   const char *input = "[[";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_wrong_ordered_brackets(void)
{
   TEST_IGNORE();
   const char *input = "}{";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_wrong_closing_bracket(void)
{
   TEST_IGNORE();
   const char *input = "{]";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_with_whitespace(void)
{
   TEST_IGNORE();
   const char *input = "{ }";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_partially_paired_brackets(void)
{
   TEST_IGNORE();
   const char *input = "{[])";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_simple_nested_brackets(void)
{
   TEST_IGNORE();
   const char *input = "{[]}";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_several_paired_brackets(void)
{
   TEST_IGNORE();
   const char *input = "{}[]";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_paired_and_nested_brackets(void)
{
   TEST_IGNORE();
   const char *input = "([{}({}[])])";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_unopened_closing_brackets(void)
{
   TEST_IGNORE();
   const char *input = "{[)][]}";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_unpaired_and_nested_brackets(void)
{
   TEST_IGNORE();
   const char *input = "([{])";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_and_wrong_nested_brackets(void)
{
   TEST_IGNORE();
   const char *input = "[({]})";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_and_incomplete_brackets(void)
{
   TEST_IGNORE();
   const char *input = "{}[";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_too_many_closing_brackets(void)
{
   TEST_IGNORE();
   const char *input = "[]]";
   TEST_ASSERT_FALSE(is_paired(input));
}

static void test_math_expression(void)
{
   TEST_IGNORE();
   const char *input = "(((185 + 223.85) * 15) - 543)/2";
   TEST_ASSERT_TRUE(is_paired(input));
}

static void test_complex_latex_expression(void)
{
   TEST_IGNORE();
   const char *input =
       "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)";
   TEST_ASSERT_TRUE(is_paired(input));
}

int main(void)
{
   UnityBegin("test_matching_brackets.c");

   RUN_TEST(test_paired_square_brackets);
   RUN_TEST(test_empty_string);
   RUN_TEST(test_unpaired_brackets);
   RUN_TEST(test_wrong_ordered_brackets);
   RUN_TEST(test_wrong_closing_bracket);
   RUN_TEST(test_paired_with_whitespace);
   RUN_TEST(test_partially_paired_brackets);
   RUN_TEST(test_simple_nested_brackets);
   RUN_TEST(test_several_paired_brackets);
   RUN_TEST(test_paired_and_nested_brackets);
   RUN_TEST(test_unopened_closing_brackets);
   RUN_TEST(test_unpaired_and_nested_brackets);
   RUN_TEST(test_paired_and_wrong_nested_brackets);
   RUN_TEST(test_paired_and_incomplete_brackets);
   RUN_TEST(test_too_many_closing_brackets);
   RUN_TEST(test_math_expression);
   RUN_TEST(test_complex_latex_expression);

   return UnityEnd();
}
