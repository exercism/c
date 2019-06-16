#include "vendor/unity.h"
#include "../src/rna_transcription.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_transcription(const char *dna, const char *expected)
{
   char *rna = to_rna(dna);
   TEST_ASSERT_EQUAL_STRING(expected, rna);
   free(rna);
}

static void test_failure(const char *dna)
{
   TEST_ASSERT_NULL(to_rna(dna));
}

static void test_transcribes_G_to_C(void)
{
   test_transcription("G", "C");
}

static void test_transcribes_C_to_G(void)
{
   TEST_IGNORE();               // delete this line to run test
   test_transcription("C", "G");
}

static void test_transcribes_T_to_A(void)
{
   TEST_IGNORE();
   test_transcription("T", "A");
}

static void test_transcribes_A_to_U(void)
{
   TEST_IGNORE();
   test_transcription("A", "U");
}

static void test_transcribes_all_occurrences(void)
{
   TEST_IGNORE();
   test_transcription("ACGTGGTCTTAA", "UGCACCAGAAUU");
}

static void test_handle_invalid_nucleotide(void)
{
   TEST_IGNORE();
   test_failure("U");
}

static void test_handle_completely_invalid_input(void)
{
   TEST_IGNORE();
   test_failure("XXX");
}

static void test_handle_partially_invalid_input(void)
{
   TEST_IGNORE();
   test_failure("ACGTXXXCTTAA");
}

int main(void)
{
   UnityBegin("test/test_rna_transcription.c");

   RUN_TEST(test_transcribes_G_to_C);
   RUN_TEST(test_transcribes_C_to_G);
   RUN_TEST(test_transcribes_T_to_A);
   RUN_TEST(test_transcribes_A_to_U);
   RUN_TEST(test_transcribes_all_occurrences);
   RUN_TEST(test_handle_invalid_nucleotide);
   RUN_TEST(test_handle_completely_invalid_input);
   RUN_TEST(test_handle_partially_invalid_input);

   return UnityEnd();
}
