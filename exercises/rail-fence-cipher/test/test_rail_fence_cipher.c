#include "vendor/unity.h"
#include <stdlib.h>
#include "../src/rail_fence_cipher.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_expected_value(char *actual, char *expected) {
  TEST_ASSERT_EQUAL_STRING(actual, expected);
}

void test_encode_with_empty_string(void) {
  char *res = encode("", 4);
  test_expected_value("", res);
  free(res);
}

void test_encode_with_one_rail(void) {
  TEST_IGNORE();
  char *res = encode("One rail, only one rail", 1);
  test_expected_value("One rail, only one rail", res);
  free(res);
}

void test_encode_with_two_rails(void) {
  TEST_IGNORE();
  char *res = encode("XOXOXOXOXOXOXOXOXO", 2);
  test_expected_value("XXXXXXXXXOOOOOOOOO", res);
  free(res);
}

void test_encode_with_three_rails(void) {
  TEST_IGNORE();
  char *res = encode("WEAREDISCOVEREDFLEEATONCE", 3);
  test_expected_value("WECRLTEERDSOEEFEAOCAIVDEN", res);
  free(res);
}

void test_encode_with_ending_in_the_middle(void) {
  TEST_IGNORE();
  char *res = encode("EXERCISES", 4);
  test_expected_value("ESXIEECSR", res);
  free(res);
}

void test_encode_with_less_letters_than_rails(void) {
  TEST_IGNORE();
  char *res = encode("More rails than letters", 24);
  test_expected_value("More rails than letters", res);
  free(res);
}

void test_decode_with_empty_string(void) {
  TEST_IGNORE();
  char *res = decode("", 4);
  test_expected_value("", res);
  free(res);
}

void test_decode_with_one_rail(void) {
  TEST_IGNORE();
  char *res = decode("ABCDEFGHIJKLMNOP", 1);
  test_expected_value("ABCDEFGHIJKLMNOP", res);
  free(res);
}

void test_decode_with_two_rails(void) {
  TEST_IGNORE();
  char *res = decode("XXXXXXXXXOOOOOOOOO", 2);
  test_expected_value("XOXOXOXOXOXOXOXOXO", res);
  free(res);
}

void test_decode_with_three_rails(void) {
  TEST_IGNORE();
  char *res = decode("TEITELHDVLSNHDTISEIIEA", 3);
  test_expected_value("THEDEVILISINTHEDETAILS", res);
  free(res);
}

void test_decode_with_four_rails(void) {
  TEST_IGNORE();
  char *res = decode("TSENEHINVRAYREEOONRWERGOH", 4);
  test_expected_value("THEREISNOGOVERNORANYWHERE", res);
  free(res);
}

int main(void)
{
  UnityBegin("test/test_expected_value_rail_fence_cipher.c");

  RUN_TEST(test_encode_with_empty_string);
  RUN_TEST(test_encode_with_one_rail);
  RUN_TEST(test_encode_with_two_rails);
  RUN_TEST(test_encode_with_three_rails);
  RUN_TEST(test_encode_with_ending_in_the_middle);
  RUN_TEST(test_encode_with_less_letters_than_rails);
  RUN_TEST(test_decode_with_empty_string);
  RUN_TEST(test_decode_with_one_rail);
  RUN_TEST(test_decode_with_two_rails);
  RUN_TEST(test_decode_with_three_rails);
  RUN_TEST(test_decode_with_four_rails);

  return UnityEnd();
}
