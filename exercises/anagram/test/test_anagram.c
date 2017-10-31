#include <stdlib.h>
#include <string.h>

#include "vendor/unity.h"
#include "../src/anagram.h"

#define MAX_STR_LEN 20

struct candidates candidates;

void setUp(void)
{
}

void tearDown(void)
{
   free(candidates.candidate);
}

static struct candidates build_candidates(char *inputs, size_t count)
{
   struct candidates result;
   result.count = count;
   result.candidate = malloc(sizeof(struct candidate) * count);
   for (int i = 0; i < (int)count; i++) {
      result.candidate[i].candidate = &inputs[i * MAX_STR_LEN];
      result.candidate[i].is_anagram = UNCHECKED;
   }

   return result;
}

static void assert_correct_anagrams(struct candidates *candidates,
                                    enum anagram_status expected[])
{
   for (int i = 0; i < (int)candidates->count; i++) {
      TEST_ASSERT_EQUAL(expected[i], candidates->candidate[i].is_anagram);
   }
}

void test_no_matches(void)
{
   char inputs[][MAX_STR_LEN] = {
      "hello",
      "world",
      "zombies",
      "pants"
   };

   char word[] = { "diaper" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_detect_simple_anagram(void)
{
   TEST_IGNORE();               // delete this line to run test
   char inputs[][MAX_STR_LEN] = {
      "tan",
      "stand",
      "at"
   };

   char word[] = { "ant" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { IS_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);

}

void test_does_not_confuse_different_duplicates(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "eagle"
   };

   char word[] = { "galea" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_eliminate_anagram_subsets(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "dog",
      "goody"
   };

   char word[] = { "good" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_detect_anagram(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "enlists",
      "google",
      "inlets",
      "banana"
   };

   char word[] = { "listen" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { NOT_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_multiple_anagrams(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "gallery",
      "ballerina",
      "regally",
      "clergy",
      "largely",
      "leading"
   };

   char word[] = { "allergy" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { IS_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM,
      NOT_ANAGRAM
   };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_case_insensitive_anagrams(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "cashregister",
      "Carthorse",
      "radishes"
   };

   char word[] = { "Orchestra" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_does_not_detect_a_word_as_its_own_anagram(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "banana"
   };

   char word[] = { "banana" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_does_not_detect_a_differently_cased_word_as_its_own_anagram(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "bAnana"
   };

   char word[] = { "banana" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_unicode_anagrams(void)
{
   TEST_IGNORE();               // This is an extra credit test.  Delete this line to accept the challenge
   // These words don't make sense, they're just greek letters cobbled together.
   char inputs[][MAX_STR_LEN] = {
      "ΒΓΑ",
      "ΒΓΔ",
      "γβα"
   };

   char word[] = { "ΑΒΓ" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { IS_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

void test_misleading_unicode_anagrams(void)
{
   TEST_IGNORE();               //This is an extra credit test, are you up for the challenge
   // Despite what a human might think these words different letters, the input uses Greek A and B
   // while the list of potential anagrams uses Latin A and B.
   char inputs[][MAX_STR_LEN] = {
      "ABΓ"
   };

   char word[] = { "ΑΒΓ" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   anagrams_for(word, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

int main(void)
{
   UnityBegin("anagram.c");

   RUN_TEST(test_no_matches);
   RUN_TEST(test_detect_simple_anagram);
   RUN_TEST(test_does_not_confuse_different_duplicates);
   RUN_TEST(test_eliminate_anagram_subsets);
   RUN_TEST(test_detect_anagram);
   RUN_TEST(test_multiple_anagrams);
   RUN_TEST(test_case_insensitive_anagrams);
   RUN_TEST(test_does_not_detect_a_word_as_its_own_anagram);
   RUN_TEST(test_does_not_detect_a_differently_cased_word_as_its_own_anagram);

   // Bonus points
   RUN_TEST(test_unicode_anagrams);
   RUN_TEST(test_misleading_unicode_anagrams);

   UnityEnd();
   return 0;
}
