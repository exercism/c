#include <stdlib.h>
#include <string.h>

#include "vendor/unity.h"
#include "../src/anagram.h"

// Empty vector for when expected output is nothing
struct Vector empty = {
   NULL,
   0
};

int stringcmp(const void *a, const void *b)
{
   return strcmp(a, b);
}

// Helper function to verify the correct output
void check_anagrams(char *in, struct Vector vin, struct Vector expected)
{
   struct Vector vout = anagrams_for(in, vin);

   // Sort actual and expected outputs for consistency
   qsort(expected.vec, expected.size, sizeof(char) * MAX_STR_LEN, stringcmp);
   qsort(vout.vec, vout.size, sizeof(char) * MAX_STR_LEN, stringcmp);

   TEST_ASSERT_EQUAL(expected.size, vout.size);
   for (int x = 0; x < vout.size; x++) {
      TEST_ASSERT_EQUAL(strlen(expected.vec[x]), strlen(vout.vec[x]));
      TEST_ASSERT_EQUAL_MEMORY(expected.vec[x], vout.vec[x],
                               strlen(expected.vec[x]));
   }
   free(vout.vec);
}

void test_no_matches(void)
{
   char inputs[][MAX_STR_LEN] = {
      "hello",
      "world",
      "zombies",
      "pants"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("diaper", vin, empty);
}

void test_detect_simple_anagram(void)
{
   char inputs[][MAX_STR_LEN] = {
      "tan",
      "stand",
      "at"
   };

   char outputs[][MAX_STR_LEN] = {
      "tan"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   struct Vector expected = {
      outputs,
      sizeof(outputs) / MAX_STR_LEN
   };

   check_anagrams("ant", vin, expected);
}

void test_does_not_confuse_different_duplicates(void)
{
   char inputs[][MAX_STR_LEN] = {
      "eagle"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("galea", vin, empty);
}

void test_eliminate_anagram_subsets(void)
{
   char inputs[][MAX_STR_LEN] = {
      "dog",
      "goody"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("good", vin, empty);
}

void test_detect_anagram(void)
{
   char inputs[][MAX_STR_LEN] = {
      "enlists",
      "google",
      "inlets",
      "banana"
   };

   char outputs[][MAX_STR_LEN] = {
      "inlets"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   struct Vector expected = {
      outputs,
      sizeof(outputs) / MAX_STR_LEN
   };

   check_anagrams("listen", vin, expected);
}

void test_multiple_anagrams(void)
{
   char inputs[][MAX_STR_LEN] = {
      "gallery",
      "ballerina",
      "regally",
      "clergy",
      "largely",
      "leading"
   };

   char outputs[][MAX_STR_LEN] = {
      "gallery",
      "regally",
      "largely"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   struct Vector expected = {
      outputs,
      sizeof(outputs) / MAX_STR_LEN
   };

   check_anagrams("allergy", vin, expected);
}

void test_case_insensitive_anagrams(void)
{
   char inputs[][MAX_STR_LEN] = {
      "cashregister",
      "Carthorse",
      "radishes"
   };

   char outputs[][MAX_STR_LEN] = {
      "Carthorse"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   struct Vector expected = {
      outputs,
      sizeof(outputs) / MAX_STR_LEN
   };

   check_anagrams("Orchestra", vin, expected);
}

void test_unicode_anagrams(void)
{
   // These words don't make sense, they're just greek letters cobbled together.
   char inputs[][MAX_STR_LEN] = {
      "ΒΓΑ",
      "ΒΓΔ",
      "γβα"
   };

   char outputs[][MAX_STR_LEN] = {
      "ΒΓΑ"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   struct Vector expected = {
      outputs,
      sizeof(outputs) / MAX_STR_LEN
   };

   check_anagrams("ΑΒΓ", vin, expected);
}

void test_misleading_unicode_anagrams(void)
{
   // Despite what a human might think these words different letters, the input uses Greek A and B
   // while the list of potential anagrams uses Latin A and B.
   char inputs[][MAX_STR_LEN] = {
      "ABΓ"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("ΑΒΓ", vin, empty);
}

void test_does_not_detect_a_word_as_its_own_anagram(void)
{
   char inputs[][MAX_STR_LEN] = {
      "banana"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("banana", vin, empty);
}

void test_does_not_detect_a_differently_cased_word_as_its_own_anagram(void)
{
   char inputs[][MAX_STR_LEN] = {
      "bAnana"
   };

   struct Vector vin = {
      inputs,
      sizeof(inputs) / MAX_STR_LEN
   };

   check_anagrams("banana", vin, empty);
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
   // RUN_TEST(test_unicode_anagrams);
   // RUN_TEST(test_misleading_unicode_anagrams);

   UnityEnd();
   return 0;
}
