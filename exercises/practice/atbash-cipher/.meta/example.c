#include "atbash_cipher.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define GROUP_SIZE      (5)

static void remove_trailing_space(char *string)
{
   if (string[strlen(string) - 1] == ' ') {
      string[strlen(string) - 1] = '\0';
   }
}

static bool is_valid_character(char character)
{
   return isalpha(character) || isdigit(character);
}

static char get_encoded_character(char character)
{
   return (isdigit(character) ? character : 'z' - (character - 'a'));
}

static char get_decoded_character(char character)
{
   return (isdigit(character) ? character : 'a' + ('z' - character));
}

char *atbash_encode(const char *input)
{
   char *output = malloc(strlen(input) + (strlen(input) / GROUP_SIZE) + 1);
   int group_count = 0;

   output[0] = '\0';

   for (size_t i = 0; i < strlen(input); i++) {
      if (is_valid_character(tolower(input[i]))) {
         char encoded_character = get_encoded_character(tolower(input[i]));

         strncat(output, &encoded_character, 1);

         if (++group_count == GROUP_SIZE) {
            strcat(output, " ");
            group_count = 0;
         }
      }
   }

   remove_trailing_space(output);

   return output;
}

char *atbash_decode(const char *input)
{
   char *output = malloc(strlen(input) + (strlen(input) / GROUP_SIZE));

   output[0] = '\0';

   for (size_t i = 0; i < strlen(input); i++) {
      if (is_valid_character(input[i])) {
         char decoded_character = get_decoded_character(input[i]);

         strncat(output, &decoded_character, 1);
      }
   }

   return output;
}
