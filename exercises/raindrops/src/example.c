#include "raindrops.h"
#include "stdio.h"
#include "string.h"

#define PLING_FACTOR 3
#define PLANG_FACTOR 5
#define PLONG_FACTOR 7

char *convert(int drops)
{
   static char result[100];
   memset(result,'\0',100);
  
   if(drops % 3 == 0) {
      strcat(result, "Pling");
   }
   if(drops % 5 == 0) {
      strcat(result, "Plang");
   }
   if(drops % 7 == 0) {
      strcat(result, "Plong");
   }
   if(strlen(result) == 0) {
      char drops_string[12] = "";
      sprintf(drops_string, "%d", drops);
      strcat(result, drops_string);
   }
   return(result);
}
