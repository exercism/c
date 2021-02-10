#include "test-framework/unity.h"
#include "difference_of_squares.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_square_of_sum_1(void)
{
   TEST_ASSERT_EQUAL(1, square_of_sum(1));
}

static void test_square_of_sum_5(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL(225, square_of_sum(5));
}

static void test_square_of_sum_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(25502500, square_of_sum(100));
}

static void test_sum_of_squares_1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1, sum_of_squares(1));
}

static void test_sum_of_squares_5(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(55, sum_of_squares(5));
}

static void test_sum_of_squares_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(338350, sum_of_squares(100));
}

static void test_difference_of_squares_1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, difference_of_squares(1));
}

static void test_difference_of_squares_5(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(170, difference_of_squares(5));
}

static void test_difference_of_squares_100(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(25164150, difference_of_squares(100));
}

int main(void)
{
   UnityBegin("test_difference_of_squares.c");

   RUN_TEST(test_square_of_sum_1);
   RUN_TEST(test_square_of_sum_5);
   RUN_TEST(test_square_of_sum_100);
   RUN_TEST(test_sum_of_squares_1);
   RUN_TEST(test_sum_of_squares_5);
   RUN_TEST(test_sum_of_squares_100);
   RUN_TEST(test_difference_of_squares_1);
   RUN_TEST(test_difference_of_squares_5);
   RUN_TEST(test_difference_of_squares_100);

   return UnityEnd();
}
