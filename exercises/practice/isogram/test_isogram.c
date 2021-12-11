#include "test-framework/unity.h"
#include "isogram.h"
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
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_FALSE(is_isogram(NULL));
}

static void test_isogram_with_only_lower_case_characters(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("isogram"));
}

static void test_word_with_one_duplicated_character(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("eleven"));
}

static void test_word_with_one_duplicated_character_from_end_of_alphabet(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("zzyzx"));
}

static void test_longest_reported_english_isogram(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("subdermatoglyphic"));
}

static void test_word_with_duplicated_letter_in_mixed_case(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("Alphabet"));
}

static void test_word_with_duplicated_letter_in_mixed_case_lowercase_first(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("alphAbet"));
}

static void test_hypothetical_isogrammic_word_with_hyphen(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("thumbscrew-japingly"));
}

static void
test_hypothetical_word_with_duplicated_character_following_hyphen(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("thumbscrew-jappingly"));
}

static void test_isogram_with_duplicated_hyphen(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("six-year-old"));
}

static void test_made_up_name_that_is_an_isogram(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("Emily Jung Schwartzkopf"));
}

static void test_duplicated_character_in_the_middle(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("accentor"));
}

static void test_same_first_and_last_characters(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("angola"));
}

static void test_word_with_duplicated_character_and_with_two_hyphens(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("up-to-date"));
}

int main(void)
{
   UnityBegin("test_isogram.c");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_null);
   RUN_TEST(test_isogram_with_only_lower_case_characters);
   RUN_TEST(test_word_with_one_duplicated_character);
   RUN_TEST(test_word_with_one_duplicated_character_from_end_of_alphabet);
   RUN_TEST(test_longest_reported_english_isogram);
   RUN_TEST(test_word_with_duplicated_letter_in_mixed_case);
   RUN_TEST(test_word_with_duplicated_letter_in_mixed_case_lowercase_first);
   RUN_TEST(test_hypothetical_isogrammic_word_with_hyphen);
   RUN_TEST(test_hypothetical_word_with_duplicated_character_following_hyphen);
   RUN_TEST(test_isogram_with_duplicated_hyphen);
   RUN_TEST(test_made_up_name_that_is_an_isogram);
   RUN_TEST(test_duplicated_character_in_the_middle);
   RUN_TEST(test_same_first_and_last_characters);
   RUN_TEST(test_word_with_duplicated_character_and_with_two_hyphens);

   return UnityEnd();
}
