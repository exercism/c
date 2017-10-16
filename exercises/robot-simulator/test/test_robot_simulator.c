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
       { default_bearing, {default_x_coordinate, default_y_coordinate} };
   robot_grid_status_t actual = robot_init();

   confirm_position(&expected, &actual);
}

void test_invalid_initial_heading(void)
{
   TEST_IGNORE();               // delete this line to run test
   robot_grid_status_t expected =
       { default_bearing, {default_x_coordinate, default_y_coordinate} };
   robot_grid_status_t actual =
       robot_init_with_position(99, default_x_coordinate, default_y_coordinate);

   confirm_position(&expected, &actual);
}

void test_init_with_negative_positions(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_south, {-1, -1} };
   robot_grid_status_t actual = robot_init_with_position(heading_south, -1, -1);

   confirm_position(&expected, &actual);
}

void test_turn_right(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_east, {0, 0} };
   robot_grid_status_t actual = robot_init();

   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_south;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_west;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_north;
   robot_turn_right(&actual);
   confirm_position(&expected, &actual);
}

void test_turn_left(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_west, {0, 0} };
   robot_grid_status_t actual = robot_init();

   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_south;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_east;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);

   expected.bearing = heading_north;
   robot_turn_left(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_north, {0, 1} };
   robot_grid_status_t actual = robot_init();

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_positive_east(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_east, {1, 0} };
   robot_grid_status_t actual = robot_init_with_position(heading_east, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_south, {0, -1} };
   robot_grid_status_t actual = robot_init_with_position(heading_south, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_advance_negative_west(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_west, {-1, 0} };
   robot_grid_status_t actual = robot_init_with_position(heading_west, 0, 0);

   robot_advance(&actual);
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_west, {-4, 1} };
   robot_grid_status_t actual = robot_init();

   robot_simulator(&actual, "LAAARALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_west_and_south(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_south, {-3, -8} };
   robot_grid_status_t actual = robot_init_with_position(heading_east, 2, -7);

   robot_simulator(&actual, "RRAAAAALA");
   confirm_position(&expected, &actual);
}

void test_simulate_move_east_and_north(void)
{
   TEST_IGNORE();
   robot_grid_status_t expected = { heading_north, {11, 5} };
   robot_grid_status_t actual = robot_init_with_position(heading_south, 8, 4);

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
