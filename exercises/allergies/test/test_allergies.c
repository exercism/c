#include "vendor/unity.h"
#include "../src/allergies.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_not_allergic_to_anything_for_eggs(void)
{
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_allergic_only_to_eggs(void)
{
   TEST_IGNORE();               // delete this line to run test
   unsigned int score = 1;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_allergic_to_eggs_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 3;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_allergic_to_something_but_not_eggs(void)
{
   TEST_IGNORE();
   unsigned int score = 2;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_allergic_to_everything_for_eggs(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_not_allergic_to_anything_for_peanuts(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, score));
}

static void test_allergic_only_to_peanuts(void)
{
   TEST_IGNORE();
   unsigned int score = 2;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, score));
}

static void test_allergic_to_peanuts_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 7;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

static void test_allergic_to_something_but_not_peanuts(void)
{
   TEST_IGNORE();
   unsigned int score = 5;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, score));
}

static void test_allergic_to_everything_for_peanuts(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, score));
}

static void test_not_allergic_to_anything_for_shellfish(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, score));
}

static void test_allergic_only_to_shellfish(void)
{
   TEST_IGNORE();
   unsigned int score = 4;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, score));
}

static void test_allergic_to_shellfish_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 14;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, score));
}

static void test_allergic_to_something_but_not_shellfish(void)
{
   TEST_IGNORE();
   unsigned int score = 10;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, score));
}

static void test_allergic_to_everything_for_shellfish(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, score));
}

static void test_not_allergic_to_anything_for_strawberries(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_allergic_only_to_strawberries(void)
{
   TEST_IGNORE();
   unsigned int score = 8;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_allergic_to_strawberries_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 28;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_allergic_to_something_but_not_strawberries(void)
{
   TEST_IGNORE();
   unsigned int score = 20;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_allergic_to_everything_for_strawberries(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

static void test_not_allergic_to_anything_for_tomatoes(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, score));
}

static void test_allergic_only_to_tomatoes(void)
{
   TEST_IGNORE();
   unsigned int score = 16;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, score));
}

static void test_allergic_to_tomatoes_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 56;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, score));
}

static void test_allergic_to_something_but_not_tomatoes(void)
{
   TEST_IGNORE();
   unsigned int score = 40;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, score));
}

static void test_allergic_to_everything_for_tomatoes(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, score));
}

static void test_not_allergic_to_anything_for_chocolate(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, score));
}

static void test_allergic_only_to_chocolate(void)
{
   TEST_IGNORE();
   unsigned int score = 32;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, score));
}

static void test_allergic_to_chocolate_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 112;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, score));
}

static void test_allergic_to_something_but_not_chocolate(void)
{
   TEST_IGNORE();
   unsigned int score = 80;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, score));
}

static void test_allergic_to_everything_for_chocolate(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, score));
}

static void test_not_allergic_to_anything_for_pollen(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, score));
}

static void test_allergic_only_to_pollen(void)
{
   TEST_IGNORE();               // delete this line to run test
   unsigned int score = 64;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, score));
}

static void test_allergic_to_pollen_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 224;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, score));
}

static void test_allergic_to_something_but_not_pollen(void)
{
   TEST_IGNORE();
   unsigned int score = 160;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, score));
}

static void test_allergic_to_everything_for_pollen(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, score));
}

static void test_not_allergic_to_anything_for_cats(void)
{
   TEST_IGNORE();
   unsigned int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, score));
}

static void test_allergic_only_to_cats(void)
{
   TEST_IGNORE();
   unsigned int score = 128;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, score));
}

static void test_allergic_to_cats_and_something_else(void)
{
   TEST_IGNORE();
   unsigned int score = 192;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, score));
}

static void test_allergic_to_something_but_not_cats(void)
{
   TEST_IGNORE();
   unsigned int score = 64;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, score));
}

static void test_allergic_to_everything_for_cats(void)
{
   TEST_IGNORE();
   unsigned int score = 255;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, score));
}

static void test_no_allergies(void)
{
   TEST_IGNORE();
   unsigned int score = 0;
   allergen_list_t list = get_allergens(score);

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

int main(void)
{
   UnityBegin("test/test_allergies.c");

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

   return UnityEnd();
}
