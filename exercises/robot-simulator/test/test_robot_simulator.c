#include "../src/robot_simulator.h"
#include "vendor/unity.h"

// Test Helper Function
void confirm_position(RobotGridStatus_t * expected, RobotGridStatus_t * actual)
{
   TEST_ASSERT_EQUAL(expected->bearing, actual->bearing);
   TEST_ASSERT_EQUAL(expected->grid.x_position, actual->grid.x_position);
   TEST_ASSERT_EQUAL(expected->grid.y_position, actual->grid.y_position);
}

// Tests...
void test_init(void)
{
   RobotGridStatus_t expected =
       { Default_Bearing, {Default_X_Coordinate, Default_Y_Coordinate} };
   RobotGridStatus_t actual = robot_init();

   confirm_position(&expected, &actual);
}

void test_invalid_initial_heading(void)
{
   RobotGridStatus_t expected =
       { Default_Bearing, {Default_X_Coordinate, Default_Y_Coordinate} };
   RobotGridStatus_t actual =
       robot_init_with_position(99, Default_X_Coordinate, Default_Y_Coordinate);

   confirm_position(&expected, &actual);
}

void test_init_with_negative_positions(void)
{
   RobotGridStatus_t expected = { Heading_South, {-1, -1} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_South, -1, -1);

   confirm_position(&expected, &actual);
}

void test_turn_right(void)
{
   RobotGridStatus_t expected = { Heading_East, {0, 0} };
   RobotGridStatus_t actual = robot_init();

   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_South;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_West;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_North;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);
}

void test_turn_left(void)
{
   RobotGridStatus_t expected = { Heading_West, {0, 0} };
   RobotGridStatus_t actual = robot_init();

   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_South;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_East;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = Heading_North;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_north(void)
{
   RobotGridStatus_t expected = { Heading_North, {0, 1} };
   RobotGridStatus_t actual = robot_init();

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_east(void)
{
   RobotGridStatus_t expected = { Heading_East, {1, 0} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_East, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_south(void)
{
   RobotGridStatus_t expected = { Heading_South, {0, -1} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_South, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_west(void)
{
   RobotGridStatus_t expected = { Heading_West, {-1, 0} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_West, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_north(void)
{
   RobotGridStatus_t expected = { Heading_West, {-4, 1} };
   RobotGridStatus_t actual = robot_init();

   robot_simulator(&actual, "LAAARALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_south(void)
{
   RobotGridStatus_t expected = { Heading_South, {-3, -8} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_East, 2, -7);

   robot_simulator(&actual, "RRAAAAALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_east_and_north(void)
{
   RobotGridStatus_t expected = { Heading_North, {11, 5} };
   RobotGridStatus_t actual = robot_init_with_position(Heading_South, 8, 4);

   robot_simulator(&actual, "LAAARRRALLLL");
   confirm_position(&expected, &actual);
}

int main(void)
{
   UnityBegin("test/test_word_count.c");

   RUN_TEST(test_init);
   RUN_TEST(test_invalid_initial_heading);
   RUN_TEST(test_init_with_negative_positions);
   RUN_TEST(test_turn_right);
   RUN_TEST(test_turn_left);
   RUN_TEST(test_advance_positive_north);
   RUN_TEST(test_advance_positive_east);
   RUN_TEST(test_advance_negative_south);
   RUN_TEST(test_advance_negative_west);
   RUN_TEST(test_simulate_move_west_and_north);
   RUN_TEST(test_simulate_move_west_and_south);
   RUN_TEST(test_simulate_move_east_and_north);

   UnityEnd();

   return 0;
}
