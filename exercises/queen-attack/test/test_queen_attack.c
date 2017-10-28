#include "vendor/unity.h"
#include "../src/queen_attack.h"

void test_invalid_if_on_same_position(void)
{
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 5;
   black_queen.column = white_queen.column;
   black_queen.row = white_queen.row;

   TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(white_queen, black_queen));
}

void test_white_queen_must_have_row_on_board(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 8;
   black_queen.column = 0;
   black_queen.row = 0;

   TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(white_queen, black_queen));
}

void test_white_queen_must_have_column_on_board(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 8;
   white_queen.row = 2;
   black_queen.column = 0;
   black_queen.row = 0;

   TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(white_queen, black_queen));
}

void test_black_queen_must_have_row_on_board(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 0;
   white_queen.row = 0;
   black_queen.column = 2;
   black_queen.row = 10;

   TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(white_queen, black_queen));
}

void test_black_queen_must_have_column_on_board(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 0;
   white_queen.row = 0;
   black_queen.column = 9;
   black_queen.row = 4;

   TEST_ASSERT_EQUAL(INVALID_POSITION, can_attack(white_queen, black_queen));
}

void test_can_not_attack(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 4;
   white_queen.row = 2;
   black_queen.column = 6;
   black_queen.row = 6;

   TEST_ASSERT_EQUAL(CAN_NOT_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_same_row(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 4;
   white_queen.row = 2;
   black_queen.column = 6;
   black_queen.row = 2;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_same_column(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 5;
   white_queen.row = 4;
   black_queen.column = 5;
   black_queen.row = 2;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_first_diagonal(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 2;
   black_queen.column = 4;
   black_queen.row = 0;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_second_diagonal(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 2;
   black_queen.column = 1;
   black_queen.row = 3;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_third_diagonal(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 2;
   black_queen.column = 1;
   black_queen.row = 1;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

void test_can_attack_on_fourth_diagonal(void)
{
   TEST_IGNORE();
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 2;
   black_queen.column = 5;
   black_queen.row = 5;

   TEST_ASSERT_EQUAL(CAN_ATTACK, can_attack(white_queen, black_queen));
}

int main(void)
{
   UnityBegin("test/test_queen_attack.c");

   RUN_TEST(test_invalid_if_on_same_position);
   RUN_TEST(test_white_queen_must_have_row_on_board);
   RUN_TEST(test_white_queen_must_have_column_on_board);
   RUN_TEST(test_black_queen_must_have_row_on_board);
   RUN_TEST(test_black_queen_must_have_column_on_board);
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
