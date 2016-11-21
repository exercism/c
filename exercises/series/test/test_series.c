#include <stdlib.h>
#include "vendor/unity.h"
#include "../src/series.h"

// helper routines to validate test results
static void testSolution(SeriesResults_t * expectedSolution,
                         SeriesResults_t * actualSolution)
{
   // result count correct
   TEST_ASSERT_EQUAL(expectedSolution->substringCount,
                     actualSolution->substringCount);

   // test each substring...
   for (unsigned int index = 0; index < expectedSolution->substringCount;
        index++) {
      TEST_ASSERT_EQUAL_STRING(expectedSolution->substring[index],
                               actualSolution->substring[index]);
      free(actualSolution->substring[index]);
   }
   if (actualSolution->substringCount) {
      free(actualSolution->substring);
   }
}

#define EXPAND_SERIES_TEST_CASES_AS_TEST(test_name, inputText, substringLength, expectedResultCount, expectedResultSubstrings)\
   void test_name(void)\
   {\
   char *substrings[] =  expectedResultSubstrings;\
   SeriesResults_t expected = {expectedResultCount, &substrings[0]};\
   SeriesResults_t actual = series(inputText, substringLength);\
   testSolution(&expected, &actual);\
   }\

#define ASSEMBLE_STRING_ARRAY(...) __VA_ARGS__

// Test cases
#define SERIES_TEST_CASES(ENTRY) \
   ENTRY(test_slices_of_one, "01234", 1, 5, { ASSEMBLE_STRING_ARRAY("0","1","2","3","4") })\
   ENTRY(test_slices_of_two, "97867564", 2, 7, { ASSEMBLE_STRING_ARRAY("97","78","86","67","75","56", "64") })\
   ENTRY(test_slices_of_three, "97867564", 3, 6, { ASSEMBLE_STRING_ARRAY("978","786","867","675","756","564") })\
   ENTRY(test_slices_of_four, "01234", 4, 2, { ASSEMBLE_STRING_ARRAY("0123","1234") })\
   ENTRY(test_slices_of_five, "01234", 5, 1, { ASSEMBLE_STRING_ARRAY("01234") })\
   ENTRY(test_overly_long_slice, "012", 4, 0, { ASSEMBLE_STRING_ARRAY("") })\
   ENTRY(test_overly_short_slice, "01234", 0, 0, { ASSEMBLE_STRING_ARRAY("") })\

SERIES_TEST_CASES(EXPAND_SERIES_TEST_CASES_AS_TEST)

int main(void)
{
   UnityBegin("test/test_word_count.c");

   RUN_TEST(test_slices_of_one);
   RUN_TEST(test_slices_of_two);
   RUN_TEST(test_slices_of_three);
   RUN_TEST(test_slices_of_four);
   RUN_TEST(test_slices_of_five);
   RUN_TEST(test_overly_long_slice);
   RUN_TEST(test_overly_short_slice);

   UnityEnd();

   return 0;
}
