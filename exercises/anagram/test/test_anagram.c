#include <stdlib.h>
#include <string.h>

#include "vendor/unity.h"
#include "../src/anagram.h"

#define MAX_STR_LEN 20

void setUp(void)
{
}

void tearDown(void)
{
}

static struct candidates buildCandidates(char *inputs, size_t size)
{
   struct candidates result;
   result.size = (int)size;
   result.candidate = malloc(sizeof(struct candidate) * size);
   for (int i = 0; i < (int)size; i++) {
      result.candidate[i].candidate = &inputs[i * MAX_STR_LEN];
      result.candidate[i].isAnagram = UNCHECKED;
   }

   return result;
}

static void assert_correct_anagrams(struct candidates *candidates,
                                    enum anagramStatus expected[])
{
   for (int x = 0; x < candidates->size; x++) {
      TEST_ASSERT_EQUAL(expected[x], candidates->candidate[x].isAnagram);
   }
   free(candidates->candidate);
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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] =
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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { IS_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM, NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] =
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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] =
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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { IS_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

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

   struct candidates candidates =
       buildCandidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagramStatus expected[] = { NOT_ANAGRAM };

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
