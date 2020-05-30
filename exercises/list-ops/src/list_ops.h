#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int list_value_t;

typedef struct {
   size_t length;
   list_value_t values[];
} list_t;

// constructs a new list
list_t *new_list(size_t length, list_value_t values[]);

// append entries to a list and return the new list
list_t *append_list(list_t * list1, list_t * list2);

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t * list, bool(*filter) (list_value_t value));

// returns the length of the list
size_t length_list(list_t * list);

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t * list, list_value_t(*map) (list_value_t value));

// folds (reduces) the given list from the left with a function
list_value_t foldl_list(list_t * list, list_value_t initial,
                        list_value_t(*foldl) (list_value_t value,
                                              list_value_t initial));

// folds (reduces) the given list from the right with a function
list_value_t foldr_list(list_t * list, list_value_t initial,
                        list_value_t(*foldr) (list_value_t value,
                                              list_value_t initial));

// reverse the elements of the list
list_t *reverse_list(list_t * list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t * list);

#endif
