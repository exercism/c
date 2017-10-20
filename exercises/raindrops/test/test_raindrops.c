#include "vendor/unity.h"
#include "../src/raindrops.h"
#include <stdlib.h>

#define BUFFER_LENGTH 16

void setUp(void)
{
}

void tearDown(void)
{
}

void convert_drops(int drops, char *expected)
{
   char result[BUFFER_LENGTH] = { 0 };
   convert(result, drops);
   TEST_ASSERT_EQUAL_STRING(expected, result);
}

void test_one_yields_itself(void)
{
   convert_drops(1, "1");
}

void test_three_yields_pling(void)
{
   TEST_IGNORE();               // delete this line to run test
   convert_drops(3, "Pling");
}

void test_five_yields_plang(void)
{
   TEST_IGNORE();
   convert_drops(5, "Plang");
}

void test_seven_yields_plong(void)
{
   TEST_IGNORE();
   convert_drops(7, "Plong");
}

void test_six_yields_pling(void)
{
   TEST_IGNORE();
   convert_drops(6, "Pling");
}

void test_nine_yields_pling(void)
{
   TEST_IGNORE();
   convert_drops(9, "Pling");
}

void test_ten_yields_plang(void)
{
   TEST_IGNORE();
   convert_drops(10, "Plang");
}

void test_fourteen_yields_plong(void)
{
   TEST_IGNORE();
   convert_drops(14, "Plong");
}

void test_fifteen_yields_plingplang(void)
{
   TEST_IGNORE();
   convert_drops(15, "PlingPlang");
}

void test_twenty_one_yields_plingplong(void)
{
   TEST_IGNORE();
   convert_drops(21, "PlingPlong");
}

void test_twenty_five_yields_plang(void)
{
   TEST_IGNORE();
   convert_drops(25, "Plang");
}

void test_thirty_five_yields_plangplong(void)
{
   TEST_IGNORE();
   convert_drops(35, "PlangPlong");
}

void test_forty_nine_yields_plong(void)
{
   TEST_IGNORE();
   convert_drops(49, "Plong");
}

void test_fifty_two_yields_itself(void)
{
   TEST_IGNORE();
   convert_drops(52, "52");
}

void test_one_hundred_five_yields_plingplangplong(void)
{
   TEST_IGNORE();
   convert_drops(105, "PlingPlangPlong");
}

void test_big_prime_yields_itself(void)
{
   TEST_IGNORE();
   convert_drops(12121, "12121");
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
