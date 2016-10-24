#include "vendor/unity.h"
#include "../src/phone_number.h"
#include <stdlib.h>

#define NUMBER_OF_DIGITS      (11)

void test_cleans_parens_dashes_and_spaces_from_the_number(void)
{
   const char dirty_number[] = "(123) 456-7890";
   const char expected_number[] = "1234567890";
   const char *result = calloc(NUMBER_OF_DIGITS, sizeof(char));

   phone_number_get_number(dirty_number, result);

   TEST_ASSERT_EQUAL_STRING(expected_number, result);
}

int main(void)
{
   UnityBegin("test/test_phone_number.c");

   RUN_TEST(test_cleans_parens_dashes_and_spaces_from_the_number);

   UnityEnd();
   return 0;
}
