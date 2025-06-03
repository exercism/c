#include "test-framework/unity.h"
#include "crypto_square.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_empty_text_res_in_an_empty_ciphertext(void)
{
   const char *input = "";
   const char *expected = "";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void test_normalization_results_in_empty_plaintext(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char *input = "... --- ...";
   const char *expected = "";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void test_lowercase(void)
{
   TEST_IGNORE();
   const char *input = "A";
   const char *expected = "a";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void test_remove_spaces(void)
{
   TEST_IGNORE();
   const char *input = "  b ";
   const char *expected = "b";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void test_remove_punctuation(void)
{
   TEST_IGNORE();
   const char *input = "@1,%!";
   const char *expected = "1";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void test_9_char_plaintext_gives_3_chunks_of_3_chars(void)
{
   TEST_IGNORE();
   const char *input = "This is fun!";
   const char *expected = "tsf hiu isn";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void
test_8_char_plaintext_gives_3_chunks_last_one_with_trailing_space(void)
{
   TEST_IGNORE();
   const char *input = "Chill out.";
   const char *expected = "clu hlt io ";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

static void
test_54_char_plaintext_gives_8_chunks_last_two_with_trailing_spaces(void)
{
   TEST_IGNORE();
   const char *input =
       "If man was meant to stay on the ground, god would have given us roots.";
   const char *expected =
       "imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau ";
   char *res = ciphertext(input);
   TEST_ASSERT_EQUAL_STRING(expected, res);
   free(res);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_empty_text_res_in_an_empty_ciphertext);
   RUN_TEST(test_normalization_results_in_empty_plaintext);
   RUN_TEST(test_lowercase);
   RUN_TEST(test_remove_spaces);
   RUN_TEST(test_remove_punctuation);
   RUN_TEST(test_9_char_plaintext_gives_3_chunks_of_3_chars);
   RUN_TEST(test_8_char_plaintext_gives_3_chunks_last_one_with_trailing_space);
   RUN_TEST(
       test_54_char_plaintext_gives_8_chunks_last_two_with_trailing_spaces);

   return UNITY_END();
}
