#include "vendor/unity.h"
#include "../src/hello_world.h"

#define BUFFER_LENGTH 128

char buffer[BUFFER_LENGTH];

void test_hello_no_name() {
  hello(buffer, BUFFER_LENGTH, "");
  TEST_ASSERT_EQUAL_STRING("Hello, World!", buffer);
}

void test_hello_alice() {
  hello(buffer, BUFFER_LENGTH, "Alice");
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", buffer);
}

void test_hello_bob(){
  hello(buffer, BUFFER_LENGTH, "Bob");
  TEST_ASSERT_EQUAL_STRING("Hello, Bob!", buffer);
}

int main(void)
{
  
  UnityBegin("test/test_hello_world.c");

  RUN_TEST(test_hello_no_name);
  RUN_TEST(test_hello_alice);
  RUN_TEST(test_hello_bob);

  UnityEnd();
  return 0;
}
