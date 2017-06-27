#include "vendor/unity.h"
#include "../src/acronym.h"
#include <stdlib.h>
#include <string.h>

void test_abbreviation(char *phrase, char *expected)
{
   char *actual = abbreviate(phrase);
   TEST_ASSERT_EQUAL_STRING(expected, actual);
   free(actual);
}

void test_basic_abbreviation(void)
{
   char *phrase = "Portable Network Graphics";
   char *expected = "PNG";
   test_abbreviation(phrase, expected);
}

void test_lower_case_words(void)
{
   char *phrase = "Ruby on Rails";
   char *expected = "ROR";
   test_abbreviation(phrase, expected);
}

void test_punctuation(void)
{
   char *phrase = "First In, First Out";
   char *expected = "FIFO";
   test_abbreviation(phrase, expected);
}

void test_all_caps_words(void)
{
   char *phrase = "PHP: Hypertext Preprocessor";
   char *expected = "PHP";
   test_abbreviation(phrase, expected);
}

void test_non_acronym_all_caps_words(void)
{
   char *phrase = "GNU Image Manipulation Program";
   char *expected = "GIMP";
   test_abbreviation(phrase, expected);
}

void test_hyphenated(void)
{
   char *phrase = "Complementary metal-oxide semiconductor";
   char *expected = "CMOS";
   test_abbreviation(phrase, expected);
}

int main(void)
{
   UnityBegin("test/test_acronym.c");

   RUN_TEST(test_basic_abbreviation);
   RUN_TEST(test_lower_case_words);
   RUN_TEST(test_punctuation);
   RUN_TEST(test_all_caps_words);
   RUN_TEST(test_non_acronym_all_caps_words);
   RUN_TEST(test_hyphenated);

   UnityEnd();
   return 0;
}
