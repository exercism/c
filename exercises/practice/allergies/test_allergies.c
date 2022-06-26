#include "test-framework/unity.h"
#include "allergies.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_not_allergic_to_anything_for_eggs(void)
{
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, 0));
}

static void test_allergic_only_to_eggs(void)
{
   TEST_IGNORE();   // delete this line to run test

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 1));
}

static void test_allergic_to_eggs_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 3));
}

static void test_allergic_to_something_but_not_eggs(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, 2));
}

static void test_allergic_to_everything_for_eggs(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 255));
}

static void test_not_allergic_to_anything_for_peanuts(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, 0));
}

static void test_allergic_only_to_peanuts(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, 2));
}

static void test_allergic_to_peanuts_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 7));
}

static void test_allergic_to_something_but_not_peanuts(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, 5));
}

static void test_allergic_to_everything_for_peanuts(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, 255));
}

static void test_not_allergic_to_anything_for_shellfish(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, 0));
}

static void test_allergic_only_to_shellfish(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 4));
}

static void test_allergic_to_shellfish_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 14));
}

static void test_allergic_to_something_but_not_shellfish(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, 10));
}

static void test_allergic_to_everything_for_shellfish(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 255));
}

static void test_not_allergic_to_anything_for_strawberries(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, 0));
}

static void test_allergic_only_to_strawberries(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 8));
}

static void test_allergic_to_strawberries_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 28));
}

static void test_allergic_to_something_but_not_strawberries(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, 20));
}

static void test_allergic_to_everything_for_strawberries(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 255));
}

static void test_not_allergic_to_anything_for_tomatoes(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, 0));
}

static void test_allergic_only_to_tomatoes(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 16));
}

static void test_allergic_to_tomatoes_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 56));
}

static void test_allergic_to_something_but_not_tomatoes(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, 40));
}

static void test_allergic_to_everything_for_tomatoes(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 255));
}

static void test_not_allergic_to_anything_for_chocolate(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, 0));
}

static void test_allergic_only_to_chocolate(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 32));
}

static void test_allergic_to_chocolate_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 112));
}

static void test_allergic_to_something_but_not_chocolate(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, 80));
}

static void test_allergic_to_everything_for_chocolate(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 255));
}

static void test_not_allergic_to_anything_for_pollen(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, 0));
}

static void test_allergic_only_to_pollen(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 64));
}

static void test_allergic_to_pollen_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 224));
}

static void test_allergic_to_something_but_not_pollen(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, 160));
}

static void test_allergic_to_everything_for_pollen(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 255));
}

static void test_not_allergic_to_anything_for_cats(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, 0));
}

static void test_allergic_only_to_cats(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 128));
}

static void test_allergic_to_cats_and_something_else(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 192));
}

static void test_allergic_to_something_but_not_cats(void)
{
   TEST_IGNORE();

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, 64));
}

static void test_allergic_to_everything_for_cats(void)
{
   TEST_IGNORE();

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 255));
}

static void test_no_allergies(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(0);
   TEST_ASSERT_EQUAL(0, list.count);
}

static void test_just_eggs(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(1);
   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
}

static void test_just_peanuts(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(2);
   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

static void test_just_strawberries(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(8);
   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
}

static void test_eggs_and_peanuts(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(3);
   TEST_ASSERT_EQUAL(2, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

static void test_more_than_eggs_but_not_peanuts(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(5);
   TEST_ASSERT_EQUAL(2, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
}

static void test_lots_of_stuff(void)
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

static void test_everything(void)
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

static void test_no_allergen_score_parts(void)
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

static void test_no_allergen_score_parts_without_highest_valid_score(void)
{
   TEST_IGNORE();

   allergen_list_t list = get_allergens(257);
   TEST_ASSERT_EQUAL(1, list.count);
   TEST_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
}

int main(void)
{
   UnityBegin("test_allergies.c");

   RUN_TEST(test_not_allergic_to_anything_for_eggs);
   RUN_TEST(test_allergic_only_to_eggs);
   RUN_TEST(test_allergic_to_eggs_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_eggs);
   RUN_TEST(test_allergic_to_everything_for_eggs);

   RUN_TEST(test_not_allergic_to_anything_for_peanuts);
   RUN_TEST(test_allergic_only_to_peanuts);
   RUN_TEST(test_allergic_to_peanuts_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_peanuts);
   RUN_TEST(test_allergic_to_everything_for_peanuts);

   RUN_TEST(test_not_allergic_to_anything_for_shellfish);
   RUN_TEST(test_allergic_only_to_shellfish);
   RUN_TEST(test_allergic_to_shellfish_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_shellfish);
   RUN_TEST(test_allergic_to_everything_for_shellfish);

   RUN_TEST(test_not_allergic_to_anything_for_strawberries);
   RUN_TEST(test_allergic_only_to_strawberries);
   RUN_TEST(test_allergic_to_strawberries_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_strawberries);
   RUN_TEST(test_allergic_to_everything_for_strawberries);

   RUN_TEST(test_not_allergic_to_anything_for_tomatoes);
   RUN_TEST(test_allergic_only_to_tomatoes);
   RUN_TEST(test_allergic_to_tomatoes_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_tomatoes);
   RUN_TEST(test_allergic_to_everything_for_tomatoes);

   RUN_TEST(test_not_allergic_to_anything_for_chocolate);
   RUN_TEST(test_allergic_only_to_chocolate);
   RUN_TEST(test_allergic_to_chocolate_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_chocolate);
   RUN_TEST(test_allergic_to_everything_for_chocolate);

   RUN_TEST(test_not_allergic_to_anything_for_pollen);
   RUN_TEST(test_allergic_only_to_pollen);
   RUN_TEST(test_allergic_to_pollen_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_pollen);
   RUN_TEST(test_allergic_to_everything_for_pollen);

   RUN_TEST(test_not_allergic_to_anything_for_cats);
   RUN_TEST(test_allergic_only_to_cats);
   RUN_TEST(test_allergic_to_cats_and_something_else);
   RUN_TEST(test_allergic_to_something_but_not_cats);
   RUN_TEST(test_allergic_to_everything_for_cats);

   RUN_TEST(test_no_allergies);
   RUN_TEST(test_just_eggs);
   RUN_TEST(test_just_peanuts);
   RUN_TEST(test_just_strawberries);
   RUN_TEST(test_eggs_and_peanuts);
   RUN_TEST(test_more_than_eggs_but_not_peanuts);
   RUN_TEST(test_lots_of_stuff);
   RUN_TEST(test_everything);
   RUN_TEST(test_no_allergen_score_parts);
   RUN_TEST(test_no_allergen_score_parts_without_highest_valid_score);

   return UnityEnd();
}
