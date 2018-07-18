#include <stddef.h>
#include <stdbool.h>
#include "vendor/unity.h"
#include "../src/linked_list.h"

struct list_item **list = NULL;

void setUp(void)
{
   list = new_list();
}

void tearDown(void)
{
   if (list != NULL) {
      delete_list(list);
      list = NULL;
   }
}

void test_new_list(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_NOT_NULL(list);
}

void test_is_list_empty_when_empty(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(is_list_empty(list));
   delete_list(list);
   list = NULL;                 // stop list from dangling
   TEST_ASSERT_TRUE(is_list_empty(list));
}

void test_is_list_empty_when_not_empty(void)
{
   TEST_IGNORE();
   // pre-populate list
   ll_data_t data = 12;
   push(list, data);
   TEST_ASSERT_FALSE(is_list_empty(list));
}

void test_push_with_invalid_list(void)
{
   TEST_IGNORE();
   ll_data_t data = 13;
   TEST_ASSERT_FALSE(push(NULL, data));
}

void test_push_with_valid_list(void)
{
   TEST_IGNORE();
   for (size_t data = 14; data < 19; ++data) {
      TEST_ASSERT_TRUE(push(list, data));
   }
}

void test_pop_returns_list_data(void)
{
   TEST_IGNORE();
   // pre-populate list
   for (size_t data = 11; data <= 15; ++data) {
      push(list, data);
   }
   for (size_t data = 15; data >= 11; --data) {
      TEST_ASSERT_EQUAL(data, pop(list));
   }
}

void test_unshift_with_invalid_list(void)
{
   TEST_IGNORE();
   ll_data_t data = 16;
   TEST_ASSERT_FALSE(unshift(NULL, data));
}

void test_unshift_with_valid_list(void)
{
   TEST_IGNORE();
   for (size_t data = 14; data < 19; ++data) {
      TEST_ASSERT_TRUE(unshift(list, data));
   }
}

void test_shift_returns_list_data(void)
{
   TEST_IGNORE();
   // pre-populate list
   for (size_t data = 12; data < 17; ++data) {
      push(list, data);
   }

   for (size_t data = 12; data < 17; ++data) {
      TEST_ASSERT_EQUAL(data, shift(list));
   }
}

int main(void)
{
   UnityBegin("test/test_leap.c");

   RUN_TEST(test_new_list);
   RUN_TEST(test_is_list_empty_when_empty);
   RUN_TEST(test_is_list_empty_when_not_empty);
   RUN_TEST(test_push_with_invalid_list);
   RUN_TEST(test_push_with_valid_list);
   RUN_TEST(test_pop_returns_list_data);
   RUN_TEST(test_unshift_with_invalid_list);
   RUN_TEST(test_unshift_with_valid_list);
   RUN_TEST(test_shift_returns_list_data);

   UnityEnd();
   return 0;
}
