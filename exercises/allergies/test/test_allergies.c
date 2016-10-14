#include "vendor/unity.h"
#include "../src/allergies.h"
#include <stdlib.h>

void test_list_count_is(int count, Allergen_List_t * list)
{
   TEST_ASSERT_EQUAL(count, list->count);
}

void test_list_contains(Allergen_t allergen, Allergen_List_t * list)
{
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
   int score = 0;

   TEST_ASSERT_FALSE(is_allergic_to(Allergen_Peanuts, score));
   TEST_ASSERT_FALSE(is_allergic_to(Allergen_Cats, score));
   TEST_ASSERT_FALSE(is_allergic_to(Allergen_Strawberries, score));
}

void test_is_allergic_to_eggs(void)
{
   int score = 1;

   TEST_ASSERT_TRUE(is_allergic_to(Allergen_Eggs, score));
}

void test_is_allergic_to_eggs_in_addition_to_other_stuff(void)
{
   int score = 5;

   TEST_ASSERT_TRUE(is_allergic_to(Allergen_Eggs, score));
   TEST_ASSERT_TRUE(is_allergic_to(Allergen_Shellfish, score));
   TEST_ASSERT_FALSE(is_allergic_to(Allergen_Strawberries, score));
}

void test_no_allergies_at_all(void)
{
   int score = 0;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(0, &list);

   free(list.allergens);
}

void test_allergic_to_just_eggs(void)
{
   int score = 1;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(Allergen_Eggs, &list);

   free(list.allergens);
}

void test_allergic_to_just_peanuts(void)
{
   int score = 2;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(Allergen_Peanuts, &list);

   free(list.allergens);
}

void test_allergic_to_just_strawberries(void)
{
   int score = 8;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(1, &list);
   test_list_contains(Allergen_Strawberries, &list);

   free(list.allergens);
}

void test_allergic_to_eggs_and_peanuts(void)
{
   int score = 3;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(2, &list);
   test_list_contains(Allergen_Eggs, &list);
   test_list_contains(Allergen_Peanuts, &list);

   free(list.allergens);
}

void test_allergic_to_more_than_eggs_but_not_peanuts(void)
{
   int score = 5;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(2, &list);
   test_list_contains(Allergen_Eggs, &list);
   test_list_contains(Allergen_Shellfish, &list);

   free(list.allergens);
}

void test_allergic_to_lots_of_stuff(void)
{
   int score = 248;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(5, &list);
   test_list_contains(Allergen_Strawberries, &list);
   test_list_contains(Allergen_Tomatoes, &list);
   test_list_contains(Allergen_Chocolate, &list);
   test_list_contains(Allergen_Pollen, &list);
   test_list_contains(Allergen_Cats, &list);

   free(list.allergens);
}

void test_allergic_to_everything(void)
{
   int score = 255;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(8, &list);
   test_list_contains(Allergen_Eggs, &list);
   test_list_contains(Allergen_Peanuts, &list);
   test_list_contains(Allergen_Shellfish, &list);
   test_list_contains(Allergen_Strawberries, &list);
   test_list_contains(Allergen_Tomatoes, &list);
   test_list_contains(Allergen_Chocolate, &list);
   test_list_contains(Allergen_Pollen, &list);
   test_list_contains(Allergen_Cats, &list);

   free(list.allergens);
}

void test_ignore_non_allergen_score_parts(void)
{
   int score = 509;
   Allergen_List_t list;

   get_allergens(score, &list);

   test_list_count_is(7, &list);
   test_list_contains(Allergen_Eggs, &list);
   test_list_contains(Allergen_Shellfish, &list);
   test_list_contains(Allergen_Strawberries, &list);
   test_list_contains(Allergen_Tomatoes, &list);
   test_list_contains(Allergen_Chocolate, &list);
   test_list_contains(Allergen_Pollen, &list);
   test_list_contains(Allergen_Cats, &list);

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
