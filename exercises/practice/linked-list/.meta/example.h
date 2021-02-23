#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef int ll_data_t;
struct list;

// constructs a new (empty) list
struct list *list_create(void);

// counts the items on a list
size_t list_count(const struct list *list);

// inserts item at back of a list
bool list_push(struct list *list, ll_data_t item_data);

// removes item from back of a list
ll_data_t list_pop(struct list *list);

// inserts item at front of a list
bool list_unshift(struct list *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(struct list *list);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list);

#endif
