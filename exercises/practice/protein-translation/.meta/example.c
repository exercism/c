#include <string.h>
#include "protein_translation.h"

enum { codon_length = 3 };

typedef struct {
   const char *const codon;
   amino_acid_t amino_acid;
   bool stop;
} amino_acid_translation_t;

static const amino_acid_translation_t translations[] = {
   { "AUG", Methionine, false },
   { "UUU", Phenylalanine, false },
   { "UUC", Phenylalanine, false },
   { "UUA", Leucine, false },
   { "UUG", Leucine, false },
   { "UCU", Serine, false },
   { "UCC", Serine, false },
   { "UCA", Serine, false },
   { "UCG", Serine, false },
   { "UAU", Tyrosine, false },
   { "UAC", Tyrosine, false },
   { "UGU", Cysteine, false },
   { "UGC", Cysteine, false },
   { "UGG", Tryptophan, false },
   { "UAA", 0, true },
   { "UAG", 0, true },
   { "UGA", 0, true },
};
static const size_t translation_count =
    sizeof(translations) / sizeof(translations[0]);

protein_t protein(const char *const rna)
{
   protein_t protein = { .valid = true, .count = 0 };

   size_t rna_length = strlen(rna);

   for (size_t i = 0; i < rna_length; i += codon_length) {
      bool found_codon = false;

      for (size_t j = 0; j < translation_count; j++) {
         if (strncmp(rna + i, translations[j].codon, codon_length) == 0) {
            if (translations[j].stop) {
               return protein;
            } else {
               protein.amino_acids[protein.count++] =
                   translations[j].amino_acid;
               found_codon = true;
               break;
            }
         }
      }

      if (!found_codon) {
         protein.valid = false;
         return protein;
      }
   }

   return protein;
}
