#include "test-framework/unity.h"
#include "protein_translation.h"
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void assert_proteins_match(proteins_t expected, proteins_t actual)
{
   TEST_ASSERT_EQUAL_CHAR(expected.valid, actual.valid);
   if (expected.valid) {
      TEST_ASSERT_EQUAL_size_t(expected.count, actual.count);
      if (expected.count > 0) {
         TEST_ASSERT_EQUAL_INT_ARRAY(expected.proteins, actual.proteins,
                                     expected.count);
      }
   }
}

static void test_empty_rna_sequence_results_in_no_proteins(void)
{
   proteins_t expected = {
      .valid = true,
      .count = 0,
   };
   proteins_t actual = proteins("");
   assert_proteins_match(expected, actual);
}

static void test_methionine_rna_sequence(void)
{
   TEST_IGNORE();   // delete this line to run test
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Methionine },
   };
   proteins_t actual = proteins("AUG");
   assert_proteins_match(expected, actual);
}

static void test_phenylalanine_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Phenylalanine },
   };
   proteins_t actual = proteins("UUU");
   assert_proteins_match(expected, actual);
}

static void test_phenylalanine_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Phenylalanine },
   };
   proteins_t actual = proteins("UUC");
   assert_proteins_match(expected, actual);
}

static void test_leucine_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Leucine },
   };
   proteins_t actual = proteins("UUA");
   assert_proteins_match(expected, actual);
}

static void test_leucine_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Leucine },
   };
   proteins_t actual = proteins("UUG");
   assert_proteins_match(expected, actual);
}

static void test_serine_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Serine },
   };
   proteins_t actual = proteins("UCU");
   assert_proteins_match(expected, actual);
}

static void test_serine_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Serine },
   };
   proteins_t actual = proteins("UCC");
   assert_proteins_match(expected, actual);
}

static void test_serine_rna_sequence_3(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Serine },
   };
   proteins_t actual = proteins("UCA");
   assert_proteins_match(expected, actual);
}

static void test_serine_rna_sequence_4(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Serine },
   };
   proteins_t actual = proteins("UCG");
   assert_proteins_match(expected, actual);
}

static void test_tyrosine_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Tyrosine },
   };
   proteins_t actual = proteins("UAU");
   assert_proteins_match(expected, actual);
}

static void test_tyrosine_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Tyrosine },
   };
   proteins_t actual = proteins("UAC");
   assert_proteins_match(expected, actual);
}

static void test_cysteine_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Cysteine },
   };
   proteins_t actual = proteins("UGU");
   assert_proteins_match(expected, actual);
}

static void test_cysteine_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Cysteine },
   };
   proteins_t actual = proteins("UGC");
   assert_proteins_match(expected, actual);
}

static void test_tryptophan_rna_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Tryptophan },
   };
   proteins_t actual = proteins("UGG");
   assert_proteins_match(expected, actual);
}

static void test_stop_codon_rna_sequence_1(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 0,
   };
   proteins_t actual = proteins("UAA");
   assert_proteins_match(expected, actual);
}

static void test_stop_codon_rna_sequence_2(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 0,
   };
   proteins_t actual = proteins("UAG");
   assert_proteins_match(expected, actual);
}

static void test_stop_codon_rna_sequence_3(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 0,
   };
   proteins_t actual = proteins("UGA");
   assert_proteins_match(expected, actual);
}

static void test_sequence_of_two_protein_codons_translates_into_proteins(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 2,
      .proteins = { Phenylalanine, Phenylalanine },
   };
   proteins_t actual = proteins("UUUUUU");
   assert_proteins_match(expected, actual);
}

static void
test_sequence_of_two_different_protein_codons_translates_into_proteins(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 2,
      .proteins = { Leucine, Leucine },
   };
   proteins_t actual = proteins("UUAUUG");
   assert_proteins_match(expected, actual);
}

static void test_translate_rna_strand_into_correct_protein_list(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 3,
      .proteins = { Methionine, Phenylalanine, Tryptophan },
   };
   proteins_t actual = proteins("AUGUUUUGG");
   assert_proteins_match(expected, actual);
}

