#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

static void test_null(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FALSE(is_isogram(NULL));
}

static void test_lower_case_only(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("isogram"));
}

static void test_duplicated_letter(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("eleven"));
}

static void test_duplicated_letter_from_end_of_alphabet(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("zzyzx"));
}

static void test_longest_known_isogram(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("subdermatoglyphic"));
}

static void test_duplicated_letter_mixed_case(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("Alphabet"));
}

static void test_duplicated_letter_mixed_case_lowercase_first(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("alphAbet"));
}

static void test_non_letter_char(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("thumbscrew-japingly"));
}

static void test_duplicated_letter_following_non_letter_char(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("thumbscrew-jappingly"));
}

static void test_duplicated_non_letter_char(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("six-year-old"));
}

static void test_multiple_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("Emily Jung Schwartzkopf"));
}

static void test_duplicated_letter_within_word(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("accentor"));
}

static void test_same_first_and_last_characters(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("angola"));
}

int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_null);
   RUN_TEST(test_lower_case_only);
   RUN_TEST(test_duplicated_letter);
   RUN_TEST(test_duplicated_letter_from_end_of_alphabet);
   RUN_TEST(test_longest_known_isogram);
   RUN_TEST(test_duplicated_letter_mixed_case);
   RUN_TEST(test_duplicated_letter_mixed_case_lowercase_first);
   RUN_TEST(test_non_letter_char);
   RUN_TEST(test_duplicated_letter_following_non_letter_char);
   RUN_TEST(test_duplicated_non_letter_char);
   RUN_TEST(test_multiple_whitespace);
   RUN_TEST(test_duplicated_letter_within_word);
   RUN_TEST(test_same_first_and_last_characters);

   return UnityEnd();
}
