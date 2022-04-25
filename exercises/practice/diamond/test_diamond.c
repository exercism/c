#include "test-framework/unity.h"
#include "diamond.h"
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_rows_degenerate_case_with_a_single_a_row(void)
{
   const char letter = 'A';
   const char *expected[] = { "A" };
   char **diamond = make_diamond(letter);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, diamond, ARRAY_SIZE(expected));
   free_diamond(diamond);
}

static void
test_rows_degenerate_case_with_no_row_with_3_distinct_groups_of_spaces(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char letter = 'B';
   const char *expected[] = {
      // clang-format off
      " A ",
      "B B",
      " A "
      //clang-format on
   };
   char **diamond = make_diamond(letter);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, diamond, ARRAY_SIZE(expected));
   free_diamond(diamond);
}

static void
test_rows_smallest_non_degenerate_case_with_odd_diamond_side_length(void)
{
   TEST_IGNORE();
   const char letter = 'C';
   const char *expected[] = {
      // clang-format off
      "  A  ",
      " B B ",
      "C   C",
      " B B ",
      "  A  "
      // clang-format on
   };
   char **diamond = make_diamond(letter);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, diamond, ARRAY_SIZE(expected));
   free_diamond(diamond);
}

static void
test_rows_smallest_non_degenerate_case_with_even_diamond_side_length(void)
{
   TEST_IGNORE();
   const char letter = 'D';
   const char *expected[] = {
      // clang-format off
      "   A   ",
      "  B B  ",
      " C   C ",
      "D     D",
      " C   C ",
      "  B B  ",
      "   A   "
      // clang-format on
   };
   char **diamond = make_diamond(letter);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, diamond, ARRAY_SIZE(expected));
   free_diamond(diamond);
}

static void test_rows_largest_possible_diamond(void)
{
   TEST_IGNORE();
   const char letter = 'Z';
   const char *expected[] = {
      // clang-format off
      "                         A                         ",
      "                        B B                        ",
      "                       C   C                       ",
      "                      D     D                      ",
      "                     E       E                     ",
      "                    F         F                    ",
      "                   G           G                   ",
      "                  H             H                  ",
      "                 I               I                 ",
      "                J                 J                ",
      "               K                   K               ",
      "              L                     L              ",
      "             M                       M             ",
      "            N                         N            ",
      "           O                           O           ",
      "          P                             P          ",
      "         Q                               Q         ",
      "        R                                 R        ",
      "       S                                   S       ",
      "      T                                     T      ",
      "     U                                       U     ",
      "    V                                         V    ",
      "   W                                           W   ",
      "  X                                             X  ",
      " Y                                               Y ",
      "Z                                                 Z",
      " Y                                               Y ",
      "  X                                             X  ",
      "   W                                           W   ",
      "    V                                         V    ",
      "     U                                       U     ",
      "      T                                     T      ",
      "       S                                   S       ",
      "        R                                 R        ",
      "         Q                               Q         ",
      "          P                             P          ",
      "           O                           O           ",
      "            N                         N            ",
      "             M                       M             ",
      "              L                     L              ",
      "               K                   K               ",
      "                J                 J                ",
      "                 I               I                 ",
      "                  H             H                  ",
      "                   G           G                   ",
      "                    F         F                    ",
      "                     E       E                     ",
      "                      D     D                      ",
      "                       C   C                       ",
      "                        B B                        ",
      "                         A                         "
      // clang-format on
   };
   char **diamond = make_diamond(letter);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, diamond, ARRAY_SIZE(expected));
   free_diamond(diamond);
}

int main(void)
{
   UnityBegin("test_diamond.c");

   RUN_TEST(test_rows_degenerate_case_with_a_single_a_row);
   RUN_TEST(
       test_rows_degenerate_case_with_no_row_with_3_distinct_groups_of_spaces);
   RUN_TEST(
       test_rows_smallest_non_degenerate_case_with_odd_diamond_side_length);
   RUN_TEST(
       test_rows_smallest_non_degenerate_case_with_even_diamond_side_length);
   RUN_TEST(test_rows_largest_possible_diamond);

   return UnityEnd();
}
