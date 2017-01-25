#include "vendor/unity.h"
#include "../src/triangle.h"

void equilateral_triangles_have_equal_sides(void)
{
   TEST_ASSERT(equilateral == kind(2, 2, 2));
}

void larger_equilateral_triangles_also_have_equal_sides(void)
{
   TEST_ASSERT(equilateral == kind(10, 10, 10));
}

void isosceles_triangles_have_last_two_sides_equal(void)
{
   TEST_ASSERT(isosceles == kind(3, 4, 4));
}

void isosceles_triangles_have_first_and_last_sides_equal(void)
{
   TEST_ASSERT(isosceles == kind(4, 3, 4));
}

void isosceles_triangles_have_first_two_sides_equal(void)
{
   TEST_ASSERT(isosceles == kind(4, 4, 3));
}

void scalene_triangles_have_no_equal_sides(void)
{
   TEST_ASSERT(scalene == kind(3, 4, 5));
}

void scalene_triangles_have_no_equal_sides_at_a_larger_scale_too(void)
{
   TEST_ASSERT(scalene == kind(10, 11, 12));
}

void very_small_triangles_are_legal(void)
{
   TEST_ASSERT(scalene == kind(0.4, 0.6, 0.3));
}

void triangles_with_no_size_are_illegal(void)
{
   TEST_ASSERT(error == kind(0, 0, 0));
}

void triangles_with_negative_sides_are_illegal(void)
{
   TEST_ASSERT(error == kind(3, 4, -5));
}

void triangles_violating_triangle_inequality_are_illegal(void)
{
   TEST_ASSERT(error == kind(1, 1, 3));
}

void larger_triangles_violating_triangle_inequality_are_illegal(void)
{
   TEST_ASSERT(error == kind(7, 3, 2));
}

int main(void)
{
   UnityBegin("test/test_triangle.c");
   RUN_TEST(equilateral_triangles_have_equal_sides);
   RUN_TEST(larger_equilateral_triangles_also_have_equal_sides);
   RUN_TEST(isosceles_triangles_have_last_two_sides_equal);
   RUN_TEST(isosceles_triangles_have_first_and_last_sides_equal);
   RUN_TEST(isosceles_triangles_have_first_two_sides_equal);
   RUN_TEST(scalene_triangles_have_no_equal_sides);
   RUN_TEST(scalene_triangles_have_no_equal_sides_at_a_larger_scale_too);
   RUN_TEST(very_small_triangles_are_legal);
   RUN_TEST(triangles_with_no_size_are_illegal);
   RUN_TEST(triangles_with_negative_sides_are_illegal);
   RUN_TEST(triangles_violating_triangle_inequality_are_illegal);
   RUN_TEST(larger_triangles_violating_triangle_inequality_are_illegal);
   UnityEnd();
   return 0;
}
