#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define AREA_CODE_LENGTH         (3)
#define EXCHANGE_LENGTH          (3)
#define EXTENSION_LENGTH         (4)
#define VALID_NUMBER_LENGTH      AREA_CODE_LENGTH + EXCHANGE_LENGTH + EXTENSION_LENGTH

#define EXCHANGE_OFFSET (AREA_CODE_LENGTH)

#define INVALID_NUMBER_RESULT    "0000000000"
#define VALID_NON_DIGIT_CHARS    " .-()"

static void remove_leading_digit(char *phone_number)
{
   for (size_t i = 0; phone_number[i]; ++i) {
      phone_number[i] = phone_number[i + 1];
   }
}

char *phone_number_clean(const char *input)
{
   char *output = calloc(VALID_NUMBER_LENGTH + 2, sizeof(char));
   size_t j = 0;

   for (size_t i = 0; i < strlen(input); i++) {

      if (isdigit(input[i]) || (i == 0 && input[0] == '+')) {

         if (j > VALID_NUMBER_LENGTH + 1) {
            break;
         }
         if (isdigit(input[i]))
            output[j++] = input[i];

      } else if (strchr(VALID_NON_DIGIT_CHARS, input[i]) == NULL) {
         strcpy(output, INVALID_NUMBER_RESULT);
         return output;
      }
   }

   if (j > 11 || j < 10) {
      strcpy(output, INVALID_NUMBER_RESULT);
   } else if (j == 11) {
      if (output[0] == '1') {
         remove_leading_digit(output);
      } else {
         strcpy(output, INVALID_NUMBER_RESULT);
      }
   }

   if (output[0] < '2' || output[EXCHANGE_OFFSET] < '2')
      strcpy(output, INVALID_NUMBER_RESULT);

   return output;
}
