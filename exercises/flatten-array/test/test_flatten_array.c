#include "vendor/unity.h"
#include "../src/flatten_array.h"
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

#define MAXELEMENTS 10
#define MAXNESTING 10

#define NESTED_ARRAY_SEQUENCE_START \
        size_t positions[MAXNESTING] = {0}; \
        size_t curr_lvl = 0; \
        size_t sequence_errors = 0; \
        size_t opened_brackets = 0;

#define ATTENTION " --error-- "

#define NESTED_ARRAY_SEQUENCE_END \
        if (opened_brackets) { \
           fprintf(stderr, ATTENTION \
                           "%ld unmatched brackets!\n", opened_brackets); \
           sequence_errors++; \
        } \
        if (sequence_errors) \
           fprintf(stderr, ATTENTION \
                           "Errors in the nested array sequence! " \
                           "The structure can be unstable!\n");

#define ADVANCE_POSITION \
        if (positions[curr_lvl] == MAXELEMENTS - 1) \
           fprintf(stderr, ATTENTION \
                           "More than max allowed elements (%i)! " \
                           "Recompile with bigger MAXELEMENTS\n", \
                           MAXELEMENTS); \
        else \
           positions[curr_lvl]++;

#define NEXT_LEVEL \
        if (curr_lvl == MAXNESTING - 1) \
           fprintf(stderr, ATTENTION \
                           "More nesting than allowed (%i)! " \
                           "Recompile with bigger MAXNESTING\n", \
                           MAXNESTING); \
        else \
           curr_lvl++;

#define POINT_TO_NEXT \
        nested_array[curr_lvl][ positions[curr_lvl] ].next = \
           &nested_array[curr_lvl][ positions[curr_lvl] + 1 ];

#define NO_ELEMENTS \
        nested_array[curr_lvl][ positions[curr_lvl] ].array_elements = NULL;

#define OPEN_BRACKET \
        nested_array[curr_lvl][ positions[curr_lvl] ].value = NONE; \
        \
        if (curr_lvl) \
           POINT_TO_NEXT \
        \
        nested_array[curr_lvl][ positions[curr_lvl] ].array_elements = \
           &nested_array[curr_lvl + 1][ positions[curr_lvl + 1] ]; \
        \
        nested_array[curr_lvl][ positions[curr_lvl] ].type = ARRAY; \
        \
        ADVANCE_POSITION \
        NEXT_LEVEL \
        opened_brackets++;

#define ITEM(x) \
        nested_array[curr_lvl][ positions[curr_lvl] ].value = x; \
        \
        POINT_TO_NEXT \
        \
        NO_ELEMENTS \
        \
        nested_array[curr_lvl][ positions[curr_lvl] ].type = ELEMENT; \
        \
        ADVANCE_POSITION

#define NULL_ITEM \
        nested_array[curr_lvl][ positions[curr_lvl] ].value = NONE; \
        \
        POINT_TO_NEXT \
        \
        NO_ELEMENTS \
        \
        nested_array[curr_lvl][ positions[curr_lvl] ].type = null; \
        \
        ADVANCE_POSITION

#define CLOSE_BRACKET \
        if (positions[curr_lvl]) \
           nested_array[curr_lvl][ positions[curr_lvl] - 1 ].next = NULL; \
        \
        if (curr_lvl) { \
           curr_lvl--; \
           opened_brackets--; \
        } else { \
           fprintf(stderr, ATTENTION \
                           "No matching opening bracket!\n"); \
           sequence_errors++; \
        }

void setUp(void)
{
}

void tearDown(void)
{
}

/* [1, 2, 3] */
void test_flatten_no_nesting(void)
{
   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET
      ITEM(1) ITEM(2) ITEM(3)
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int expected[] = { 1, 2, 3 };
   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
   free(actual);
}

/* [1, [2, 3, 4, 5, 6, 7], 8] */
void test_flatten_flattens_array_with_just_integers_present(void)
{
   TEST_IGNORE();               // delete this line to run test

   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET 
      ITEM(1)
      OPEN_BRACKET
         ITEM(2) ITEM(3) ITEM(4) ITEM(5) ITEM(6) ITEM(7)
      CLOSE_BRACKET
      ITEM(8)
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
   free(actual);
}

