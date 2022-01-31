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

static void test_word_beginning_with_a(void)
{
   const char *phrase = "apple";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("appleay", res);
}

static void test_word_beginning_with_e(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char *phrase = "ear";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("earay", res);
}

static void test_word_beginning_with_i(void)
{
   TEST_IGNORE();
   const char *phrase = "igloo";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("iglooay", res);
}

static void test_word_beginning_with_o(void)
{
   TEST_IGNORE();
   const char *phrase = "object";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("objectay", res);
}

static void test_word_beginning_with_u(void)
{
   TEST_IGNORE();
   const char *phrase = "under";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("underay", res);
}

static void test_word_beginning_with_a_vowel_and_followed_by_a_qu(void)
{
   TEST_IGNORE();
   const char *phrase = "equal";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("equalay", res);
}

static void test_word_beginning_with_p(void)
{
   TEST_IGNORE();
   const char *phrase = "pig";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("igpay", res);
}

static void test_word_beginning_with_k(void)
{
   TEST_IGNORE();
   const char *phrase = "koala";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("oalakay", res);
}

static void test_word_beginning_with_x(void)
{
   TEST_IGNORE();
   const char *phrase = "xenon";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("enonxay", res);
}

static void test_word_beginning_with_q_without_a_following_u(void)
{
   TEST_IGNORE();
   const char *phrase = "qat";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("atqay", res);
}

static void test_word_beginning_with_ch(void)
{
   TEST_IGNORE();
   const char *phrase = "chair";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("airchay", res);
}

static void test_word_beginning_with_qu(void)
{
   TEST_IGNORE();
   const char *phrase = "queen";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("eenquay", res);
}

static void test_word_beginning_with_qu_and_a_preceding_consonant(void)
{
   TEST_IGNORE();
   const char *phrase = "square";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("aresquay", res);
}

static void test_word_beginning_with_th(void)
{
   TEST_IGNORE();
   const char *phrase = "therapy";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("erapythay", res);
}

static void test_word_beginning_with_thr(void)
{
   TEST_IGNORE();
   const char *phrase = "thrush";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ushthray", res);
}

static void test_word_beginning_with_sch(void)
{
   TEST_IGNORE();
   const char *phrase = "school";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("oolschay", res);
}

static void test_word_beginning_with_yt(void)
{
   TEST_IGNORE();
   const char *phrase = "yttria";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("yttriaay", res);
}

static void test_word_beginning_with_xr(void)
{
   TEST_IGNORE();
   const char *phrase = "xray";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("xrayay", res);
}

static void test_y_is_treated_like_a_consonant_at_the_beginning_of_a_word(void)
{
   TEST_IGNORE();
   const char *phrase = "yellow";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ellowyay", res);
}

static void
test_y_is_treated_like_a_vowel_at_the_end_of_a_consonant_cluster(void)
{
   TEST_IGNORE();
   const char *phrase = "rhythm";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ythmrhay", res);
}

static void test_y_as_second_letter_in_two_letter_word(void)
{
   TEST_IGNORE();
   const char *phrase = "my";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ymay", res);
}

static void test_a_whole_phrase(void)
{
   TEST_IGNORE();
   const char *phrase = "quick fast run";
   res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ickquay astfay unray", res);
}

int main(void)
{
   UnityBegin("test_pig_latin.c");

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

   return UnityEnd();
}
