#include "vendor/unity.h"
#include "../src/hello_world.h"

#define BUFFER_LENGTH 128

char buffer[BUFFER_LENGTH];

void test_hello_no_name(void) {
  hello(buffer, BUFFER_LENGTH, "");
  TEST_ASSERT_EQUAL_STRING("Hello, World!", buffer);
}

void test_hello_alice(void) {
  hello(buffer, BUFFER_LENGTH, "Alice");
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", buffer);
}

void test_hello_bob(void){
  hello(buffer, BUFFER_LENGTH, "Bob");
  TEST_ASSERT_EQUAL_STRING("Hello, Bob!", buffer);
}

void test_no_buffer_overflow_for_small_buffer(void){
  buffer[8] = '?';
  hello(buffer, 8, "Mr. President");
  TEST_ASSERT_EQUAL('?', buffer[8]);
}

int main(void)
{
  
  UnityBegin("test/test_hello_world.c");

  RUN_TEST(test_hello_no_name);
  RUN_TEST(test_hello_alice);
  RUN_TEST(test_hello_bob);
  RUN_TEST(test_no_buffer_overflow_for_small_buffer);

  UnityEnd();
  return 0;
}
