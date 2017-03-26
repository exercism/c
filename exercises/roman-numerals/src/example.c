#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

#define NUM_OF_ELEMENTS(a)    (sizeof(a) / sizeof(a[0]))
#define MAX_NUMERAL_LENGTH    (7)

typedef struct {
   char *numeral;
   unsigned int value;
} numeral_values_t;

const numeral_values_t numeral_values[] = {
   {"M", 1000},
   {"CM", 900},
   {"D", 500},
   {"CD", 400},
   {"C", 100},
   {"XC", 90},
   {"L", 50},
   {"XL", 40},
   {"X", 10},
   {"IX", 9},
   {"V", 5},
   {"IV", 4},
   {"I", 1}
};

char *to_roman_numeral(unsigned int number)
{
   char *numerals = calloc(sizeof(char), MAX_NUMERAL_LENGTH);

   for (size_t i = 0; i < NUM_OF_ELEMENTS(numeral_values); i++) {
      while (number >= numeral_values[i].value) {
         strncat(numerals, numeral_values[i].numeral,
                 MAX_NUMERAL_LENGTH - strlen(numerals));
         number -= numeral_values[i].value;
      }
   }

   return numerals;
}
