# Introduction

There are several ways to solve Linked List.
One approach is to implement a circular doubly-linked list.

## General guidance

At the time of writing the tests don't cover certain error conditions, so some error handling that would be used in production
won't necessarily be used here.

As the instructions say:
>To keep your implementation simple, the tests will not cover error conditions.
>Specifically: `pop` or `shift` will never be called on an empty list.

## Approach: Circular Doubly-Linked List

**linked_list.h**

```c
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef int ll_data_t;
typedef struct list list_t;
typedef struct list_node node_t;

// constructs a new (empty) list
struct list *list_create(void);

// counts the items on a list
size_t list_count(const struct list *list);

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data);

// removes item from back of a list
ll_data_t list_pop(struct list *list);

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(struct list *list);

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list);

#endif
```

**linked_list.c**

```c
#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *head, *tail;
   size_t length;
};

struct list *list_create(void)
{
   list_t *new_list = malloc(sizeof(list_t));
   if (!new_list)
      return NULL;
   new_list->head = NULL;
   new_list->tail = NULL;
   new_list->length = 0;
   return new_list;
}

size_t list_count(const struct list *list)
{
   return list->length;
}

static node_t *create_node(ll_data_t data, struct list *list)
{
   node_t *new_node = (node_t *)malloc(sizeof(node_t));
   if (!new_node)
      return NULL;
   new_node->data = data;
   if (list->head != NULL) {
      new_node->prev = list->tail;
      new_node->next = list->head;
      list->tail->next = new_node;
      list->head->prev = new_node;
   } else {
      new_node->prev = new_node;
      new_node->next = new_node;
      list->head = new_node;
      list->tail = new_node;
   }
   list->length++;
   return new_node;
}

static ll_data_t destroy_node(node_t *node, struct list *list)
{
   ll_data_t data = node->data;
   node->prev->next = node->next;
   node->next->prev = node->prev;
   if (node == list->head)
      list->head = node->next;
   if (node == list->tail)
      list->tail = node->prev;
   node->prev = NULL;
   node->next = NULL;
   free(node);
   node = NULL;
   list->length--;
   if (list->length == 0) {
      list->head = NULL;
      list->tail = NULL;
   }
   return data;
}

void list_push(struct list *list, ll_data_t item_data)
{
   list->tail = create_node(item_data, list);
}

ll_data_t list_pop(struct list *list)
{
   return destroy_node(list->tail, list);
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   list->head = create_node(item_data, list);
}

ll_data_t list_shift(struct list *list)
{
   return destroy_node(list->head, list);
}

void list_delete(struct list *list, ll_data_t data)
{
   node_t *node = list->head;
   while (node) {
      if (node->data == data) {
         destroy_node(node, list);
         break;
      }
      if (node->next == list->head)
         break;
      node = node->next;
   }
}

void list_destroy(struct list *list)
{
   node_t *node = list->head;
   while (node) {
      node_t *next_node = node->next;
      destroy_node(node, list);
      if (node == next_node)
         break;
      node = next_node;
   }
   free(list);
   list = NULL;
}
```

For more information, check the [Circular Doubly-Linked List approach][approach-circular-doubly-linked-list].

[approach-circular-doubly-linked-list]: https://exercism.org/tracks/c/exercises/armstrong-numbers/approaches/circular-doubly-linked-list
[circular-doubly-linked-list]: https://www.sanfoundry.com/c-program-circular-doubly-linked-list/
