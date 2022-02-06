#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "test-framework/unity.h"
#include "pascals_triangle.h"

uint8_t **actual = NULL;
size_t count = 0;

void setUp(void)
{
}

void tearDown(void)
{
   if (actual) {
      for (size_t i = 0; i < count; ++i) {
         if (actual[i]) {
            free(actual[i]);
            actual[i] = NULL;
         }
      }
      free(actual);
      actual = NULL;
   }
}

static bool check_triangle(size_t count, uint8_t expected[][count],
                           uint8_t **actual)
{
   if (!actual)
      return false;

   for (size_t i = 0; i < count; i++)
      for (size_t j = 0; j < count; j++)
         if (expected[i][j] != actual[i][j])
            return false;

   return true;
}

static void test_no_rows(void)
{
   uint8_t expected[1][1] = { { 0 } };
   actual = create_triangle(0);
   TEST_ASSERT_TRUE(check_triangle((count = 1), expected, actual));
   free_triangle(actual, 1);
   actual = NULL;
}

static void test_single_row(void)
{
   TEST_IGNORE();   // delete this line to run test
   uint8_t expected[1][1] = { { 1 } };
   actual = create_triangle(1);
   TEST_ASSERT_TRUE(check_triangle((count = 1), expected, actual));
   free_triangle(actual, 1);
   actual = NULL;
}

static void test_two_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[2][2] = {
      // clang-format off
      {1, 0},
      {1, 1}
      // clang-format on
   };
   actual = create_triangle(2);
   TEST_ASSERT_TRUE(check_triangle((count = 2), expected, actual));
   free_triangle(actual, 2);
   actual = NULL;
}

static void test_three_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[3][3] = {
      // clang-format off
      {1, 0, 0},
      {1, 1, 0},
      {1, 2, 1}
      // clang-format on
   };
   actual = create_triangle(3);
   TEST_ASSERT_TRUE(check_triangle((count = 3), expected, actual));
   free_triangle(actual, 3);
   actual = NULL;
}

static void test_four_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[4][4] = {
      // clang-format off
      {1, 0, 0, 0},
      {1, 1, 0, 0},
      {1, 2, 1, 0},
      {1, 3, 3, 1}
      // clang-format on
   };
   actual = create_triangle(4);
   TEST_ASSERT_TRUE(check_triangle((count = 4), expected, actual));
   free_triangle(actual, 4);
   actual = NULL;
}

static void test_five_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[5][5] = {
      // clang-format off
      {1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {1, 2, 1, 0, 0},
      {1, 3, 3, 1, 0},
      {1, 4, 6, 4, 1}
      // clang-format on
   };
   actual = create_triangle(5);
   TEST_ASSERT_TRUE(check_triangle((count = 5), expected, actual));
   free_triangle(actual, 5);
   actual = NULL;
}

static void test_six_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[6][6] = {
      // clang-format off
      {1, 0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0},
      {1, 2, 1, 0, 0, 0},
      {1, 3, 3, 1, 0, 0},
      {1, 4, 6, 4, 1, 0},
      {1, 5, 10, 10, 5, 1},
      // clang-format on
   };
   actual = create_triangle(6);
   TEST_ASSERT_TRUE(check_triangle((count = 6), expected, actual));
   free_triangle(actual, 6);
   actual = NULL;
}

static void test_ten_rows(void)
{
   TEST_IGNORE();
   uint8_t expected[10][10] = {
      // clang-format off
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 2, 1, 0, 0, 0, 0, 0, 0, 0},
      {1, 3, 3, 1, 0, 0, 0, 0, 0, 0},
      {1, 4, 6, 4, 1, 0, 0, 0, 0, 0},
      {1, 5, 10, 10, 5, 1, 0, 0, 0, 0},
      {1, 6, 15, 20, 15, 6, 1, 0, 0, 0},
      {1, 7, 21, 35, 35, 21, 7, 1, 0, 0},
      {1, 8, 28, 56, 70, 56, 28, 8, 1, 0},
      {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}
      // clang-format off
   };
   actual = create_triangle(10);
   TEST_ASSERT_TRUE(check_triangle((count = 10), expected, actual));
   free_triangle(actual, 10);
   actual = NULL;
}

int main(void)
{
   UnityBegin("test_pascals_triangle.c");

   RUN_TEST(test_no_rows);
   RUN_TEST(test_single_row);
   RUN_TEST(test_two_rows);
   RUN_TEST(test_three_rows);
   RUN_TEST(test_four_rows);
   RUN_TEST(test_five_rows);
   RUN_TEST(test_six_rows);
   RUN_TEST(test_ten_rows);

   return UnityEnd();
}
