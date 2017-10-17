#include "../src/robot_simulator.h"
#include "vendor/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// Test Helper Function
void confirm_position(robot_grid_status_t * expected,
                      robot_grid_status_t * actual)
{
   TEST_ASSERT_EQUAL(expected->bearing, actual->bearing);
   TEST_ASSERT_EQUAL(expected->grid.x_position, actual->grid.x_position);
   TEST_ASSERT_EQUAL(expected->grid.y_position, actual->grid.y_position);
}

// Tests...
void test_init(void)
{
   robot_grid_status_t expected =
       { DEFAULT_BEARING, {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE} };
   robot_grid_status_t actual = robot_init();

   confirm_position(&expected, &actual);
}

void test_invalid_initial_heading(void)
{
   TEST_IGNORE();               // delete this line to run test
   robot_grid_status_t expected =
       { DEFAULT_BEARING, {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE} };
   robot_grid_status_t actual =
       robot_init_with_position(99, DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE);

   confirm_position(&expected, &actual);
}

void test_init_with_negative_positions(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {-1, -1} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_SOUTH, -1, -1);

   confirm_position(&expected, &actual);
}

void test_turn_right(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_EAST, {0, 0} };
   robot_grid_status_t actual = robot_init();

   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_SOUTH;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_WEST;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_NORTH;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);
}

void test_turn_left(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {0, 0} };
   robot_grid_status_t actual = robot_init();

   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_SOUTH;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_EAST;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = HEADING_NORTH;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {0, 1} };
   robot_grid_status_t actual = robot_init();

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_east(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_EAST, {1, 0} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_EAST, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {0, -1} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_SOUTH, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_west(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {-1, 0} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_WEST, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_WEST, {-4, 1} };
   robot_grid_status_t actual = robot_init();

   robot_simulator(&actual, "LAAARALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_SOUTH, {-3, -8} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_EAST, 2, -7);

   robot_simulator(&actual, "RRAAAAALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_east_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { HEADING_NORTH, {11, 5} };
   robot_grid_status_t actual = robot_init_with_position(HEADING_SOUTH, 8, 4);

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
