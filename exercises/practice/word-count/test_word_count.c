#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "test-framework/unity.h"
#include "word_count.h"

#define STRING_SIZE (MAX_WORD_LENGTH + 1)

word_count_word_t actual_solution[MAX_WORDS];
word_count_word_t expected_solution[MAX_WORDS + 1];

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_solution(word_count_word_t *expected_solution,
                           int expected_word_count,
                           word_count_word_t *actual_solution,
                           int actual_word_count)
{
   // All words counted?
   TEST_ASSERT_EQUAL(expected_word_count, actual_word_count);

   // now test the word count for the words...
   for (int index = 0; index < MAX_WORDS; index++) {
      TEST_ASSERT_EQUAL(expected_solution[index].count,
                        actual_solution[index].count);
      TEST_ASSERT_EQUAL_STRING_LEN(expected_solution[index].text,
                                   actual_solution[index].text,
                                   strlen(expected_solution[index].text) + 1);
   }
}

// Tests Start here
static void test_count_one_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "word";
   const int expected_word_count = 1;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "word", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_count_one_of_each_word(void)
{
   TEST_IGNORE();   // delete this line to run test
   int index = 0;
   int actual_word_count;
   char *input_text = "one of each";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "of", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "each", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_multiple_occurrences_of_a_word(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one fish two fish red fish blue fish";
   const int expected_word_count = 5;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 4;
   strncpy(expected_solution[index++].text, "fish", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "red", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "blue", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_handles_cramped_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,two,three";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_handles_expanded_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,\ntwo,\nthree";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_ignore_punctuation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "car: carpet as java: javascript!!&@$%^&";
   const int expected_word_count = 5;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "car", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "carpet", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "as", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "java", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "javascript", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_include_numbers(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "testing, 1, 2 testing";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "testing", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "1", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "2", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_normalize_case(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "go Go GO Stop stop";
   const int expected_word_count = 2;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "go", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "stop", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_with_apostrophes(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "First: don't laugh. Then: don't cry. You're getting it.";
   const int expected_word_count = 8;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "first", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "don't", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "laugh", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "then", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "cry", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "you're", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "getting", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "it", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_with_quotations(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between 'large' and large.";
   const int expected_word_count = 6;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "joe", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "can't", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "tell", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "between", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "large", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "and", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_substrings_from_the_beginning(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between app, apple and a.";
   const int expected_word_count = 8;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "joe", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "can't", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "tell", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "between", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "app", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "apple", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "and", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "a", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_multiple_spaces_not_detected_as_a_word(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text = " multiple   whitespaces";

   const int expected_word_count = 2;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "multiple", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "whitespaces", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_alternating_word_separators_not_detected_as_a_word(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text = ",\n,one,\n ,two \n 'three'";

   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

static void test_quotation_for_word_with_apostrophe(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text = "can, can't, 'can't'";

   const int expected_word_count = 2;

   // build the expected solution
   memset(expected_solution, 0,
          sizeof(expected_solution));   // clear to start with a known value
   memset(actual_solution, 0, sizeof(actual_solution));

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "can", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "can't", STRING_SIZE);

   actual_word_count = count_words(input_text, actual_solution);

   check_solution(expected_solution, expected_word_count, actual_solution,
                  actual_word_count);
}

int main(void)
{
   UnityBegin("test_word_count.c");

   RUN_TEST(test_count_one_word);
   RUN_TEST(test_count_one_of_each_word);
   RUN_TEST(test_multiple_occurrences_of_a_word);
   RUN_TEST(test_handles_cramped_lists);
   RUN_TEST(test_handles_expanded_lists);
   RUN_TEST(test_ignore_punctuation);
   RUN_TEST(test_include_numbers);
   RUN_TEST(test_normalize_case);
   RUN_TEST(test_with_apostrophes);
   RUN_TEST(test_with_quotations);
   RUN_TEST(test_substrings_from_the_beginning);
   RUN_TEST(test_multiple_spaces_not_detected_as_a_word);
   RUN_TEST(test_alternating_word_separators_not_detected_as_a_word);
   RUN_TEST(test_quotation_for_word_with_apostrophe);

   return UnityEnd();
}
