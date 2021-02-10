#include "test-framework/unity.h"
#include "space_age.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_age_on_earth(void)
{
   TEST_ASSERT_FLOAT_WITHIN(1, 31.69, age(EARTH, 1000000000));
}

static void test_age_on_mercury(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_FLOAT_WITHIN(3, 280.88, age(MERCURY, 2134835688));
}

static void test_age_on_venus(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(1, 9.78, age(VENUS, 189839836));
}

static void test_age_on_mars(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(1, 35.88, age(MARS, 2129871239));
}

static void test_age_on_jupiter(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 2.41, age(JUPITER, 901876382));
}

static void test_age_on_saturn(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 2.15, age(SATURN, 2000000000));
}

static void test_age_on_uranus(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 0.46, age(URANUS, 1210123456));
}

static void test_age_on_neptune(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FLOAT_WITHIN(0.1, 0.35, age(NEPTUNE, 1821023456));
}

int main(void)
{
   UnityBegin("test_space_age.c");

   RUN_TEST(test_age_on_earth);
   RUN_TEST(test_age_on_mercury);
   RUN_TEST(test_age_on_venus);
   RUN_TEST(test_age_on_mars);
   RUN_TEST(test_age_on_jupiter);
   RUN_TEST(test_age_on_saturn);
   RUN_TEST(test_age_on_uranus);
   RUN_TEST(test_age_on_neptune);

   return UnityEnd();
}
