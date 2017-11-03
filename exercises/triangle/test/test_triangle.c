#include "vendor/unity.h"
#include "../src/triangle.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_equilateral_is_true_if_all_sides_are_equal(void)
{
   triangle_t sides = { 2, 2, 2 };
   TEST_ASSERT_TRUE(is_equilateral(sides));
}

void test_equilateral_is_false_if_any_side_is_unequal(void)
{
   TEST_IGNORE();               // delete this line to run test
   triangle_t sides = { 2, 3, 2 };
   TEST_ASSERT_FALSE(is_equilateral(sides));
}

void test_equilateral_is_false_if_all_sides_zero(void)
{
   TEST_IGNORE();
   triangle_t sides = { 0, 0, 0 };
   TEST_ASSERT_FALSE(is_equilateral(sides));
}

void test_equilateral_sides_may_be_floats(void)
{
   TEST_IGNORE();
   triangle_t sides = { 0.5, 0.5, 0.5 };
   TEST_ASSERT_TRUE(is_equilateral(sides));
}

void test_isosceles_is_true_if_last_two_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 3, 4, 4 };
   TEST_ASSERT_TRUE(is_isosceles(sides));
}

void test_isosceles_is_true_if_first_two_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 4, 4, 3 };
   TEST_ASSERT_TRUE(is_isosceles(sides));
}

void test_isosceles_is_true_if_first_and_last_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 4, 3, 4 };
   TEST_ASSERT_TRUE(is_isosceles(sides));
}

void test_equilateral_triangles_are_also_isosceles(void)
{
   TEST_IGNORE();
   triangle_t sides = { 4, 4, 4 };
   TEST_ASSERT_TRUE(is_isosceles(sides));
}

void test_isosceles_is_false_if_no_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 2, 3, 4 };
   TEST_ASSERT_FALSE(is_isosceles(sides));
}

void test_isosceles_is_false_if_two_sides_equal_and_violate_inequality(void)
{
   TEST_IGNORE();
   triangle_t sides = { 1, 1, 3 };
   TEST_ASSERT_FALSE(is_isosceles(sides));
}

void test_isosceles_sides_may_be_floats(void)
{
   TEST_IGNORE();
   triangle_t sides = { 0.5, 0.4, 0.5 };
   TEST_ASSERT_TRUE(is_isosceles(sides));
}

void test_scalene_is_true_if_no_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 5, 4, 6 };
   TEST_ASSERT_TRUE(is_scalene(sides));
}

void test_scalene_is_false_if_all_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 4, 4, 4 };
   TEST_ASSERT_FALSE(is_scalene(sides));
}

void test_scalene_is_false_if_two_sides_are_equal(void)
{
   TEST_IGNORE();
   triangle_t sides = { 4, 4, 3 };
   TEST_ASSERT_FALSE(is_scalene(sides));
}

void test_scalene_is_false_if_no_sides_equal_and_violate_inequality(void)
{
   TEST_IGNORE();
   triangle_t sides = { 7, 3, 2 };
   TEST_ASSERT_FALSE(is_scalene(sides));
}

void test_scalene_sides_may_be_floats(void)
{
   TEST_IGNORE();
   triangle_t sides = { 0.5, 0.4, 0.6 };
   TEST_ASSERT_TRUE(is_scalene(sides));
}

int main(void)
{
   UnityBegin("test/test_triangle.c");

   RUN_TEST(test_equilateral_is_true_if_all_sides_are_equal);
   RUN_TEST(test_equilateral_is_false_if_any_side_is_unequal);
   RUN_TEST(test_equilateral_is_false_if_all_sides_zero);
   RUN_TEST(test_equilateral_sides_may_be_floats);
   RUN_TEST(test_isosceles_is_true_if_last_two_sides_are_equal);
   RUN_TEST(test_isosceles_is_true_if_first_two_sides_are_equal);
   RUN_TEST(test_isosceles_is_true_if_first_and_last_sides_are_equal);
   RUN_TEST(test_equilateral_triangles_are_also_isosceles);
   RUN_TEST(test_isosceles_is_false_if_no_sides_are_equal);
   RUN_TEST(test_isosceles_is_false_if_two_sides_equal_and_violate_inequality);
   RUN_TEST(test_isosceles_sides_may_be_floats);
   RUN_TEST(test_scalene_is_true_if_no_sides_are_equal);
   RUN_TEST(test_scalene_is_false_if_all_sides_are_equal);
   RUN_TEST(test_scalene_is_false_if_two_sides_are_equal);
   RUN_TEST(test_scalene_is_false_if_no_sides_equal_and_violate_inequality);
   RUN_TEST(test_scalene_sides_may_be_floats);

   UnityEnd();
   return 0;
}
