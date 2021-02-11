#include "raindrops.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

char *convert(char result[], int drops)
{
   if (drops % 3 == 0) {
      strcat(result, "Pling");
   }
   if (drops % 5 == 0) {
      strcat(result, "Plang");
   }
   if (drops % 7 == 0) {
      strcat(result, "Plong");
   }
   if (strlen(result) == 0) {
      char drops_string[12] = "\0";
      sprintf(drops_string, "%d", drops);
      strcat(result, drops_string);
   }
   return result;
}
