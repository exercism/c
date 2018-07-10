#include <stddef.h>
#include <stdbool.h>
#include "vendor/unity.h"
#include "../src/linked_list.h"

void setUp(void)
{
}

void tearDown(void)
{
   delete_list();
}

void test_new(void)
{
   TEST_IGNORE();               // delete this line to run test
   ll_data_t data = 10;
   struct list_item *item = new(data);
   TEST_ASSERT_NOT_NULL(item);
   delete_item(&item);
}

void test_delete_item_with_invalid_item(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(delete_item(NULL));
}

void test_delete_item_with_valid_item(void)
{
   TEST_IGNORE();
   ll_data_t data = 11;
   struct list_item *item = new(data);
   TEST_ASSERT_TRUE(delete_item(&item));
   TEST_ASSERT_NULL(item);
}

void test_delete_list(void)
{
   TEST_IGNORE();
   // pre-populate list
   push(new(12));

   TEST_ASSERT_TRUE(delete_list());
   TEST_ASSERT_NULL(pop());
}

void test_item_data_returns_correct_data(void)
{
   TEST_IGNORE();
   ll_data_t data = 13;
   struct list_item *item = new(data);
   TEST_ASSERT_EQUAL(data, item_data(item));
   delete_item(&item);
}

void test_push_with_invalid_item(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(push(NULL));
}

void test_push_with_valid_items(void)
{
   TEST_IGNORE();
   for (size_t i = 14; i < 19; ++i) {
      struct list_item *item = new(i);
      TEST_ASSERT_TRUE(push(item));
   }
}

void test_pop_with_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_NULL(pop());
}

void test_pop_with_populated_list(void)
{
   TEST_IGNORE();
   // pre-populate list
   for (size_t i = 11; i < 16; ++i) {
      push(new(i));
   }
   for (size_t i = 15; i > 10; --i) {
      struct list_item *item = pop();
      TEST_ASSERT_NOT_NULL(item);
      TEST_ASSERT_EQUAL(i, item_data(item));
      delete_item(&item);
   }
}

void test_unshift_with_invalid_item(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(unshift(NULL));
}

void test_unshift_with_valid_items(void)
{
   TEST_IGNORE();
   for (size_t i = 14; i < 19; ++i) {
      struct list_item *item = new(i);
      TEST_ASSERT_TRUE(unshift(item));
   }
}

void test_shift_with_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_FALSE(shift());
}

void test_shift_with_populated_list(void)
{
   TEST_IGNORE()
       // pre=populate list
       for (size_t i = 12; i < 17; ++i) {
      push(new(i));
   }

   for (size_t i = 12; i < 17; ++i) {
      struct list_item *item = shift();
      TEST_ASSERT_NOT_NULL(item);
      TEST_ASSERT_EQUAL(i, item_data(item));
      delete_item(&item);
   }
}

int main(void)
{
   UnityBegin("test/test_leap.c");

   RUN_TEST(test_new);
   RUN_TEST(test_delete_item_with_invalid_item);
   RUN_TEST(test_delete_item_with_valid_item);
   RUN_TEST(test_delete_list);
   RUN_TEST(test_item_data_returns_correct_data);
   RUN_TEST(test_push_with_invalid_item);
   RUN_TEST(test_push_with_valid_items);
   RUN_TEST(test_pop_with_empty_list);
   RUN_TEST(test_pop_with_populated_list);
   RUN_TEST(test_unshift_with_invalid_item);
   RUN_TEST(test_unshift_with_valid_items);
   RUN_TEST(test_shift_with_empty_list);
   RUN_TEST(test_shift_with_populated_list);

   UnityEnd();
   return 0;
}
