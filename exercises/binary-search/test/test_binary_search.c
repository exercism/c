#include "vendor/unity.h"
#include "../src/binary_search.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_single_element(void)
{
   int arr[] = { 6 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[0] == binary_search(6, arr, length));
}

static void test_value_in_middle(void)
{
   TEST_IGNORE();               // delete this line to run test
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[3] == binary_search(6, arr, length));
}

static void test_value_at_beginning(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[0] == binary_search(1, arr, length));
}

static void test_value_at_end(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[6] == binary_search(11, arr, length));
}

static void test_find_value_with_odd_length(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[9] == binary_search(144, arr, length));
}

static void test_find_value_with_even_length(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[5] == binary_search(21, arr, length));
}

static void test_identify_missing_value(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(7, arr, length));
}

static void test_value_smaller_than_everything(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(0, arr, length));
}

static void test_value_larger_than_everything(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(13, arr, length));
}

static void test_empty_array(void)
{
   TEST_IGNORE();
   int *arr = NULL;
   size_t length = 0;
   TEST_ASSERT(NULL == binary_search(1, arr, length));
}

static void test_zero_length_array(void)
{
   TEST_IGNORE();
   int arr[] = { 1 };
   size_t length = 0;
   TEST_ASSERT(NULL == binary_search(1, arr, length));
}

int main(void)
{
   UnityBegin("test/test_binary_search.c");

   RUN_TEST(test_single_element);
   RUN_TEST(test_value_in_middle);
   RUN_TEST(test_value_at_beginning);
   RUN_TEST(test_value_at_end);
   RUN_TEST(test_find_value_with_odd_length);
   RUN_TEST(test_find_value_with_even_length);
   RUN_TEST(test_identify_missing_value);
   RUN_TEST(test_value_smaller_than_everything);
   RUN_TEST(test_value_larger_than_everything);
   RUN_TEST(test_empty_array);
   RUN_TEST(test_zero_length_array);

   return UnityEnd();
}
