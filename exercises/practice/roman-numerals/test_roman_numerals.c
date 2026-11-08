#include "test-framework/unity.h"
#include "roman_numerals.h"
#include <stdlib.h>

static char *result = NULL;

void setUp(void)
{
}

void tearDown(void)
{
   if (result)
      free(result);
   result = NULL;
}

static void check_conversion(int number, char *expected)
{
   result = to_roman_numeral(number);
   TEST_ASSERT_EQUAL_STRING(expected, result);
}

static void test_1_is_i(void)
{
   check_conversion(1, "I");
}

static void test_2_is_ii(void)
{
   TEST_IGNORE();   // delete this line to run test
   check_conversion(2, "II");
}

static void test_3_is_iii(void)
{
   TEST_IGNORE();
   check_conversion(3, "III");
}

static void test_4_is_iv(void)
{
   TEST_IGNORE();
   check_conversion(4, "IV");
}

static void test_5_is_v(void)
{
   TEST_IGNORE();
   check_conversion(5, "V");
}

static void test_6_is_vi(void)
{
   TEST_IGNORE();
   check_conversion(6, "VI");
}

static void test_9_is_ix(void)
{
   TEST_IGNORE();
   check_conversion(9, "IX");
}

static void test_16_is_xvi(void)
{
   TEST_IGNORE();
   check_conversion(16, "XVI");
}

static void test_27_is_xxvii(void)
{
   TEST_IGNORE();
   check_conversion(27, "XXVII");
}

static void test_48_is_xlviii(void)
{
   TEST_IGNORE();
   check_conversion(48, "XLVIII");
}

static void test_49_is_xlix(void)
{
   TEST_IGNORE();
   check_conversion(49, "XLIX");
}

static void test_59_is_lix(void)
{
   TEST_IGNORE();
   check_conversion(59, "LIX");
}

static void test_66_is_lxvi(void)
{
   TEST_IGNORE();
   check_conversion(66, "LXVI");
}

static void test_93_is_xciii(void)
{
   TEST_IGNORE();
   check_conversion(93, "XCIII");
}

static void test_141_is_cxli(void)
{
   TEST_IGNORE();
   check_conversion(141, "CXLI");
}

static void test_163_is_clxiii(void)
{
   TEST_IGNORE();
   check_conversion(163, "CLXIII");
}

static void test_166_is_clxvi(void)
{
   TEST_IGNORE();
   check_conversion(166, "CLXVI");
}

static void test_402_is_cdii(void)
{
   TEST_IGNORE();
   check_conversion(402, "CDII");
}

static void test_575_is_dlxxv(void)
{
   TEST_IGNORE();
   check_conversion(575, "DLXXV");
}

static void test_666_is_dclxvi(void)
{
   TEST_IGNORE();
   check_conversion(666, "DCLXVI");
}

static void test_911_is_cmxi(void)
{
   TEST_IGNORE();
   check_conversion(911, "CMXI");
}

static void test_1024_is_mxxiv(void)
{
   TEST_IGNORE();
   check_conversion(1024, "MXXIV");
}

static void test_1666_is_mdclxvi(void)
{
   TEST_IGNORE();
   check_conversion(1666, "MDCLXVI");
}

static void test_3000_is_mmm(void)
{
   TEST_IGNORE();
   check_conversion(3000, "MMM");
}

static void test_3001_is_mmmi(void)
{
   TEST_IGNORE();
   check_conversion(3001, "MMMI");
}

static void test_3888_is_mmmdccclxxxviii(void)
{
   TEST_IGNORE();
   check_conversion(3888, "MMMDCCCLXXXVIII");
}

static void test_3999_is_mmmcmxcix(void)
{
   TEST_IGNORE();
   check_conversion(3999, "MMMCMXCIX");
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_1_is_i);
   RUN_TEST(test_2_is_ii);
   RUN_TEST(test_3_is_iii);
   RUN_TEST(test_4_is_iv);
   RUN_TEST(test_5_is_v);
   RUN_TEST(test_6_is_vi);
   RUN_TEST(test_9_is_ix);
   RUN_TEST(test_16_is_xvi);
   RUN_TEST(test_27_is_xxvii);
   RUN_TEST(test_48_is_xlviii);
   RUN_TEST(test_49_is_xlix);
   RUN_TEST(test_59_is_lix);
   RUN_TEST(test_66_is_lxvi);
   RUN_TEST(test_93_is_xciii);
   RUN_TEST(test_141_is_cxli);
   RUN_TEST(test_163_is_clxiii);
   RUN_TEST(test_166_is_clxvi);
   RUN_TEST(test_402_is_cdii);
   RUN_TEST(test_575_is_dlxxv);
   RUN_TEST(test_666_is_dclxvi);
   RUN_TEST(test_911_is_cmxi);
   RUN_TEST(test_1024_is_mxxiv);
   RUN_TEST(test_1666_is_mdclxvi);
   RUN_TEST(test_3000_is_mmm);
   RUN_TEST(test_3001_is_mmmi);
   RUN_TEST(test_3888_is_mmmdccclxxxviii);
   RUN_TEST(test_3999_is_mmmcmxcix);

   return UNITY_END();
}
