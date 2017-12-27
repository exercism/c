#include <stdlib.h>
#include "vendor/unity.h"
#include "../src/series.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// helper routines to validate test results
static void test_solution(series_results_t * expected_solution,
                          series_results_t * actual_solution)
{
   // result count correct
   TEST_ASSERT_EQUAL(expected_solution->substring_count,
                     actual_solution->substring_count);

   // test each substring...
   for (unsigned int index = 0; index < expected_solution->substring_count;
        index++) {
      TEST_ASSERT_EQUAL_STRING(expected_solution->substring[index],
                               actual_solution->substring[index]);
      free(actual_solution->substring[index]);
   }
   if (actual_solution->substring_count) {
      free(actual_solution->substring);
   }
}

// Test cases
void test_slices_of_one(void)
{
   char *substrings[] = { "0", "1", "2", "3", "4" };
   series_results_t expected = { 5, &substrings[0] };
   series_results_t actual = series("01234", 1);

   test_solution(&expected, &actual);
}

void test_slices_of_two(void)
{
   TEST_IGNORE();               // delete this line to run test
   char *substrings[] = { "97", "78", "86", "67", "75", "56", "64" };
   series_results_t expected = { 7, &substrings[0] };
   series_results_t actual = series("97867564", 2);

   test_solution(&expected, &actual);
}

void test_slices_of_three(void)
{
   TEST_IGNORE();
   char *substrings[] = { "978", "786", "867", "675", "756", "564" };
   series_results_t expected = { 6, &substrings[0] };
   series_results_t actual = series("97867564", 3);

   test_solution(&expected, &actual);
}

void test_slices_of_four(void)
{
   TEST_IGNORE();
   char *substrings[] = { "0123", "1234" };
   series_results_t expected = { 2, &substrings[0] };
   series_results_t actual = series("01234", 4);

   test_solution(&expected, &actual);
}

void test_slices_of_five(void)
{
   TEST_IGNORE();
   char *substrings[] = { "01234" };
   series_results_t expected = { 1, &substrings[0] };
   series_results_t actual = series("01234", 5);

   test_solution(&expected, &actual);
}

void test_overly_long_slice(void)
{
   TEST_IGNORE();
   char *substrings[] = { "" };
   series_results_t expected = { 0, &substrings[0] };
   series_results_t actual = series("012", 4);

   test_solution(&expected, &actual);
}

void test_overly_short_slice(void)
{
   TEST_IGNORE();
   char *substrings[] = { "" };
   series_results_t expected = { 0, &substrings[0] };
   series_results_t actual = series("01234", 0);

   test_solution(&expected, &actual);
}

int main(void)
{
   UnityBegin("test/test_series.c");

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
