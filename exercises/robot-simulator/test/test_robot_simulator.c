#include "../src/robot_simulator.h"
#include "vendor/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_position(robot_grid_status_t * expected,
                           robot_grid_status_t * actual)
{
   TEST_ASSERT_EQUAL(expected->bearing, actual->bearing);
   TEST_ASSERT_EQUAL(expected->grid.x_position, actual->grid.x_position);
   TEST_ASSERT_EQUAL(expected->grid.y_position, actual->grid.y_position);
}

static void test_create_at_origin_facing_north(void)
{
   robot_grid_status_t expected = { HEADING_NORTH, {0, 0} };

   robot_grid_status_t actual = robot_init_with_position(HEADING_NORTH, 0, 0);

   check_position(&expected, &actual);
}

static void test_create_at_negative_position_facing_south(void)
{
   TEST_IGNORE();               // delete this line to run test
   robot_grid_status_t expected = { HEADING_SOUTH, {-1, -1} };

   robot_grid_status_t actual = robot_init_with_position(HEADING_SOUTH, -1, -1);

   check_position(&expected, &actual);
}

static void test_rotating_clockwise_changes_north_to_east(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_EAST, {0, 0} };

   robot_grid_status_t actual = { HEADING_NORTH, {0, 0} };
   robot_simulator(&actual, "R");

   check_position(&expected, &actual);
}

static void test_rotating_clockwise_changes_east_to_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {0, 0} };

   robot_grid_status_t actual = { HEADING_EAST, {0, 0} };
   robot_simulator(&actual, "R");

   check_position(&expected, &actual);
}

static void test_rotating_clockwise_changes_south_to_west(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {0, 0} };

   robot_grid_status_t actual = { HEADING_SOUTH, {0, 0} };
   robot_simulator(&actual, "R");

   check_position(&expected, &actual);
}

static void test_rotating_clockwise_changes_west_to_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {0, 0} };

   robot_grid_status_t actual = { HEADING_WEST, {0, 0} };
   robot_simulator(&actual, "R");

   check_position(&expected, &actual);
}

static void test_rotating_counter_clockwise_changes_north_to_west(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {0, 0} };

   robot_grid_status_t actual = { HEADING_NORTH, {0, 0} };
   robot_simulator(&actual, "L");

   check_position(&expected, &actual);
}

static void test_rotating_counter_clockwise_changes_west_to_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {0, 0} };

   robot_grid_status_t actual = { HEADING_WEST, {0, 0} };
   robot_simulator(&actual, "L");

   check_position(&expected, &actual);
}

static void test_rotating_counter_clockwise_changes_south_to_east(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_EAST, {0, 0} };

   robot_grid_status_t actual = { HEADING_SOUTH, {0, 0} };
   robot_simulator(&actual, "L");

   check_position(&expected, &actual);
}

static void test_rotating_counter_clockwise_changes_east_to_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {0, 0} };

   robot_grid_status_t actual = { HEADING_EAST, {0, 0} };
   robot_simulator(&actual, "L");

   check_position(&expected, &actual);
}

static void test_moving_forward_one_facing_north_increments_Y(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {0, 1} };

   robot_grid_status_t actual = { HEADING_NORTH, {0, 0} };
   robot_simulator(&actual, "A");

   check_position(&expected, &actual);
}

static void test_moving_forward_one_facing_south_decrements_Y(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {0, -1} };

   robot_grid_status_t actual = { HEADING_SOUTH, {0, 0} };
   robot_simulator(&actual, "A");

   check_position(&expected, &actual);
}

static void test_moving_forward_one_facing_east_increments_X(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_EAST, {1, 0} };

   robot_grid_status_t actual = { HEADING_EAST, {0, 0} };
   robot_simulator(&actual, "A");

   check_position(&expected, &actual);
}

static void test_moving_forward_one_facing_west_decrements_X(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {-1, 0} };

   robot_grid_status_t actual = { HEADING_WEST, {0, 0} };
   robot_simulator(&actual, "A");

   check_position(&expected, &actual);
}

static void
test_follow_series_of_instructions_moving_east_and_north_from_README(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {9, 4} };

   robot_grid_status_t actual = { HEADING_NORTH, {7, 3} };
   robot_simulator(&actual, "RAALAL");

   check_position(&expected, &actual);
}

static void test_follow_series_of_instructions_moving_west_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {-4, 1} };

   robot_grid_status_t actual = { HEADING_NORTH, {0, 0} };
   robot_simulator(&actual, "LAAARALA");

   check_position(&expected, &actual);
}

static void test_follow_series_of_instructions_moving_west_and_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {-3, -8} };

   robot_grid_status_t actual = { HEADING_EAST, {2, -7} };
   robot_simulator(&actual, "RRAAAAALA");

   check_position(&expected, &actual);
}

static void test_follow_series_of_instructions_moving_east_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {11, 5} };

   robot_grid_status_t actual = { HEADING_SOUTH, {8, 4} };
   robot_simulator(&actual, "LAAARRRALLLL");

   check_position(&expected, &actual);
}

int main(void)
{
   UnityBegin("test/test_robot_simulator.c");

   RUN_TEST(test_create_at_origin_facing_north);
   RUN_TEST(test_create_at_negative_position_facing_south);
   RUN_TEST(test_rotating_clockwise_changes_north_to_east);
   RUN_TEST(test_rotating_clockwise_changes_east_to_south);
   RUN_TEST(test_rotating_clockwise_changes_south_to_west);
   RUN_TEST(test_rotating_clockwise_changes_west_to_north);
   RUN_TEST(test_rotating_counter_clockwise_changes_north_to_west);
   RUN_TEST(test_rotating_counter_clockwise_changes_west_to_south);
   RUN_TEST(test_rotating_counter_clockwise_changes_south_to_east);
   RUN_TEST(test_rotating_counter_clockwise_changes_east_to_north);
   RUN_TEST(test_moving_forward_one_facing_north_increments_Y);
   RUN_TEST(test_moving_forward_one_facing_south_decrements_Y);
   RUN_TEST(test_moving_forward_one_facing_east_increments_X);
   RUN_TEST(test_moving_forward_one_facing_west_decrements_X);
   RUN_TEST
       (test_follow_series_of_instructions_moving_east_and_north_from_README);
   RUN_TEST(test_follow_series_of_instructions_moving_west_and_north);
   RUN_TEST(test_follow_series_of_instructions_moving_west_and_south);
   RUN_TEST(test_follow_series_of_instructions_moving_east_and_north);

   return UnityEnd();
}
