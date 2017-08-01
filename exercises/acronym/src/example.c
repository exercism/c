#include <ctype.h>
#include <stdlib.h>

static int is_first_letter_of_word(int character, int preceding_character)
{
   return isalpha(character)
       && ((preceding_character == ' ')
           || (preceding_character == '-')) ? 1 : 0;
}

static int count_words(const char phrase[])
{
   int count = 0;

   if (phrase != NULL)
      count = 1;                /* first word */
   else
      return count;

   for (size_t i = 1; phrase[i] != '\0'; ++i)
      if (is_first_letter_of_word(phrase[i], phrase[i - 1]))
         ++count;               /* subsequent words */
   return count;
}

char *abbreviate(const char phrase[])
{
   char *acronym = NULL;

   if (phrase == NULL || phrase[0] == '\0')
      return NULL;              /* invalid argument */

   acronym = calloc(count_words(phrase) + 1, sizeof phrase[0]);
   if (!acronym)
      return NULL;              /* calloc failed */

   acronym[0] = toupper(phrase[0]);     /* first letter of first word */

   for (size_t i = 1, j = 1; phrase[i] != '\0'; ++i) {
      if (is_first_letter_of_word(phrase[i], phrase[i - 1]))
         acronym[j++] = toupper(phrase[i]);     /* first letter of subsequent words */
   }
   return acronym;
}
