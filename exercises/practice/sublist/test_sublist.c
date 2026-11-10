#include "test-framework/unity.h"
#include "sublist.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_empty_lists(void)
{
   TEST_ASSERT_EQUAL(EQUAL, check_lists(NULL, NULL, 0, 0));
}

static void test_empty_list_within_non_empty_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   int base_list[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(NULL, base_list, 0, 3));
}

static void test_non_empty_list_contains_empty_list(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(SUPERLIST, check_lists(list_to_compare, NULL, 3, 0));
}

static void test_list_equals_itself(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 3 };
   int base_list[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(EQUAL, check_lists(list_to_compare, base_list, 3, 3));
}

static void test_different_lists(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 3 };
   int base_list[] = { 2, 3, 4 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 3, 3));
}

static void test_false_start(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 5 };
   int base_list[] = { 0, 1, 2, 3, 1, 2, 5, 6 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(list_to_compare, base_list, 3, 8));
}

static void test_consecutive(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 1, 2 };
   int base_list[] = { 0, 1, 1, 1, 2, 1, 2 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(list_to_compare, base_list, 3, 7));
}

static void test_sublist_at_start(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 0, 1, 2 };
   int base_list[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(list_to_compare, base_list, 3, 6));
}

static void test_sublist_in_middle(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 2, 3, 4 };
   int base_list[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(list_to_compare, base_list, 3, 6));
}

static void test_sublist_at_end(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 3, 4, 5 };
   int base_list[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST, check_lists(list_to_compare, base_list, 3, 6));
}

static void test_at_start_of_superlist(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 0, 1, 2, 3, 4, 5 };
   int base_list[] = { 0, 1, 2 };

   TEST_ASSERT_EQUAL(SUPERLIST, check_lists(list_to_compare, base_list, 6, 3));
}

static void test_in_middle_of_superlist(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 0, 1, 2, 3, 4, 5 };
   int base_list[] = { 2, 3 };

   TEST_ASSERT_EQUAL(SUPERLIST, check_lists(list_to_compare, base_list, 6, 2));
}

static void test_at_end_of_superlist(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 0, 1, 2, 3, 4, 5 };
   int base_list[] = { 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUPERLIST, check_lists(list_to_compare, base_list, 6, 3));
}

static void test_first_list_missing_element_from_second_list(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 3 };
   int base_list[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 2, 3));
}

static void test_second_list_missing_element_from_first_list(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 3 };
   int base_list[] = { 1, 3 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 3, 2));
}

static void test_first_list_missing_additional_digits_from_second_list(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2 };
   int base_list[] = { 1, 22 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 2, 2));
}

static void test_order_matters_to_a_list(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 2, 3 };
   int base_list[] = { 3, 2, 1 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 3, 3));
}

static void test_same_digits_but_different_numbers(void)
{
   TEST_IGNORE();
   int list_to_compare[] = { 1, 0, 1 };
   int base_list[] = { 10, 1 };

   TEST_ASSERT_EQUAL(UNEQUAL, check_lists(list_to_compare, base_list, 3, 2));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_empty_lists);
   RUN_TEST(test_empty_list_within_non_empty_list);
   RUN_TEST(test_non_empty_list_contains_empty_list);
   RUN_TEST(test_list_equals_itself);
   RUN_TEST(test_different_lists);
   RUN_TEST(test_false_start);
   RUN_TEST(test_consecutive);
   RUN_TEST(test_sublist_at_start);
   RUN_TEST(test_sublist_in_middle);
   RUN_TEST(test_sublist_at_end);
   RUN_TEST(test_at_start_of_superlist);
   RUN_TEST(test_in_middle_of_superlist);
   RUN_TEST(test_at_end_of_superlist);
   RUN_TEST(test_first_list_missing_element_from_second_list);
   RUN_TEST(test_second_list_missing_element_from_first_list);
   RUN_TEST(test_first_list_missing_additional_digits_from_second_list);
   RUN_TEST(test_order_matters_to_a_list);
   RUN_TEST(test_same_digits_but_different_numbers);

   return UNITY_END();
}
