#include "test-framework/unity.h"
#include "flower_field.h"
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_annotate_no_rows(void)
{
   const char **garden = NULL;
   const size_t rows = 0;
   char **actual = annotate(garden, rows);
   TEST_ASSERT_NULL(actual);
}

static void test_annotate_no_columns(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char *garden[] = { "" };
   const char *expected[] = { "" };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_no_flowers(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "   ",
      "   ",
      "   "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "   ",
      "   ",
      "   "
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_garden_full_of_flowers(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "***",
      "***",
      "***"
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "***",
      "***",
      "***"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_flower_surrounded_by_spaces(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "   ",
      " * ",
      "   "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "111",
      "1*1",
      "111"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_space_surrounded_by_flowers(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "***",
      "* *",
      "***"
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "***",
      "*8*",
      "***"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_horizontal_line(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      " * * "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "1*2*1"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_horizontal_line_flowers_at_edges(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "*   *"
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "*1 1*"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_vertical_line(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      " ",
      "*",
      " ",
      "*",
      " "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "1",
      "*",
      "2",
      "*",
      "1"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_vertical_line_flowers_at_edges(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "*",
      " ",
      " ",
      " ",
      "*"
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "*",
      "1",
      " ",
      "1",
      "*"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_cross(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      "  *  ",
      "  *  ",
      "*****",
      "  *  ",
      "  *  "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      " 2*2 ",
      "25*52",
      "*****",
      "25*52",
      " 2*2 "
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

static void test_annotate_large_garden(void)
{
   TEST_IGNORE();
   const char *garden[] = {
      // clang-format off
      " *  * ",
      "  *   ",
      "    * ",
      "   * *",
      " *  * ",
      "      "
      // clang-format on
   };
   const char *expected[] = {
      // clang-format off
      "1*22*1",
      "12*322",
      " 123*2",
      "112*4*",
      "1*22*2",
      "111111"
      // clang-format on
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(garden, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_annotation(actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_annotate_no_rows);
   RUN_TEST(test_annotate_no_columns);
   RUN_TEST(test_annotate_no_flowers);
   RUN_TEST(test_annotate_garden_full_of_flowers);
   RUN_TEST(test_annotate_flower_surrounded_by_spaces);
   RUN_TEST(test_annotate_space_surrounded_by_flowers);
   RUN_TEST(test_annotate_horizontal_line);
   RUN_TEST(test_annotate_horizontal_line_flowers_at_edges);
   RUN_TEST(test_annotate_vertical_line);
   RUN_TEST(test_annotate_vertical_line_flowers_at_edges);
   RUN_TEST(test_annotate_cross);
   RUN_TEST(test_annotate_large_garden);

   return UNITY_END();
}
