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
      for (j = 0; j < count; j++) {
         if (expected[i][j] != result[i][j]) {
            return 0;
         }
      }
   }
   return 1;
}

void test_no_rows(void)
{
   size_t expected[1][1] = { {0} };
   size_t **r = create_triangle(0);
   TEST_ASSERT_TRUE(check(1, expected, r));
   free_triangle(r, 1);
}

void test_single_row(void)
{
   TEST_IGNORE();               // delete this line to run test
   size_t expected[1][1] = {
      {1}
   };
   size_t **r = create_triangle(1);
   TEST_ASSERT_TRUE(check(1, expected, r));
   free_triangle(r, 1);
}

void test_two_rows(void)
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

void test_three_rows(void)
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

void test_four_rows(void)
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

void test_negative_rows(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE((create_triangle(-1) == NULL));
}

int main(void)
{
   UnityBegin("test/test_pascals_triangle.c");
   RUN_TEST(test_no_rows);
   RUN_TEST(test_single_row);
   RUN_TEST(test_two_rows);
   RUN_TEST(test_three_rows);
   RUN_TEST(test_four_rows);
   RUN_TEST(test_negative_rows);
   UnityEnd();
}
