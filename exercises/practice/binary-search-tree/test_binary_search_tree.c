#include "test-framework/unity.h"
#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_data_data_is_retained(void)
{
   int tree_data[] = { 4 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   free_tree(tree);
}

static void test_data_smaller_number_at_left_node(void)
{
   TEST_IGNORE();   // delete this line to run test
   int tree_data[] = { 4, 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->left->data);
   TEST_ASSERT_NULL(tree->left->left);
   TEST_ASSERT_NULL(tree->left->right);

   free_tree(tree);
}

static void test_data_same_number_at_left_node(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 4 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(4, tree->left->data);
   TEST_ASSERT_NULL(tree->left->left);
   TEST_ASSERT_NULL(tree->left->right);

   free_tree(tree);
}

static void test_data_greater_number_at_right_node(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 5 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(5, tree->right->data);
   TEST_ASSERT_NULL(tree->right->left);
   TEST_ASSERT_NULL(tree->right->right);

   free_tree(tree);
}

static void test_data_can_create_complex_tree(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 2, 6, 1, 3, 5, 7 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->left->data);
   TEST_ASSERT_NOT_NULL(tree->left->left);
   TEST_ASSERT_NOT_NULL(tree->left->right);

   TEST_ASSERT_EQUAL_INT(6, tree->right->data);
   TEST_ASSERT_NOT_NULL(tree->right->left);
   TEST_ASSERT_NOT_NULL(tree->right->right);

   TEST_ASSERT_EQUAL_INT(1, tree->left->left->data);
   TEST_ASSERT_NULL(tree->left->left->left);
   TEST_ASSERT_NULL(tree->left->left->right);

   TEST_ASSERT_EQUAL_INT(3, tree->left->right->data);
   TEST_ASSERT_NULL(tree->left->right->left);
   TEST_ASSERT_NULL(tree->left->right->right);

   TEST_ASSERT_EQUAL_INT(5, tree->right->left->data);
   TEST_ASSERT_NULL(tree->right->left->left);
   TEST_ASSERT_NULL(tree->right->left->right);

   TEST_ASSERT_EQUAL_INT(7, tree->right->right->data);
   TEST_ASSERT_NULL(tree->right->right->left);
   TEST_ASSERT_NULL(tree->right->right->right);

   free_tree(tree);
}

static void test_sorted_data_can_sort_single_number(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void
test_sorted_data_can_sort_if_second_number_is_smaller_than_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 1 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 1, 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_can_sort_if_second_number_is_same_as_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2, 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void
test_sorted_data_can_sort_if_second_number_is_greater_than_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 3 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2, 3 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_can_sort_complex_tree(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 1, 3, 6, 7, 5 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 1, 2, 3, 5, 6, 7 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_data_data_is_retained);
   RUN_TEST(test_data_smaller_number_at_left_node);
   RUN_TEST(test_data_same_number_at_left_node);
   RUN_TEST(test_data_greater_number_at_right_node);
   RUN_TEST(test_data_can_create_complex_tree);
   RUN_TEST(test_sorted_data_can_sort_single_number);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_smaller_than_first);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_same_as_first);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_greater_than_first);
   RUN_TEST(test_sorted_data_can_sort_complex_tree);

   return UNITY_END();
}
