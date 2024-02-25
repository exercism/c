#include "test-framework/unity.h"
#include "pig_latin.h"
#include <stdlib.h>

static char *res = NULL;
void setUp(void)
{
}

void tearDown(void)
{
   if (res)
      free(res);
   res = NULL;
}

static void check_transate(const char *phrase, const char *expected)
{
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING(expected, res);
}

static void test_word_beginning_with_a(void)
{
   check_transate("apple", "appleay");
}

static void test_word_beginning_with_e(void)
{
   TEST_IGNORE();   // delete this line to run test
   check_transate("ear", "earay");
}

static void test_word_beginning_with_i(void)
{
   TEST_IGNORE();
   check_transate("igloo", "iglooay");
}

static void test_word_beginning_with_o(void)
{
   TEST_IGNORE();
   check_transate("object", "objectay");
}

static void test_word_beginning_with_u(void)
{
   TEST_IGNORE();
   check_transate("under", "underay");
}

static void test_word_beginning_with_a_vowel_and_followed_by_a_qu(void)
{
   TEST_IGNORE();
   check_transate("equal", "equalay");
}

static void test_word_beginning_with_p(void)
{
   TEST_IGNORE();
   check_transate("pig", "igpay");
}

static void test_word_beginning_with_k(void)
{
   TEST_IGNORE();
   check_transate("koala", "oalakay");
}

static void test_word_beginning_with_x(void)
{
   TEST_IGNORE();
   check_transate("xenon", "enonxay");
}

static void test_word_beginning_with_q_without_a_following_u(void)
{
   TEST_IGNORE();
   check_transate("qat", "atqay");
}

static void test_word_beginning_with_ch(void)
{
   TEST_IGNORE();
   check_transate("chair", "airchay");
}

static void test_word_beginning_with_qu(void)
{
   TEST_IGNORE();
   check_transate("queen", "eenquay");
}

static void test_word_beginning_with_qu_and_a_preceding_consonant(void)
{
   TEST_IGNORE();
   check_transate("square", "aresquay");
}

static void test_word_beginning_with_th(void)
{
   TEST_IGNORE();
   check_transate("therapy", "erapythay");
}

static void test_word_beginning_with_thr(void)
{
   TEST_IGNORE();
   check_transate("thrush", "ushthray");
}

static void test_word_beginning_with_sch(void)
{
   TEST_IGNORE();
   check_transate("school", "oolschay");
}

static void test_word_beginning_with_yt(void)
{
   TEST_IGNORE();
   check_transate("yttria", "yttriaay");
}

static void test_word_beginning_with_xr(void)
{
   TEST_IGNORE();
   check_transate("xray", "xrayay");
}

static void test_y_is_treated_like_a_consonant_at_the_beginning_of_a_word(void)
{
   TEST_IGNORE();
   check_transate("yellow", "ellowyay");
}

static void
test_y_is_treated_like_a_vowel_at_the_end_of_a_consonant_cluster(void)
{
   TEST_IGNORE();
   check_transate("rhythm", "ythmrhay");
}

static void test_y_as_second_letter_in_two_letter_word(void)
{
   TEST_IGNORE();
   check_transate("my", "ymay");
}

static void test_a_whole_phrase(void)
{
   TEST_IGNORE();
   check_transate("quick fast run", "ickquay astfay unray");
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_word_beginning_with_a);
   RUN_TEST(test_word_beginning_with_e);
   RUN_TEST(test_word_beginning_with_i);
   RUN_TEST(test_word_beginning_with_o);
   RUN_TEST(test_word_beginning_with_u);
   RUN_TEST(test_word_beginning_with_a_vowel_and_followed_by_a_qu);
   RUN_TEST(test_word_beginning_with_p);
   RUN_TEST(test_word_beginning_with_k);
   RUN_TEST(test_word_beginning_with_x);
   RUN_TEST(test_word_beginning_with_q_without_a_following_u);
   RUN_TEST(test_word_beginning_with_ch);
   RUN_TEST(test_word_beginning_with_qu);
   RUN_TEST(test_word_beginning_with_qu_and_a_preceding_consonant);
   RUN_TEST(test_word_beginning_with_th);
   RUN_TEST(test_word_beginning_with_thr);
   RUN_TEST(test_word_beginning_with_sch);
   RUN_TEST(test_word_beginning_with_yt);
   RUN_TEST(test_word_beginning_with_xr);
   RUN_TEST(test_y_is_treated_like_a_consonant_at_the_beginning_of_a_word);
   RUN_TEST(test_y_is_treated_like_a_vowel_at_the_end_of_a_consonant_cluster);
   RUN_TEST(test_y_as_second_letter_in_two_letter_word);
   RUN_TEST(test_a_whole_phrase);

   return UNITY_END();
}
