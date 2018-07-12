#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef int ll_data_t;

struct list_item;

// constructs new item holding specified data
struct list_item *new(ll_data_t);

// retrieves data from item
ll_data_t item_data(struct list_item *item);

// inserts item at back of list
bool push(struct list_item *item);

// removes item from back of list
struct list_item *pop(void);

// removes item from front of list
struct list_item *shift(void);

// inserts item at front of list
bool unshift(struct list_item *item);

// destroy a single item
bool delete_item(struct list_item **item);

// destroy the entire list
bool delete_list(void);

#endif
