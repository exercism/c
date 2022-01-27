#include "test-framework/unity.h"
#include "resistor_color.h"
#include <stdlib.h>

#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_black(void)
{
   TEST_ASSERT_EQUAL_UINT16(0, color_code(BLACK));
}

static void test_white(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL_UINT16(9, color_code(WHITE));
}

static void test_orange(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(3, color_code(ORANGE));
}

static void test_colors(void)
{
   TEST_IGNORE();
   const resistor_band_t expected[] = { BLACK, BROWN, RED,    ORANGE, YELLOW,
                                        GREEN, BLUE,  VIOLET, GREY,   WHITE };
   resistor_band_t *colors_values = colors();
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, colors_values, ARRAY_LENGTH(expected));
   free(colors_values);
}

int main(void)
{
   UnityBegin("test_resistor_color.c");

   RUN_TEST(test_black);
   RUN_TEST(test_white);
   RUN_TEST(test_orange);
   RUN_TEST(test_colors);

   return UnityEnd();
}
