#include "simple_linked_list.h"

/*
Initialize new node
*/ 
    node * new_node(int data) 
{
   node * startp = (node *) malloc(sizeof(node));
   if (startp == NULL) {
      printf("error in making new node");
      return NULL;
   }
   startp->data = data;
   startp->next = NULL;
   return startp;
}

 
/*
Find node by key (-1 otherwise)
*/ 
int find_node(node * startp, int key) 
{
   int result = -1;
   while (startp != NULL) {
      if (startp->data == key)
         return startp->data;
      startp = startp->next;
   }
   return result;
}

 
/*
Insert data at the front of the list
*/ 
void insert_beg(node ** startp, int data_new) 
{
   node * temp = new_node(data_new);
   temp->next = *startp;
   *startp = temp;
}  

/*
Display contents of linked list
*/ 
void display_forward(node * start) 
{
   printf("Linked List Contents: \n");
   while (start) {
      printf("%d \n", start->data);
      start = start->next;
   }
}

 
/*
Delete first occurence of key in linked list
*/ 
void delete_node(node ** startp, int key) 
{
   node * temp = *startp;
   node * prev = NULL;
   if (temp != NULL && temp->data == key) {
      *startp = temp->next;
      free(temp);
      return;
   }
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL)
      return;
   prev->next = temp->next;
   free(temp);
}

 
/*
Reverse contents of linked list
*/ 
void reverse(node ** startp) 
{
   node * prev = NULL;
   node * curr = *startp;
   node * next = NULL;
   while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   *startp = prev;
}

 
/*
Convert array to linked list
*/ 
    node * array_to_list(int list_array[], int array_size) 
{
   int i;
   node * startp = NULL;
   for (i = 0; i < array_size; i++) {
      insert_beg(&startp, list_array[i]);
   }
   return startp;
}

 
/*
Convert linked list to array
*/ 
int *list_to_array(node * startp, int array_size) 
{
   int i = 0;
   int *list_array = malloc(sizeof(int) * array_size);
   while (startp != NULL) {
      list_array[i] = startp->data;
      startp = startp->next;
      i++;
   }
   return list_array;
}

 
