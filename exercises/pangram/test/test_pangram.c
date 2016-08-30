#include "vendor/unity.h"
#include "../src/pangram.h"

void test_empty_sentence(void) {
   const char sentence[] = "";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_lowercase_pangram(void) {
   const char sentence[] = "the quick brown fox jumps over the lazy dog";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_uppercase_pangram(void) {
   const char sentence[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_missing_character_x(void) {
   const char sentence[] = "a quick movement of the enemy will jeopardize five gunboats";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_mixed_case_and_punctuation(void) {
   const char sentence[] = "\"Five quacking Zephyrs jolt my wax bed.\"";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_non_ascii_characters(void) {
   const char sentence[] = "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich.";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

int main(void) {
  UnityBegin("test/test_pangram.c");

  RUN_TEST(test_empty_sentence);
  RUN_TEST(test_lowercase_pangram);
  RUN_TEST(test_uppercase_pangram);
  RUN_TEST(test_missing_character_x);
  RUN_TEST(test_mixed_case_and_punctuation);
  RUN_TEST(test_non_ascii_characters);

  UnityEnd();
  return 0;
}
