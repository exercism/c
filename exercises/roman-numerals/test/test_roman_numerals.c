#include "vendor/unity.h"
#include "../src/roman_numerals.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_conversion(int number, char *expected)
{
   char *result = to_roman_numeral(number);
   TEST_ASSERT_EQUAL_STRING(expected, result);
   free(result);
}

void test_one_yields_I(void)
{
   test_conversion(1, "I");
}

void test_two_yields_II(void)
{
   TEST_IGNORE();               // delete this line to run test
   test_conversion(2, "II");
}

void test_three_yields_III(void)
{
   TEST_IGNORE();
   test_conversion(3, "III");
}

void test_four_yields_IV(void)
{
   TEST_IGNORE();
   test_conversion(4, "IV");
}

void test_five_yields_V(void)
{
   TEST_IGNORE();
   test_conversion(5, "V");
}

void test_six_yields_VI(void)
{
   TEST_IGNORE();
   test_conversion(6, "VI");
}

void test_nine_yields_IX(void)
{
   TEST_IGNORE();
   test_conversion(9, "IX");
}

void test_twenty_seven_yields_XXVII(void)
{
   TEST_IGNORE();
   test_conversion(27, "XXVII");
}

void test_forty_eight_yields_XLVIII(void)
{
   TEST_IGNORE();
   test_conversion(48, "XLVIII");
}

void test_forty_nine_yields_XLIX(void)
{
   TEST_IGNORE();
   test_conversion(49, "XLIX");
}

void test_fifty_nine_yields_LIX(void)
{
   TEST_IGNORE();
   test_conversion(59, "LIX");
}

void test_ninety_three_yields_XCIII(void)
{
   TEST_IGNORE();
   test_conversion(93, "XCIII");
}

void test_one_hundred_forty_one_yields_CXLI(void)
{
   TEST_IGNORE();
   test_conversion(141, "CXLI");
}

void test_one_hundred_sixty_three_yields_CLXIII(void)
{
   TEST_IGNORE();
   test_conversion(163, "CLXIII");
}

void test_four_hundred_two_yields_CDII(void)
{
   TEST_IGNORE();
   test_conversion(402, "CDII");
}

void test_five_hundred_seventy_five_yields_DLXXV(void)
{
   TEST_IGNORE();
   test_conversion(575, "DLXXV");
}

void test_nine_hundred_eleven_yields_CMXI(void)
{
   TEST_IGNORE();
   test_conversion(911, "CMXI");
}

void test_one_thousand_twenty_four_yields_MXXIV(void)
{
   TEST_IGNORE();
   test_conversion(1024, "MXXIV");
}

void test_three_thousand_yields_MMM(void)
{
   TEST_IGNORE();
   test_conversion(3000, "MMM");
}

int main(void)
{
   UnityBegin("test/test_roman_numerals.c");

   RUN_TEST(test_one_yields_I);
   RUN_TEST(test_two_yields_II);
   RUN_TEST(test_three_yields_III);
   RUN_TEST(test_four_yields_IV);
   RUN_TEST(test_five_yields_V);
   RUN_TEST(test_nine_yields_IX);
   RUN_TEST(test_six_yields_VI);
   RUN_TEST(test_twenty_seven_yields_XXVII);
   RUN_TEST(test_forty_eight_yields_XLVIII);
   RUN_TEST(test_forty_nine_yields_XLIX);
   RUN_TEST(test_fifty_nine_yields_LIX);
   RUN_TEST(test_ninety_three_yields_XCIII);
   RUN_TEST(test_one_hundred_forty_one_yields_CXLI);
   RUN_TEST(test_one_hundred_sixty_three_yields_CLXIII);
   RUN_TEST(test_four_hundred_two_yields_CDII);
   RUN_TEST(test_five_hundred_seventy_five_yields_DLXXV);
   RUN_TEST(test_nine_hundred_eleven_yields_CMXI);
   RUN_TEST(test_one_thousand_twenty_four_yields_MXXIV);
   RUN_TEST(test_three_thousand_yields_MMM);

   UnityEnd();
   return 0;
}
