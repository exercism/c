#include "vendor/unity.h"
#include "../src/pythagorean_triplet.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_count(size_t expected, size_t actual)
{
   TEST_ASSERT_EQUAL_UINT64(expected, actual);
}

static void check_triplets(size_t count, triplet_t expected[],
                           triplet_t actual[])
{
   // assumes array counts match
   for (size_t i = 0; i < count; ++i) {
      bool triplet_found = false;
      for (size_t j = 0; j < count; ++j) {
         if (expected[i].a == actual[j].a
             && expected[i].b == actual[j].b && expected[i].c == actual[j].c) {
            triplet_found = true;
            break;
         }
      }
      if (!triplet_found)
         TEST_FAIL();
   }
}

static void test_triplets_whose_sum_is_12(void)
{
   uint16_t sum = 12;
   uint16_t expected_count = 1;
   triplet_t expected_triplets[] = { {3, 4, 5} };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

static void test_triplets_whose_sum_is_108(void)
{
   TEST_IGNORE();               // delete this line to run test
   uint16_t sum = 108;
   uint16_t expected_count = 1;
   triplet_t expected_triplets[] = { {27, 36, 45} };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

static void test_triplets_whose_sum_is_1000(void)
{
   TEST_IGNORE();
   uint16_t sum = 1000;
   uint16_t expected_count = 1;
   triplet_t expected_triplets[] = { {200, 375, 425} };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

static void test_no_matching_triplets_for_1001(void)
{
   TEST_IGNORE();
   uint16_t sum = 1001;
   uint16_t expected_count = 0;
   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   free_triplets(triplets);
}

static void test_returns_all_matching_triplets(void)
{
   TEST_IGNORE();
   uint16_t sum = 90;
   uint16_t expected_count = 2;
   triplet_t expected_triplets[] = {
      {9, 40, 41},
      {15, 36, 39}
   };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

static void test_several_matching_triplets(void)
{
   TEST_IGNORE();
   uint16_t sum = 840;
   uint16_t expected_count = 8;
   triplet_t expected_triplets[] = {
      {40, 399, 401},
      {56, 390, 394},
      {105, 360, 375},
      {120, 350, 370},
      {140, 336, 364},
      {168, 315, 357},
      {210, 280, 350},
      {240, 252, 348}
   };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

static void test_triplets_for_large_number(void)
{
   TEST_IGNORE();
   uint16_t sum = 30000;
   uint16_t expected_count = 5;
   triplet_t expected_triplets[] = {
      {1200, 14375, 14425},
      {1875, 14000, 14125},
      {5000, 12000, 13000},
      {6000, 11250, 12750},
      {7500, 10000, 12500}
   };

   triplets_t *triplets = triplets_with_sum(sum);
   check_count(expected_count, triplets->count);
   check_triplets(expected_count, expected_triplets, triplets->triplets);
   free_triplets(triplets);
}

int main(void)
{
   UnityBegin("test/test_pythagorean_triplet.c");

   RUN_TEST(test_triplets_whose_sum_is_12);
   RUN_TEST(test_triplets_whose_sum_is_108);
   RUN_TEST(test_triplets_whose_sum_is_1000);
   RUN_TEST(test_no_matching_triplets_for_1001);
   RUN_TEST(test_returns_all_matching_triplets);
   RUN_TEST(test_several_matching_triplets);
   RUN_TEST(test_triplets_for_large_number);

   return UnityEnd();
}
