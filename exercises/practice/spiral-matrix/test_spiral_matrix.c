#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "test-framework/unity.h"
#include "spiral_matrix.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static bool matrix_matches(int expected_size,
                           int expected_matrix[][expected_size],
                           const spiral_matrix_t *actual)
{
   if (expected_size != actual->size)
      return false;

   for (int i = 0; i < expected_size; i++) {
      for (int j = 0; j < expected_size; j++) {
         if (expected_matrix[i][j] != actual->matrix[i][j]) {
            printf("expected[%d][%d] = %d\n", i, j, expected_matrix[i][j]);
            printf("actual[%d][%d] = %d\n", i, j, actual->matrix[i][j]);
            return false;
         }
      }
   }

   return true;
}

static void test_empty_spiral(void)
{
   spiral_matrix_t *actual = spiral_matrix_create(0);
   TEST_ASSERT_EQUAL_UINT(0, actual->size);
   TEST_ASSERT_NULL(actual->matrix);
   spiral_matrix_destroy(actual);
}

static void test_trivial_spiral(void)
{
   int expected_matrix[1][1] = {
      { 1 },
   };

   spiral_matrix_t *actual = spiral_matrix_create(1);
   TEST_ASSERT_TRUE(matrix_matches(1, expected_matrix, actual));
   spiral_matrix_destroy(actual);
}

static void test_spiral_of_size_2(void)
{
   int expected_matrix[2][2] = {
      { 1, 2 },
      { 4, 3 },
   };

   spiral_matrix_t *actual = spiral_matrix_create(2);
   TEST_ASSERT_TRUE(matrix_matches(2, expected_matrix, actual));
   spiral_matrix_destroy(actual);
}

static void test_spiral_of_size_3(void)
{
   int expected_matrix[3][3] = {
      { 1, 2, 3 },
      { 8, 9, 4 },
      { 7, 6, 5 },
   };

   spiral_matrix_t *actual = spiral_matrix_create(3);
   TEST_ASSERT_TRUE(matrix_matches(3, expected_matrix, actual));
   spiral_matrix_destroy(actual);
}

static void test_spiral_of_size_4(void)
{
   int expected_matrix[4][4] = {
      { 1, 2, 3, 4 },
      { 12, 13, 14, 5 },
      { 11, 16, 15, 6 },
      { 10, 9, 8, 7 },
   };

   spiral_matrix_t *actual = spiral_matrix_create(4);
   TEST_ASSERT_TRUE(matrix_matches(4, expected_matrix, actual));
   spiral_matrix_destroy(actual);
}

static void test_spiral_of_size_5(void)
{
   int expected_matrix[5][5] = {
      { 1, 2, 3, 4, 5 },       //
      { 16, 17, 18, 19, 6 },   //
      { 15, 24, 25, 20, 7 },   //
      { 14, 23, 22, 21, 8 },   //
      { 13, 12, 11, 10, 9 },
   };

   spiral_matrix_t *actual = spiral_matrix_create(5);
   TEST_ASSERT_TRUE(matrix_matches(5, expected_matrix, actual));
   spiral_matrix_destroy(actual);
}

int main(void)
{
   UnityBegin("test_spiral_matrix.c");

   RUN_TEST(test_empty_spiral);
   RUN_TEST(test_trivial_spiral);
   RUN_TEST(test_spiral_of_size_2);
   RUN_TEST(test_spiral_of_size_3);
   RUN_TEST(test_spiral_of_size_4);
   RUN_TEST(test_spiral_of_size_5);

   return UnityEnd();
}
