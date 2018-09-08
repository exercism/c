#include "vendor/unity.h"
#include "../src/grains.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_square_1(void)
{
   TEST_ASSERT(1ull == square(1));
}

void test_square_2(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT(2ull == square(2));
}

void test_square_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT(4ull == square(3));
}

void test_square_4(void)
{
   TEST_IGNORE();
   TEST_ASSERT(8ull == square(4));
}

void test_square_16(void)
{
   TEST_IGNORE();
   TEST_ASSERT(32768ull == square(16));
}

void test_square_32(void)
{
   TEST_IGNORE();
   TEST_ASSERT(2147483648ull == square(32));
}

void test_square_64(void)
{
   TEST_IGNORE();
   TEST_ASSERT(9223372036854775808ull == square(64));
}

void test_square_0_does_not_exist(void)
{
   TEST_IGNORE();
   TEST_ASSERT(0 == square(0));
}

void test_square_greater_than_64_does_not_exist(void)
{
   TEST_IGNORE();
   TEST_ASSERT(0 == square(65));
}

void test_total(void)
{
   TEST_IGNORE();
   TEST_ASSERT(18446744073709551615ull == total());
}

int main(void)
{
   UnityBegin("test/test_grains.c");

   RUN_TEST(test_square_1);
   RUN_TEST(test_square_2);
   RUN_TEST(test_square_3);
   RUN_TEST(test_square_4);
   RUN_TEST(test_square_16);
   RUN_TEST(test_square_32);
   RUN_TEST(test_square_64);
   RUN_TEST(test_square_0_does_not_exist);
   RUN_TEST(test_square_greater_than_64_does_not_exist);
   RUN_TEST(test_total);

   UnityEnd();
   return 0;
}
