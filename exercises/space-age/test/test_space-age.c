#include "vendor/unity.h"
#include "../src/space-age.h"


void test_convert_Earth_Year(void)
{
   TEST_ASSERT_EQUAL(1, convert_Earth_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Mercury_Year(void)
{
   TEST_ASSERT_EQUAL(0.2408467, convert_Mercury_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Venus_Year(void)
{
   TEST_ASSERT_EQUAL(0.61519726, convert_Venus_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Mars_Year(void)
{
   TEST_ASSERT_EQUAL(1.8808158, convert_Mars_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Jupiter_Year(void)
{
   TEST_ASSERT_EQUAL(11.862615, convert_Jupiter_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Saturn_Year(void)
{
   TEST_ASSERT_EQUAL(29.447498, convert_Saturn_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Uranus_Year(void)
{
   TEST_ASSERT_EQUAL(84.016846, convert_Uranus_Age(SECONDS_ON_EARTH_YEAR));
}

void test_convert_Neptune_Year(void)
{
   TEST_ASSERT_EQUAL(164.79132, convert_Neptune_Age(SECONDS_ON_EARTH_YEAR));
}

int main(void)
{
   UnityBegin("test/test_space-age.c");
   RUN_TEST(test_convert_Earth_Year);
   UnityEnd();
   return 0;
}
