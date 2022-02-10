#include <stdarg.h>
#include "list_ops.h"
#include "test-framework/unity.h"

static const int MAX_STRING_LEN = 100;
static list_t *list = NULL;
static list_t *list2 = NULL;
static list_t *actual = NULL;
static char *error_message = NULL;

void setUp(void)
{
}

static void release_lists(int count, ...)
{
   va_list ptr;
   va_start(ptr, count);
   for (int i = 0; i < count; ++i) {
      list_t **list = va_arg(ptr, list_t **);
      if (*list) {
         free(*list);
         *list = NULL;
      }
   }
   va_end(ptr);
}

void tearDown(void)
{
   release_lists(3, &list, &list2, &actual);
   if (error_message) {
      free(error_message);
      error_message = NULL;
   }
}

static char *print_elements(size_t length, list_element_t list_elements[])
{
   char *array = malloc(MAX_STRING_LEN * sizeof(char));
   char *ptr = array;
   for (size_t i = 0; i < length; i++) {
      int printed = snprintf(ptr, MAX_STRING_LEN - (ptr - array), " %d ",
                             (list_elements[i]));
      ptr += printed;
      if (ptr - array > MAX_STRING_LEN) {
         break;
      }
   }
   return array;
}

static char *create_error_message(size_t length,
                                  list_element_t expected_elements[],
                                  list_element_t actual_elements[])
{
   char *message = malloc(MAX_STRING_LEN * sizeof(char));
   char *expected_string = print_elements(length, expected_elements);
   char *actual_string = print_elements(length, actual_elements);
   snprintf(message, MAX_STRING_LEN, "[%s] != [%s]", expected_string,
            actual_string);
   free(expected_string);
   free(actual_string);
   return message;
}

static void check_lists_match(size_t expected_length,
                              list_element_t expected_elements[],
                              list_t *actual)
{
   // check actual list is a valid list
   TEST_ASSERT_NOT_NULL(actual);

   // check lengths match
   TEST_ASSERT_EQUAL_MESSAGE(expected_length, actual->length,
                             "List lengths differ");

   // check elements match in non-zero length list
   if (expected_length) {
      error_message = create_error_message(expected_length, expected_elements,
                                           actual->elements);
      TEST_ASSERT_EQUAL_MEMORY_ARRAY_MESSAGE(
          expected_elements, actual->elements, sizeof(list_element_t),
          expected_length, error_message);
      free(error_message);
      error_message = NULL;
   }
}

static bool filter_modulo(list_element_t element)
{
   return (element % 2 == 1);
}

static list_element_t map_increment(list_element_t element)
{
   return element + 1;
}

static list_element_t fold_multiply(list_element_t element,
                                    list_element_t accumulator)
{
   return element * accumulator;
}

static list_element_t fold_add(list_element_t element,
                               list_element_t accumulator)
{
   return element + accumulator;
}

static list_element_t fold_divide(list_element_t element,
                                  list_element_t accumulator)
{
   return (accumulator == 0) ? 0 : element / accumulator;
}

static void call_delete_list(list_t **list)
{
   delete_list(*list);
   *list = NULL;
}

static void test_append_empty_lists(void)
{
   list = new_list(0, NULL);
   list2 = new_list(0, NULL);

   actual = append_list(list, list2);
   check_lists_match(0, NULL, actual);

   call_delete_list(&list);
   call_delete_list(&list2);
   call_delete_list(&actual);
}

static void test_append_list_to_empty_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list = new_list(0, NULL);
   list2 = new_list(3, (list_element_t[]){ 1, 3, 4 });
   size_t expected_length = 3;
   list_element_t expected_elements[] = { 1, 3, 4 };

   actual = append_list(list, list2);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&list2);
   call_delete_list(&actual);
}

static void test_append_empty_list_to_list(void)
{
   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 2, 3, 4 });
   list2 = new_list(0, NULL);
   size_t expected_length = 4;
   list_element_t expected_elements[] = { 1, 2, 3, 4 };

   actual = append_list(list, list2);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&list2);
   call_delete_list(&actual);
}

