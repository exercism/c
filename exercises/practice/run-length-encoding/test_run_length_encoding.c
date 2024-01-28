#include "test-framework/unity.h"
#include "run_length_encoding.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_encode_empty_string(void)
{
   char *res = encode("");
   TEST_ASSERT_EQUAL_STRING("", res);
   free(res);
}

static void test_encode_single_characters_only_are_encoded_without_count(void)
{
   TEST_IGNORE();   // delete this line to run test
   char *res = encode("XYZ");
   TEST_ASSERT_EQUAL_STRING("XYZ", res);
   free(res);
}

static void test_encode_string_with_no_single_characters(void)
{
   TEST_IGNORE();
   char *res = encode("AABBBCCCC");
   TEST_ASSERT_EQUAL_STRING("2A3B4C", res);
   free(res);
}

static void test_encode_single_characters_mixed_with_repeated_characters(void)
{
   TEST_IGNORE();
   char *res = encode("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB");
   TEST_ASSERT_EQUAL_STRING("12WB12W3B24WB", res);
   free(res);
}

static void test_encode_multiple_whitespace_mixed_in_string(void)
{
   TEST_IGNORE();
   char *res = encode("  hsqq qww  ");
   TEST_ASSERT_EQUAL_STRING("2 hs2q q2w2 ", res);
   free(res);
}

static void test_encode_lowercase_characters(void)
{
   TEST_IGNORE();
   char *res = encode("aabbbcccc");
   TEST_ASSERT_EQUAL_STRING("2a3b4c", res);
   free(res);
}

static void test_decode_empty_string(void)
{
   TEST_IGNORE();
   char *res = decode("");
   TEST_ASSERT_EQUAL_STRING("", res);
   free(res);
}

static void test_decode_single_characters_only(void)
{
   TEST_IGNORE();
   char *res = decode("XYZ");
   TEST_ASSERT_EQUAL_STRING("XYZ", res);
   free(res);
}

static void test_decode_string_with_no_single_characters(void)
{
   TEST_IGNORE();
   char *res = decode("2A3B4C");
   TEST_ASSERT_EQUAL_STRING("AABBBCCCC", res);
   free(res);
}

static void test_decode_single_characters_with_repeated_characters(void)
{
   TEST_IGNORE();
   char *res = decode("12WB12W3B24WB");
   TEST_ASSERT_EQUAL_STRING(
       "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB", res);
   free(res);
}

static void test_decode_multiple_whitespace_mixed_in_string(void)
{
   TEST_IGNORE();
   char *res = decode("2 hs2q q2w2 ");
   TEST_ASSERT_EQUAL_STRING("  hsqq qww  ", res);
   free(res);
}

static void test_decode_lower_case_string(void)
{
   TEST_IGNORE();
   char *res = decode("2a3b4c");
   TEST_ASSERT_EQUAL_STRING("aabbbcccc", res);
   free(res);
}

static void
test_consistency_encode_followed_by_decode_gives_original_string(void)
{
   TEST_IGNORE();
   char *res_enc = encode("zzz ZZ  zZ");
   char *res_dec = decode(res_enc);
   TEST_ASSERT_EQUAL_STRING("zzz ZZ  zZ", res_dec);
   free(res_enc);
   free(res_dec);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_encode_empty_string);
   RUN_TEST(test_encode_single_characters_only_are_encoded_without_count);
   RUN_TEST(test_encode_string_with_no_single_characters);
   RUN_TEST(test_encode_single_characters_mixed_with_repeated_characters);
   RUN_TEST(test_encode_multiple_whitespace_mixed_in_string);
   RUN_TEST(test_encode_lowercase_characters);
   RUN_TEST(test_decode_empty_string);
   RUN_TEST(test_decode_single_characters_only);
   RUN_TEST(test_decode_string_with_no_single_characters);
   RUN_TEST(test_decode_single_characters_with_repeated_characters);
   RUN_TEST(test_decode_multiple_whitespace_mixed_in_string);
   RUN_TEST(test_decode_lower_case_string);
   RUN_TEST(test_consistency_encode_followed_by_decode_gives_original_string);

   return UNITY_END();
}
