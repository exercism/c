#include "test-framework/unity.h"
#include "raindrops.h"
#include <stdlib.h>

#define BUFFER_LENGTH 16

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_convert_drops(int drops, char *expected)
{
   char actual[BUFFER_LENGTH] = { 0 };
   convert(actual, drops);
   TEST_ASSERT_EQUAL_STRING(expected, actual);
}

static void test_the_sound_for_1_is_1(void)
{
   check_convert_drops(1, "1");
}

static void test_the_sound_for_3_is_pling(void)
{
   TEST_IGNORE();               // delete this line to run test
   check_convert_drops(3, "Pling");
}

static void test_the_sound_for_5_is_plang(void)
{
   TEST_IGNORE();
   check_convert_drops(5, "Plang");
}

static void test_the_sound_for_7_is_plong(void)
{
   TEST_IGNORE();
   check_convert_drops(7, "Plong");
}

static void test_the_sound_for_6_is_pling_as_it_has_a_factor_3(void)
{
   TEST_IGNORE();
   check_convert_drops(6, "Pling");
}

static void
    test_2_to_the_power_3_does_not_make_a_raindrop_sound_as_3_is_the_exponent_not_the_base
    (void) {
   TEST_IGNORE();
   check_convert_drops(8, "8");
}

static void test_the_sound_for_9_is_pling_as_it_has_a_factor_3(void)
{
   TEST_IGNORE();
   check_convert_drops(9, "Pling");
}

static void test_the_sound_for_10_is_plang_as_it_has_a_factor_5(void)
{
   TEST_IGNORE();
   check_convert_drops(10, "Plang");
}

static void test_the_sound_for_14_is_plong_as_it_has_a_factor_7(void)
{
   TEST_IGNORE();
   check_convert_drops(14, "Plong");
}

static void test_the_sound_for_15_is_plingplang_as_it_has_factors_3_and_5(void)
{
   TEST_IGNORE();
   check_convert_drops(15, "PlingPlang");
}

static void test_the_sound_for_21_is_plingplong_as_it_has_factors_3_and_7(void)
{
   TEST_IGNORE();
   check_convert_drops(21, "PlingPlong");
}

static void test_the_sound_for_25_is_plingplang_as_it_has_a_factor_5(void)
{
   TEST_IGNORE();
   check_convert_drops(25, "Plang");
}

static void test_the_sound_for_35_is_plangplong_as_it_has_factors_5_and_7(void)
{
   TEST_IGNORE();
   check_convert_drops(35, "PlangPlong");
}

static void test_the_sound_for_49_is_plong_as_it_has_a_factor_7(void)
{
   TEST_IGNORE();
   check_convert_drops(49, "Plong");
}

static void test_the_sound_for_52_is_52(void)
{
   TEST_IGNORE();
   check_convert_drops(52, "52");
}

static void
test_the_sound_for_105_is_plangplangplong_as_it_has_factor_3_5_and_7(void)
{
   TEST_IGNORE();
   check_convert_drops(105, "PlingPlangPlong");
}

static void test_the_sound_for_3125_is_plang_as_it_has_a_factor_5(void)
{
   TEST_IGNORE();
   check_convert_drops(3125, "Plang");
}

int main(void)
{
   UnityBegin("test_raindrops.c");

   RUN_TEST(test_the_sound_for_1_is_1);
   RUN_TEST(test_the_sound_for_3_is_pling);
   RUN_TEST(test_the_sound_for_5_is_plang);
   RUN_TEST(test_the_sound_for_7_is_plong);
   RUN_TEST(test_the_sound_for_6_is_pling_as_it_has_a_factor_3);
   RUN_TEST
       (test_2_to_the_power_3_does_not_make_a_raindrop_sound_as_3_is_the_exponent_not_the_base);
   RUN_TEST(test_the_sound_for_9_is_pling_as_it_has_a_factor_3);
   RUN_TEST(test_the_sound_for_10_is_plang_as_it_has_a_factor_5);
   RUN_TEST(test_the_sound_for_14_is_plong_as_it_has_a_factor_7);
   RUN_TEST(test_the_sound_for_15_is_plingplang_as_it_has_factors_3_and_5);
   RUN_TEST(test_the_sound_for_21_is_plingplong_as_it_has_factors_3_and_7);
   RUN_TEST(test_the_sound_for_25_is_plingplang_as_it_has_a_factor_5);
   RUN_TEST(test_the_sound_for_35_is_plangplong_as_it_has_factors_5_and_7);
   RUN_TEST(test_the_sound_for_49_is_plong_as_it_has_a_factor_7);
   RUN_TEST(test_the_sound_for_52_is_52);
   RUN_TEST
       (test_the_sound_for_105_is_plangplangplong_as_it_has_factor_3_5_and_7);
   RUN_TEST(test_the_sound_for_3125_is_plang_as_it_has_a_factor_5);

   return UnityEnd();
}
