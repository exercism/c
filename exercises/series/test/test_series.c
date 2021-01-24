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
static void test_solution(slices_t * expected_solution,
                          slices_t * actual_solution)
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
static void test_slices_of_one_from_one(void)
{
   char *substrings[] = { "1" };
   slices_t expected = { 1, &substrings[0] };
   slices_t actual = slices("1", 1);

   test_solution(&expected, &actual);
}

static void test_slices_of_one_from_two(void)
{
   TEST_IGNORE();               // delete this line to run test
   char *substrings[] = { "1", "2" };
   slices_t expected = { 2, &substrings[0] };
   slices_t actual = slices("12", 1);

   test_solution(&expected, &actual);
}

static void test_slices_of_two(void)
{
   TEST_IGNORE();
   char *substrings[] = { "35" };
   slices_t expected = { 1, &substrings[0] };
   slices_t actual = slices("35", 2);

   test_solution(&expected, &actual);
}

static void test_slices_of_two_overlap(void)
{
   TEST_IGNORE();
   char *substrings[] = { "91", "14", "42" };
   slices_t expected = { 3, &substrings[0] };
   slices_t actual = slices("9142", 2);

   test_solution(&expected, &actual);
}

static void test_slices_can_include_duplicates(void)
{
   TEST_IGNORE();
   char *substrings[] = { "777", "777", "777", "777" };
   slices_t expected = { 4, &substrings[0] };
   slices_t actual = slices("777777", 3);

   test_solution(&expected, &actual);
}

static void test_slices_of_a_long_series(void)
{
   TEST_IGNORE();
   char *substrings[] =
       { "91849", "18493", "84939", "49390", "93904", "39042", "90424",
      "04243"
   };
   slices_t expected = { 8, &substrings[0] };
   slices_t actual = slices("918493904243", 5);

   test_solution(&expected, &actual);
}

static void test_slice_length_is_too_large(void)
{
   TEST_IGNORE();
   char *substrings[] = { "" };
   slices_t expected = { 0, &substrings[0] };
   slices_t actual = slices("12345", 6);

   test_solution(&expected, &actual);
}

static void test_slice_length_cannot_be_zero(void)
{
   TEST_IGNORE();
   char *substrings[] = { "" };
   slices_t expected = { 0, &substrings[0] };
   slices_t actual = slices("12345", 0);

   test_solution(&expected, &actual);
}

static void test_empty_series_is_invalid(void)
{
   TEST_IGNORE();
   char *substrings[] = { "" };
   slices_t expected = { 0, &substrings[0] };
   slices_t actual = slices("", 1);

   test_solution(&expected, &actual);
}

int main(void)
{
   UnityBegin("test/test_series.c");

   RUN_TEST(test_slices_of_one_from_one);
   RUN_TEST(test_slices_of_one_from_two);
   RUN_TEST(test_slices_of_two);
   RUN_TEST(test_slices_of_two_overlap);
   RUN_TEST(test_slices_can_include_duplicates);
   RUN_TEST(test_slices_of_a_long_series);
   RUN_TEST(test_slice_length_is_too_large);
   RUN_TEST(test_slice_length_cannot_be_zero);
   RUN_TEST(test_empty_series_is_invalid);

   return UnityEnd();
}
