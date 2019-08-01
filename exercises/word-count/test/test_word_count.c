#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"
#include "../src/word_count.h"

#define STRING_SIZE (MAX_WORD_LENGTH + 1)

word_count_word_t actual_solution[MAX_WORDS];
word_count_word_t expected_solution[MAX_WORDS + 1];

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_solution(word_count_word_t * expected_solution,
                           int expected_word_count,
                           word_count_word_t * actual_solution,
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
static void test_word_count_one_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "word";
   const int expected_word_count = 1;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "word", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_one_of_each_word(void)
{
   TEST_IGNORE();               // delete this line to run test
   int index = 0;
   int actual_word_count;
   char *input_text = "one of each";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "of", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "each", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_multiple_occurrences_of_a_word(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one fish two fish red fish blue fish";
   const int expected_word_count = 5;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_handles_cramped_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,two,three";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_handles_expanded_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,\ntwo,\nthree";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_ignore_punctuation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "car: carpet as java: javascript!!&@$%^&";
   const int expected_word_count = 5;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_include_numbers(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "testing, 1, 2 testing";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "testing", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "1", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "2", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_normalize_case(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "go Go GO Stop stop";
   const int expected_word_count = 2;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "go", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "stop", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_with_apostrophes(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "First: don't laugh. Then: don't cry.";
   const int expected_word_count = 5;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_with_quotation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between 'large' and large.";
   const int expected_word_count = 6;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_word_count_from_example(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "olly olly in come free";
   const int expected_word_count = 4;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "olly", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "come", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "free", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_max_length_word(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text =
       "Look thisisaveeeeeerylongwordtypedwithoutusinganyspaces and look again, thisisaveeeeeerylongwordtypedwithoutusinganyspaces";

   const int expected_word_count = 4;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "look", STRING_SIZE);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text,
           "thisisaveeeeeerylongwordtypedwithoutusinganyspaces", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "and", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "again", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_excessive_length_word(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text =
       "Look thisisanexcessivelylongwordthatsomeonetypedwithoutusingthespacebar enough";

   const int expected_word_count = EXCESSIVE_LENGTH_WORD;
   word_count_word_t expected_solution[MAX_WORDS];

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "look", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_max_number_words(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text =
       "Once upon a time, a long while in the past, there lived a strange little man who could spin straw into gold";

   const int expected_word_count = 20;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "once", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "upon", STRING_SIZE);

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "a", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "time", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "long", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "while", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "the", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "past", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "there", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "lived", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "strange", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "little", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "man", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "who", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "could", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "spin", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "straw", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "into", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "gold", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

static void test_excessive_number_words(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text =
       "Once upon a time, a long while in the past, there lived a strange little man who could spin straw into pure gold.";

   const int expected_word_count = EXCESSIVE_NUMBER_OF_WORDS;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "once", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "upon", STRING_SIZE);

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "a", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "time", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "long", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "while", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "the", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "past", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "there", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "lived", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "strange", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "little", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "man", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "who", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "could", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "spin", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "straw", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "into", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "pure", STRING_SIZE);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "gold", STRING_SIZE);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
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
   RUN_TEST(test_max_length_word);
   RUN_TEST(test_excessive_length_word);
   RUN_TEST(test_max_number_words);
   RUN_TEST(test_excessive_number_words);

   return UnityEnd();
}
