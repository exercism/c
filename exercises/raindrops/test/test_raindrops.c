#include "vendor/unity.h"
#include "../src/raindrops.h"

#define BUFFER_LENGTH 100

void setUp(void)
{
}

void tearDown(void)
{
}

void test_one_yields_itself(void)
{
   TEST_ASSERT_EQUAL_STRING("1", convert(1));
}

void test_three_yields_pling(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL_STRING("Pling", convert(3));
}

void test_five_yields_plang(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plang", convert(5));
}

void test_seven_yields_plong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plong", convert(7));
}

void test_six_yields_pling(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Pling", convert(6));
}

void test_nine_yields_pling(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Pling", convert(9));
}

void test_ten_yields_plang(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plang", convert(10));
}

void test_fourteen_yields_plong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plong", convert(14));
}

void test_fifteen_yields_plingplang(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("PlingPlang", convert(15));
}

void test_twenty_one_yields_plingplong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("PlingPlong", convert(21));
}

void test_twenty_five_yields_plang(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plang", convert(25));
}

void test_thirty_five_yields_plangplong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("PlangPlong", convert(35));
}

void test_forty_nine_yields_plong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("Plong", convert(49));
}

void test_fifty_two_yields_itself(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("52", convert(52));
}

void test_one_hundred_five_yields_plingplangplong(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("PlingPlangPlong", convert(105));
}

void test_big_prime_yields_itself(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_STRING("12121", convert(12121));
}

int main(void)
{
   UnityBegin("raindrops.c");

   RUN_TEST(test_one_yields_itself);
   RUN_TEST(test_three_yields_pling);
   RUN_TEST(test_five_yields_plang);
   RUN_TEST(test_seven_yields_plong);
   RUN_TEST(test_six_yields_pling);
   RUN_TEST(test_nine_yields_pling);
   RUN_TEST(test_ten_yields_plang);
   RUN_TEST(test_fourteen_yields_plong);
   RUN_TEST(test_fifteen_yields_plingplang);
   RUN_TEST(test_twenty_one_yields_plingplong);
   RUN_TEST(test_twenty_five_yields_plang);
   RUN_TEST(test_thirty_five_yields_plangplong);
   RUN_TEST(test_forty_nine_yields_plong);
   RUN_TEST(test_fifty_two_yields_itself);
   RUN_TEST(test_one_hundred_five_yields_plingplangplong);
   RUN_TEST(test_big_prime_yields_itself);

   UnityEnd();
   return 0;
}
