#include "vendor/unity.h"
#include "../src/pangram.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_null(void)
{
   TEST_ASSERT_FALSE(is_pangram(NULL));
}

void test_empty_sentence(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char sentence[] = "";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_perfect_lowercase_pangram(void)
{
   TEST_IGNORE();
   const char sentence[] = "abcdefghijklmnopqrstuvwxyz";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_lowercase_pangram(void)
{
   TEST_IGNORE();
   const char sentence[] = "the quick brown fox jumps over the lazy dog";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_missing_character_x(void)
{
   TEST_IGNORE();
   const char sentence[] =
       "a quick movement of the enemy will jeopardize five gunboats";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_another_missing_h(void)
{
   TEST_IGNORE();
   const char sentence[] = "five boxing wizards jump quickly at it";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_pangram_with_underscores(void)
{
   TEST_IGNORE();
   const char sentence[] = "the_quick_brown_fox_jumps_over_the_lazy_dog";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_pangram_with_numbers(void)
{
   TEST_IGNORE();
   const char sentence[] = "the 1 quick brown fox jumps over the 2 lazy dogs";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_missing_letters_replaced_by_numbers(void)
{
   TEST_IGNORE();
   const char sentence[] = "7h3 qu1ck brown fox jumps ov3r 7h3 lazy dog";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_mixed_case_and_punctuation(void)
{
   TEST_IGNORE();
   const char sentence[] = "\"Five quacking Zephyrs jolt my wax bed.\"";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_upper_and_lower_case_of_same_character(void)
{
   TEST_IGNORE();
   const char sentence[] = "the quick brown fox jumps over with lazy FX";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

int main(void)
{
   UnityBegin("test/test_pangram.c");

   RUN_TEST(test_null);
   RUN_TEST(test_empty_sentence);
   RUN_TEST(test_perfect_lowercase_pangram);
   RUN_TEST(test_lowercase_pangram);
   RUN_TEST(test_missing_character_x);
   RUN_TEST(test_another_missing_h);
   RUN_TEST(test_pangram_with_underscores);
   RUN_TEST(test_pangram_with_numbers);
   RUN_TEST(test_missing_letters_replaced_by_numbers);
   RUN_TEST(test_mixed_case_and_punctuation);
   RUN_TEST(test_upper_and_lower_case_of_same_character);

   return UnityEnd();
}
