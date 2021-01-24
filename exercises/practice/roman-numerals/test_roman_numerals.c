#include "test-framework/unity.h"
#include "roman_numerals.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_conversion(int number, char *expected)
{
   char *result = to_roman_numeral(number);
   TEST_ASSERT_EQUAL_STRING(expected, result);
   free(result);
}

static void test_1_is_a_single_I(void)
{
   check_conversion(1, "I");
}

static void test_2_is_two_Is(void)
{
   TEST_IGNORE();               // delete this line to run test
   check_conversion(2, "II");
}

static void test_3_is_three_Is(void)
{
   TEST_IGNORE();
   check_conversion(3, "III");
}

static void test_4_being_5_minus_1_is_IV(void)
{
   TEST_IGNORE();
   check_conversion(4, "IV");
}

static void test_5_is_a_single_V(void)
{
   TEST_IGNORE();
   check_conversion(5, "V");
}

static void test_6_being_5_plus_1_is_VI(void)
{
   TEST_IGNORE();
   check_conversion(6, "VI");
}

static void test_nine_being_10_minus_1_is_IX(void)
{
   TEST_IGNORE();
   check_conversion(9, "IX");
}

static void test_20_is_two_XXs(void)
{
   TEST_IGNORE();
   check_conversion(20, "XX");
}

static void test_48_is_not_50_minus_2_but_rather_40_plus_8(void)
{
   TEST_IGNORE();
   check_conversion(48, "XLVIII");
}

static void
test_49_is_not_40_plus_5_plus_4_but_rather_50_minus_10_plus_10_minus_1(void)
{
   TEST_IGNORE();
   check_conversion(49, "XLIX");
}

static void test_50_is_a_single_L(void)
{
   TEST_IGNORE();
   check_conversion(50, "L");
}

static void test_90_being_100_minus_10_is_XC(void)
{
   TEST_IGNORE();
   check_conversion(90, "XC");
}

static void test_100_is_a_single_C(void)
{
   TEST_IGNORE();
   check_conversion(100, "C");
}

static void test_sixty_being_50_plus_10_is_LX(void)
{
   TEST_IGNORE();
   check_conversion(60, "LX");
}

static void test_400_being_500_minus_100_is_CD(void)
{
   TEST_IGNORE();
   check_conversion(400, "CD");
}

static void test_500_is_a_single_D(void)
{
   TEST_IGNORE();
   check_conversion(500, "D");
}

static void test_900_being_1000_minus_100_is_CM(void)
{
   TEST_IGNORE();
   check_conversion(900, "CM");
}

static void test_1000_is_a_single_M(void)
{
   TEST_IGNORE();
   check_conversion(1000, "M");
}

static void test_3000_is_3_Ms(void)
{
   TEST_IGNORE();
   check_conversion(3000, "MMM");
}

int main(void)
{
   UnityBegin("test_roman_numerals.c");

   RUN_TEST(test_1_is_a_single_I);
   RUN_TEST(test_2_is_two_Is);
   RUN_TEST(test_3_is_three_Is);
   RUN_TEST(test_4_being_5_minus_1_is_IV);
   RUN_TEST(test_5_is_a_single_V);
   RUN_TEST(test_6_being_5_plus_1_is_VI);
   RUN_TEST(test_nine_being_10_minus_1_is_IX);
   RUN_TEST(test_20_is_two_XXs);
   RUN_TEST(test_48_is_not_50_minus_2_but_rather_40_plus_8);
   RUN_TEST
       (test_49_is_not_40_plus_5_plus_4_but_rather_50_minus_10_plus_10_minus_1);
   RUN_TEST(test_50_is_a_single_L);
   RUN_TEST(test_90_being_100_minus_10_is_XC);
   RUN_TEST(test_100_is_a_single_C);
   RUN_TEST(test_sixty_being_50_plus_10_is_LX);
   RUN_TEST(test_400_being_500_minus_100_is_CD);
   RUN_TEST(test_500_is_a_single_D);
   RUN_TEST(test_900_being_1000_minus_100_is_CM);
   RUN_TEST(test_1000_is_a_single_M);
   RUN_TEST(test_3000_is_3_Ms);

   return UnityEnd();
}
