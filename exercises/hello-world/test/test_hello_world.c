#include <stddef.h>
#include "vendor/unity.h"
#include "../src/hello_world.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello(void)
{
   TEST_ASSERT_EQUAL_STRING("Hello, World!", hello());
}

int main(void)
{
   UnityBegin("test/test_hello_world.c");

   RUN_TEST(test_hello);

   UnityEnd();

   return 0;
}
