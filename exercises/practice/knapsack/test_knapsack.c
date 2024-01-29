#include <stddef.h>
#include "test-framework/unity.h"
#include "knapsack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_no_items(void)
{
   item_t *items = NULL;
   size_t item_count = 0;
   unsigned int maximum_weight = 100;

   TEST_ASSERT_EQUAL_UINT(0, maximum_value(maximum_weight, items, item_count));
}

static void test_one_item_too_heavy(void)
{
   TEST_IGNORE();   // delete this line to run test

   item_t items[] = {
      { .weight = 100, .value = 1 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 10;

   TEST_ASSERT_EQUAL_UINT(0, maximum_value(maximum_weight, items, item_count));
}

static void test_five_items_cannot_be_greedy_by_weight(void)
{
   TEST_IGNORE();

   item_t items[] = {
      { .weight = 2, .value = 5 },   { .weight = 2, .value = 5 },
      { .weight = 2, .value = 5 },   { .weight = 2, .value = 5 },
      { .weight = 10, .value = 21 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 10;

   TEST_ASSERT_EQUAL_UINT(21, maximum_value(maximum_weight, items, item_count));
}

static void test_five_items_cannot_be_greedy_by_value(void)
{
   TEST_IGNORE();

   item_t items[] = {
      { .weight = 2, .value = 20 },  { .weight = 2, .value = 20 },
      { .weight = 2, .value = 20 },  { .weight = 2, .value = 20 },
      { .weight = 10, .value = 50 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 10;

   TEST_ASSERT_EQUAL_UINT(80, maximum_value(maximum_weight, items, item_count));
}

static void test_example_knapsack(void)
{
   TEST_IGNORE();

   item_t items[] = {
      { .weight = 5, .value = 10 },
      { .weight = 4, .value = 40 },
      { .weight = 6, .value = 30 },
      { .weight = 4, .value = 50 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 10;

   TEST_ASSERT_EQUAL_UINT(90, maximum_value(maximum_weight, items, item_count));
}

static void test_eight_items(void)
{
   TEST_IGNORE();

   item_t items[] = {
      { .weight = 5, .value = 10 },   { .weight = 25, .value = 350 },
      { .weight = 35, .value = 400 }, { .weight = 45, .value = 450 },
      { .weight = 5, .value = 20 },   { .weight = 25, .value = 70 },
      { .weight = 3, .value = 8 },    { .weight = 2, .value = 5 },
      { .weight = 2, .value = 5 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 104;

   TEST_ASSERT_EQUAL_UINT(900,
                          maximum_value(maximum_weight, items, item_count));
}

static void test_fifteen_items(void)
{
   TEST_IGNORE();

   item_t items[] = {
      { .weight = 70, .value = 135 },  { .weight = 73, .value = 139 },
      { .weight = 77, .value = 149 },  { .weight = 80, .value = 150 },
      { .weight = 82, .value = 156 },  { .weight = 87, .value = 163 },
      { .weight = 90, .value = 173 },  { .weight = 94, .value = 184 },
      { .weight = 98, .value = 192 },  { .weight = 106, .value = 201 },
      { .weight = 110, .value = 210 }, { .weight = 113, .value = 214 },
      { .weight = 115, .value = 221 }, { .weight = 118, .value = 229 },
      { .weight = 120, .value = 240 },
   };
   size_t item_count = sizeof(items) / sizeof(items[0]);
   unsigned int maximum_weight = 750;

   TEST_ASSERT_EQUAL_UINT(1458,
                          maximum_value(maximum_weight, items, item_count));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_no_items);
   RUN_TEST(test_one_item_too_heavy);
   RUN_TEST(test_five_items_cannot_be_greedy_by_weight);
   RUN_TEST(test_five_items_cannot_be_greedy_by_value);
   RUN_TEST(test_example_knapsack);
   RUN_TEST(test_eight_items);
   RUN_TEST(test_fifteen_items);

   return UNITY_END();
}
