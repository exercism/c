#include "vendor/unity.h"
#include "../src/minesweeper.h"
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void free_all(char **field)
{
   free(field[0]);
   free(field);
}

void test_annotate_no_rows(void)
{
   const char **minefield = NULL;
   const size_t rows = 0;
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_NULL(actual);
}

void test_annotate_no_columns(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char *minefield[] = {
      ""
   };
   const char *expected[] = { "" };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_no_mines(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "   ",
      "   ",
      "   "
   };
   const char *expected[] = {
      "   ",
      "   ",
      "   "
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_minefield_with_only_mines(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "***",
      "***",
      "***"
   };
   const char *expected[] = {
      "***",
      "***",
      "***"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_mine_surrounded_by_spaces(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "   ",
      " * ",
      "   "
   };
   const char *expected[] = {
      "111",
      "1*1",
      "111"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_space_surrounded_by_mines(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "***",
      "* *",
      "***"
   };
   const char *expected[] = {
      "***",
      "*8*",
      "***"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_horizontal_line(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      " * * "
   };
   const char *expected[] = {
      "1*2*1"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_horizontal_line_mines_at_edges(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "*   *"
   };
   const char *expected[] = {
      "*1 1*"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_vertical_line(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      " ",
      "*",
      " ",
      "*",
      " "
   };
   const char *expected[] = {
      "1",
      "*",
      "2",
      "*",
      "1"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_vertical_line_mines_at_edges(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "*",
      " ",
      " ",
      " ",
      "*"
   };
   const char *expected[] = {
      "*",
      "1",
      " ",
      "1",
      "*"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_cross(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      "  *  ",
      "  *  ",
      "*****",
      "  *  ",
      "  *  "
   };
   const char *expected[] = {
      " 2*2 ",
      "25*52",
      "*****",
      "25*52",
      " 2*2 "
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

void test_annotate_large_minefield(void)
{
   TEST_IGNORE();
   const char *minefield[] = {
      " *  * ",
      "  *   ",
      "    * ",
      "   * *",
      " *  * ",
      "      "
   };
   const char *expected[] = {
      "1*22*1",
      "12*322",
      " 123*2",
      "112*4*",
      "1*22*2",
      "111111"
   };
   const size_t rows = ARRAY_SIZE(expected);
   char **actual = annotate(minefield, rows);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, rows);
   free_all(actual);
}

int main(void)
{
   UnityBegin("test/test_minesweeper.c");

   RUN_TEST(test_annotate_no_rows);
   RUN_TEST(test_annotate_no_columns);
   RUN_TEST(test_annotate_no_mines);
   RUN_TEST(test_annotate_minefield_with_only_mines);
   RUN_TEST(test_annotate_mine_surrounded_by_spaces);
   RUN_TEST(test_annotate_space_surrounded_by_mines);
   RUN_TEST(test_annotate_horizontal_line);
   RUN_TEST(test_annotate_horizontal_line_mines_at_edges);
   RUN_TEST(test_annotate_vertical_line);
   RUN_TEST(test_annotate_vertical_line_mines_at_edges);
   RUN_TEST(test_annotate_cross);
   RUN_TEST(test_annotate_large_minefield);

   UnityEnd();
   return 0;
}
