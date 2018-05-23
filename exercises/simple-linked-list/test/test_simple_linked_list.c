#include "vendor/unity.h"
#include "../src/simple_linked_list.h"
 void setUp(void) 
{
}  void tearDown(void) 
{
}  void free_list(node * startp) 
{
   if (startp == NULL) {
      return;
   }
   free_list(startp->next);
   free(startp);
}

 void test_node(void) 
{
   TEST_IGNORE();              // delete this line to run test
   node *startp = new_node(3);
    TEST_ASSERT_NOT_NULL(startp);
   TEST_ASSERT_EQUAL_INT(3, startp->data);
   TEST_ASSERT_NULL(startp->next);
    free_list(startp);
}  void test_inserts_at_beg(void) 
{
   TEST_IGNORE();
   node * np = new_node(0);
   insert_beg(&np, 1);
   insert_beg(&np, 2);
    TEST_ASSERT_EQUAL_INT(2, np->data);
   TEST_ASSERT_NOT_NULL(np->next);
   TEST_ASSERT_EQUAL_INT(1, np->next->data);
    free_list(np);
}  void test_delete_by_key(void) 
{
   TEST_IGNORE();
   node * ptr = new_node(10);
   insert_beg(&ptr, 20);
   insert_beg(&ptr, 30);
   delete_node(&ptr, 20);
    TEST_ASSERT_EQUAL_INT(-1, find_node(ptr, 20));
    free_list(ptr);
}  void test_reverse(void) 
{
   TEST_IGNORE();
   node * head = new_node(0);
   insert_beg(&head, 1);
   insert_beg(&head, 2);
   reverse(&head);
    TEST_ASSERT_EQUAL_INT(0, head->data);
   TEST_ASSERT_EQUAL_INT(1, head->next->data);
    free_list(head);
}  void test_array_to_list(void) 
{
   int list_of_nums[4] = { 1, 2, 3, 4 };
   node * ptr2 = array_to_list(list_of_nums, 4);
    TEST_ASSERT_EQUAL_INT(4, ptr2->data);
   TEST_ASSERT_EQUAL_INT(3, ptr2->next->data);
   TEST_ASSERT_EQUAL_INT(2, ptr2->next->next->data);
   TEST_ASSERT_EQUAL_INT(1, ptr2->next->next->next->data);
    free_list(ptr2);
}  void test_list_to_array(void) 
{
   node * ptrn = NULL;
   insert_beg(&ptrn, 0);
   insert_beg(&ptrn, 1);
   insert_beg(&ptrn, 2);
   insert_beg(&ptrn, 3);
   int *list_of_nums;
   list_of_nums = list_to_array(ptrn, 4);
    TEST_ASSERT_EQUAL_INT(3, list_of_nums[0]);
   TEST_ASSERT_EQUAL_INT(2, list_of_nums[1]);
   TEST_ASSERT_EQUAL_INT(1, list_of_nums[2]);
   TEST_ASSERT_EQUAL_INT(0, list_of_nums[3]);
    free(list_of_nums);
   free_list(ptrn);
}  int main(void) 
{
   UnityBegin("test/test_simple_linked_list.c");
    RUN_TEST(test_node);
   RUN_TEST(test_inserts_at_beg);
   RUN_TEST(test_delete_by_key);
   RUN_TEST(test_reverse);
   RUN_TEST(test_array_to_list);
   RUN_TEST(test_list_to_array);
    UNITY_END();
   return 0;
}

 
