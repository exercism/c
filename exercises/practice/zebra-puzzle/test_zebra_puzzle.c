#include "zebra_puzzle.h"
#include "test-framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_who_drinks_water(void)
{
   TEST_ASSERT_EQUAL_STRING("Norwegian", drinks_water());
}

static void test_who_owns_the_zebra(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL_STRING("Japanese", owns_zebra());
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_who_drinks_water);
   RUN_TEST(test_who_owns_the_zebra);

   return UNITY_END();
}
