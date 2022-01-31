#include "test-framework/unity.h"
#include "acronym.h"
#include <stdlib.h>
#include <string.h>

static char *actual = NULL;
void setUp(void)
{
}

void tearDown(void)
{
   if (actual)
      free(actual);
   actual = NULL;
}

static void check_abbreviation(char *phrase, char *expected)
{
   actual = abbreviate(phrase);
   TEST_ASSERT_EQUAL_STRING(expected, actual);
}

static void test_null_string(void)
{
   TEST_IGNORE();   // delete this line to run test
   char *phrase = NULL;
   char *expected = NULL;
   check_abbreviation(phrase, expected);
}

static void test_empty_string(void)
{
   TEST_IGNORE();
   char *phrase = "";
   char *expected = NULL;
   check_abbreviation(phrase, expected);
}

static void test_basic_abbreviation(void)
{
   TEST_IGNORE();
   char *phrase = "Portable Network Graphics";
   char *expected = "PNG";
   check_abbreviation(phrase, expected);
}

static void test_lowercase_words(void)
{
   TEST_IGNORE();
   char *phrase = "Ruby on Rails";
   char *expected = "ROR";
   check_abbreviation(phrase, expected);
}

static void test_punctuation(void)
{
   TEST_IGNORE();
   char *phrase = "First In, First Out";
   char *expected = "FIFO";
   check_abbreviation(phrase, expected);
}

static void test_all_caps_words(void)
{
   TEST_IGNORE();
   char *phrase = "GNU Image Manipulation Program";
   char *expected = "GIMP";
   check_abbreviation(phrase, expected);
}

static void test_punctuation_without_whitespace(void)
{
   TEST_IGNORE();
   char *phrase = "Complementary metal-oxide semiconductor";
   char *expected = "CMOS";
   check_abbreviation(phrase, expected);
}

static void test_long_abbreviation(void)
{
   TEST_IGNORE();
   char *phrase = "Rolling On The Floor Laughing So Hard "
                  "That My Dogs Came Over And Licked Me";
   char *expected = "ROTFLSHTMDCOALM";
   check_abbreviation(phrase, expected);
}

static void test_consecutive_delimiters_abbreviation(void)
{
   TEST_IGNORE();
   char *phrase = "Something - I made up from thin air";
   char *expected = "SIMUFTA";
   check_abbreviation(phrase, expected);
}

static void test_apostrophes(void)
{
   TEST_IGNORE();
   char *phrase = "Halley's Comet";
   char *expected = "HC";
   check_abbreviation(phrase, expected);
}

static void test_underscore_emphasis(void)
{
   TEST_IGNORE();
   char *phrase = "The Road _Not_ Taken";
   char *expected = "TRNT";
   check_abbreviation(phrase, expected);
}

int main(void)
{
   UnityBegin("test_acronym.c");

   RUN_TEST(test_null_string);
   RUN_TEST(test_empty_string);
   RUN_TEST(test_basic_abbreviation);
   RUN_TEST(test_lowercase_words);
   RUN_TEST(test_punctuation);
   RUN_TEST(test_all_caps_words);
   RUN_TEST(test_punctuation_without_whitespace);
   RUN_TEST(test_long_abbreviation);
   RUN_TEST(test_consecutive_delimiters_abbreviation);
   RUN_TEST(test_apostrophes);
   RUN_TEST(test_underscore_emphasis);

   return UnityEnd();
}
