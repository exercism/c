#include "vendor/unity.h"
#include "../src/pig_latin.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_word_beginning_with_a(void)
{
   const char *phrase = "apple";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("appleay", res);
   free(res);
}

static void test_word_beginning_with_e(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char *phrase = "ear";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("earay", res);
   free(res);
}

static void test_word_beginning_with_i(void)
{
   TEST_IGNORE();
   const char *phrase = "igloo";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("iglooay", res);
   free(res);
}

static void test_word_beginning_with_o(void)
{
   TEST_IGNORE();
   const char *phrase = "object";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("objectay", res);
   free(res);
}

static void test_word_beginning_with_u(void)
{
   TEST_IGNORE();
   const char *phrase = "under";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("underay", res);
   free(res);
}

static void test_word_beginning_with_a_vowel_and_followed_by_a_qu(void)
{
   TEST_IGNORE();
   const char *phrase = "equal";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("equalay", res);
   free(res);
}

static void test_word_beginning_with_p(void)
{
   TEST_IGNORE();
   const char *phrase = "pig";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("igpay", res);
   free(res);
}

static void test_word_beginning_with_k(void)
{
   TEST_IGNORE();
   const char *phrase = "koala";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("oalakay", res);
   free(res);
}

static void test_word_beginning_with_x(void)
{
   TEST_IGNORE();
   const char *phrase = "xenon";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("enonxay", res);
   free(res);
}

static void test_word_beginning_with_q_without_a_following_u(void)
{
   TEST_IGNORE();
   const char *phrase = "qat";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("atqay", res);
   free(res);
}

static void test_word_beginning_with_ch(void)
{
   TEST_IGNORE();
   const char *phrase = "chair";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("airchay", res);
   free(res);
}

static void test_word_beginning_with_qu(void)
{
   TEST_IGNORE();
   const char *phrase = "queen";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("eenquay", res);
   free(res);
}

static void test_word_beginning_with_qu_and_a_preceding_consonant(void)
{
   TEST_IGNORE();
   const char *phrase = "square";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("aresquay", res);
   free(res);
}

static void test_word_beginning_with_th(void)
{
   TEST_IGNORE();
   const char *phrase = "therapy";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("erapythay", res);
   free(res);
}

static void test_word_beginning_with_thr(void)
{
   TEST_IGNORE();
   const char *phrase = "thrush";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ushthray", res);
   free(res);
}

static void test_word_beginning_with_sch(void)
{
   TEST_IGNORE();
   const char *phrase = "school";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("oolschay", res);
   free(res);
}

static void test_word_beginning_with_yt(void)
{
   TEST_IGNORE();
   const char *phrase = "yttria";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("yttriaay", res);
   free(res);
}

static void test_word_beginning_with_xr(void)
{
   TEST_IGNORE();
   const char *phrase = "xray";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("xrayay", res);
   free(res);
}

static void test_y_is_treated_like_a_consonant_at_the_beginning_of_a_word(void)
{
   TEST_IGNORE();
   const char *phrase = "yellow";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ellowyay", res);
   free(res);
}

static void test_y_is_treated_like_a_vowel_at_the_end_of_a_consonant_cluster(void)
{
   TEST_IGNORE();
   const char *phrase = "rhythm";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ythmrhay", res);
   free(res);
}

static void test_y_as_second_letter_in_two_letter_word(void)
{
   TEST_IGNORE();
   const char *phrase = "my";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ymay", res);
   free(res);
}

static void test_a_whole_phrase(void)
{
   TEST_IGNORE();
   const char *phrase = "quick fast run";
   char *res = translate(phrase);
   TEST_ASSERT_EQUAL_STRING("ickquay astfay unray", res);
   free(res);
}

int main(void)
{
   UnityBegin("test/test_pig_latin.c");

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
