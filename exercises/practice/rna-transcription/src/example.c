#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna)
{
   size_t len = strlen(dna);
   char *rna = calloc(sizeof(char), len + 1);

   for (size_t i = 0; i < len; i++) {
      switch (dna[i]) {
      case 'G':
         rna[i] = 'C';
         break;
      case 'C':
         rna[i] = 'G';
         break;
      case 'T':
         rna[i] = 'A';
         break;
      case 'A':
         rna[i] = 'U';
         break;
      default:
         free(rna);
         return NULL;
      }
   }

   return rna;
}
