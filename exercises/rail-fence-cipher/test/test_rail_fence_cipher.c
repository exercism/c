#include "vendor/unity.h"
#include "../src/rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_expected_value(char *actual, char *expected)
{
   TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_encode_with_empty_string(void)
{
   test_expected_value("", encode("", 4));
}

void test_encode_with_one_rail(void)
{
   TEST_IGNORE();
   test_expected_value("One rail, only one rail",
                       encode("One rail, only one rail", 1));
}

void test_encode_with_two_rails(void)
{
   TEST_IGNORE();
   test_expected_value("XXXXXXXXXOOOOOOOOO", encode("XOXOXOXOXOXOXOXOXO", 2));
}

void test_encode_with_three_rails(void)
{
   TEST_IGNORE();
   test_expected_value("WECRLTEERDSOEEFEAOCAIVDEN",
                       encode("WEAREDISCOVEREDFLEEATONCE", 3));
}

void test_encode_with_ending_in_the_middle(void)
{
   TEST_IGNORE();
   test_expected_value("ESXIEECSR", encode("EXERCISES", 4));
}

void test_encode_with_less_letters_than_rails(void)
{
   TEST_IGNORE();
   test_expected_value("More rails than letters",
                       encode("More rails than letters", 24));
}

void test_decode_with_empty_string(void)
{
   TEST_IGNORE();
   test_expected_value("", decode("", 4));
}

void test_decode_with_one_rail(void)
{
   TEST_IGNORE();
   test_expected_value("ABCDEFGHIJKLMNOP", decode("ABCDEFGHIJKLMNOP", 1));
}

void test_decode_with_two_rails(void)
{
   TEST_IGNORE();
   test_expected_value("XOXOXOXOXOXOXOXOXO", decode("XXXXXXXXXOOOOOOOOO", 2));
}

void test_decode_with_three_rails(void)
{
   TEST_IGNORE();
   test_expected_value("THEDEVILISINTHEDETAILS",
                       decode("TEITELHDVLSNHDTISEIIEA", 3));
}

void test_decode_with_four_rails(void)
{
   TEST_IGNORE();
   test_expected_value("THEREISNOGOVERNORANYWHERE",
                       decode("TSENEHINVRAYREEOONRWERGOH", 4));
}

int main(void)
{
   UnityBegin("test/test_rail_fence_cipher.c");

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
