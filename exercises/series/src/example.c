#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "series.h"

series_results_t series(char *input_text, unsigned int substring_length)
{
   int substring_count = strlen(input_text) - (substring_length - 1);
   series_results_t results;

   memset(&results, 0, sizeof(results));
   if ((substring_count > 0) && (substring_length > 0)) {
      results.substring_count = substring_count;
      results.substring = malloc(sizeof(char *) * substring_count);
      for (int index = 0; index < substring_count; index++) {
         results.substring[index] =
             malloc(sizeof(char) * (substring_length + 1));
         sprintf(results.substring[index], "%.*s", substring_length,
                 &input_text[index]);
      }
   }
   return results;
}
