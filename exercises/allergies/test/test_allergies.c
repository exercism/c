#include "vendor/unity.h"
#include "../src/allergies.h"
#include <stdlib.h>

void test_list_count_is(int count, allergen_list_t * list)
{
   TEST_ASSERT_EQUAL(count, list->count);
}

void test_list_contains(allergen_t allergen, allergen_list_t * list)
{
   TEST_IGNORE();               // delete this line to run test
   bool allergen_found = false;

   for (int i = 0; i < list->count; i++) {
      if (list->allergens[i] == allergen) {
         allergen_found = true;
         break;
      }
   }

   TEST_ASSERT_TRUE(allergen_found);
}

void test_no_allergies_means_not_allergic(void)
{
   TEST_IGNORE();
   int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

void test_is_allergic_to_eggs(void)
{
   TEST_IGNORE();
   int score = 1;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
}

void test_is_allergic_to_eggs_in_addition_to_other_stuff(void)
{
   TEST_IGNORE();
   int score = 5;

   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, score));
   TEST_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, score));
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, score));
}

void test_no_allergies_at_all(void)
{
   TEST_IGNORE();
   int score = 0;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(0, &list);

   free(list.allergens);
}

void test_allergic_to_just_eggs(void)
{
   TEST_IGNORE();
   int score = 1;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(ALLERGEN_EGGS, &list);

   free(list.allergens);
}

void test_allergic_to_just_peanuts(void)
{
   TEST_IGNORE();
   int score = 2;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(ALLERGEN_PEANUTS, &list);

   free(list.allergens);
}

void test_allergic_to_just_strawberries(void)
{
   TEST_IGNORE();
   int score = 8;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(ALLERGEN_STRAWBERRIES, &list);

   free(list.allergens);
}

void test_allergic_to_eggs_and_peanuts(void)
{
   TEST_IGNORE();
   int score = 3;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(2, &list);
   test_list_contains(ALLERGEN_EGGS, &list);
   test_list_contains(ALLERGEN_PEANUTS, &list);

   free(list.allergens);
}

void test_allergic_to_more_than_eggs_but_not_peanuts(void)
{
   TEST_IGNORE();
   int score = 5;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(2, &list);
   test_list_contains(ALLERGEN_EGGS, &list);
   test_list_contains(ALLERGEN_SHELLFISH, &list);

   free(list.allergens);
}

void test_allergic_to_lots_of_stuff(void)
{
   TEST_IGNORE();
   int score = 248;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(5, &list);
   test_list_contains(ALLERGEN_STRAWBERRIES, &list);
   test_list_contains(ALLERGEN_TOMATOES, &list);
   test_list_contains(ALLERGEN_CHOCOLATE, &list);
   test_list_contains(ALLERGEN_POLLEN, &list);
   test_list_contains(ALLERGEN_CATS, &list);

   free(list.allergens);
}

void test_allergic_to_everything(void)
{
   TEST_IGNORE();
   int score = 255;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(8, &list);
   test_list_contains(ALLERGEN_EGGS, &list);
   test_list_contains(ALLERGEN_PEANUTS, &list);
   test_list_contains(ALLERGEN_SHELLFISH, &list);
   test_list_contains(ALLERGEN_STRAWBERRIES, &list);
   test_list_contains(ALLERGEN_TOMATOES, &list);
   test_list_contains(ALLERGEN_CHOCOLATE, &list);
   test_list_contains(ALLERGEN_POLLEN, &list);
   test_list_contains(ALLERGEN_CATS, &list);

   free(list.allergens);
}

void test_ignore_non_allergen_score_parts(void)
{
   TEST_IGNORE();
   int score = 509;
   allergen_list_t list;

   get_allergens(score, &list);

   test_list_count_is(7, &list);
   test_list_contains(ALLERGEN_EGGS, &list);
   test_list_contains(ALLERGEN_SHELLFISH, &list);
   test_list_contains(ALLERGEN_STRAWBERRIES, &list);
   test_list_contains(ALLERGEN_TOMATOES, &list);
   test_list_contains(ALLERGEN_CHOCOLATE, &list);
   test_list_contains(ALLERGEN_POLLEN, &list);
   test_list_contains(ALLERGEN_CATS, &list);

   free(list.allergens);
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

   UnityEnd();
   return 0;
}
