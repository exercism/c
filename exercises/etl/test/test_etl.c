#include "vendor/unity.h"
#include "../src/etl.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static int compare_map(new_map * a, new_map * b, int len)
{
   if (a == NULL)
      return (b == NULL) ? 0 : 1;
   if (b == NULL)
      return 1;
   while (--len >= 0)
      if ((a[len].key != b[len].key) || (a[len].value != b[len].value))
         return 1;
   return !(len == -1);
}

void test_a_single_letter(void)
{
   legacy_map input[] = { {1, "A"} };
   int input_len = 1;

   new_map expected_map[] = { {'a', 1} };
   int expected_length = 1;

   new_map *output = NULL;
   int actual_length = convert(input, input_len, &output);

   TEST_ASSERT_EQUAL_INT(expected_length, actual_length);
   TEST_ASSERT_EQUAL_INT(0, compare_map(expected_map, output, actual_length));

   free(output);
}

void test_single_score_with_multiple_letters(void)
{
   TEST_IGNORE();               // delete this line to run test
   legacy_map input[] = { {1, "AEIOU"} };
   int input_len = 1;

   new_map expected_map[] = {
      {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}
   };
   int expected_length = 5;

   new_map *output = NULL;
   int actual_length = convert(input, input_len, &output);

   TEST_ASSERT_EQUAL_INT(expected_length, actual_length);
   TEST_ASSERT_EQUAL_INT(0, compare_map(expected_map, output, actual_length));

   free(output);
}

void test_multiple_scores_with_multiple_letters(void)
{
   TEST_IGNORE();
   legacy_map input[] = { {1, "AE"}, {2, "DG"} };
   int input_len = 2;

   new_map expected_map[] = {
      {'a', 1}, {'d', 2}, {'e', 1}, {'g', 2}
   };
   int expected_length = 4;

   new_map *output = NULL;
   int actual_length = convert(input, input_len, &output);

   TEST_ASSERT_EQUAL_INT(expected_length, actual_length);
   TEST_ASSERT_EQUAL_INT(0, compare_map(expected_map, output, actual_length));

   free(output);
}

void test_multiple_scores_with_differing_numbers_of_letters(void)
{
   TEST_IGNORE();
   legacy_map input[] = {
      {10, "QZ"}, {1, "AEIOULNRST"}, {3, "BCMP"}, {2, "DG"},
      {5, "K"}, {4, "FHVWY"}, {8, "JX"}
   };
   int input_len = 7;

   new_map expected_map[] = {
      {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2}, {'e', 1}, {'f', 4},
      {'g', 2}, {'h', 4}, {'i', 1}, {'j', 8}, {'k', 5}, {'l', 1},
      {'m', 3}, {'n', 1}, {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1},
      {'s', 1}, {'t', 1}, {'u', 1}, {'v', 4}, {'w', 4}, {'x', 8},
      {'y', 4}, {'z', 10}
   };
   int expected_length = 26;

   new_map *output = NULL;
   int actual_length = convert(input, input_len, &output);

   TEST_ASSERT_EQUAL_INT(expected_length, actual_length);
   TEST_ASSERT_EQUAL_INT(0, compare_map(expected_map, output, actual_length));

   free(output);
}

int main(void)
{
   UnityBegin("test/test_etl.c");

   RUN_TEST(test_a_single_letter);
   RUN_TEST(test_single_score_with_multiple_letters);
   RUN_TEST(test_multiple_scores_with_multiple_letters);
   RUN_TEST(test_multiple_scores_with_differing_numbers_of_letters);

   UnityEnd();
   return 0;
}
