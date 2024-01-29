#include "test-framework/unity.h"
#include "resistor_color_duo.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_brown_and_black(void)
{
   uint16_t actual = color_code((resistor_band_t[]){ BROWN, BLACK });
   TEST_ASSERT_EQUAL_UINT16(10, actual);
}

static void test_blue_and_grey(void)
{
   TEST_IGNORE();   // delete this line to run test
   uint16_t actual = color_code((resistor_band_t[]){ BLUE, GREY });
   TEST_ASSERT_EQUAL_UINT16(68, actual);
}

static void test_yellow_and_violet(void)
{
   TEST_IGNORE();
   uint16_t actual = color_code((resistor_band_t[]){ YELLOW, VIOLET });
   TEST_ASSERT_EQUAL_UINT16(47, actual);
}

static void test_white_and_red(void)
{
   TEST_IGNORE();
   uint16_t actual = color_code((resistor_band_t[]){ WHITE, RED });
   TEST_ASSERT_EQUAL_UINT16(92, actual);
}

static void test_orange_and_orange(void)
{
   TEST_IGNORE();
   uint16_t actual = color_code((resistor_band_t[]){ ORANGE, ORANGE });
   TEST_ASSERT_EQUAL_UINT16(33, actual);
}

static void test_ignore_additional_colors(void)
{
   TEST_IGNORE();
   uint16_t actual = color_code((resistor_band_t[]){ GREEN, BROWN, ORANGE });
   TEST_ASSERT_EQUAL_UINT16(51, actual);
}

static void test_black_and_brown_one_digit(void)
{
   TEST_IGNORE();
   uint16_t actual = color_code((resistor_band_t[]){ BLACK, BROWN });
   TEST_ASSERT_EQUAL_UINT16(1, actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_brown_and_black);
   RUN_TEST(test_blue_and_grey);
   RUN_TEST(test_yellow_and_violet);
   RUN_TEST(test_white_and_red);
   RUN_TEST(test_orange_and_orange);
   RUN_TEST(test_ignore_additional_colors);
   RUN_TEST(test_black_and_brown_one_digit);

   return UNITY_END();
}
