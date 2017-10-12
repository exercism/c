#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

typedef struct {
   int smallest;
   int largest;
} product_t;

/* Return the smallest and largest palindrome products in the range of min and max */
product_t get_palindrome_product(int min, int max);

#endif
