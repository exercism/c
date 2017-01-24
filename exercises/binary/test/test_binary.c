#include "vendor/unity.h"
#include "../src/binary.h"

void b1_is_decimal_1(void)
{
   TEST_ASSERT(1 == convert("1"));
}

void b10_is_decimal_2(void)
{
   int r = (2 == convert("10"));
   TEST_ASSERT(r);
}

void b11_is_decimal_3(void)
{
   int r = (3 == convert("11"));
   TEST_ASSERT(r);
}

void b100_is_decimal_4(void)
{
   int r = (4 == convert("100"));
   TEST_ASSERT(r);
}

void b101_is_decimal_5(void)
{
   int r = (5 == convert("101"));
   TEST_ASSERT(r);
}

void b110_is_decimal_6(void)
{
   int r = (6 == convert("110"));
   TEST_ASSERT(r);
}

void b111_is_decimal_7(void)
{
   int r = (7 == convert("111"));
   TEST_ASSERT(r);
}

void b1000_is_decimal_8(void)
{
   int r = (8 == convert("1000"));
   TEST_ASSERT(r);
}

void b1001_is_decimal_9(void)
{
   int r = (9 == convert("1001"));
   TEST_ASSERT(r);
}

void b10001101000_is_decimal_1128(void)
{
   int r = (1128 == convert("10001101000"));
   TEST_ASSERT(r);
}

void invalid_entry_is_decimal_0(void)
{
   int r = (0 == convert("invalid entry!"));
   TEST_ASSERT(r);
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

   return 0;
}
