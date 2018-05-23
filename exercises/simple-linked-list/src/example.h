#ifndef SIMPLE_LINKED_LIST
#define SIMPLE_LINKED_LIST
#include <stdio.h>
#include <stdlib.h>
 typedef struct node node;
 struct node {
   node * next;
   int data;
};
 node * new_node(int data);
int find_node(node * startp, int key);
void insert_beg(node ** startp, int data_new);
void display_forward(node * startp);
void delete_node(node ** startp, int key);
void reverse(node ** startp);
int *list_to_array(node * startp, int array_size);
node * array_to_list(int list_array[], int array_size);
 
#endif
