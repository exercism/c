#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"
#include "../src/word_count.h"

WordCount_Word_t ActualSolution[MAX_WORDS];

static void test_solution(WordCount_Word_t * expected_solution,
                          int expected_word_count,
                          WordCount_Word_t * actual_solution,
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
   memset(ActualSolution, 0, sizeof(ActualSolution));
}

// Tests Start here
void test_word_count_one_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "word";
   const int expected_word_count = 1;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   // fill in the expected words
   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "word", MAX_WORD_LENGTH);

   reset_actual_solution();

   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_one_of_each_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "one of each";
   const int expected_word_count = 3;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   // fill in the expected words
   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "one", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "of", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "each", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_multiple_occurrences_of_a_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "one fish two fish red fish blue fish";
   const int expected_word_count = 5;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "one", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 4;
   strncpy(ExpectedSolution[index++].text, "fish", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "two", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "red", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "blue", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_handles_cramped_lists(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "one,two,three";
   const int expected_word_count = 3;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "one", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "two", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "three", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_handles_expanded_lists(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "one,\ntwo,\nthree";
   const int expected_word_count = 3;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "one", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "two", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "three", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_ignore_punctuation(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "car: carpet as java: javascript!!&@$%^&";
   const int expected_word_count = 5;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "car", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "carpet", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "as", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "java", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "javascript", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_include_numbers(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "testing, 1, 2 testing";
   const int expected_word_count = 3;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 2;
   strncpy(ExpectedSolution[index++].text, "testing", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "1", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "2", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_normalize_case(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "go Go GO Stop stop";
   const int expected_word_count = 2;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 3;
   strncpy(ExpectedSolution[index++].text, "go", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 2;
   strncpy(ExpectedSolution[index++].text, "stop", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_with_apostrophes(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "First: don't laugh. Then: don't cry.";
   const int expected_word_count = 5;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "first", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 2;
   strncpy(ExpectedSolution[index++].text, "don't", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "laugh", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "then", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "cry", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_with_quotation(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between 'large' and large.";
   const int expected_word_count = 6;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "joe", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "can't", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "tell", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "between", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 2;
   strncpy(ExpectedSolution[index++].text, "large", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "and", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
}

void test_word_count_from_example(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "olly olly in come free";
   const int expected_word_count = 4;
   WordCount_Word_t ExpectedSolution[expected_word_count];

   // build the expected solution
   memset(ExpectedSolution, 0, sizeof(ExpectedSolution));       // clear to start with a known value

   ExpectedSolution[index].count = 2;
   strncpy(ExpectedSolution[index++].text, "olly", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "in", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "come", MAX_WORD_LENGTH);

   ExpectedSolution[index].count = 1;
   strncpy(ExpectedSolution[index++].text, "free", MAX_WORD_LENGTH);

   reset_actual_solution();
   actual_word_count = word_count(input_text, ActualSolution);

   test_solution(ExpectedSolution,
                 expected_word_count, ActualSolution, actual_word_count);
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
