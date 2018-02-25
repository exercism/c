#include "pig_latin.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static bool is_vowel(const char a)
{
   return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

static bool starts_with_vowel(const char a, const char b)
{
   return is_vowel(a) || (a == 'x' && b == 'r') || (a == 'y' && b == 't');
}

static void count_words_and_chars(const char *input, size_t * words,
                                  size_t * chars)
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

static void mstrncpy(char *dst, const char *src, size_t n)
{
   while ((n--) && (*dst++ = tolower(*src++))) ;
}

static void append_ay(char *res)
{
   *res = 'a';
   *(res + 1) = 'y';
}

static void process_pig_logic(char *dst, const char *src, size_t word_len)
{
   append_ay(dst + word_len);

   const char a = tolower(*src);
   const char b = a ? tolower(*(src + 1)) : 0;

   if (starts_with_vowel(a, b)) {
      mstrncpy(dst, src, word_len);
      return;
   }

   size_t i = 0;
   while (src[i]) {
      const char a = tolower(src[i]);
      const char b = tolower(src[i + 1]);

      if (is_vowel(a))
         break;

      if (b == 'y') {
         i++;
         break;
      }

      if (a == 'q' && b == 'u') {
         i += 2;
         break;
      }
      i++;
   }
   mstrncpy(dst, src + i, word_len - i);
   mstrncpy(dst + (word_len - i), src, i);
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
   const size_t res_len = chars + words * 2;

   char *res = malloc(res_len + 1);
   if (res == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   if (words == 0)
      return strcpy(res, phrase);

   char *tmp = res;
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
   res[res_len] = '\0';

   return res;
}
