#include "unity.h"
#include "hamming.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_no_difference_between_identical_strands(void)
{
    TEST_ASSERT_EQUAL(0, compute("A", 1, "A", 1));
}

void test_hamming_distance_for_single_nucleotide_strand(void)
{
    TEST_ASSERT_EQUAL(1, compute("A", 1, "G", 1));
}

void test_complete_hamming_distance_for_small_strand(void)
{
    TEST_ASSERT_EQUAL(2, compute("AG", 2, "CT", 2));
}

void test_small_hamming_distance(void)
{
    TEST_ASSERT_EQUAL(1, compute("AT", 2, "CT", 2));
}

void test_small_hamming_distance_in_longer_strand(void)
{
    TEST_ASSERT_EQUAL(1, compute("GGACG", 4, "GGTCG", 5));
}

void test_ignores_extra_length_on_first_strand_when_longer(void)
{
    TEST_ASSERT_EQUAL(0, compute("AAAG", 4, "AAA", 3));
}

void test_ignores_extra_length_on_other_strand_when_longer(void)
{
    TEST_ASSERT_EQUAL(0, compute("AAA", 3, "AAAG", 4));
}

void test_large_hamming_distance(void)
{
    TEST_ASSERT_EQUAL(4, compute("GATACA", 6, "GCATAA", 6));
}

void test_hamming_distance_in_very_long_strand(void)
{
    TEST_ASSERT_EQUAL(9, compute("GGACGGATTCTG", 12, "AGGACGGATTCT", 12));
}

