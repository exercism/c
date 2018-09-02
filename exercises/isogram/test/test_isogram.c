#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

void test_null(void)
{
   TEST_ASSERT_TRUE(is_isogram(NULL));
}

void test_lower_case_only(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_TRUE(is_isogram("isogram"));
}

void test_duplicated_letter(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("eleven"));
}

void test_duplicated_letter_from_end_of_alphabet(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("zzyzx"));
}

void test_longest_known_isogram(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("subdermatoglyphic"));
}

void test_duplicated_on_ends(void)
{
   TEST_ASSERT_FALSE(is_isogram("oreo"));
}

void test_duplicated_letter_mixed_case(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("Alphabet"));
}

void test_non_letter_char(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("thumbscrew-japingly"));
}

void test_duplicated_non_letter_char(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("Hjelmqvist-Gryb-Zock-Pfund-Wax"));
}

void test_multiple_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("Emily Jung Schwartzkopf"));
}

void test_duplicated_letter_within_word(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(is_isogram("accentor"));
}

void test_quit_early(void)
{
   clock_t a, b;
   double small, big;
   const char small_word[] = "aa";
   const char big_word[10000] = { 'a' };
   
   a = clock();
   is_isogram(small_word);
   b = clock();
   
   small = (double)(b - a);
   
   a = clock();
   is_isogram(big_word);
   b = clock();
   
   big = (double)(b - a);

   TEST_ASSERT_FLOAT_WITHIN(small, big, small);
}

int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_null);
   RUN_TEST(test_lower_case_only);
   RUN_TEST(test_duplicated_letter);
   RUN_TEST(test_duplicated_on_ends);
   RUN_TEST(test_duplicated_letter_from_end_of_alphabet);
   RUN_TEST(test_longest_known_isogram);
   RUN_TEST(test_duplicated_letter_mixed_case);
   RUN_TEST(test_non_letter_char);
   RUN_TEST(test_duplicated_non_letter_char);
   RUN_TEST(test_multiple_whitespace);
   RUN_TEST(test_duplicated_letter_within_word);
   RUN_TEST(test_quit_early);

   UnityEnd();
   return 0;
}
