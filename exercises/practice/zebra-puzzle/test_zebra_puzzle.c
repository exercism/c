#include "test-framework/unity.h"
#include "zebra_puzzle.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_resident_who_drinks_water(void)
{
   solution_t solution = solve_puzzle();
   TEST_ASSERT_EQUAL_STRING("Norwegian", solution.drinks_water);
}

static void test_resident_who_owns_zebra(void)
{
   TEST_IGNORE();   // delete this line to run test
   solution_t solution = solve_puzzle();
   TEST_ASSERT_EQUAL_STRING("Japanese", solution.owns_zebra);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_resident_who_drinks_water);
   RUN_TEST(test_resident_who_owns_zebra);

   return UNITY_END();
}
