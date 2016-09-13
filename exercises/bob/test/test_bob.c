#include "vendor/unity.h"
#include "../src/bob.h"

void test_stating_something(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("Tom-ay-to, tom-aaaah-to.")
       );
}

void test_shouting(void)
{
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("WATCH OUT!")
       );
}

void test_asking_a_question(void)
{
   TEST_ASSERT_EQUAL_STRING("Sure.",
                            hey_bob
                            ("Does this cryogenic chamber make me look fat?")
       );
}

void test_talking_forcefully(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob("Let's go make out behind the gym!")
       );
}

void test_using_acronyms_in_regular_speech(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob
                            ("It's OK if you don't want to go to the DMV.")
       );
}

void test_forceful_questions(void)
{
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!",
                            hey_bob("WHAT THE HELL WERE YOU THINKING?")
       );
}

void test_shouting_numbers(void)
{
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("1, 2, 3 GO!")
       );
}

void test_only_numbers(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("1, 2, 3")
       );
}

void test_question_with_only_numbers(void)
{
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob("4?")
       );
}

void test_shouting_with_special_characters(void)
{
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!",
                            hey_bob
                            ("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!")
       );
}

void test_shouting_with_no_exclamation_mark(void)
{
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("I HATE YOU")
       );
}

void test_statement_containing_question_mark(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob("Ending with a ? means a question.")
       );
}

void test_prattling_on(void)
{
   TEST_ASSERT_EQUAL_STRING("Sure.",
                            hey_bob("Wait! Hang on.  Are you going to be OK?")
       );
}

void test_question_with_trailing_whitespace(void)
{
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob("Are you ok? ")
       );
}

void test_silence(void)
{
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!", hey_bob("")
       );
}

void test_prolonged_silence(void)
{
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!", hey_bob("   ")
       );
}

void test_not_all_silence(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob(" A bit of silence can be nice.  ")
       );
}

int main(void)
{
   UnityBegin("test/test_bob.c");

   RUN_TEST(test_stating_something);
   RUN_TEST(test_shouting);
   RUN_TEST(test_asking_a_question);
   RUN_TEST(test_talking_forcefully);
   RUN_TEST(test_using_acronyms_in_regular_speech);
   RUN_TEST(test_forceful_questions);
   RUN_TEST(test_shouting_numbers);
   RUN_TEST(test_only_numbers);
   RUN_TEST(test_question_with_only_numbers);
   RUN_TEST(test_shouting_with_special_characters);
   RUN_TEST(test_shouting_with_no_exclamation_mark);
   RUN_TEST(test_statement_containing_question_mark);
   RUN_TEST(test_prattling_on);
   RUN_TEST(test_question_with_trailing_whitespace);
   RUN_TEST(test_silence);
   RUN_TEST(test_prolonged_silence);
   RUN_TEST(test_not_all_silence);

   UnityEnd();
   return 0;
}
