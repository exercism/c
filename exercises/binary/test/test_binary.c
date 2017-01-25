#include "vendor/unity.h"
#include "../src/binary.h"

void b1_is_decimal_1(void)
{
   TEST_ASSERT(1 == convert("1"));
}

void b10_is_decimal_2(void)
{
   int result = convert("10");
   TEST_ASSERT_EQUAL(2, result);
}

void b11_is_decimal_3(void)
{
   int result = convert("11");
   TEST_ASSERT_EQUAL(3, result);
}

void b100_is_decimal_4(void)
{
   int result = convert("100");
   TEST_ASSERT_EQUAL(4, result);
}

void b101_is_decimal_5(void)
{
   int result = convert("101");
   TEST_ASSERT_EQUAL(5, result);
}

void b110_is_decimal_6(void)
{
   int result = convert("110");
   TEST_ASSERT_EQUAL(6, result);
}

void b111_is_decimal_7(void)
{
   int result = convert("111");
   TEST_ASSERT_EQUAL(7, result);
}

void b1000_is_decimal_8(void)
{
   int result = convert("1000");
   TEST_ASSERT_EQUAL(8, result);
}

void b1001_is_decimal_9(void)
{
   int result = convert("1001");
   TEST_ASSERT_EQUAL(9, result);
}

void b10001101000_is_decimal_1128(void)
{
   int result = convert("10001101000");
   TEST_ASSERT_EQUAL(1128, result);
}

void invalid_entry_is_decimal_0(void)
{
   int result = convert("invalid entry");
   TEST_ASSERT_EQUAL(0, result);
}

int main(void)
{
   UnityBegin("test/test_binary.c");
   RUN_TEST(b1_is_decimal_1);
   RUN_TEST(b10_is_decimal_2);
   RUN_TEST(b11_is_decimal_3);
   RUN_TEST(b100_is_decimal_4);
   RUN_TEST(b101_is_decimal_5);
   RUN_TEST(b110_is_decimal_6);
   RUN_TEST(b111_is_decimal_7);
   RUN_TEST(b1000_is_decimal_8);
   RUN_TEST(b1001_is_decimal_9);
   RUN_TEST(b10001101000_is_decimal_1128);
   RUN_TEST(invalid_entry_is_decimal_0);
   UnityEnd();
   return 0;
}
