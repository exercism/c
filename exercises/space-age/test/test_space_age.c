#include "vendor/unity.h"
#include "../src/space_age.h"


void test_convert_earth_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(1, convert_earth_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_mercury_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(0.2408467, convert_mercury_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_venus_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(0.61519726, convert_venus_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_mars_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(1.8808158, convert_mars_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_jupiter_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(11.862615, convert_jupiter_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_saturn_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(29.447498, convert_saturn_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_uranus_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(84.016846, convert_uranus_age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_neptune_year(void)
{
   TEST_ASSERT_EQUAL_FLOAT(164.79132, convert_neptune_age(SECONDS_ON_EARTH_YEAR));
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
