#include "vendor/unity.h"
#include "../src/sublist.h"

#define ELEMENT_COUNT(array) (sizeof(array) / sizeof(array[0]))

void test_empty_lists(void)
{
   TEST_ASSERT_EQUAL(EQUAL, check_lists(NULL, NULL, 0, 0));
}

void test_empty_list_within_non_empty_list(void)
{
   int listTwo[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(NULL, listTwo, 0, ELEMENT_COUNT(listTwo)));
}

void test_non_empty_list_contains_empty_list(void)
{
   int listOne[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(SUPERLIST,
                     check_lists(listOne, NULL, ELEMENT_COUNT(listOne), 0));
}

void test_list_equals_itself(void)
{
   int listOne[] = { 1, 2, 3 };
   int listTwo[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(EQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_different_lists(void)
{
   int listOne[] = { 1, 2, 3 };
   int listTwo[] = { 2, 3, 4 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_false_start(void)
{
   int listOne[] = { 1, 2, 5 };
   int listTwo[] = { 0, 1, 2, 3, 1, 2, 5, 6 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_consecutive(void)
{
   int listOne[] = { 1, 1, 2 };
   int listTwo[] = { 0, 1, 1, 1, 2, 1, 2 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_sublist_at_start(void)
{
   int listOne[] = { 0, 1, 2 };
   int listTwo[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_sublist_at_middle(void)
{
   int listOne[] = { 2, 3, 4 };
   int listTwo[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_sublist_at_end(void)
{
   int listOne[] = { 3, 4, 5 };
   int listTwo[] = { 0, 1, 2, 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUBLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_at_start_of_superlist(void)
{
   int listOne[] = { 0, 1, 2, 3, 4, 5 };
   int listTwo[] = { 0, 1, 2 };

   TEST_ASSERT_EQUAL(SUPERLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_in_middle_of_superlist(void)
{
   int listOne[] = { 0, 1, 2, 3, 4, 5 };
   int listTwo[] = { 2, 3 };

   TEST_ASSERT_EQUAL(SUPERLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_at_end_of_superlist(void)
{
   int listOne[] = { 0, 1, 2, 3, 4, 5 };
   int listTwo[] = { 3, 4, 5 };

   TEST_ASSERT_EQUAL(SUPERLIST,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_first_list_missing_element_from_second_list(void)
{
   int listOne[] = { 1, 3 };
   int listTwo[] = { 1, 2, 3 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_second_list_missing_element_from_first_list(void)
{
   int listOne[] = { 1, 2, 3 };
   int listTwo[] = { 1, 3 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_order_matters_to_a_list(void)
{
   int listOne[] = { 1, 2, 3 };
   int listTwo[] = { 3, 2, 1 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_same_digits_but_different_numbers(void)
{
   int listOne[] = { 1, 0, 1 };
   int listTwo[] = { 10, 1 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

void test_different_signs(void)
{
   int listOne[] = { 1, 2, 3 };
   int listTwo[] = { 1, -2, 3 };

   TEST_ASSERT_EQUAL(UNEQUAL,
                     check_lists(listOne, listTwo, ELEMENT_COUNT(listOne),
                                 ELEMENT_COUNT(listTwo)));
}

int main(void)
{
   UnityBegin("test/test_sublist.c");

   RUN_TEST(test_empty_lists);
   RUN_TEST(test_empty_list_within_non_empty_list);
   RUN_TEST(test_non_empty_list_contains_empty_list);
   RUN_TEST(test_list_equals_itself);
   RUN_TEST(test_different_lists);
   RUN_TEST(test_false_start);
   RUN_TEST(test_consecutive);
   RUN_TEST(test_sublist_at_start);
   RUN_TEST(test_sublist_at_middle);
   RUN_TEST(test_sublist_at_end);
   RUN_TEST(test_at_start_of_superlist);
   RUN_TEST(test_in_middle_of_superlist);
   RUN_TEST(test_at_end_of_superlist);
   RUN_TEST(test_first_list_missing_element_from_second_list);
   RUN_TEST(test_second_list_missing_element_from_first_list);
   RUN_TEST(test_order_matters_to_a_list);
   RUN_TEST(test_same_digits_but_different_numbers);
   RUN_TEST(test_different_signs);

   UnityEnd();
   return 0;
}
