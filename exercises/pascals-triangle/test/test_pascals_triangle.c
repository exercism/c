#include <stdbool.h>
#include "../src/pascals_triangle.h"
#include "vendor/unity.h"

bool check(int count, size_t result[][count], size_t expected[][count])
{
   for (int i = 0; i < count; i++) {
      for (int j = 0; j < i; j++) {
         if (result[i][j] != expected[i][j]) {
            return 0;
         }
      }
   }
   return 1;
}

void test_no_rows(void)
{
   size_t result[1][1];
   size_t expected[1][1];
   pascals_triangle(0, result);
   TEST_ASSERT_TRUE(check(1, result, expected));
}

void test_single_row(void)
{
   size_t result[1][1];
   size_t expected[1][1] = {
      {1}
   };
   pascals_triangle(1, result);
   TEST_ASSERT_TRUE(check(1, result, expected));
}

void test_two_rows(void)
{
   size_t result[2][2];
   size_t expected[2][2] = {
      {1},
      {1, 1}
   };
   pascals_triangle(2, result);
   TEST_ASSERT_TRUE(check(2, result, expected));
}

void test_three_rows(void)
{
   size_t result[3][3];
   size_t expected[3][3] = {
      {1},
      {1, 1},
      {1, 2, 1}
   };
   pascals_triangle(3, result);
   TEST_ASSERT_TRUE(check(3, result, expected));
}

void test_four_rows(void)
{
   size_t result[4][4];
   size_t expected[4][4] = {
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1}
   };
   pascals_triangle(4, result);
   TEST_ASSERT_TRUE(check(4, result, expected));
}

void test_negative_rows(void)
{
   size_t result[1][1];
   size_t expected[1][1] = { {-1} };
   pascals_triangle(-1, result);
   TEST_ASSERT_TRUE(check(1, result, expected));
}

int main(void)
{
   UnityBegin("test_pascals_triangle.c");
   RUN_TEST(test_no_rows);
   RUN_TEST(test_single_row);
   RUN_TEST(test_two_rows);
   RUN_TEST(test_three_rows);
   RUN_TEST(test_negative_rows);
   UnityEnd();
}
