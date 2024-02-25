// Include the test framework.
#include "test-framework/unity.h"

// Include the header file with the declarations of the functions you create.
#include "hello_world.h"

// Runs before every test.
void setUp(void)
{
}

// Runs after every test.
void tearDown(void)
{
}

// Defines a single test.
static void test_say_hi(void)
{
   // Check if the 'hello()' function returns "Hello, World!"
   // This test is expected to fail after first downloading this exercise.
   // To make this test pass, fix the 'hello()' function definition in the
   // source file hello_world.c.
   TEST_ASSERT_EQUAL_STRING("Hello, World!", hello());
}

// Runs the test(s)
int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_say_hi);

   return UNITY_END();
}
