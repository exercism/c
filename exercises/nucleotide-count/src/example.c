#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
   bool invalid_char = false;
   size_t index;
   size_t nucleotide_A_count = 0;
   size_t nucleotide_C_count = 0;
   size_t nucleotide_G_count = 0;
   size_t nucleotide_T_count = 0;
   char *count_results = calloc(1, 50);

   for (index = 0; (index < strlen(dna_strand)) && (invalid_char == false);
        index++) {
      switch (dna_strand[index]) {
      case 'A':
         nucleotide_A_count++;
         break;
      case 'C':
         nucleotide_C_count++;
         break;
      case 'G':
         nucleotide_G_count++;
         break;
      case 'T':
         nucleotide_T_count++;
         break;
      default:
         invalid_char = true;
         break;
      }
   }

   if (!invalid_char) {
      sprintf(count_results, "A:%zd C:%zd G:%zd T:%zd", nucleotide_A_count,
              nucleotide_C_count, nucleotide_G_count, nucleotide_T_count);
   }
   return count_results;
}
