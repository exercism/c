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

void test_longest_known_isogram(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_isogram("subdermatoglyphic"));
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

int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_lower_case_only);
   RUN_TEST(test_duplicated_letter);
   RUN_TEST(test_longest_known_isogram);
   RUN_TEST(test_duplicated_letter_mixed_case);
   RUN_TEST(test_non_letter_char);
   RUN_TEST(test_duplicated_non_letter_char);
   RUN_TEST(test_multiple_whitespace);
   RUN_TEST(test_duplicated_letter_within_word);

   UnityEnd();
   return 0;
}
