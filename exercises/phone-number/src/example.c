#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define AREA_CODE_LENGTH         (3)
#define EXCHANGE_LENGTH          (3)
#define EXTENSION_LENGTH         (4)
#define VALID_NUMBER_LENGTH      AREA_CODE_LENGTH + EXCHANGE_LENGTH + EXTENSION_LENGTH
#define FORMATTED_LENGTH         VALID_NUMBER_LENGTH + 4

#define EXCHANGE_OFFSET (AREA_CODE_LENGTH)
#define EXTENSION_OFFSET (AREA_CODE_LENGTH + EXCHANGE_LENGTH)

#define INVALID_NUMBER_RESULT    "0000000000"

static void remove_leading_digit(char *phone_number) {
   char *temp = calloc(VALID_NUMBER_LENGTH, sizeof(char));
   strcpy(temp, &phone_number[1]);
   strcpy(phone_number, temp);
   free(temp);
}

char *phone_number_clean(const char *input)
{
   char *output = calloc(VALID_NUMBER_LENGTH + 1, sizeof(char));

   for (size_t i = 0; i < strlen(input); i++) {
      if (isdigit(input[i])) {
         strncat(output, &input[i], 1);
      }
   }

   if ((strlen(output) > 11) || (strlen(output) < 10)) {
      strcpy(output, INVALID_NUMBER_RESULT);
   } else if (strlen(output) == 11) {
      if (output[0] == '1') {
         remove_leading_digit(output);
      } else {
         strcpy(output, INVALID_NUMBER_RESULT);
      }
   }

   return output;
}

char *phone_number_get_area_code(const char *input)
{
   char *output = phone_number_clean(input);
   output[3] = '\0';

   return output;
}

char *phone_number_format(const char *input)
{
   char *cleaned_input = phone_number_clean(input);
   char *output = calloc(FORMATTED_LENGTH, sizeof(char));

   sprintf(output, "(%.3s) %.3s-%.4s", cleaned_input, &cleaned_input[AREA_CODE_LENGTH], &cleaned_input[EXTENSION_OFFSET]);

   free(cleaned_input);

   return output;
}
