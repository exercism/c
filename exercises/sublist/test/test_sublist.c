#include "vendor/unity.h"
#include "../src/sublist.h"
#include <stdlib.h>

#define ELEMENT_COUNT(array) (sizeof(array)/sizeof(array[0]))

void test_empty_lists(void)
{
    int *listOne = malloc(0);
    int *listTwo = malloc(0);

    TEST_ASSERT_EQUAL(EQUAL, check_lists(listOne, listTwo, 0, 0));

    free(listOne);
    free(listTwo);
}

void test_empty_list_within_non_empty_list(void)
{
    int *listOne = malloc(0);
    int *listTwo = malloc(3);

    listTwo[0] = 1;
    listTwo[1] = 2;
    listTwo[2] = 3;

    TEST_ASSERT_EQUAL(SUBLIST, check_lists(listOne, listTwo, 0, 3));

    free(listOne);
    free(listTwo);
}

void test_non_empty_list_contains_empty_list(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(0);

    listOne[0] = 1;
    listOne[1] = 2;
    listOne[2] = 3;

    TEST_ASSERT_EQUAL(SUPERLIST, check_lists(listOne, listTwo, 3, 0));

    free(listOne);
    free(listTwo);
}

void test_list_equals_itself(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(3);

    listOne[0] = 1;
    listOne[1] = 2;
    listOne[2] = 3;

    listTwo[0] = 1;
    listTwo[1] = 2;
    listTwo[2] = 3;

    TEST_ASSERT_EQUAL(EQUAL, check_lists(listOne, listTwo, 3, 3));

    free(listOne);
    free(listTwo);
}

void test_different_lists(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(3);

    listOne[0] = 1;
    listOne[1] = 2;
    listOne[2] = 3;

    listTwo[0] = 2;
    listTwo[1] = 3;
    listTwo[2] = 4;

    TEST_ASSERT_EQUAL(UNEQUAL, check_lists(listOne, listTwo, 3, 3));

    free(listOne);
    free(listTwo);
}

void test_false_start(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(8);

    listOne[0] = 1;
    listOne[1] = 2;
    listOne[2] = 5;

    listTwo[0] = 0;
    listTwo[1] = 1;
    listTwo[2] = 2;
    listTwo[3] = 3;
    listTwo[4] = 1;
    listTwo[5] = 2;
    listTwo[6] = 5;
    listTwo[7] = 6;

    TEST_ASSERT_EQUAL(SUBLIST, check_lists(listOne, listTwo, 3, 8));

    free(listOne);
    free(listTwo);
}

void test_consecutive(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(7);

    listOne[0] = 1;
    listOne[1] = 1;
    listOne[2] = 2;

    listTwo[0] = 0;
    listTwo[1] = 1;
    listTwo[2] = 1;
    listTwo[3] = 1;
    listTwo[4] = 2;
    listTwo[5] = 1;
    listTwo[6] = 2;


    TEST_ASSERT_EQUAL(SUBLIST, check_lists(listOne, listTwo, 3, 7));

    free(listOne);
    free(listTwo);
}

void test_sublist_at_start(void)
{
    int *listOne = malloc(3);
    int *listTwo = malloc(6);

    listOne[0] = 0;
    listOne[1] = 1;
    listOne[2] = 2;

    listTwo[0] = 0;
    listTwo[1] = 1;
    listTwo[2] = 2;
    listTwo[3] = 3;
    listTwo[4] = 4;
    listTwo[5] = 5;


    TEST_ASSERT_EQUAL(SUBLIST, check_lists(listOne, listTwo, 3, 6));

    free(listOne);
    free(listTwo);
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

   UnityEnd();
   return 0;
}
