#include <stdbool.h>
#include "../src/pascals_triangle.h"
#include "vendor/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static bool check(size_t count, size_t expected[][count], size_t ** result)
{
   size_t i, j;
   for (i = 0; i < count; i++) {
      for (j = 0; j <= i; j++) {
         if (expected[i][j] != result[i][j]) {
            return 0;
         }
      }
   }
   return 1;
}

static void test_no_rows(void)
{
   size_t expected[1][1] = { {0} };
   size_t **r = create_triangle(0);
   TEST_ASSERT_TRUE(check(1, expected, r));
   free_triangle(r, 1);
}

static void test_single_row(void)
{
   TEST_IGNORE();               // delete this line to run test
   size_t expected[1][1] = {
      {1}
   };
   size_t **r = create_triangle(1);
   TEST_ASSERT_TRUE(check(1, expected, r));
   free_triangle(r, 1);
}

static void test_two_rows(void)
{
   TEST_IGNORE();
   size_t expected[2][2] = {
      {1, 0},
      {1, 1}
   };
   size_t **r = create_triangle(2);
   TEST_ASSERT_TRUE(check(2, expected, r));
   free_triangle(r, 2);
}

static void test_three_rows(void)
{
   TEST_IGNORE();
   size_t expected[3][3] = {
      {1, 0, 0},
      {1, 1, 0},
      {1, 2, 1}
   };
   size_t **r = create_triangle(3);
   TEST_ASSERT_TRUE(check(3, expected, r));
   free_triangle(r, 3);
}

static void test_four_rows(void)
{
   TEST_IGNORE();
   size_t expected[4][4] = {
      {1, 0, 0, 0},
      {1, 1, 0, 0},
      {1, 2, 1, 0},
      {1, 3, 3, 1}
   };
   size_t **r = create_triangle(4);
   TEST_ASSERT_TRUE(check(4, expected, r));
   free_triangle(r, 4);
}

static void test_five_rows(void)
{
   TEST_IGNORE();
   size_t expected[5][5] = {
      {1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {1, 2, 1, 0, 0},
      {1, 3, 3, 1, 0},
      {1, 4, 6, 4, 1}
   };
   size_t **r = create_triangle(5);
   TEST_ASSERT_TRUE(check(5, expected, r));
   free_triangle(r, 5);
}

static void test_six_rows(void)
{
   TEST_IGNORE();
   size_t expected[6][6] = {
      {1, 0,  0,  0, 0, 0},
      {1, 1,  0,  0, 0, 0},
      {1, 2,  1,  0, 0, 0},
      {1, 3,  3,  1, 0, 0},
      {1, 4,  6,  4, 1, 0},
      {1, 5, 10, 10, 5, 1},
   };
   size_t **r = create_triangle(6);
   TEST_ASSERT_TRUE(check(6, expected, r));
   free_triangle(r, 6);
}

static void test_ten_rows(void)
{
   TEST_IGNORE();
   size_t expected[10][10] = {
      {1, 0,  0,  0,   0,   0,  0,  0, 0, 0},
      {1, 1,  0,  0,   0,   0,  0,  0, 0, 0},
      {1, 2,  1,  0,   0,   0,  0,  0, 0, 0},
      {1, 3,  3,  1,   0,   0,  0,  0, 0, 0},
      {1, 4,  6,  4,   1,   0,  0,  0, 0, 0},
      {1, 5, 10, 10,   5,   1,  0,  0, 0, 0},
      {1, 6, 15, 20,  15,   6,  1,  0, 0, 0},
      {1, 7, 21, 35,  35,  21,  7,  1, 0, 0},
      {1, 8, 28, 56,  70,  56, 28,  8, 1, 0},
      {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}
   };
   size_t **r = create_triangle(10);
   TEST_ASSERT_TRUE(check(10, expected, r));
   free_triangle(r, 10);
}

int main(void)
{
   UnityBegin("test/test_pascals_triangle.c");

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
