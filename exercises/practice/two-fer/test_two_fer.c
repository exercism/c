#include "test-framework/unity.h"
#include "two_fer.h"
#include <stddef.h>

#define BUFFER_SIZE (100)

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_two_fer_no_name_given(void)
{
   char response[BUFFER_SIZE];
   const char *expected = "One for you, one for me.";
   two_fer(response, NULL);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_two_fer_a_name_given(void)
{
   TEST_IGNORE();   // delete this line to run test
   char response[BUFFER_SIZE];
   const char *expected = "One for Alice, one for me.";
   two_fer(response, "Alice");
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_two_fer_another_name_given(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char *expected = "One for Bob, one for me.";
   two_fer(response, "Bob");
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

int main(void)
{
   UnityBegin("test_two_fer.c");

   RUN_TEST(test_two_fer_no_name_given);
   RUN_TEST(test_two_fer_a_name_given);
   RUN_TEST(test_two_fer_another_name_given);

   return UnityEnd();
}
