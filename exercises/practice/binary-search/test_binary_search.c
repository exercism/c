#include "test-framework/unity.h"
#include "binary_search.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_finds_a_value_in_an_array_with_one_element(void)
{
   int arr[] = { 6 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[0] == binary_search(6, arr, length));
}

static void test_a_value_in_the_middle_of_an_array(void)
{
   TEST_IGNORE();   // delete this line to run test
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[3] == binary_search(6, arr, length));
}

static void test_finds_a_value_at_the_beginning_of_an_array(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[0] == binary_search(1, arr, length));
}

static void test_finds_a_value_at_the_end_of_an_array(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[6] == binary_search(11, arr, length));
}

static void test_finds_a_value_in_an_array_of_odd_length(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[9] == binary_search(144, arr, length));
}

static void test_finds_a_value_in_an_array_of_even_length(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(&arr[5] == binary_search(21, arr, length));
}

static void test_identifies_that_a_value_is_not_included_in_the_array(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(7, arr, length));
}

static void
test_a_value_smaller_than_the_arrays_smallest_value_is_not_found(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(0, arr, length));
}

static void test_a_value_larger_than_the_arrays_largest_value_is_not_found(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(13, arr, length));
}

static void test_nothing_is_found_in_an_empty_array(void)
{
   TEST_IGNORE();
   int arr[] = { 1 };
   size_t length = 0;
   TEST_ASSERT(NULL == binary_search(1, arr, length));
}

static void test_nothing_is_found_when_the_left_and_right_bounds_cross(void)
{
   TEST_IGNORE();
   int arr[] = { 1, 2 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT(NULL == binary_search(0, arr, length));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_finds_a_value_in_an_array_with_one_element);
   RUN_TEST(test_a_value_in_the_middle_of_an_array);
   RUN_TEST(test_finds_a_value_at_the_beginning_of_an_array);
   RUN_TEST(test_finds_a_value_at_the_end_of_an_array);
   RUN_TEST(test_finds_a_value_in_an_array_of_odd_length);
   RUN_TEST(test_finds_a_value_in_an_array_of_even_length);
   RUN_TEST(test_identifies_that_a_value_is_not_included_in_the_array);
   RUN_TEST(test_a_value_smaller_than_the_arrays_smallest_value_is_not_found);
   RUN_TEST(test_a_value_larger_than_the_arrays_largest_value_is_not_found);
   RUN_TEST(test_nothing_is_found_in_an_empty_array);
   RUN_TEST(test_nothing_is_found_when_the_left_and_right_bounds_cross);

   return UNITY_END();
}
