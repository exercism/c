#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef int ll_data_t;

struct list_item;

// constructs a new list of items
struct list_item **new_list(void);

// checks if the list is empty
bool is_list_empty(struct list_item **list);

// inserts item at back of list
bool push(struct list_item **list, ll_data_t item_data);

// removes item from back of list
ll_data_t pop(struct list_item **list);

// removes item from front of list
ll_data_t shift(struct list_item **list);

// inserts item at front of list
bool unshift(struct list_item **list, ll_data_t item_data);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(struct list_item **list);

#endif
