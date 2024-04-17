#include "dnd_character.h"

#include "test-framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_ability_modifier_for_score_3_is_neg4(void)
{
   TEST_ASSERT_EQUAL_INT(-4, modifier(3));
}

static void test_ability_modifier_for_score_4_is_neg3(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL_INT(-3, modifier(4));
}

static void test_ability_modifier_for_score_5_is_neg3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(-3, modifier(5));
}

static void test_ability_modifier_for_score_6_is_neg2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(-2, modifier(6));
}

static void test_ability_modifier_for_score_7_is_neg2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(-2, modifier(7));
}

static void test_ability_modifier_for_score_8_is_neg1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(-1, modifier(8));
}

static void test_ability_modifier_for_score_9_is_neg1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(-1, modifier(9));
}

static void test_ability_modifier_for_score_10_is_0(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(0, modifier(10));
}

static void test_ability_modifier_for_score_11_is_0(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(0, modifier(11));
}

static void test_ability_modifier_for_score_12_is_1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, modifier(12));
}

static void test_ability_modifier_for_score_13_is_1(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(1, modifier(13));
}

static void test_ability_modifier_for_score_14_is_2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(2, modifier(14));
}

static void test_ability_modifier_for_score_15_is_2(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(2, modifier(15));
}

static void test_ability_modifier_for_score_16_is_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, modifier(16));
}

static void test_ability_modifier_for_score_17_is_3(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(3, modifier(17));
}

static void test_ability_modifier_for_score_18_is_4(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL_INT(4, modifier(18));
}

static void check_valid_score(int score)
{
   TEST_ASSERT(score >= 3 && score <= 18);
}

static void test_random_ability_is_within_range(void)
{
   TEST_IGNORE();
   const int score = ability();
   check_valid_score(score);
}

static void test_random_character_is_valid(void)
{
   TEST_IGNORE();
   const dnd_character_t character = make_dnd_character();
   check_valid_score(character.strength);
   check_valid_score(character.dexterity);
   check_valid_score(character.constitution);
   check_valid_score(character.intelligence);
   check_valid_score(character.wisdom);
   check_valid_score(character.charisma);
   TEST_ASSERT_EQUAL_INT(10 + modifier(character.constitution),
                         character.hitpoints);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_ability_modifier_for_score_3_is_neg4);
   RUN_TEST(test_ability_modifier_for_score_4_is_neg3);
   RUN_TEST(test_ability_modifier_for_score_5_is_neg3);
   RUN_TEST(test_ability_modifier_for_score_6_is_neg2);
   RUN_TEST(test_ability_modifier_for_score_7_is_neg2);
   RUN_TEST(test_ability_modifier_for_score_8_is_neg1);
   RUN_TEST(test_ability_modifier_for_score_9_is_neg1);
   RUN_TEST(test_ability_modifier_for_score_10_is_0);
   RUN_TEST(test_ability_modifier_for_score_11_is_0);
   RUN_TEST(test_ability_modifier_for_score_12_is_1);
   RUN_TEST(test_ability_modifier_for_score_13_is_1);
   RUN_TEST(test_ability_modifier_for_score_14_is_2);
   RUN_TEST(test_ability_modifier_for_score_15_is_2);
   RUN_TEST(test_ability_modifier_for_score_16_is_3);
   RUN_TEST(test_ability_modifier_for_score_17_is_3);
   RUN_TEST(test_ability_modifier_for_score_18_is_4);
   RUN_TEST(test_random_ability_is_within_range);
   RUN_TEST(test_random_character_is_valid);

   return UNITY_END();
}
