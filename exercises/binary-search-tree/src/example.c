#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define CHUNK_SIZE 100
static bool mem_ok;
static int *parsed_tree;
static size_t parsed_len;

static void free_tree(node_t * head)
{
   if (head == NULL)
      return;
   free_tree(head->right);
   free_tree(head->left);
   free(head);
}

static node_t *add_node(node_t * head, int data)
{
   if (!mem_ok)
      return NULL;

   if (head == NULL) {
      head = malloc(sizeof(node_t));
      if (head == NULL) {
         fprintf(stderr, "Memory error!\n");
         mem_ok = false;
         return NULL;
      }
      head->data = data;
      head->left = NULL;
      head->right = NULL;

   } else if (head->data >= data) {
      head->left = add_node(head->left, data);

   } else if (head->data < data) {
      head->right = add_node(head->right, data);

   }
   return head;
}

static void parse_tree(node_t * head)
{
   if (head == NULL || !mem_ok)
      return;

   parsed_tree[parsed_len++] = head->data;
   if (parsed_len % CHUNK_SIZE == 0) {
      parsed_tree =
          realloc(parsed_tree, sizeof(int) * (parsed_len + CHUNK_SIZE));
      if (parsed_tree == NULL) {
         fprintf(stderr, "Memory error!\n");
         mem_ok = false;
         return;
      }
   }
   parse_tree(head->left);
   parse_tree(head->right);
}

static int compare(const void *a, const void *b)
{
   return *(int *)a - *(int *)b;
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
   if (tree_data == NULL || tree_data_len == 0)
      return NULL;

   node_t *head = NULL;
   mem_ok = true;
   for (size_t i = 0; i < tree_data_len; i++) {
      node_t *tmp = add_node(head, tree_data[i]);
      if (tmp == NULL) {
         free_tree(head);
         return NULL;
      }
      head = tmp;
   }

   return head;
}

int *sorted_data(node_t * head)
{
   if (head == NULL)
      return NULL;

   parsed_tree = malloc(sizeof(int) * CHUNK_SIZE);
   if (parsed_tree == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   mem_ok = true;
   parsed_len = 0;
   parse_tree(head);
   if (!mem_ok)
      return NULL;

   qsort(parsed_tree, parsed_len, sizeof(int), compare);

   return parsed_tree;
}
