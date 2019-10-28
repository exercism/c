#ifndef LIST_OPS_H
#define LIST_OPS_H

#include <stdlib.h>
#include <stdbool.h>

typedef int list_data_t;

typedef struct list_item list_item_t;

// constructs a new list of items
struct list_item **new_list(void);

// constructs a new list item
list_item_t *new_list_item(list_data_t data);

// checks if the list is empty
bool is_list_empty(struct list_item **list);

// inserts item at back of list
bool push(list_item_t ** list, list_data_t item_data);

// removes item from front of list
list_data_t shift(struct list_item **list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(struct list_item **list);

// append entries to a list and return the new list
bool append_list(list_item_t ** list1, list_item_t ** list2);

// returns a new list whose items are those from the given list that satisfy
// the filter function
// filter should return NULL for items that are unsatisfactory
list_item_t **filter_list(list_item_t ** list,
                          list_item_t * (*filter) (list_data_t));

// returns the length of the given list
size_t length_list(list_item_t ** list);

// returns a new list whose items equal the given list values transformed by
// the mapping function
list_item_t **map_list(list_item_t ** list, list_data_t(*map) (list_data_t));

// folds (reduces) the given list from the left with a function
list_data_t foldl_list(list_item_t ** list, list_data_t initial,
                       list_data_t(*foldl) (list_data_t, list_data_t));

// folds (reduces) the given list from the right with a function
list_data_t foldr_list(list_item_t ** list, list_data_t initial,
                       list_data_t(*foldr) (list_data_t, list_data_t));

// return a new list whose items are the reverse order of the given list
list_item_t **reverse_list(list_item_t ** list);

#endif
