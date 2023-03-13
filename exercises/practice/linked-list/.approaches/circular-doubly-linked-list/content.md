# Circular Doubly-Linked List

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

There are several ways of implementing a [circular doubly-linked list][circular-doubly-linked-list].
This approach adds a `length` field which is initialized to `0` on list creation and updated as nodes are added and removed.

A circular doubly-linked list populated with at least one node does not have `NULL` values for any node's `prev` or `next` fields.

- If there is only one node in the list, its `prev` and `next` fields will point to itself.
- If there are two nodes in a list, node `A` will point to node `B` for both its `prev` and `next` fields.
Likewise, node `B` will point to node `A` for both its `prev` and `next` fields.
- If there are three nodes in a list, node `A`'s `prev` will point at node `C` and node `A`'s `next` will point at node `B`.
Node `B`'s `prev` will point at node `A` and node `B`'s `next` will point at node `C`.
Node `C`'s `prev` will point at node `B` and node `C`'s `next` will point at node `A`.

The only item the list's `head` and `tail` will be `NULL` is when the list is empty.
This is enforced by the `list_create` function.

The `list_count` function returns the value of the lists's `length` field.

The `create_node` function is a helper function to handle adding a node.
Whether the node is added to the back or the front of the list, the new node is always placed between the `tail` and the `end` of the list,
so the same implementation for creating the node is used for adding to either the front or back.

If it is thought that the most usual case is that the list already has one node, then the condition can be tested that the `head` is not `NULL`.
If so, then the new node is "wired up" to have its `prev` be the `tail` and its `next` be the head.
Also, the `tail`'s `next` will be the new node and the `head`'s `prev` will be the new node.

If the `head` is `NULL`, then the new node will be the only node in the list, so its `prev` and `next` fields will point at itself,
and it will be both the `head` and `tail` of the list.

The `length` of the list is incremented for the new node, and the new node is returned from the `create_node` function.

The `destroy_node` function is a helper function to handle removing a node.
Whether the node is removed from the back or front of the list, or from somewhere else, the same implementation for removing the node is used.

The removed node's data is saved to be returned at the end of the function.

The removed node's `next` field is assigned to the `next` field of the node before the removed node,
so the node before the removed node now has a `next` pointing at the node after the removed node.

The removed node's `prev` field is assigned to the `prev` field of the node after the removed node,
so the node after the removed node now has a `prev` pointing at the node before the removed node.

```c
node->prev->next = node->next;
node->next->prev = node->prev;
if (node == list->head)
   list->head = node->next;
if (node == list->tail)
   list->tail = node->prev;
```

If the node being removed is either the `head` or the `tail`, then the `head` or `tail` is adjusted accordingly.
If the removed node is both the `head` and `tail`, then the removed node is the last node left, and the `head` and `tail`
are set to `NULL`.

[circular-doubly-linked-list]: https://www.sanfoundry.com/c-program-circular-doubly-linked-list/
