#include "vendor/unity.h"
#include "../src/pangram.h"

void test_null(void)
{
   TEST_ASSERT_FALSE(is_pangram(NULL));
}

void test_empty_sentence(void)
{
   const char sentence[] = "";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_lowercase_pangram(void)
{
   const char sentence[] = "the quick brown fox jumps over the lazy dog";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_uppercase_pangram(void)
{
   const char sentence[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_missing_character_x(void)
{
   const char sentence[] =
       "a quick movement of the enemy will jeopardize five gunboats";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_another_missing_x(void)
{
   const char sentence[] = "the quick brown fish jumps over the lazy dog";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_pangram_with_underscores(void)
{
   const char sentence[] = "the_quick_brown_fox_jumps_over_the_lazy_dog";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_pangram_with_numbers(void)
{
   const char sentence[] = "the 1 quick brown fox jumps over the 2 lazy dogs";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_missing_letters_replaced_by_numbers(void)
{
   const char sentence[] = "7h3 qu1ck brown fox jumps ov3r 7h3 lazy dog";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

void test_mixed_case_and_punctuation(void)
{
   const char sentence[] = "\"Five quacking Zephyrs jolt my wax bed.\"";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_non_ascii_characters(void)
{
   const char sentence[] =
       "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich.";

   TEST_ASSERT_TRUE(is_pangram(sentence));
}

void test_pangram_in_alphabet_other_than_ascii(void)
{
   const char sentence[] =
       "Широкая электрификация южных губерний даст мощный толчок подъёму сельского хозяйства.";

   TEST_ASSERT_FALSE(is_pangram(sentence));
}

int main(void)
{
   UnityBegin("test/test_pangram.c");

   RUN_TEST(test_null);
   RUN_TEST(test_empty_sentence);
   RUN_TEST(test_lowercase_pangram);
   RUN_TEST(test_uppercase_pangram);
   RUN_TEST(test_missing_character_x);
   RUN_TEST(test_another_missing_x);
   RUN_TEST(test_pangram_with_underscores);
   RUN_TEST(test_pangram_with_numbers);
   RUN_TEST(test_missing_letters_replaced_by_numbers);
   RUN_TEST(test_mixed_case_and_punctuation);
   RUN_TEST(test_non_ascii_characters);
   RUN_TEST(test_pangram_in_alphabet_other_than_ascii);

   UnityEnd();
   return 0;
}
