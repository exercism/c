#include "vendor/unity.h"
#include "../src/list_ops.h"

struct list_item **list = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_lists_match(list_item_t ** expected, list_item_t ** actual)
{
   // expects inputs to be valid lists
   while (1) {
      bool expected_empty = is_list_empty(expected);
      bool actual_empty = is_list_empty(actual);
      TEST_ASSERT_EQUAL_MESSAGE(expected_empty, actual_empty,
                                "List lengths differ");
      if (expected_empty)
         break;

      list_data_t expected_item = shift(expected);
      list_data_t actual_item = shift(actual);
      TEST_ASSERT_EQUAL_MESSAGE(expected_item, actual_item,
                                "List contents differ");
   }
}

static list_item_t *filter_modulo(list_item_t * item)
{
   return (item && item->data % 2 == 1) ? item : NULL;
}

static list_data_t map_increment(list_data_t data)
{
   return data + 1;
}

static list_data_t fold_multiply(list_data_t data, list_data_t initial)
{
   return data * initial;
}

static list_data_t fold_add(list_data_t data, list_data_t initial)
{
   return data + initial;
}

static list_data_t fold_divide(list_data_t data, list_data_t initial)
{
   return (initial == 0) ? 0 : data / initial;
}

static void test_append_empty_lists(void)
{
   list_item_t **list1 = new_list();
   list_item_t **list2 = new_list();
   list_item_t **expected = new_list();

   TEST_ASSERT_TRUE(append_list(list1, list2));
   check_lists_match(expected, list1);

   delete_list(list1);
   delete_list(list2);
   delete_list(expected);
}

static void test_append_list_to_empty_list(void)
{
   TEST_IGNORE();               // delete this line to run test
   list_item_t **list1 = new_list();
   list_item_t **list2 = new_list();
   push(list2, 1);
   push(list2, 3);
   push(list2, 4);
   list_item_t **expected = new_list();
   push(expected, 1);
   push(expected, 3);
   push(expected, 4);

   TEST_ASSERT_TRUE(append_list(list1, list2));
   check_lists_match(expected, list1);

   delete_list(list1);
   delete_list(list2);
   delete_list(expected);
}

static void test_append_empty_list_to_list(void)
{
   TEST_IGNORE();
   list_item_t **list1 = new_list();
   push(list1, 1);
   push(list1, 2);
   push(list1, 3);
   push(list1, 4);
   list_item_t **list2 = new_list();
   list_item_t **expected = new_list();
   push(expected, 1);
   push(expected, 2);
   push(expected, 3);
   push(expected, 4);

   TEST_ASSERT_TRUE(append_list(list1, list2));
   check_lists_match(expected, list1);

   delete_list(list1);
   delete_list(list2);
   delete_list(expected);
}

static void test_append_non_empty_lists(void)
{
   TEST_IGNORE();
   list_item_t **list1 = new_list();
   push(list1, 1);
   push(list1, 2);
   list_item_t **list2 = new_list();
   push(list2, 2);
   push(list2, 3);
   push(list2, 4);
   push(list2, 5);
   list_item_t **expected = new_list();
   push(expected, 1);
   push(expected, 2);
   push(expected, 2);
   push(expected, 3);
   push(expected, 4);
   push(expected, 5);

   TEST_ASSERT_TRUE(append_list(list1, list2));
   check_lists_match(expected, list1);

   delete_list(list1);
   delete_list(list2);
   delete_list(expected);
}

static void test_filter_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   list_item_t **expected = new_list();
   list_item_t **actual = NULL;

   actual = filter_list(list, filter_modulo);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

static void test_filter_non_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 2);
   push(list, 3);
   push(list, 5);
   list_item_t **expected = new_list();
   push(expected, 1);
   push(expected, 3);
   push(expected, 5);
   list_item_t **actual = NULL;

   actual = filter_list(list, filter_modulo);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

static void test_length_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   size_t expected = 0;
   size_t actual = length_list(list);
   TEST_ASSERT_EQUAL(expected, actual);
   delete_list(list);
}

static void test_length_non_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 2);
   push(list, 3);
   push(list, 4);
   size_t expected = 4;

   size_t actual = length_list(list);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_map_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   list_item_t **expected = new_list();

   list_item_t **actual = map_list(list, map_increment);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

static void test_map_non_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 3);
   push(list, 5);
   push(list, 7);
   list_item_t **expected = new_list();
   push(expected, 2);
   push(expected, 4);
   push(expected, 6);
   push(expected, 8);

   list_item_t **actual = map_list(list, map_increment);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

static void test_foldl_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   list_data_t initial = 2;
   list_data_t expected = 2;

   list_data_t actual = foldl_list(list, initial, fold_multiply);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_foldl_direction_independent(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 2);
   push(list, 3);
   push(list, 4);
   list_data_t initial = 5;
   list_data_t expected = 15;

   list_data_t actual = foldl_list(list, initial, fold_add);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_foldl_direction_dependent(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 2);
   push(list, 5);
   list_data_t initial = 5;
   list_data_t expected = 0;

   list_data_t actual = foldl_list(list, initial, fold_divide);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_foldr_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   list_data_t initial = 2;
   list_data_t expected = 2;

   list_data_t actual = foldr_list(list, initial, fold_multiply);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_foldr_direction_independent(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 2);
   push(list, 3);
   push(list, 4);
   list_data_t initial = 5;
   list_data_t expected = 15;

   list_data_t actual = foldr_list(list, initial, fold_add);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_foldr_direction_dependent(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 2);
   push(list, 5);
   list_data_t initial = 5;
   list_data_t expected = 2;

   list_data_t actual = foldr_list(list, initial, fold_divide);
   TEST_ASSERT_EQUAL(expected, actual);

   delete_list(list);
}

static void test_reverse_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   list_item_t **expected = new_list();

   list_item_t **actual = reverse_list(list);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

static void test_reverse_non_empty_list(void)
{
   TEST_IGNORE();
   list_item_t **list = new_list();
   push(list, 1);
   push(list, 3);
   push(list, 5);
   push(list, 7);
   list_item_t **expected = new_list();
   push(expected, 7);
   push(expected, 5);
   push(expected, 3);
   push(expected, 1);

   list_item_t **actual = reverse_list(list);
   check_lists_match(expected, actual);

   delete_list(list);
   delete_list(expected);
   delete_list(actual);
}

int main(void)
{
   UnityBegin("test/test_list_ops.c");

   RUN_TEST(test_append_empty_lists);
   RUN_TEST(test_append_list_to_empty_list);
   RUN_TEST(test_append_empty_list_to_list);
   RUN_TEST(test_append_non_empty_lists);
   RUN_TEST(test_filter_empty_list);
   RUN_TEST(test_filter_non_empty_list);
   RUN_TEST(test_length_empty_list);
   RUN_TEST(test_length_non_empty_list);
   RUN_TEST(test_map_empty_list);
   RUN_TEST(test_map_non_empty_list);
   RUN_TEST(test_foldl_empty_list);
   RUN_TEST(test_foldl_direction_independent);
   RUN_TEST(test_foldl_direction_dependent);
   RUN_TEST(test_foldr_empty_list);
   RUN_TEST(test_foldr_direction_independent);
   RUN_TEST(test_foldr_direction_dependent);
   RUN_TEST(test_reverse_empty_list);
   RUN_TEST(test_reverse_non_empty_list);

   return UnityEnd();
}
