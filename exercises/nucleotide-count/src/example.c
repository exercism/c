#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
   bool invalidChar = false;
   uint16_t index;
   uint16_t nucleotide_A_count = 0;
   uint16_t nucleotide_C_count = 0;
   uint16_t nucleotide_G_count = 0;
   uint16_t nucleotide_T_count = 0;
   char *count_results = calloc(1, 50);

   for (index = 0; (index < strlen(dna_strand)) && (invalidChar == false);
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
         invalidChar = true;
         break;
      }
   }

   if (!invalidChar) {
      sprintf(count_results, "A:%u C:%u G:%u T:%u", nucleotide_A_count,
              nucleotide_C_count, nucleotide_G_count, nucleotide_T_count);
   }
   return count_results;
}
