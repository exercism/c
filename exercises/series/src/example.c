#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdio.h>
#include "series.h"

SeriesResults_t *series(char *inputText, unsigned int substringLength)
{
   int substringCount = strlen(inputText) - (substringLength - 1);
   SeriesResults_t *results = malloc(sizeof(SeriesResults_t));

   memset(results, 0, sizeof(*results));
   if ((substringCount > 0) && (substringLength > 0)) {
      results->substringCount = substringCount;
      results->substring = malloc(substringCount * sizeof(char *));
      for (int index = 0; index < substringCount; index++) {
         results->substring[index] = malloc(substringLength + 1);
         strncpy(results->substring[index], &inputText[index], substringLength);
      }
   }
   return results;
}
