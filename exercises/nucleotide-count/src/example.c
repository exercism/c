#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
   bool invalidChar = false;
   uint16_t index;
   uint16_t count_a = 0;
   uint16_t count_c = 0;
   uint16_t count_g = 0;
   uint16_t count_t = 0;
   char *count_results = calloc(1, 50);

   for (index = 0; (index < strlen(dna_strand)) && (invalidChar == false);
        index++) {
      switch (dna_strand[index]) {
      case 'A':
         count_a++;
         break;
      case 'C':
         count_c++;
         break;
      case 'G':
         count_g++;
         break;
      case 'T':
         count_t++;
         break;
      default:
         invalidChar = true;
         break;
      }
   }

   if (!invalidChar) {
      sprintf(count_results, "A:%u C:%u G:%u T:%u", count_a, count_c, count_g,
              count_t);
   }
   return count_results;
}
