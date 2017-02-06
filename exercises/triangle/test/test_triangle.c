#include "vendor/unity.h"
#include "../src/triangle.h"

void test_equilateral_triangles_have_equal_sides(void)
{
   TEST_ASSERT_EQUAL(equilateral, kind(2, 2, 2));
}

void test_larger_equilateral_triangles_also_have_equal_sides(void)
{
   TEST_ASSERT_EQUAL(equilateral, kind(10, 10, 10));
}

void test_isosceles_triangles_have_last_two_sides_equal(void)
{
   TEST_ASSERT_EQUAL(isosceles, kind(3, 4, 4));
}

void test_isosceles_triangles_have_first_and_last_sides_equal(void)
{
   TEST_ASSERT_EQUAL(isosceles, kind(4, 3, 4));
}

void test_isosceles_triangles_have_first_two_sides_equal(void)
{
   TEST_ASSERT_EQUAL(isosceles, kind(4, 4, 3));
}

void test_scalene_triangles_have_no_equal_sides(void)
{
   TEST_ASSERT_EQUAL(scalene, kind(3, 4, 5));
}

void test_scalene_triangles_have_no_equal_sides_at_a_larger_scale_too(void)
{
   TEST_ASSERT_EQUAL(scalene, kind(10, 11, 12));
}

void test_very_small_triangles_are_legal(void)
{
   TEST_ASSERT_EQUAL(scalene, kind(0.4, 0.6, 0.3));
}

void test_triangles_with_no_size_are_illegal(void)
{
   TEST_ASSERT_EQUAL(invalid, kind(0, 0, 0));
}

void test_triangles_with_negative_sides_are_illegal(void)
{
   TEST_ASSERT_EQUAL(invalid, kind(3, 4, -5));
}

void test_triangles_violating_triangle_inequality_are_illegal(void)
{
   TEST_ASSERT_EQUAL(invalid, kind(1, 1, 3));
}

void test_larger_triangles_violating_triangle_inequality_are_illegal(void)
{
   TEST_ASSERT_EQUAL(invalid, kind(7, 3, 2));
}

int main(void)
{
   UnityBegin("test/test_triangle.c");
   RUN_TEST(test_equilateral_triangles_have_equal_sides);
   RUN_TEST(test_larger_equilateral_triangles_also_have_equal_sides);
   RUN_TEST(test_isosceles_triangles_have_last_two_sides_equal);
   RUN_TEST(test_isosceles_triangles_have_first_and_last_sides_equal);
   RUN_TEST(test_isosceles_triangles_have_first_two_sides_equal);
   RUN_TEST(test_scalene_triangles_have_no_equal_sides);
   RUN_TEST(test_scalene_triangles_have_no_equal_sides_at_a_larger_scale_too);
   RUN_TEST(test_very_small_triangles_are_legal);
   RUN_TEST(test_triangles_with_no_size_are_illegal);
   RUN_TEST(test_triangles_with_negative_sides_are_illegal);
   RUN_TEST(test_triangles_violating_triangle_inequality_are_illegal);
   RUN_TEST(test_larger_triangles_violating_triangle_inequality_are_illegal);
   UnityEnd();
   return 0;
}
