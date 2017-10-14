#include "vendor/unity.h"
#include "../src/difference_of_squares.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_square_of_sum_up_to_5(void)
{
   TEST_ASSERT_EQUAL(225, square_of_sum(5));
}

void test_square_of_sum_up_to_10(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL(3025, square_of_sum(10));
}

void test_square_of_sum_up_to_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(25502500, square_of_sum(100));
}

void test_sum_of_squares_up_to_5(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(55, sum_of_squares(5));
}

void test_sum_of_squares_up_to_10(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(385, sum_of_squares(10));
}

void test_sum_of_squares_up_to_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(338350, sum_of_squares(100));
}

void test_difference_of_squares_up_to_0(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, difference_of_squares(0));
}

void test_difference_of_squares_up_to_5(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(170, difference_of_squares(5));
}

void test_difference_of_squares_up_to_10(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(2640, difference_of_squares(10));
}

void test_difference_of_squares_up_to_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(25164150, difference_of_squares(100));
}

int main(void)
{
   UnityBegin("test/test_difference_of_squares.c");

   RUN_TEST(test_square_of_sum_up_to_5);
   RUN_TEST(test_square_of_sum_up_to_10);
   RUN_TEST(test_square_of_sum_up_to_100);
   RUN_TEST(test_sum_of_squares_up_to_5);
   RUN_TEST(test_sum_of_squares_up_to_10);
   RUN_TEST(test_sum_of_squares_up_to_100);
   RUN_TEST(test_difference_of_squares_up_to_0);
   RUN_TEST(test_difference_of_squares_up_to_5);
   RUN_TEST(test_difference_of_squares_up_to_10);
   RUN_TEST(test_difference_of_squares_up_to_100);

   UnityEnd();
   return 0;
}
