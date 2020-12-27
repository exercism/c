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
   candidates.candidate = NULL;
}

static struct candidates build_candidates(char *inputs, size_t count)
{
   struct candidates result;
   result.count = count;
   result.candidate = malloc(sizeof(struct candidate) * count);
   for (int i = 0; i < (int)count; i++) {
      result.candidate[i].word = &inputs[i * MAX_STR_LEN];
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

static void test_no_matches(void)
{
   char inputs[][MAX_STR_LEN] = {
      "hello",
      "world",
      "zombies",
      "pants"
   };

   char subject[] = { "diaper" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detect_two_anagrams(void)
{
   TEST_IGNORE();               // delete this line to run test
   char inputs[][MAX_STR_LEN] = {
      "stream",
      "Pigeon",
      "maters"
   };

   char subject[] = { "master" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { IS_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_does_not_detect_anagram_subsets(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "dog",
      "goody"
   };

   char subject[] = { "good" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detects_anagram(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "enlists",
      "google",
      "inlets",
      "banana"
   };

   char subject[] = { "listen" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { NOT_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_three_anagrams(void)
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

   char subject[] = { "allergy" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] =
       { IS_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM, IS_ANAGRAM,
      NOT_ANAGRAM
   };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detects_multiple_anagrams_with_different_case(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "Eons",
      "ONES"
   };

   char subject[] = { "nose" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { IS_ANAGRAM, IS_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_does_not_detect_non_anagrams_with_identical_checksum(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "last"
   };

   char subject[] = { "mass" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detects_anagrams_case_insensitively(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "cashregister",
      "Carthorse",
      "radishes"
   };

   char subject[] = { "Orchestra" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detects_anagram_using_case_insensitive_subject(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "cashregister",
      "carthorse",
      "radishes"
   };

   char subject[] = { "Orchestra" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_detects_anagrams_using_case_insensitive_possible_matches(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "cashregister",
      "Carthorse",
      "radishes"
   };

   char subject[] = { "orchestra" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void
test_does_not_detect_an_anagram_if_the_original_word_is_repeated(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "go",
      "Go",
      "GO"
   };

   char subject[] = { "orchestra" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_anagrams_must_use_all_letters_exactly_once(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "patter"
   };

   char subject[] = { "tapper" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_words_are_not_anagrams_of_themselves(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "BANANA",
      "Banana",
      "banana"
   };

   char subject[] = { "BANANA" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_words_other_than_themselves_can_be_anagrams(void)
{
   TEST_IGNORE();
   char inputs[][MAX_STR_LEN] = {
      "Listen",
      "Silent",
      "LISTEN"
   };

   char subject[] = { "LISTEN" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM, IS_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_unicode_anagrams(void)
{
   TEST_IGNORE();               // This is an extra credit test.  Delete this line to accept the challenge
   // These words don't make sense, they're just greek letters cobbled together.
   char inputs[][MAX_STR_LEN] = {
      "ΒΓΑ",
      "ΒΓΔ",
      "γβα"
   };

   char subject[] = { "ΑΒΓ" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { IS_ANAGRAM, NOT_ANAGRAM, NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

static void test_misleading_unicode_anagrams(void)
{
   TEST_IGNORE();               //This is an extra credit test, are you up for the challenge
   // Despite what a human might think these words different letters, the input uses Greek A and B
   // while the list of potential anagrams uses Latin A and B.
   char inputs[][MAX_STR_LEN] = {
      "ABΓ"
   };

   char subject[] = { "ΑΒΓ" };

   candidates = build_candidates(*inputs, sizeof(inputs) / MAX_STR_LEN);
   enum anagram_status expected[] = { NOT_ANAGRAM };

   find_anagrams(subject, &candidates);
   assert_correct_anagrams(&candidates, expected);
}

int main(void)
{
   UnityBegin("test/test_anagram.c");

   RUN_TEST(test_no_matches);
   RUN_TEST(test_detect_two_anagrams);
   RUN_TEST(test_does_not_detect_anagram_subsets);
   RUN_TEST(test_detects_anagram);
   RUN_TEST(test_three_anagrams);
   RUN_TEST(test_detects_multiple_anagrams_with_different_case);
   RUN_TEST(test_does_not_detect_non_anagrams_with_identical_checksum);
   RUN_TEST(test_detects_anagrams_case_insensitively);
   RUN_TEST(test_detects_anagram_using_case_insensitive_subject);
   RUN_TEST(test_detects_anagrams_using_case_insensitive_possible_matches);
   RUN_TEST(test_does_not_detect_an_anagram_if_the_original_word_is_repeated);
   RUN_TEST(test_anagrams_must_use_all_letters_exactly_once);
   RUN_TEST(test_words_are_not_anagrams_of_themselves);
   RUN_TEST(test_words_other_than_themselves_can_be_anagrams);

   // Bonus points
   RUN_TEST(test_unicode_anagrams);
   RUN_TEST(test_misleading_unicode_anagrams);

   return UnityEnd();
}
