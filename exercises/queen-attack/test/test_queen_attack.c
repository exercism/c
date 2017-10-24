#include "vendor/unity.h"
#include "../src/queen_attack.h"

void test_invalid_if_on_same_position(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 5;
    queen_2.column = queen_1.column;
    queen_2.row = queen_1.row;

    TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(queen_1, queen_2));
}

void test_queen_1_must_have_row_on_board(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 8;
    queen_2.column = 0;
    queen_2.row = 0;

    TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(queen_1, queen_2));
}

void test_queen_1_must_have_column_on_board(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 8;
    queen_1.row = 2;
    queen_2.column = 0;
    queen_2.row = 0;

    TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(queen_1, queen_2));
}

void test_queen_2_must_have_row_on_board(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 0;
    queen_1.row = 0;
    queen_2.column = 2;
    queen_2.row = 10;

    TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(queen_1, queen_2));
}

void test_queen_2_must_have_column_on_board(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 0;
    queen_1.row = 0;
    queen_2.column = 9;
    queen_2.row = 4;

    TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(queen_1, queen_2));
}

void test_can_not_attack(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 4;
    queen_1.row = 2;
    queen_2.column = 6;
    queen_2.row = 6;

    TEST_ASSERT_EQUAL(CAN_NOT_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_same_row(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 4;
    queen_1.row = 2;
    queen_2.column = 6;
    queen_2.row = 2;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_same_column(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 5;
    queen_1.row = 4;
    queen_2.column = 5;
    queen_2.row = 2;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_first_diagonal(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 2;
    queen_2.column = 4;
    queen_2.row = 0;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_second_diagonal(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 2;
    queen_2.column = 1;
    queen_2.row = 3;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_third_diagonal(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 2;
    queen_2.column = 1;
    queen_2.row = 1;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

void test_can_attack_on_fourth_diagonal(void)
{
    queen_position_t queen_1;
    queen_position_t queen_2;

    queen_1.column = 2;
    queen_1.row = 2;
    queen_2.column = 5;
    queen_2.row = 5;

    TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(queen_1, queen_2));
}

int main(void)
{
   UnityBegin("test/test_queen_attack.c");

   RUN_TEST(test_invalid_if_on_same_position);
   RUN_TEST(test_queen_1_must_have_row_on_board);
   RUN_TEST(test_queen_1_must_have_column_on_board);
   RUN_TEST(test_queen_2_must_have_row_on_board);
   RUN_TEST(test_queen_2_must_have_column_on_board);
   RUN_TEST(test_can_not_attack);
   RUN_TEST(test_can_attack_on_same_row);
   RUN_TEST(test_can_attack_on_same_column);
   RUN_TEST(test_can_attack_on_first_diagonal);
   RUN_TEST(test_can_attack_on_second_diagonal);
   RUN_TEST(test_can_attack_on_third_diagonal);
   RUN_TEST(test_can_attack_on_fourth_diagonal);

   UnityEnd();
   return 0;
}
