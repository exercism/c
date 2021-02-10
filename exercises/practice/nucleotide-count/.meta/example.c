#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
   bool invalid_char = false;
   size_t index;
   size_t nucleotide_a_count = 0;
   size_t nucleotide_c_count = 0;
   size_t nucleotide_g_count = 0;
   size_t nucleotide_t_count = 0;
   char *count_results = calloc(1, 50);

   for (index = 0; (index < strlen(dna_strand)) && (invalid_char == false);
        index++) {
      switch (dna_strand[index]) {
      case 'A':
         nucleotide_a_count++;
         break;
      case 'C':
         nucleotide_c_count++;
         break;
      case 'G':
         nucleotide_g_count++;
         break;
      case 'T':
         nucleotide_t_count++;
         break;
      default:
         invalid_char = true;
         break;
      }
   }

   if (!invalid_char) {
      sprintf(count_results, "A:%zu C:%zu G:%zu T:%zu", nucleotide_a_count,
              nucleotide_c_count, nucleotide_g_count, nucleotide_t_count);
   }
   return count_results;
}
