#include "../src/linked_list.h"
#include <stdbool.h>
#include <stddef.h>
#include "vendor/unity.h"

struct list *list = NULL;

void setUp(void)
{
   list = list_create();
}

void tearDown(void)
{
   if (list != NULL) {
      list_destroy(list);
      list = NULL;
   }
}

static void test_list_create(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_NOT_NULL(list);
}

static void test_list_is_empty_returns_true_when_empty(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(list_is_empty(list));
}

static void test_list_is_empty_returns_false_when_not_empty(void)
{
   TEST_IGNORE();
   // pre-populate list
   ll_data_t data = 12;
   list_push(list, data);
   TEST_ASSERT_FALSE(list_is_empty(list));
}

static void test_list_push_with_multiple_items(void)
{
   TEST_IGNORE();
   for (ll_data_t data = 14; data < 19; ++data) {
      TEST_ASSERT_NOT_NULL(list_push(list, data));
   }
}

static void test_list_pop_returns_data_in_correct_order(void)
{
   TEST_IGNORE();
   // pre-populate list
   for (ll_data_t data = 11; data <= 15; ++data) {
      list_push(list, data);
   }

   for (ll_data_t data = 15; data >= 11; --data) {
      TEST_ASSERT_EQUAL(data, list_pop(list));
   }
}

static void test_list_unshift_with_multiple_items(void)
{
   TEST_IGNORE();
   for (ll_data_t data = 14; data < 19; ++data) {
      TEST_ASSERT_NOT_NULL(list_unshift(list, data));
   }
}

static void test_list_shift_returns_data_in_correct_order(void)
{
   TEST_IGNORE();
   // pre-populate list
   for (ll_data_t data = 12; data < 17; ++data) {
      list_unshift(list, data);
   }

   for (ll_data_t data = 17; data < 12; --data) {
      TEST_ASSERT_EQUAL(data, list_shift(list));
   }
}

static void test_pushed_data_can_be_shifted_in_original_order(void)
{
   TEST_IGNORE();
   for (ll_data_t data = 16; data < 21; ++data) {
      list_push(list, data);
   }
   for (ll_data_t data = 16; data < 21; ++data) {
      TEST_ASSERT_EQUAL(data, list_shift(list));
   }
   TEST_ASSERT_TRUE(list_is_empty(list));
}

static void test_unshifted_data_can_be_popped_in_original_order(void)
{
   TEST_IGNORE();
   for (ll_data_t data = 16; data < 21; ++data) {
      list_unshift(list, data);
   }
   for (ll_data_t data = 16; data < 21; ++data) {
      TEST_ASSERT_EQUAL(data, list_pop(list));
   }
   TEST_ASSERT_TRUE(list_is_empty(list));
}

int main(void)
{
   UnityBegin("test/test_linked_list.c");

   RUN_TEST(test_list_create);
   RUN_TEST(test_list_is_empty_returns_true_when_empty);
   RUN_TEST(test_list_is_empty_returns_false_when_not_empty);
   RUN_TEST(test_list_push_with_multiple_items);
   RUN_TEST(test_list_pop_returns_data_in_correct_order);
   RUN_TEST(test_list_unshift_with_multiple_items);
   RUN_TEST(test_list_shift_returns_data_in_correct_order);
   RUN_TEST(test_pushed_data_can_be_shifted_in_original_order);
   RUN_TEST(test_pushed_data_can_be_shifted_in_original_order);
   RUN_TEST(test_unshifted_data_can_be_popped_in_original_order);

   return UnityEnd();
}
