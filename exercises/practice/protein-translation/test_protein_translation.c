#include "test-framework/unity.h"
#include "protein_translation.h"
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void assert_protein_match(protein_t expected, protein_t actual)
{
   TEST_ASSERT_EQUAL_CHAR(expected.valid, actual.valid);
   if (expected.valid) {
      TEST_ASSERT_EQUAL_size_t(expected.count, actual.count);
      if (expected.count > 0) {
         TEST_ASSERT_EQUAL_INT_ARRAY(expected.amino_acids, actual.amino_acids,
                                     expected.count);
      }
   }
}

static void test_empty_rna_sequence_results_in_no_protein(void)
{
   protein_t expected = {
      .valid = true,
      .count = 0,
   };
   protein_t actual = protein("");
   assert_protein_match(expected, actual);
}

static void test_methionine_rna_sequence(void)
{
   TEST_IGNORE();   // delete this line to run test
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Methionine },
   };
   protein_t actual = protein("AUG");
   assert_protein_match(expected, actual);
}

static void test_phenylalanine_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Phenylalanine },
   };
   protein_t actual = protein("UUU");
   assert_protein_match(expected, actual);
}

static void test_phenylalanine_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Phenylalanine },
   };
   protein_t actual = protein("UUC");
   assert_protein_match(expected, actual);
}

static void test_leucine_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Leucine },
   };
   protein_t actual = protein("UUA");
   assert_protein_match(expected, actual);
}

static void test_leucine_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Leucine },
   };
   protein_t actual = protein("UUG");
   assert_protein_match(expected, actual);
}

static void test_serine_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Serine },
   };
   protein_t actual = protein("UCU");
   assert_protein_match(expected, actual);
}

static void test_serine_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Serine },
   };
   protein_t actual = protein("UCC");
   assert_protein_match(expected, actual);
}

static void test_serine_rna_sequence_3(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Serine },
   };
   protein_t actual = protein("UCA");
   assert_protein_match(expected, actual);
}

static void test_serine_rna_sequence_4(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Serine },
   };
   protein_t actual = protein("UCG");
   assert_protein_match(expected, actual);
}

static void test_tyrosine_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Tyrosine },
   };
   protein_t actual = protein("UAU");
   assert_protein_match(expected, actual);
}

static void test_tyrosine_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Tyrosine },
   };
   protein_t actual = protein("UAC");
   assert_protein_match(expected, actual);
}

static void test_cysteine_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Cysteine },
   };
   protein_t actual = protein("UGU");
   assert_protein_match(expected, actual);
}

static void test_cysteine_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Cysteine },
   };
   protein_t actual = protein("UGC");
   assert_protein_match(expected, actual);
}

static void test_tryptophan_rna_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Tryptophan },
   };
   protein_t actual = protein("UGG");
   assert_protein_match(expected, actual);
}

static void test_stop_codon_rna_sequence_1(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 0,
   };
   protein_t actual = protein("UAA");
   assert_protein_match(expected, actual);
}

static void test_stop_codon_rna_sequence_2(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 0,
   };
   protein_t actual = protein("UAG");
   assert_protein_match(expected, actual);
}

static void test_stop_codon_rna_sequence_3(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 0,
   };
   protein_t actual = protein("UGA");
   assert_protein_match(expected, actual);
}

static void test_sequence_of_two_protein_codons_translates_into_protein(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 2,
      .amino_acids = { Phenylalanine, Phenylalanine },
   };
   protein_t actual = protein("UUUUUU");
   assert_protein_match(expected, actual);
}

static void
test_sequence_of_two_different_protein_codons_translates_into_protein(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 2,
      .amino_acids = { Leucine, Leucine },
   };
   protein_t actual = protein("UUAUUG");
   assert_protein_match(expected, actual);
}

static void test_translate_rna_strand_into_correct_protein_list(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 3,
      .amino_acids = { Methionine, Phenylalanine, Tryptophan },
   };
   protein_t actual = protein("AUGUUUUGG");
   assert_protein_match(expected, actual);
}

static void test_translation_stops_if_stop_codon_at_beginning_of_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 0,
   };
   protein_t actual = protein("UAGUGG");
   assert_protein_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_at_end_of_two_codon_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Tryptophan },
   };
   protein_t actual = protein("UGGUAG");
   assert_protein_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_at_end_of_three_codon_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 2,
      .amino_acids = { Methionine, Phenylalanine },
   };
   protein_t actual = protein("AUGUUUUAA");
   assert_protein_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_in_middle_of_three_codon_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 1,
      .amino_acids = { Tryptophan },
   };
   protein_t actual = protein("UGGUAGUGG");
   assert_protein_match(expected, actual);
}

static void
test_translation_stops_if_stop_codon_in_middle_of_six_codon_sequence(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 3,
      .amino_acids = { Tryptophan, Cysteine, Tyrosine },
   };
   protein_t actual = protein("UGGUGUUAUUAAUGGUUU");
   assert_protein_match(expected, actual);
}

static void
test_sequence_of_two_non_stop_codons_does_not_translate_to_a_stop_codon(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 2,
      .amino_acids = { Methionine, Methionine },
   };
   protein_t actual = protein("AUGAUG");
   assert_protein_match(expected, actual);
}

static void test_non_existing_codon_cant_translate(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = false,
   };
   protein_t actual = protein("AAA");
   assert_protein_match(expected, actual);
}

static void test_unknown_amino_acids_not_part_of_a_codon_cant_translate(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = false,
   };
   protein_t actual = protein("XYZ");
   assert_protein_match(expected, actual);
}

static void test_invalid_codon_cant_translate(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = false,
   };
   protein_t actual = protein("AUGU");
   assert_protein_match(expected, actual);
}

static void
test_incomplete_rna_sequence_can_translate_if_valid_until_a_stop_codon(void)
{
   TEST_IGNORE();
   protein_t expected = {
      .valid = true,
      .count = 2,
      .amino_acids = { Phenylalanine, Phenylalanine },
   };
   protein_t actual = protein("UUCUUCUAAUGGU");
   assert_protein_match(expected, actual);
}

int main(void)
{
   UNITY_BEGIN();

   // clang-format off
   RUN_TEST(test_empty_rna_sequence_results_in_no_protein);
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
   RUN_TEST(test_sequence_of_two_protein_codons_translates_into_protein);
   RUN_TEST(test_sequence_of_two_different_protein_codons_translates_into_protein);
   RUN_TEST(test_translate_rna_strand_into_correct_protein_list);
   RUN_TEST(test_translation_stops_if_stop_codon_at_beginning_of_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_at_end_of_two_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_at_end_of_three_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_in_middle_of_three_codon_sequence);
   RUN_TEST(test_translation_stops_if_stop_codon_in_middle_of_six_codon_sequence);
   RUN_TEST(test_sequence_of_two_non_stop_codons_does_not_translate_to_a_stop_codon);
   RUN_TEST(test_non_existing_codon_cant_translate);
   RUN_TEST(test_unknown_amino_acids_not_part_of_a_codon_cant_translate);
   RUN_TEST(test_invalid_codon_cant_translate);
   RUN_TEST(test_incomplete_rna_sequence_can_translate_if_valid_until_a_stop_codon);
   // clang-format on

   return UNITY_END();
}