static void test_append_non_empty_lists(void)
{
   TEST_IGNORE();
   list = new_list(2, (list_element_t[]){ 1, 2 });
   list2 = new_list(4, (list_element_t[]){ 2, 3, 4, 5 });
   size_t expected_length = 6;
   list_element_t expected_elements[] = { 1, 2, 2, 3, 4, 5 };

   actual = append_list(list, list2);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&list2);
   call_delete_list(&actual);
}

static void test_filter_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);

   actual = filter_list(list, filter_modulo);
   check_lists_match(0, NULL, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

static void test_filter_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(5, (list_element_t[]){ 1, 2, 3, 4, 5 });
   size_t expected_length = 3;
   list_element_t expected_elements[] = { 1, 3, 5 };

   actual = filter_list(list, filter_modulo);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

static void test_length_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);
   size_t expected = 0;

   size_t actual = length_list(list);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void test_length_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 2, 3, 4 });
   size_t expected = 4;

   size_t actual = length_list(list);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void test_map_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);

   actual = map_list(list, map_increment);
   check_lists_match(0, NULL, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

static void test_map_non_empty_list(void)
{

   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 3, 5, 7 });
   size_t expected_length = 4;
   list_element_t expected_elements[] = { 2, 4, 6, 8 };

   actual = map_list(list, map_increment);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

static void test_foldl_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);
   list_element_t initial = 2;
   list_element_t expected = 2;

   list_element_t actual = foldl_list(list, initial, fold_divide);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void
test_foldl_direction_independent_function_applied_to_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 2, 3, 4 });
   list_element_t initial = 5;
   list_element_t expected = 15;

   list_element_t actual = foldl_list(list, initial, fold_add);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void
test_foldl_direction_dependent_function_applied_to_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(2, (list_element_t[]){ 2, 5 });
   list_element_t initial = 5;
   list_element_t expected = 0;

   list_element_t actual = foldl_list(list, initial, fold_divide);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void test_foldr_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);
   list_element_t initial = 2;
   list_element_t expected = 2;

   list_element_t actual = foldr_list(list, initial, fold_multiply);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void
test_foldr_direction_independent_function_applied_to_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 2, 3, 4 });
   list_element_t initial = 5;
   list_element_t expected = 15;

   list_element_t actual = foldr_list(list, initial, fold_add);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void
test_foldr_direction_dependent_function_applied_to_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(2, (list_element_t[]){ 2, 5 });
   list_element_t initial = 5;
   list_element_t expected = 2;

   list_element_t actual = foldr_list(list, initial, fold_divide);
   TEST_ASSERT_EQUAL(expected, actual);

   call_delete_list(&list);
}

static void test_reverse_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(0, NULL);

   actual = reverse_list(list);
   check_lists_match(0, NULL, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

static void test_reverse_non_empty_list(void)
{
   TEST_IGNORE();
   list = new_list(4, (list_element_t[]){ 1, 3, 5, 7 });
   size_t expected_length = 4;
   list_element_t expected_elements[] = { 7, 5, 3, 1 };

   actual = reverse_list(list);
   check_lists_match(expected_length, expected_elements, actual);

   call_delete_list(&list);
   call_delete_list(&actual);
}

int main(void)
{
   UnityBegin("test_list_ops.c");

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
   RUN_TEST(
       test_foldl_direction_independent_function_applied_to_non_empty_list);
   RUN_TEST(test_foldl_direction_dependent_function_applied_to_non_empty_list);
   RUN_TEST(test_foldr_empty_list);
   RUN_TEST(
       test_foldr_direction_independent_function_applied_to_non_empty_list);
   RUN_TEST(test_foldr_direction_dependent_function_applied_to_non_empty_list);
   RUN_TEST(test_reverse_empty_list);
   RUN_TEST(test_reverse_non_empty_list);

   return UnityEnd();
}
