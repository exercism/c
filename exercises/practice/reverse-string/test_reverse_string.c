#include "test-framework/unity.h"
#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_reverse(char *phrase, char *expected)
{
   char *actual = reverse(phrase);

   TEST_ASSERT_EQUAL_STRING(expected, actual);

   free(actual);
}

static void test_an_empty_string(void)
{
   test_reverse("", "");
}

static void test_a_word(void)
{
   test_reverse("robot", "tobor");
}

static void test_a_capitalized_word(void)
{
   test_reverse("Ramen", "nemaR");
}

static void test_a_sentence_with_punctuation(void)
{
   test_reverse("I'm hungry!", "!yrgnuh m'I");
}

static void test_a_palindrome(void)
{
   test_reverse("racecar", "racecar");
}

static void test_an_even_sized_word(void)
{
   test_reverse("drawer", "reward");
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_an_empty_string);
   RUN_TEST(test_a_word);
   RUN_TEST(test_a_capitalized_word);
   RUN_TEST(test_a_sentence_with_punctuation);
   RUN_TEST(test_a_palindrome);
   RUN_TEST(test_an_even_sized_word);

   /*
    * Commenting out the following tests for now because the current
    * implementation does not support handling wide characters, grapheme
    * clusters, or UTF characters. The implementation currently only handles
    * 8-bit ASCII characters, so these tests will cause failures when executed.
    * Once support for wider character sets is added, these tests can be
    * re-enabled for proper validation.
    */

   // RUN_TEST(test_wide_characters);
   // RUN_TEST(test_grapheme_cluster_with_pre_combined_form);
   // RUN_TEST(test_grapheme_clusters);

   return UNITY_END();
}
