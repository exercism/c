#include "test-framework/unity.h"
#include "hamming.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_empty_strands(void)
{
   TEST_ASSERT_EQUAL(0, compute("", ""));
}

static void test_single_identical_strands(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL(0, compute("A", "A"));
}

static void test_single_letter_different_strands(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1, compute("G", "T"));
}

static void test_long_identical_strands(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, compute("GGACTGAAATCTG", "GGACTGAAATCTG"));
}

static void test_long_different_strands(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(9, compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

static void test_disallow_first_strand_when_longer(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("AATG", "AAA"));
}

static void test_disallow_second_strand_when_longer(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("ATA", "AGTG"));
}

static void test_disallow_empty_first_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("", "G"));
}

static void test_disallow_empty_second_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("G", ""));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_empty_strands);
   RUN_TEST(test_single_identical_strands);
   RUN_TEST(test_single_letter_different_strands);
   RUN_TEST(test_long_identical_strands);
   RUN_TEST(test_long_different_strands);
   RUN_TEST(test_disallow_first_strand_when_longer);
   RUN_TEST(test_disallow_second_strand_when_longer);
   RUN_TEST(test_disallow_empty_first_strand);
   RUN_TEST(test_disallow_empty_second_strand);

   return UNITY_END();
}
