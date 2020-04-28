#include "pig_latin.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static bool is_vowel(const char letter)
{
   return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
       || letter == 'u';
}

static bool starts_with_vowel_sound(const char *input)
{
   const char first_letter = tolower(input[0]);
   const char sec_letter = tolower(input[1]);

   return is_vowel(first_letter) || (first_letter == 'x' && sec_letter == 'r')
       || (first_letter == 'y' && sec_letter == 't');
}

static void count_words_and_chars(const char *input, size_t *words,
                                  size_t *chars)
{
   bool in_word = false;
   while (*input) {
      (*chars)++;
      if (isalpha(*input++)) {
         *words += in_word ? 0 : 1;
         in_word = true;
      } else {
         in_word = false;
      }
   }
}

static void strncpy_tolower(char *dst, const char *src, size_t n)
{
   while ((n--) && (*dst++ = tolower(*src++))) ;
}

static void append_ay(char *translated)
{
   *translated = 'a';
   *(translated + 1) = 'y';
}

static bool starts_with(const char *input, const char *start_seq)
{
   while (*start_seq)
      if (tolower(*input++) != *start_seq++)
         return false;

   return true;
}

static void process_pig_logic(char *dst, const char *src, size_t word_len)
{
   append_ay(dst + word_len);

   if (starts_with_vowel_sound(src)) {
      strncpy_tolower(dst, src, word_len);
      return;
   }

   size_t i = 0;
   while (src[i]) {
      if (is_vowel(tolower(src[i])))
         break;

      if (starts_with(&src[i + 1], "y")) {
         i++;
         break;
      }

      if (starts_with(&src[i], "qu")) {
         i += 2;
         break;
      }
      i++;
   }

   strncpy_tolower(dst, src + i, word_len - i);
   strncpy_tolower(dst + (word_len - i), src, i);
}

char *translate(const char *phrase)
{
   if (phrase == NULL)
      return NULL;

   size_t words = 0, chars = 0;
   count_words_and_chars(phrase, &words, &chars);
   if (chars == 0)
      return NULL;

   /* every word gets 'ay' at the end */
   const size_t translated_len = chars + words * 2;

   char *translated = malloc(translated_len + 1);
   if (translated == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   if (words == 0)
      return strcpy(translated, phrase);

   char *tmp = translated;
   while (words--) {
      /* just copy non-alphas */
      while (*phrase && !isalpha(*phrase))
         *tmp++ = *phrase++;

      size_t word_len = 0;
      while (isalpha(phrase[word_len]))
         word_len++;

      process_pig_logic(tmp, phrase, word_len);

      tmp += word_len + 2;
      phrase += word_len;
   }
   translated[translated_len] = '\0';

   return translated;
}
