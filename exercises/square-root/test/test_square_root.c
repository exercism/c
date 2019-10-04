#include "vendor/unity.h"
#include "../src/square_root.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_root_of_1(void)
{
   TEST_ASSERT_EQUAL_UINT16(1, squareRoot(1));
}

static void test_root_of_4(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(2, squareRoot(4));
}

static void test_root_of_25(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(5, squareRoot(25));
}

static void test_root_of_81(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(9, squareRoot(81));
}

static void test_root_of_196(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(14, squareRoot(196));
}

static void test_root_of_65025(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_UINT16(255, squareRoot(65025));
}

int main(void)
{
   UnityBegin("test/test_square_root.c");

   RUN_TEST(test_root_of_1);
   RUN_TEST(test_root_of_4);
   RUN_TEST(test_root_of_25);
   RUN_TEST(test_root_of_81);
   RUN_TEST(test_root_of_196);
   RUN_TEST(test_root_of_65025);

   return UnityEnd();
}
