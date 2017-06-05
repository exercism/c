#include "wordy.h"

#define ADDITION 1
#define SUBRACTION 2
#define DIVISION 3
#define MULTIPLICATION 4
#define EXPO 5

static char *strdup(const char *str)
{
   char *copy;
   if ((copy = calloc(strlen(str) + 1, sizeof(char *))) != NULL) {
      strcpy(copy, str);
   }
   return copy;
}

static char *strsep(char **stringp, const char *delim)
{
   char *s;
   const char *spanp;
   int c, sc;
   char *tok;
   if ((s = *stringp) == NULL)
      return (NULL);
   for (tok = s;;) {
      c = *s++;
      spanp = delim;
      do {
         if ((sc = *spanp++) == c) {
            if (c == 0)
               s = NULL;
            else
               s[-1] = 0;
            *stringp = s;
            return (tok);
         }
      } while (sc != 0);
   }
}

static int raise_to(int base, int exp)
{
   int ret = 1;
   for (int i = 0; i < exp; i++) {
      ret = ret * base;
   }
   return ret;
}

static void free_list(char **list, size_t n)
{
   for (size_t i = 0; i < n; ++i) {
      free(list[i]);
   }
   free(list);
}

static char *is_integer(char *s)
{
   size_t s_len = strlen(s);
   size_t i = 0;
   if (strstr(s, "-")) {
      i = 1;
   }
   for (; i < s_len; i++) {
      if (!isdigit(s[i])) {
         return NULL;
      }
   }
   return s;
}

static char **create_list(const char *input, size_t * n)
{
   char *s = strdup(input);
   size_t list_alloc = 1;
   size_t list_used = 0;
   char **lists = calloc(list_alloc, sizeof(char *));
   char *list, *rest = s;
   while ((list = strsep(&rest, " ")) != NULL) {
      if (list_used == list_alloc) {
         list_alloc *= 2;
         lists = realloc(lists, list_alloc * sizeof(char *));
      }
      lists[list_used++] = strdup(list);
   }
   if (list_used == 0) {
      free(lists);
      lists = NULL;
   } else {
      lists = realloc(lists, list_used * sizeof(char *));
   }
   *n = list_used;
   free(s);
   return lists;
}

int wordy(const char *instructions)
{
   int result = 0;
   int operator = - 1;
   int no_op = 1;
   char *buf1 = NULL;
   char *buf2 = NULL;
   size_t n = 0;
   size_t instructions_len = strlen(instructions);
   if (instructions[instructions_len - 1] != '?') {
      return result;
   }
   char *input = calloc(instructions_len, sizeof(char *));
   strncpy(input, instructions, instructions_len - 1);
   char **l = create_list(input, &n);
   free(input);
   if (strcmp(l[0], "What") || strcmp(l[1], "is") || n == 0) {
      free_list(l, n);
      return result;
   }
   for (size_t i = 2; i < n; ++i) {
      if ((buf1 = is_integer(l[i])) != NULL && i == 2) {
         result = atoi(buf1);
      }
      if (((buf1 = is_integer(l[i])) != NULL && i != 2)
          || (strstr(l[i], "th") && i != 2 && isdigit(l[i][0]))) {
         if (operator == ADDITION) {
            result = result + atoi(buf1);
         } else if (operator == SUBRACTION) {
            result = result - atoi(buf1);
         } else if (operator == MULTIPLICATION) {
            result = result * atoi(buf1);
         } else if (operator == DIVISION) {
            result = result / atoi(buf1);
         } else if (operator == EXPO) {
            if (strstr(l[i], "th")) {
               buf2 = calloc(strlen(l[i]), sizeof(char *));
               strncpy(buf2, l[i], strlen(l[i]) - 2);
               result = raise_to(result, atoi(buf2));
               free(buf2);
            } else {
               result = raise_to(result, atoi(buf1));
            }
         } else {
            break;
         }
         operator = - 1;
      }
      if (!strcmp(l[i], "plus")) {
         operator = ADDITION;
         no_op = 0;
      }
      if (!strcmp(l[i], "minus")) {
         operator = SUBRACTION;
         no_op = 0;
      }
      if (!strcmp(l[i], "multiplied") && !strcmp(l[i + 1], "by")) {
         operator = MULTIPLICATION;
         no_op = 0;
      }
      if (!strcmp(l[i], "divided") && !strcmp(l[i + 1], "by")) {
         operator = DIVISION;
         no_op = 0;
      }
      if (!strcmp(l[i], "raised") && !strcmp(l[i + 1], "to")
          && !strcmp(l[i + 2], "the")) {
         operator = EXPO;
         no_op = 0;
      }
   }
   free_list(l, n);
   if (no_op) {
      result = 0;
   }
   return result;
}
