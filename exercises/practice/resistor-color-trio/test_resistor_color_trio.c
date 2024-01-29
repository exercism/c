#include "test-framework/unity.h"
#include "resistor_color_trio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_orange_orange_black(void)
{
   resistor_value_t actual =
       color_code((resistor_band_t[]){ ORANGE, ORANGE, BLACK });
   TEST_ASSERT_EQUAL_UINT16(33, actual.value);
   TEST_ASSERT_EQUAL(OHMS, actual.unit);
}

static void test_blue_grey_brown(void)
{
   TEST_IGNORE();   // delete this line to run test
   resistor_value_t actual =
       color_code((resistor_band_t[]){ BLUE, GREY, BROWN });
   TEST_ASSERT_EQUAL_UINT16(680, actual.value);
   TEST_ASSERT_EQUAL(OHMS, actual.unit);
}

static void test_red_black_red(void)
{
   TEST_IGNORE();
   resistor_value_t actual = color_code((resistor_band_t[]){ RED, BLACK, RED });
   TEST_ASSERT_EQUAL_UINT16(2, actual.value);
   TEST_ASSERT_EQUAL(KILOOHMS, actual.unit);
}

static void test_green_brown_orange(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ GREEN, BROWN, ORANGE });
   TEST_ASSERT_EQUAL_UINT16(51, actual.value);
   TEST_ASSERT_EQUAL(KILOOHMS, actual.unit);
}

static void test_yellow_violet_yellow(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ YELLOW, VIOLET, YELLOW });
   TEST_ASSERT_EQUAL_UINT16(470, actual.value);
   TEST_ASSERT_EQUAL(KILOOHMS, actual.unit);
}

static void test_blue_violet_blue(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ BLUE, VIOLET, BLUE });
   TEST_ASSERT_EQUAL_UINT16(67, actual.value);
   TEST_ASSERT_EQUAL(MEGAOHMS, actual.unit);
}

static void test_minimum_possible_value(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ BLACK, BLACK, BLACK });
   TEST_ASSERT_EQUAL_UINT16(0, actual.value);
   TEST_ASSERT_EQUAL(OHMS, actual.unit);
}

static void test_maximum_possible_value(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ WHITE, WHITE, WHITE });
   TEST_ASSERT_EQUAL_UINT16(99, actual.value);
   TEST_ASSERT_EQUAL(GIGAOHMS, actual.unit);
}

static void test_invalid_octal(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ BLACK, GREY, BLACK });
   TEST_ASSERT_EQUAL_UINT16(8, actual.value);
   TEST_ASSERT_EQUAL(OHMS, actual.unit);
}

static void test_ignore_extra_colors(void)
{
   TEST_IGNORE();
   resistor_value_t actual =
       color_code((resistor_band_t[]){ BLUE, GREEN, YELLOW, ORANGE });
   TEST_ASSERT_EQUAL_UINT16(650, actual.value);
   TEST_ASSERT_EQUAL(KILOOHMS, actual.unit);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_orange_orange_black);
   RUN_TEST(test_blue_grey_brown);
   RUN_TEST(test_red_black_red);
   RUN_TEST(test_green_brown_orange);
   RUN_TEST(test_yellow_violet_yellow);
   RUN_TEST(test_blue_violet_blue);
   RUN_TEST(test_minimum_possible_value);
   RUN_TEST(test_maximum_possible_value);
   RUN_TEST(test_invalid_octal);
   RUN_TEST(test_ignore_extra_colors);

   return UNITY_END();
}
