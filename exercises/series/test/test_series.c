#include <stddef.h>
#include <stdlib.h>
#include <string.h>
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
   free(actualSolution->substring);
   free(actualSolution);
}

// Test cases
//
#define EXPAND_SERIES_TEST_CASES_AS_TEST(test_name, inputText, substringLength, expectedResultCount, expectedResultSubstrings)\
   void test_name(void)\
   {\
   char *substrings[] =  expectedResultSubstrings;\
   SeriesResults_t expected = {expectedResultCount, &substrings[0]};\
   SeriesResults_t *actual = series(inputText, substringLength);\
   testSolution(&expected, actual);\
   }\

#define DERP(...) __VA_ARGS__

#define SERIES_TEST_CASES(ENTRY) \
   ENTRY(test_slices_of_one, "01234", 1, 5, { DERP("0","1","2","3","4") })\
   ENTRY(test_slices_of_two, "97867564", 2, 7, { DERP("97","78","86","67","75","56", "64") })\
   ENTRY(test_slices_of_three, "97867564", 3, 6, { DERP("978","786","867","675","756","564") })\
   ENTRY(test_slices_of_four, "01234", 4, 2, { DERP("0123","1234") })\
   ENTRY(test_slices_of_five, "01234", 5, 1, { DERP("01234")})\
   ENTRY(test_overly_long_slice, "012", 4, 0, {DERP("")})\
   ENTRY(test_overly_short_slice, "01234", 0, 0, {DERP("")})\

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

#if (0)

no data available but these are the tests done in python ...
class SeriesTest(unittest.TestCase):def test_slices_of_one(self):self.
assertEqual([[0],[1],[2],[3],[4]], slices("01234", 1))

def test_slices_of_two(self):self.assertEqual([[9, 7],[7, 8],[8, 6],[6, 7],
                                               [7, 5],[5, 6],[6, 4]],
                                              slices("97867564", 2))

def test_slices_of_three(self):self.assertEqual([[9, 7, 8],[7, 8, 6],[8, 6, 7],
                                                 [6, 7, 5],[7, 5, 6],[5, 6, 4]],
                                                slices("97867564", 3))

def test_slices_of_four(self):self.assertEqual([[0, 1, 2, 3],[1, 2, 3, 4]],
                                               slices("01234", 4))

def test_slices_of_five(self):self.assertEqual([[0, 1, 2, 3, 4]],
                                               slices("01234", 5))

def test_overly_long_slice(self):with self.
assertRaises(ValueError):slices("012", 4)

def test_overly_short_slice(self):with self.
assertRaises(ValueError):slices("01234", 0)

#endif