static void test_translation_stops_if_stop_codon_at_beginning_of_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 0,
   };
   proteins_t actual = proteins("UAGUGG");
   assert_proteins_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_at_end_of_two_codon_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Tryptophan },
   };
   proteins_t actual = proteins("UGGUAG");
   assert_proteins_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_at_end_of_three_codon_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 2,
      .proteins = { Methionine, Phenylalanine },
   };
   proteins_t actual = proteins("AUGUUUUAA");
   assert_proteins_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_in_middle_of_three_codon_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 1,
      .proteins = { Tryptophan },
   };
   proteins_t actual = proteins("UGGUAGUGG");
   assert_proteins_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_in_middle_of_six_codon_sequence(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 3,
      .proteins = { Tryptophan, Cysteine, Tyrosine },
   };
   proteins_t actual = proteins("UGGUGUUAUUAAUGGUUU");
   assert_proteins_match(expected, actual);
}

static void
test_seuence_of_two_non_stop_codons_does_not_translate_to_a_stop_codon(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 2,
      .proteins = { Methionine, Methionine },
   };
   proteins_t actual = proteins("AUGAUG");
   assert_proteins_match(expected, actual);
}

static void test_non_existing_codon_cant_translate(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = false,
   };
   proteins_t actual = proteins("AAA");
   assert_proteins_match(expected, actual);
}

static void test_unknown_amino_acids_not_part_of_a_codon_cant_translate(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = false,
   };
   proteins_t actual = proteins("XYZ");
   assert_proteins_match(expected, actual);
}

static void test_invalid_codon_cant_translate(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = false,
   };
   proteins_t actual = proteins("AUGU");
   assert_proteins_match(expected, actual);
}

static void
test_incomplete_rna_sequence_can_translate_if_valid_until_a_stop_codon(void)
{
   TEST_IGNORE();
   proteins_t expected = {
      .valid = true,
      .count = 2,
      .proteins = { Phenylalanine, Phenylalanine },
   };
   proteins_t actual = proteins("UUCUUCUAAUGGU");
   assert_proteins_match(expected, actual);
}

int main(void)
{
   UNITY_BEGIN();

   // clang-format off
   RUN_TEST(test_empty_rna_sequence_results_in_no_proteins);
   RUN_TEST(test_methionine_rna_sequence);
   RUN_TEST(test_phenylalanine_rna_sequence_1);
   RUN_TEST(test_phenylalanine_rna_sequence_2);
   RUN_TEST(test_leucine_rna_sequence_1);
   RUN_TEST(test_leucine_rna_sequence_2);
   RUN_TEST(test_serine_rna_sequence_1);
   RUN_TEST(test_serine_rna_sequence_2);
   RUN_TEST(test_serine_rna_sequence_3);
   RUN_TEST(test_serine_rna_sequence_4);
   RUN_TEST(test_tyrosine_rna_sequence_1);
   RUN_TEST(test_tyrosine_rna_sequence_2);
   RUN_TEST(test_cysteine_rna_sequence_1);
   RUN_TEST(test_cysteine_rna_sequence_2);
   RUN_TEST(test_tryptophan_rna_sequence);
   RUN_TEST(test_stop_codon_rna_sequence_1);
   RUN_TEST(test_stop_codon_rna_sequence_2);
   RUN_TEST(test_stop_codon_rna_sequence_3);
   RUN_TEST(test_sequence_of_two_protein_codons_translates_into_proteins);
   RUN_TEST(test_sequence_of_two_different_protein_codons_translates_into_proteins);
   RUN_TEST(test_translate_rna_strand_into_correct_protein_list);
   RUN_TEST(test_translation_stops_if_stop_codon_at_beginning_of_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_at_end_of_two_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_at_end_of_three_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_in_middle_of_three_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_in_middle_of_six_codon_sequence);
   RUN_TEST(test_seuence_of_two_non_stop_codons_does_not_translate_to_a_stop_codon);
   RUN_TEST(test_non_existing_codon_cant_translate);
   RUN_TEST(test_unknown_amino_acids_not_part_of_a_codon_cant_translate);
   RUN_TEST(test_invalid_codon_cant_translate);
   RUN_TEST(test_incomplete_rna_sequence_can_translate_if_valid_until_a_stop_codon);
   // clang-format on

   return UNITY_END();
}
