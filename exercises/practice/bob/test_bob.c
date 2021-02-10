#include "test-framework/unity.h"
#include "bob.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_stating_something(void)
{
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("Tom-ay-to, tom-aaaah-to.")
       );
}

static void test_shouting(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("WATCH OUT!")
       );
}

static void test_shouting_gibberish(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("FCECDFCAAB")
       );
}

static void test_asking_a_question(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.",
                            hey_bob
                            ("Does this cryogenic chamber make me look fat?")
       );
}

static void test_asking_a_numeric_question(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob("You are, what, like 15?")
       );
}

static void test_asking_gibberish(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob("fffbbcbeab?")
       );
}

static void test_talking_forcefully(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("Hi there!"));
}

static void test_using_acronyms_in_regular_speech(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob
                            ("It's OK if you don't want to go work for NASA.")
       );
}

static void test_forceful_question(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Calm down, I know what I'm doing!",
                            hey_bob("WHAT'S GOING ON?")
       );
}

static void test_shouting_numbers(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("1, 2, 3 GO!")
       );
}

static void test_only_numbers(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("1, 2, 3")
       );
}

static void test_question_with_only_numbers(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob("4?")
       );
}

static void test_shouting_with_special_characters(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!",
                            hey_bob
                            ("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!")
       );
}

static void test_shouting_with_no_exclamation_mark(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whoa, chill out!", hey_bob("I HATE THE DENTIST")
       );
}

static void test_statement_containing_question_mark(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob("Ending with ? means a question.")
       );
}

static void test_non_letters_with_question(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.", hey_bob(":) ?")
       );
}

static void test_prattling_on(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.",
                            hey_bob("Wait! Hang on.  Are you going to be OK?")
       );
}

static void test_silence(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!", hey_bob("")
       );
}

static void test_prolonged_silence(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!", hey_bob("          ")
       );
}

static void test_alternate_silence(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!",
                            hey_bob("\t\t\t\t\t\t\t\t\t\t")
       );
}

static void test_multiple_line_question(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob
                            ("\nDoes this cryogenic chamber make me look fat?\nNo")
       );
}

static void test_starting_with_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.", hey_bob("         hmmmmmmm...")
       );
}

static void test_ending_with_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Sure.",
                            hey_bob
                            ("Okay if like my  spacebar  quite a bit?   ")
       );
}

static void test_other_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Fine. Be that way!", hey_bob("\n\r \t")
       );
}

static void test_non_question_ending_with_whitespace(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Whatever.",
                            hey_bob
                            ("This is a statement ending with whitespace      ")
       );
}

int main(void)
{
   UnityBegin("test_bob.c");

   RUN_TEST(test_stating_something);
   RUN_TEST(test_shouting);
   RUN_TEST(test_shouting_gibberish);
   RUN_TEST(test_asking_a_question);
   RUN_TEST(test_asking_a_numeric_question);
   RUN_TEST(test_asking_gibberish);
   RUN_TEST(test_talking_forcefully);
   RUN_TEST(test_using_acronyms_in_regular_speech);
   RUN_TEST(test_forceful_question);
   RUN_TEST(test_shouting_numbers);
   RUN_TEST(test_only_numbers);
   RUN_TEST(test_question_with_only_numbers);
   RUN_TEST(test_shouting_with_special_characters);
   RUN_TEST(test_shouting_with_no_exclamation_mark);
   RUN_TEST(test_statement_containing_question_mark);
   RUN_TEST(test_non_letters_with_question);
   RUN_TEST(test_prattling_on);
   RUN_TEST(test_silence);
   RUN_TEST(test_prolonged_silence);
   RUN_TEST(test_alternate_silence);
   RUN_TEST(test_multiple_line_question);
   RUN_TEST(test_starting_with_whitespace);
   RUN_TEST(test_ending_with_whitespace);
   RUN_TEST(test_other_whitespace);
   RUN_TEST(test_non_question_ending_with_whitespace);

   return UnityEnd();
}
