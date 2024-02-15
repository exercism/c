#include <string.h>
#include "protein_translation.h"

enum { codon_length = 3 };

typedef struct {
   const char *const codon;
   protein_t protein;
   bool stop;
} protein_translation_t;

static const protein_translation_t translations[] = {
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

proteins_t proteins(const char *const rna)
{
   proteins_t proteins = { .valid = true, .count = 0 };

   size_t rna_length = strlen(rna);

   for (size_t i = 0; i < rna_length; i += codon_length) {
      bool found_codon = false;

      for (size_t j = 0; j < translation_count; j++) {
         if (strncmp(rna + i, translations[j].codon, codon_length) == 0) {
            if (translations[j].stop) {
               return proteins;
            } else {
               proteins.proteins[proteins.count++] = translations[j].protein;
               found_codon = true;
               break;
            }
         }
      }

      if (!found_codon) {
         proteins.valid = false;
         return proteins;
      }
   }

   return proteins;
}
