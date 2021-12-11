#include "test-framework/unity.h"
#include "robot_simulator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_position(robot_status_t expected, robot_status_t actual)
{
   TEST_ASSERT_EQUAL(expected.direction, actual.direction);
   TEST_ASSERT_EQUAL(expected.position.x, actual.position.x);
   TEST_ASSERT_EQUAL(expected.position.y, actual.position.y);
}

static void test_create_at_origin_facing_north(void)
{
   robot_status_t expected = { DIRECTION_NORTH, { 0, 0 } };

   robot_status_t actual = robot_create(DIRECTION_NORTH, 0, 0);

   check_position(expected, actual);
}

static void test_create_at_negative_position_facing_south(void)
{
   TEST_IGNORE();   // delete this line to run test
   robot_status_t expected = { DIRECTION_SOUTH, { -1, -1 } };

   robot_status_t actual = robot_create(DIRECTION_SOUTH, -1, -1);

   check_position(expected, actual);
}

static void test_rotating_clockwise_changes_north_to_east(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_EAST, { 0, 0 } };

   robot_status_t actual = { DIRECTION_NORTH, { 0, 0 } };
   robot_move(&actual, "R");

   check_position(expected, actual);
}

static void test_rotating_clockwise_changes_east_to_south(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_SOUTH, { 0, 0 } };

   robot_status_t actual = { DIRECTION_EAST, { 0, 0 } };
   robot_move(&actual, "R");

   check_position(expected, actual);
}

static void test_rotating_clockwise_changes_south_to_west(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_WEST, { 0, 0 } };

   robot_status_t actual = { DIRECTION_SOUTH, { 0, 0 } };
   robot_move(&actual, "R");

   check_position(expected, actual);
}

static void test_rotating_clockwise_changes_west_to_north(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_NORTH, { 0, 0 } };

   robot_status_t actual = { DIRECTION_WEST, { 0, 0 } };
   robot_move(&actual, "R");

   check_position(expected, actual);
}

static void test_rotating_counter_clockwise_changes_north_to_west(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_WEST, { 0, 0 } };

   robot_status_t actual = { DIRECTION_NORTH, { 0, 0 } };
   robot_move(&actual, "L");

   check_position(expected, actual);
}

static void test_rotating_counter_clockwise_changes_west_to_south(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_SOUTH, { 0, 0 } };

   robot_status_t actual = { DIRECTION_WEST, { 0, 0 } };
   robot_move(&actual, "L");

   check_position(expected, actual);
}

static void test_rotating_counter_clockwise_changes_south_to_east(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_EAST, { 0, 0 } };

   robot_status_t actual = { DIRECTION_SOUTH, { 0, 0 } };
   robot_move(&actual, "L");

   check_position(expected, actual);
}

static void test_rotating_counter_clockwise_changes_east_to_north(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_NORTH, { 0, 0 } };

   robot_status_t actual = { DIRECTION_EAST, { 0, 0 } };
   robot_move(&actual, "L");

   check_position(expected, actual);
}

static void test_moving_forward_one_facing_north_increments_Y(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_NORTH, { 0, 1 } };

   robot_status_t actual = { DIRECTION_NORTH, { 0, 0 } };
   robot_move(&actual, "A");

   check_position(expected, actual);
}

static void test_moving_forward_one_facing_south_decrements_Y(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_SOUTH, { 0, -1 } };

   robot_status_t actual = { DIRECTION_SOUTH, { 0, 0 } };
   robot_move(&actual, "A");

   check_position(expected, actual);
}

static void test_moving_forward_one_facing_east_increments_X(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_EAST, { 1, 0 } };

   robot_status_t actual = { DIRECTION_EAST, { 0, 0 } };
   robot_move(&actual, "A");

   check_position(expected, actual);
}

static void test_moving_forward_one_facing_west_decrements_X(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_WEST, { -1, 0 } };

   robot_status_t actual = { DIRECTION_WEST, { 0, 0 } };
   robot_move(&actual, "A");

   check_position(expected, actual);
}

static void
test_follow_series_of_instructions_moving_east_and_north_from_README(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_WEST, { 9, 4 } };

   robot_status_t actual = { DIRECTION_NORTH, { 7, 3 } };
   robot_move(&actual, "RAALAL");

   check_position(expected, actual);
}

static void test_follow_series_of_instructions_moving_west_and_north(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_WEST, { -4, 1 } };

   robot_status_t actual = { DIRECTION_NORTH, { 0, 0 } };
   robot_move(&actual, "LAAARALA");

   check_position(expected, actual);
}

static void test_follow_series_of_instructions_moving_west_and_south(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_SOUTH, { -3, -8 } };

   robot_status_t actual = { DIRECTION_EAST, { 2, -7 } };
   robot_move(&actual, "RRAAAAALA");

   check_position(expected, actual);
}

static void test_follow_series_of_instructions_moving_east_and_north(void)
{
   TEST_IGNORE();
   robot_status_t expected = { DIRECTION_NORTH, { 11, 5 } };

   robot_status_t actual = { DIRECTION_SOUTH, { 8, 4 } };
   robot_move(&actual, "LAAARRRALLLL");

   check_position(expected, actual);
}

int main(void)
{
   UnityBegin("test_robot_simulator.c");

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
   RUN_TEST(
       test_follow_series_of_instructions_moving_east_and_north_from_README);
   RUN_TEST(test_follow_series_of_instructions_moving_west_and_north);
   RUN_TEST(test_follow_series_of_instructions_moving_west_and_south);
   RUN_TEST(test_follow_series_of_instructions_moving_east_and_north);

   return UnityEnd();
}
