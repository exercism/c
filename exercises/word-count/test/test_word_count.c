#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"
#include "../src/word_count.h"

word_count_word_t actual_solution[MAX_WORDS];
word_count_word_t expected_solution[MAX_WORDS];
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
      TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_solution[index].text,
                                    actual_solution[index].text,
                                    MAX_WORD_LENGTH);
   }
}

// Tests Start here
void test_word_count_one_word(void)
{
   int index = 0;
   int actual_word_count;
   char *input_text = "word";
   const int expected_word_count = 1;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   // fill in the expected words
   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "word", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_one_of_each_word(void)
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
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "of", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "each", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_multiple_occurrences_of_a_word(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one fish two fish red fish blue fish";
   const int expected_word_count = 5;

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_handles_cramped_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,two,three";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_handles_expanded_lists(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "one,\ntwo,\nthree";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "one", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "two", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "three", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_ignore_punctuation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "car: carpet as java: javascript!!&@$%^&";
   const int expected_word_count = 5;

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_include_numbers(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "testing, 1, 2 testing";
   const int expected_word_count = 3;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "testing", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "1", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "2", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_normalize_case(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "go Go GO Stop stop";
   const int expected_word_count = 2;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "go", MAX_WORD_LENGTH);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text, "stop", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_with_apostrophes(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "First: don't laugh. Then: don't cry.";
   const int expected_word_count = 5;

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_with_quotation(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "Joe can't tell between 'large' and large.";
   const int expected_word_count = 6;

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_word_count_from_example(void)
{
   TEST_IGNORE();
   int index = 0;
   int actual_word_count;
   char *input_text = "olly olly in come free";
   const int expected_word_count = 4;

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

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_max_length_word(void)
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
   strncpy(expected_solution[index++].text, "look", MAX_WORD_LENGTH);

   expected_solution[index].count = 2;
   strncpy(expected_solution[index++].text,
           "thisisaveeeeeerylongwordtypedwithoutusinganyspaces",
           MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "and", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "again", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_excessive_length_word(void)
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
   strncpy(expected_solution[index++].text, "look", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_max_number_words(void)
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
   strncpy(expected_solution[index++].text, "once", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "upon", MAX_WORD_LENGTH);

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "a", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "time", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "long", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "while", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "the", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "past", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "there", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "lived", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "strange", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "little", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "man", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "who", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "could", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "spin", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "straw", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "into", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "gold", MAX_WORD_LENGTH);

   actual_word_count = word_count(input_text, actual_solution);

   check_solution(expected_solution,
                  expected_word_count, actual_solution, actual_word_count);
}

void test_excessive_number_words(void)
{
   TEST_IGNORE();
   int actual_word_count;
   int index = 0;
   char *input_text =
       "Once upon a time, a long while in the past, there lived a strange little man who could spin straw into gold. His name was...";

   const int expected_word_count = EXCESSIVE_NUMBER_OF_WORDS;

   // build the expected solution
   memset(expected_solution, 0, sizeof(expected_solution));     // clear to start with a known value

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "once", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "upon", MAX_WORD_LENGTH);

   expected_solution[index].count = 3;
   strncpy(expected_solution[index++].text, "a", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "time", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "long", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "while", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "in", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "the", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "past", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "there", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "lived", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "strange", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "little", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "man", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "who", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "could", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "spin", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "straw", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "into", MAX_WORD_LENGTH);

   expected_solution[index].count = 1;
   strncpy(expected_solution[index++].text, "gold", MAX_WORD_LENGTH);

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

   UnityEnd();

   return 0;
}
