#include "vendor/unity.h"
#include "../src/hamming.h"

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

static void test_rejects_null_strand(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL(-1, compute(NULL, "A"));
}

static void test_rejects_other_null_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("A", NULL));
}

static void test_no_difference_between_identical_strands(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, compute("A", "A"));
}

static void test_identical_long_strands(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, compute("GGACTGA", "GGACTGA"));
}

static void test_hamming_distance_for_single_nucleotide_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1, compute("A", "G"));
}

static void test_complete_hamming_distance_for_small_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(2, compute("AG", "CT"));
}

static void test_small_hamming_distance(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1, compute("AT", "CT"));
}

static void test_small_hamming_distance_in_longer_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(1, compute("GGACG", "GGTCG"));
}

static void test_rejects_extra_length_on_first_strand_when_longer(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("AAAG", "AAA"));
}

static void test_rejects_extra_length_on_other_strand_when_longer(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(-1, compute("AAA", "AAAG"));
}

static void test_large_hamming_distance(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(4, compute("GATACA", "GCATAA"));
}

static void test_hamming_distance_in_very_long_strand(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(9, compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

int main(void)
{
   UnityBegin("test/test_hamming.c");

   RUN_TEST(test_empty_strands);
   RUN_TEST(test_no_difference_between_identical_strands);
   RUN_TEST(test_rejects_null_strand);
   RUN_TEST(test_rejects_other_null_strand);
   RUN_TEST(test_identical_long_strands);
   RUN_TEST(test_hamming_distance_for_single_nucleotide_strand);
   RUN_TEST(test_complete_hamming_distance_for_small_strand);
   RUN_TEST(test_small_hamming_distance);
   RUN_TEST(test_small_hamming_distance_in_longer_strand);
   RUN_TEST(test_rejects_extra_length_on_first_strand_when_longer);
   RUN_TEST(test_rejects_extra_length_on_other_strand_when_longer);
   RUN_TEST(test_large_hamming_distance);
   RUN_TEST(test_hamming_distance_in_very_long_strand);

   return UnityEnd();
}
