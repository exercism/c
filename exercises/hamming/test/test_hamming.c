#include "vendor/unity.h"
#include "../src/hamming.h"

void test_no_difference_between_identical_strands(void)
{
   TEST_ASSERT_EQUAL(0, compute("A", "A"));
}

void test_hamming_distance_for_single_nucleotide_strand(void)
{
   TEST_ASSERT_EQUAL(1, compute("A", "G"));
}

void test_complete_hamming_distance_for_small_strand(void)
{
   TEST_ASSERT_EQUAL(2, compute("AG", "CT"));
}

void test_small_hamming_distance(void)
{
   TEST_ASSERT_EQUAL(1, compute("AT", "CT"));
}

void test_small_hamming_distance_in_longer_strand(void)
{
   TEST_ASSERT_EQUAL(1, compute("GGACG", "GGTCG"));
}

void test_ignores_extra_length_on_first_strand_when_longer(void)
{
   TEST_ASSERT_EQUAL(0, compute("AAAG", "AAA"));
}

void test_ignores_extra_length_on_other_strand_when_longer(void)
{
   TEST_ASSERT_EQUAL(0, compute("AAA", "AAAG"));
}

void test_large_hamming_distance(void)
{
   TEST_ASSERT_EQUAL(4, compute("GATACA", "GCATAA"));
}

void test_hamming_distance_in_very_long_strand(void)
{
   TEST_ASSERT_EQUAL(9, compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

int main(void)
{
   UnityBegin("hamming.c");

   RUN_TEST(test_no_difference_between_identical_strands);
   RUN_TEST(test_hamming_distance_for_single_nucleotide_strand);
   RUN_TEST(test_complete_hamming_distance_for_small_strand);
   RUN_TEST(test_small_hamming_distance);
   RUN_TEST(test_small_hamming_distance_in_longer_strand);
   RUN_TEST(test_ignores_extra_length_on_first_strand_when_longer);
   RUN_TEST(test_ignores_extra_length_on_other_strand_when_longer);
   RUN_TEST(test_large_hamming_distance);
   RUN_TEST(test_hamming_distance_in_very_long_strand);

   UnityEnd();
   return 0;
}
