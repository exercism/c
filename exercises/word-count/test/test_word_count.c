#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"
#include "../src/word_count.h"

word_count_word_t actual_solution[MAX_WORDS];

static void test_solution(word_count_word_t * expected_solution,
                          int expected_word_count,
                          word_count_word_t * actual_solution,
                          int actual_word_count)
{
   // All words counted?
   TEST_ASSERT_EQUAL(expected_word_count, actual_word_count);

   // now test the word count for the words...
   for (int index = 0; index < actual_word_count; index++) {
      TEST_ASSERT_EQUAL(expected_solution[index].count,
                        actual_solution[index].count);
      TEST_ASSERT_EQUAL_STRING(expected_solution[index].text,
                               actual_solution[index].text);
   }
}

static void reset_actual_solution(void)
{
   memset(actual_solution, 0, sizeof(actual_solution));
}

// Tests Start here
void test_word_count_one_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "word";
   const int expected_word_count = 1;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "word", MAX_WORD_LENGTH);

   reset_actual_solution();

   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_one_of_each_word(void)
{
   TEST_IGNORE();               // delete this line to run test
   int index = 0;
   int actual_word_count;
   char *input_text = "one of each";
   const int expected_word_count = 3;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "of", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "each", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_multiple_occurrences_of_a_word(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one fish two fish red fish blue fish";
   const int expected_word_count = 5;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 4;
   strncpy(expected_solution[index++].text, "fish", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "red", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "blue", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_handles_cramped_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,two,three";
   const int expected_word_count = 3;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_handles_expanded_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,\ntwo,\nthree";
   const int expected_word_count = 3;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_ignore_punctuation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "car: carpet as java: javascript!!&@$%^&";
   const int expected_word_count = 5;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "car", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "carpet", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "as", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "java", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "javascript", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_include_numbers(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "testing, 1, 2 testing";
   const int expected_word_count = 3;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "testing", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "1", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "2", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_normalize_case(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "go Go GO Stop stop";
   const int expected_word_count = 2;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "go", MAX_WORD_LENGTH);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "stop", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_with_apostrophes(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "First: don't laugh. Then: don't cry.";
   const int expected_word_count = 5;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "first", MAX_WORD_LENGTH);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "don't", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "laugh", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "then", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "cry", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_with_quotation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between 'large' and large.";
   const int expected_word_count = 6;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "joe", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "can't", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "tell", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "between", MAX_WORD_LENGTH);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "large", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "and", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_from_example(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "olly olly in come free";
   const int expected_word_count = 4;
   word_count_word_t expected_solution[expected_word_count];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "olly", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "come", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "free", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, actual_solution);

   test_solution(expected_solution,
                 expected_word_count, actual_solution, actual_word_count);
}

int main(void)
{
   UnityBegin("test/test_word_count.c");

   RUN_TEST(test_word_count_one_word);
   RUN_TEST(test_word_count_one_of_each_word);
   RUN_TEST(test_word_count_multiple_occurrences_of_a_word);
   RUN_TEST(test_word_count_handles_cramped_lists);
   RUN_TEST(test_word_count_handles_expanded_lists);
   RUN_TEST(test_word_count_ignore_punctuation);
   RUN_TEST(test_word_count_include_numbers);
   RUN_TEST(test_word_count_normalize_case);
   RUN_TEST(test_word_count_with_apostrophes);
   RUN_TEST(test_word_count_with_quotation);
   RUN_TEST(test_word_count_from_example);

   UnityEnd();

   return 0;
}
