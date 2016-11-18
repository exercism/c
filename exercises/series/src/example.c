#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "series.h"

SeriesResults_t *series(char *inputText, unsigned int substringLength)
{
   int substringCount = strlen(inputText) - (substringLength - 1);
   SeriesResults_t *results = malloc(sizeof(SeriesResults_t));

   memset(results, 0, sizeof(*results));
   if ((substringCount > 0) && (substringLength > 0)) {
      results->substringCount = substringCount;
      results->substring = malloc(sizeof(char *) * substringCount);
      for (int index = 0; index < substringCount; index++) {
         results->substring[index] =
             malloc(sizeof(char) * (substringLength + 1));
         sprintf(results->substring[index], "%.*s", substringLength,
                 &inputText[index]);
      }
   }
   return results;
}
