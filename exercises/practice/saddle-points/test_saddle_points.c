#include "test-framework/unity.h"
#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_count(size_t expected, size_t actual)
{
   TEST_ASSERT_EQUAL_UINT64(expected, actual);
}

static void check_points(size_t count, saddle_point_t expected[],
                         saddle_point_t actual[])
{
   // assumes array counts match
   for (size_t i = 0; i < count; ++i) {
      bool point_found = false;
      for (size_t j = 0; j < count; ++j) {
         if (expected[i].row == actual[j].row &&
             expected[i].column == actual[j].column) {
            point_found = true;
            break;
         }
      }
      if (!point_found)
         TEST_FAIL();
   }
}

static void test_single_saddle_point(void)
{
   uint8_t matrix[3][3] = { { 9, 8, 7 }, { 5, 3, 2 }, { 6, 6, 7 } };

   size_t expected_count = 1;
   saddle_point_t expected_points[] = { { 2, 1 } };
   saddle_points_t *actual = saddle_points(3, 3, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void test_empty_matrix_has_no_saddle_points(void)
{
   TEST_IGNORE();   // delete this line to run test
   size_t expected_count = 0;
   saddle_points_t *actual = saddle_points(0, 0, NULL);
   check_count(expected_count, actual->count);
   free_saddle_points(actual);
}

static void test_lack_of_saddle_points_when_there_are_none(void)
{
   TEST_IGNORE();
   uint8_t matrix[3][3] = { { 1, 2, 3 }, { 3, 1, 2 }, { 2, 3, 1 } };

   size_t expected_count = 0;
   saddle_points_t *actual = saddle_points(3, 3, matrix);
   check_count(expected_count, actual->count);
   free_saddle_points(actual);
}

static void test_multiple_saddle_points_in_a_column(void)
{
   TEST_IGNORE();
   uint8_t matrix[3][3] = { { 4, 5, 4 }, { 3, 5, 5 }, { 1, 5, 4 } };

   size_t expected_count = 3;
   saddle_point_t expected_points[] = { { 1, 2 }, { 2, 2 }, { 3, 2 } };
   saddle_points_t *actual = saddle_points(3, 3, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void test_multiple_saddle_points_in_a_row(void)
{
   TEST_IGNORE();
   uint8_t matrix[3][3] = { { 6, 7, 8 }, { 5, 5, 5 }, { 7, 5, 6 } };

   size_t expected_count = 3;
   saddle_point_t expected_points[] = { { 2, 1 }, { 2, 2 }, { 2, 3 } };
   saddle_points_t *actual = saddle_points(3, 3, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void test_saddle_point_in_bottom_right_corner(void)
{
   TEST_IGNORE();
   uint8_t matrix[3][3] = { { 8, 7, 9 }, { 6, 7, 6 }, { 3, 2, 5 } };

   size_t expected_count = 1;
   saddle_point_t expected_points[] = { { 3, 3 } };
   saddle_points_t *actual = saddle_points(3, 3, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void test_saddle_points_in_non_square_matrix(void)
{
   TEST_IGNORE();
   uint8_t matrix[2][3] = { { 3, 1, 3 }, { 3, 2, 4 } };

   size_t expected_count = 2;
   saddle_point_t expected_points[] = { { 1, 3 }, { 1, 1 } };
   saddle_points_t *actual = saddle_points(2, 3, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void
test_saddle_points_in_single_column_matrix_are_those_with_the_minimum_value(
    void)
{
   TEST_IGNORE();
   uint8_t matrix[4][1] = { { 2 }, { 1 }, { 4 }, { 1 } };

   size_t expected_count = 2;
   saddle_point_t expected_points[] = { { 2, 1 }, { 4, 1 } };
   saddle_points_t *actual = saddle_points(4, 1, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

static void
test_saddle_points_in_single_row_matrix_are_those_with_the_maximum_value(void)
{
   TEST_IGNORE();
   uint8_t matrix[1][4] = { { 2, 5, 3, 5 } };

   size_t expected_count = 2;
   saddle_point_t expected_points[] = { { 1, 2 }, { 1, 4 } };
   saddle_points_t *actual = saddle_points(1, 4, matrix);
   check_count(expected_count, actual->count);
   check_points(expected_count, expected_points, actual->points);
   free_saddle_points(actual);
}

int main(void)
{
   UnityBegin("test_saddle_points.c");

   RUN_TEST(test_single_saddle_point);
   RUN_TEST(test_empty_matrix_has_no_saddle_points);
   RUN_TEST(test_lack_of_saddle_points_when_there_are_none);
   RUN_TEST(test_multiple_saddle_points_in_a_column);
   RUN_TEST(test_multiple_saddle_points_in_a_row);
   RUN_TEST(test_saddle_point_in_bottom_right_corner);
   RUN_TEST(test_saddle_points_in_non_square_matrix);
   RUN_TEST(
       test_saddle_points_in_single_column_matrix_are_those_with_the_minimum_value);
   RUN_TEST(
       test_saddle_points_in_single_row_matrix_are_those_with_the_maximum_value);

   return UnityEnd();
}
