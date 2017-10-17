#include "vendor/unity.h"
#include "../src/space_age.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_convert_earth_year(void)
{
   TEST_ASSERT_FLOAT_WITHIN(1, 31.69, convert_planet_age(EARTH, 1000000000));
}

void test_convert_mercury_year(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FLOAT_WITHIN(3, 280.88, convert_planet_age(MERCURY, 2134835688));
}

void test_convert_venus_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(1, 9.78, convert_planet_age(VENUS, 189839836));
}

void test_convert_mars_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(1, 39.25, convert_planet_age(MARS, 2329871239));
}

void test_convert_jupiter_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 2.41, convert_planet_age(JUPITER, 901876382));
}

void test_convert_saturn_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 3.23, convert_planet_age(SATURN, 3000000000));
}

void test_convert_uranus_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 1.21, convert_planet_age(URANUS, 3210123456));
}

void test_convert_neptune_year(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 1.58, convert_planet_age(NEPTUNE, 8210123456));
}

int main(void)
{
   UnityBegin("test/test_space_age.c");

   RUN_TEST(test_convert_earth_year);
   RUN_TEST(test_convert_mercury_year);
   RUN_TEST(test_convert_venus_year);
   RUN_TEST(test_convert_mars_year);
   RUN_TEST(test_convert_jupiter_year);
   RUN_TEST(test_convert_saturn_year);
   RUN_TEST(test_convert_uranus_year);
   RUN_TEST(test_convert_neptune_year);

   UnityEnd();
   return 0;
}
