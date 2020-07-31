#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef int ll_data_t;
struct list_node
{
    struct list_node *prev, *next;
    ll_data_t data;
};
struct list
{
    struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void);

// checks if the list is empty
bool list_is_empty(const struct list *list);

// inserts item at back of list
struct list_node *list_push(struct list *list, ll_data_t item_data);

// removes item from back of list
ll_data_t list_pop(struct list *list);

// inserts item at front of list
struct list_node *list_unshift(struct list *list, ll_data_t item_data);

// removes item from front of list
ll_data_t list_shift(struct list *list);

// destroys the entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list);

#endif
