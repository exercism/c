#include "vendor/unity.h"
#include "../src/nucleotide_count.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_strand_count(const char *dna_strand, const char *expected)
{
   char *actual_count = count(dna_strand);

   TEST_ASSERT_TRUE(strcmp(actual_count, expected) == 0);
   free(actual_count);
}

void test_empty_strand(void)
{
   TEST_IGNORE();               // delete this line to run test
   const char *dna_strand = "";
   const char *expected = "A:0 C:0 G:0 T:0";

   test_strand_count(dna_strand, expected);
}

void test_repeated_nucleotide(void)
{
   TEST_IGNORE();
   const char *dna_strand = "GGGGGGG";
   const char *expected = "A:0 C:0 G:7 T:0";

   test_strand_count(dna_strand, expected);
}

void test_multiple_nucleotides(void)
{
   TEST_IGNORE();
   const char *dna_strand =
       "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
   const char *expected = "A:20 C:12 G:17 T:21";

   test_strand_count(dna_strand, expected);
}

void test_invalid_nucleotide(void)
{
   TEST_IGNORE();
   const char *dna_strand = "AGXXACT";
   const char *expected = "";

   test_strand_count(dna_strand, expected);
}

int main(void)
{
   UnityBegin("test/test_rna_transcription.c");

   RUN_TEST(test_empty_strand);
   RUN_TEST(test_repeated_nucleotide);
   RUN_TEST(test_multiple_nucleotides);
   RUN_TEST(test_invalid_nucleotide);

   UnityEnd();
   return 0;
}