/* [0, 2, [[2, 3], 8, 100, 4, [[[50]]]], -2] */
void test_flatten_5_level_nesting(void)
{
   TEST_IGNORE();
   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET 
      ITEM(0)
      ITEM(2)
      OPEN_BRACKET
         OPEN_BRACKET
            ITEM(2) ITEM(3)
         CLOSE_BRACKET
         ITEM(8)
         ITEM(100)
         ITEM(4)
         OPEN_BRACKET
            OPEN_BRACKET
               OPEN_BRACKET
                  ITEM(50)
               CLOSE_BRACKET
            CLOSE_BRACKET
         CLOSE_BRACKET
      CLOSE_BRACKET
   ITEM(-2)
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int expected[] = { 0, 2, 2, 3, 8, 100, 4, 50, -2 };
   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
   free(actual);
}

/* [1, [2, [[3]], [4, [[5]]], 6, 7], 8] */
void test_flatten_6_level_nesting(void)
{
   TEST_IGNORE();
   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET
      ITEM(1)
      OPEN_BRACKET
         ITEM(2)
         OPEN_BRACKET
            OPEN_BRACKET
               ITEM(3)
            CLOSE_BRACKET
         CLOSE_BRACKET
         OPEN_BRACKET
            ITEM(4)
            OPEN_BRACKET
               OPEN_BRACKET
                  ITEM(5)
               CLOSE_BRACKET
            CLOSE_BRACKET
         CLOSE_BRACKET
         ITEM(6) ITEM(7)
      CLOSE_BRACKET
   ITEM(8)
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
   free(actual);
}

/* [0, 2, [[2, 3], 8, [[100]], nul, [[null]]], -2] */
void test_flatten_6_level_nest_list_with_null_values(void)
{
   TEST_IGNORE();
   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET
      ITEM(0) ITEM(2)
      OPEN_BRACKET
         OPEN_BRACKET
            ITEM(2) ITEM(3)
         CLOSE_BRACKET
         ITEM(8)
         OPEN_BRACKET
            OPEN_BRACKET
               ITEM(100)
            CLOSE_BRACKET
         CLOSE_BRACKET
         NULL_ITEM
         OPEN_BRACKET
            OPEN_BRACKET
               NULL_ITEM
            CLOSE_BRACKET
         CLOSE_BRACKET
      CLOSE_BRACKET
      ITEM(-2)
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int expected[] = { 0, 2, 2, 3, 8, 100, -2 };
   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
   free(actual);
}

/* [null, [[[null]]], null, null, [[null, null], null], null]  */
void test_flatten_all_values_in_nested_list_are_null(void)
{
   TEST_IGNORE();
   item_t nested_array[MAXNESTING][MAXELEMENTS] = { NULL, NULL, UNDEF, NONE };

/* *INDENT-OFF* */
   NESTED_ARRAY_SEQUENCE_START
   OPEN_BRACKET
      NULL_ITEM
      OPEN_BRACKET
         OPEN_BRACKET
            OPEN_BRACKET
               NULL_ITEM
            CLOSE_BRACKET
         CLOSE_BRACKET
      CLOSE_BRACKET
      NULL_ITEM NULL_ITEM
      OPEN_BRACKET
         OPEN_BRACKET
            NULL_ITEM NULL_ITEM
         CLOSE_BRACKET
         NULL_ITEM
      CLOSE_BRACKET
      NULL_ITEM
   CLOSE_BRACKET
   NESTED_ARRAY_SEQUENCE_END
/* *INDENT-ON* */

   int *actual = flatten(&nested_array[0][0]);
   TEST_ASSERT_NULL(actual);
}

int main(void)
{
   UnityBegin("test/test_flatten_array.c");

   RUN_TEST(test_flatten_no_nesting);
   RUN_TEST(test_flatten_flattens_array_with_just_integers_present);
   RUN_TEST(test_flatten_5_level_nesting);
   RUN_TEST(test_flatten_6_level_nesting);
   RUN_TEST(test_flatten_6_level_nest_list_with_null_values);
   RUN_TEST(test_flatten_all_values_in_nested_list_are_null);

   UnityEnd();
   return 0;
}
