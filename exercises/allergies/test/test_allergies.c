#include "vendor/unity.h"
#include "../src/allergies.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_no_allergies_means_not_allergic(void)
{
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_is_allergic_to_eggs(void)
{
   TEST_IGNORE();               // delete this line to run test
   unsigned int score = 1;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_is_allergic_to_eggs_in_addition_to_other_stuff(void)
{
   TEST_IGNORE();
   unsigned int score = 5;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_no_allergies_at_all(void)
{
   TEST_IGNORE();
   unsigned int score = 0;
   allergen_list_t list = get_allergens(score);

   TEST_ASSERT_EQUAL(0, list.count);
}

static void test_allergic_to_just_eggs(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(1);

   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
}

static void test_allergic_to_just_peanuts(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(2);

   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

static void test_allergic_to_just_strawberries(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(8);

   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
}

static void test_allergic_to_eggs_and_peanuts(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(3);

   TEST_ASSERT_EQUAL(2, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

static void test_allergic_to_more_than_eggs_but_not_peanuts(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(5);

   TEST_ASSERT_EQUAL(2, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
}

static void test_allergic_to_lots_of_stuff(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(248);

   TEST_ASSERT_EQUAL(5, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

static void test_allergic_to_everything(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(255);

   TEST_ASSERT_EQUAL(8, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

static void test_ignore_non_allergen_score_parts(void)
{
   TEST_IGNORE();
   allergen_list_t list = get_allergens(509);

   TEST_ASSERT_EQUAL(7, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

int main(void)
{
   UnityBegin("test/test_allergies.c");

   RUN_TEST(test_no_allergies_means_not_allergic);
   RUN_TEST(test_is_allergic_to_eggs);
   RUN_TEST(test_is_allergic_to_eggs_in_addition_to_other_stuff);
   RUN_TEST(test_no_allergies_at_all);
   RUN_TEST(test_allergic_to_just_eggs);
   RUN_TEST(test_allergic_to_just_peanuts);
   RUN_TEST(test_allergic_to_just_strawberries);
   RUN_TEST(test_allergic_to_eggs_and_peanuts);
   RUN_TEST(test_allergic_to_more_than_eggs_but_not_peanuts);
   RUN_TEST(test_allergic_to_lots_of_stuff);
   RUN_TEST(test_allergic_to_everything);
   RUN_TEST(test_ignore_non_allergen_score_parts);

   return UnityEnd();
}
