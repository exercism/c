#include <stddef.h>
#include "test-framework/unity.h"
#include "linked_list.h"

struct list *list = NULL;

void setUp(void)
{
   list = list_create();
}

void tearDown(void)
{
   if (list) {
      list_destroy(list);
      list = NULL;
   }
}

static void test_pop_gets_element_from_the_list(void)
{
   list_push(list, 7);
   TEST_ASSERT_EQUAL(7, list_pop(list));
}

static void test_push_pop_respectively_add_remove_at_the_end_of_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push(list, 11);
   list_push(list, 13);
   TEST_ASSERT_EQUAL(13, list_pop(list));
   TEST_ASSERT_EQUAL(11, list_pop(list));
}

static void test_shift_gets_an_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push(list, 17);
   TEST_ASSERT_EQUAL(17, list_shift(list));
}

static void test_shift_gets_first_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push(list, 23);
   list_push(list, 5);
   TEST_ASSERT_EQUAL(23, list_shift(list));
   TEST_ASSERT_EQUAL(5, list_shift(list));
}

static void test_unshift_adds_element_at_start_of_the_list(void)
{
   TEST_IGNORE();
   list_unshift(list, 23);
   list_unshift(list, 5);
   TEST_ASSERT_EQUAL(5, list_shift(list));
   TEST_ASSERT_EQUAL(23, list_shift(list));
}

static void test_pop_push_shift_and_unshift_can_be_used_in_any_order(void)
{
   TEST_IGNORE();
   list_push(list, 1);
   list_push(list, 2);
   TEST_ASSERT_EQUAL(2, list_pop(list));
   list_push(list, 3);
   TEST_ASSERT_EQUAL(1, list_shift(list));
   list_unshift(list, 4);
   list_push(list, 5);
   TEST_ASSERT_EQUAL(4, list_shift(list));
   TEST_ASSERT_EQUAL(5, list_pop(list));
   TEST_ASSERT_EQUAL(3, list_shift(list));
}

static void test_count_an_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void test_count_a_list_with_items(void)
{
   TEST_IGNORE();
   list_push(list, 37);
   list_push(list, 1);
   TEST_ASSERT_EQUAL(2, list_count(list));
}

static void test_count_is_correct_after_mutation(void)
{
   TEST_IGNORE();
   list_push(list, 31);
   TEST_ASSERT_EQUAL(1, list_count(list));
   list_unshift(list, 43);
   TEST_ASSERT_EQUAL(2, list_count(list));
   list_shift(list);
   TEST_ASSERT_EQUAL(1, list_count(list));
   list_pop(list);
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void test_popping_to_empty_does_not_break_the_list(void)
{
   TEST_IGNORE();
   list_push(list, 41);
   list_push(list, 59);
   list_pop(list);
   list_pop(list);
   list_push(list, 47);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(47, list_pop(list));
}

static void test_shifting_to_empty_does_not_break_the_list(void)
{
   TEST_IGNORE();
   list_push(list, 41);
   list_push(list, 59);
   list_shift(list);
   list_shift(list);
   list_push(list, 47);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(47, list_shift(list));
}

static void test_deletes_the_only_element(void)
{
   TEST_IGNORE();
   list_push(list, 61);
   list_delete(list, 61);
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list(void)
{
   TEST_IGNORE();
   list_push(list, 71);
   list_push(list, 83);
   list_push(list, 79);
   list_delete(list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(79, list_pop(list));
   TEST_ASSERT_EQUAL(71, list_shift(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_tail(
    void)
{
   TEST_IGNORE();
   list_push(list, 71);
   list_push(list, 83);
   list_push(list, 79);
   list_delete(list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(79, list_pop(list));
   TEST_ASSERT_EQUAL(71, list_pop(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_head(
    void)
{
   TEST_IGNORE();
   list_push(list, 71);
   list_push(list, 83);
   list_push(list, 79);
   list_delete(list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(71, list_shift(list));
   TEST_ASSERT_EQUAL(79, list_shift(list));
}

static void test_deletes_the_first_of_two_elements(void)
{
   TEST_IGNORE();
   list_push(list, 97);
   list_push(list, 101);
   list_delete(list, 97);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(101, list_pop(list));
}

static void test_deletes_the_second_of_two_elements(void)
{
   TEST_IGNORE();
   list_push(list, 97);
   list_push(list, 101);
   list_delete(list, 101);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(97, list_pop(list));
}

static void
test_delete_does_not_modify_the_list_if_the_element_is_not_found(void)
{
   TEST_IGNORE();
   list_push(list, 89);
   list_delete(list, 103);
   TEST_ASSERT_EQUAL(1, list_count(list));
}

static void test_deletes_only_the_first_occurrence(void)
{
   TEST_IGNORE();
   list_push(list, 73);
   list_push(list, 9);
   list_push(list, 9);
   list_push(list, 107);
   list_delete(list, 9);
   TEST_ASSERT_EQUAL(3, list_count(list));
   TEST_ASSERT_EQUAL(107, list_pop(list));
   TEST_ASSERT_EQUAL(9, list_pop(list));
   TEST_ASSERT_EQUAL(73, list_pop(list));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_pop_gets_element_from_the_list);
   RUN_TEST(test_push_pop_respectively_add_remove_at_the_end_of_the_list);
   RUN_TEST(test_shift_gets_an_element_from_the_list);
   RUN_TEST(test_shift_gets_first_element_from_the_list);
   RUN_TEST(test_unshift_adds_element_at_start_of_the_list);
   RUN_TEST(test_pop_push_shift_and_unshift_can_be_used_in_any_order);
   RUN_TEST(test_count_an_empty_list);
   RUN_TEST(test_count_a_list_with_items);
   RUN_TEST(test_count_is_correct_after_mutation);
   RUN_TEST(test_popping_to_empty_does_not_break_the_list);
   RUN_TEST(test_shifting_to_empty_does_not_break_the_list);
   RUN_TEST(test_deletes_the_only_element);
   RUN_TEST(test_deletes_the_element_with_the_specified_value_from_the_list);
   RUN_TEST(
       test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_tail);
   RUN_TEST(
       test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_head);
   RUN_TEST(test_deletes_the_first_of_two_elements);
   RUN_TEST(test_deletes_the_second_of_two_elements);
   RUN_TEST(test_delete_does_not_modify_the_list_if_the_element_is_not_found);
   RUN_TEST(test_deletes_only_the_first_occurrence);

   return UNITY_END();
}
