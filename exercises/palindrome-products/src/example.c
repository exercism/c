#include "palindrome_products.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

__attribute__ ((optimize("-O3")))
static bool palindrome(int n)
{
   /* 0 is palindrome */
   if (n == 0)
      return true;

   /* negative can not be palindrome */
   if (n < 0)
      return false;

   int tail;

   /* a not-null number can not start with 0 */
   if ((tail = n % 10) == 0)
      return false;
   n /= 10;

   /* split and reverse the second half */
   while (n > tail) {
      tail = (tail * 10) + (n % 10);
      n /= 10;
   }

   return (n == tail)           /* even length */
       ||(n == tail / 10);      /* odd length - discard the middle */
}

static void free_ll(struct factors *p)
{
   if (p == NULL)
      return;
   if (p->next != NULL)
      free_ll(p->next);
   free(p);
}

static int addfactors(factor_t ** p, int factor_one, int factor_two)
{
   int n = factor_one * factor_two;
   if ((*p == NULL) || (((*p)->factor_a) * (*p)->factor_b != n)) {
      free_ll(*p);
      *p = NULL;
   }

   factor_t *tmp = malloc(sizeof(factor_t));
   if (tmp == NULL) {
      fprintf(stderr, "Memory error!\n");
      return 1;
   }

   tmp->next = *p;
   tmp->factor_a = factor_one;
   tmp->factor_b = factor_two;
   *p = tmp;
   return 0;
}

product_t *get_palindrome_product(int from, int to)
{
   product_t *result = malloc(sizeof(product_t));
   if (result == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   result->error[MAXERR - 1] = '\0';
   result->smallest = INT_MAX;
   result->largest = INT_MIN;
   result->factors_lg = NULL;
   result->factors_sm = NULL;

   if (from > to) {
      snprintf(result->error, MAXERR - 1,
               "invalid input: min is %i and max is %i", from, to);
      return result;
   }

   int i, k, n;
   int err = 0;
   for (i = from; i <= to; i++)
      for (k = i; k <= to; k++)
         if (palindrome(n = i * k)) {
            if (n <= result->smallest) {
               result->smallest = n;
               err = addfactors(&result->factors_sm, i, k);
            } else if (n >= result->largest) {
               result->largest = n;
               err = addfactors(&result->factors_lg, i, k);
            }
            if (err) {
               free(result);
               return NULL;
            }
         }

   if ((result->smallest == INT_MAX) || (result->largest == INT_MIN)) {
      snprintf(result->error, MAXERR - 1,
               "no palindrome with factors in the range %i to %i", from, to);
      return result;
   }
   return result;
}

void free_product(product_t * p)
{
   if (p == NULL)
      return;
   free_ll(p->factors_lg);
   free_ll(p->factors_sm);
   free(p);
}
