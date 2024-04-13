#include "yacht.h"

#include "test-framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_yacht(void)
{
   const dice_t dice = { { 5, 5, 5, 5, 5 } };
   TEST_ASSERT_EQUAL_INT(50, score(dice, YACHT));
}

static void test_not_yacht(void)
{
   TEST_IGNORE();   // delete this line to run test
   const dice_t dice = { { 1, 3, 3, 2, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, YACHT));
}

static void test_ones(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 1, 1, 3, 5 } };
   TEST_ASSERT_EQUAL_INT(3, score(dice, ONES));
}

static void test_ones_out_of_order(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 1, 1, 5, 1 } };
   TEST_ASSERT_EQUAL_INT(3, score(dice, ONES));
}

static void test_no_ones(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 4, 3, 6, 5, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, ONES));
}

static void test_twos(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 3, 4, 5, 6 } };
   TEST_ASSERT_EQUAL_INT(2, score(dice, TWOS));
}

static void test_fours(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 4, 1, 4, 1 } };
   TEST_ASSERT_EQUAL_INT(8, score(dice, FOURS));
}

static void test_yacht_counted_as_threes(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 3, 3, 3, 3 } };
   TEST_ASSERT_EQUAL_INT(15, score(dice, THREES));
}

static void test_yacht_of_3s_counted_as_fives(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 3, 3, 3, 3 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, FIVES));
}

static void test_fives(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 5, 3, 5, 3 } };
   TEST_ASSERT_EQUAL_INT(10, score(dice, FIVES));
}

static void test_sixes(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 3, 4, 5, 6 } };
   TEST_ASSERT_EQUAL_INT(6, score(dice, SIXES));
}

static void test_full_house_two_small_three_big(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 2, 4, 4, 4 } };
   TEST_ASSERT_EQUAL_INT(16, score(dice, FULL_HOUSE));
}

static void test_full_house_three_small_two_big(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 5, 3, 3, 5, 3 } };
   TEST_ASSERT_EQUAL_INT(19, score(dice, FULL_HOUSE));
}

static void test_two_pair_is_not_a_full_house(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 2, 4, 4, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, FULL_HOUSE));
}

static void test_four_of_a_kind_is_not_a_full_house(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 4, 4, 4, 4 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, FULL_HOUSE));
}

static void test_yacht_is_not_a_full_house(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 2, 2, 2, 2 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, FULL_HOUSE));
}

static void test_four_of_a_kind(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 6, 6, 4, 6, 6 } };
   TEST_ASSERT_EQUAL_INT(24, score(dice, FOUR_OF_A_KIND));
}

static void test_yacht_can_be_scored_as_four_of_a_kind(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 3, 3, 3, 3 } };
   TEST_ASSERT_EQUAL_INT(12, score(dice, FOUR_OF_A_KIND));
}

static void test_full_house_is_not_four_of_a_kind(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 3, 3, 5, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, FOUR_OF_A_KIND));
}

static void test_little_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 5, 4, 1, 2 } };
   TEST_ASSERT_EQUAL_INT(30, score(dice, LITTLE_STRAIGHT));
}

static void test_little_straight_as_big_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 2, 3, 4, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, BIG_STRAIGHT));
}

static void test_four_in_order_but_not_a_little_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 1, 2, 3, 4 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, LITTLE_STRAIGHT));
}

static void test_no_pairs_but_not_a_little_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 2, 3, 4, 6 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, LITTLE_STRAIGHT));
}

static void test_minimum_is_1_maximum_is_5_but_not_a_little_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 1, 1, 3, 4, 5 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, LITTLE_STRAIGHT));
}

static void test_big_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 4, 6, 2, 5, 3 } };
   TEST_ASSERT_EQUAL_INT(30, score(dice, BIG_STRAIGHT));
}

static void test_big_straight_as_little_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 6, 5, 4, 3, 2 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, LITTLE_STRAIGHT));
}

static void test_no_pairs_but_not_a_big_straight(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 6, 5, 4, 3, 1 } };
   TEST_ASSERT_EQUAL_INT(0, score(dice, BIG_STRAIGHT));
}

static void test_choice(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 3, 3, 5, 6, 6 } };
   TEST_ASSERT_EQUAL_INT(23, score(dice, CHOICE));
}

static void test_yacht_as_choice(void)
{
   TEST_IGNORE();
   const dice_t dice = { { 2, 2, 2, 2, 2 } };
   TEST_ASSERT_EQUAL_INT(10, score(dice, CHOICE));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_yacht);
   RUN_TEST(test_not_yacht);
   RUN_TEST(test_ones);
   RUN_TEST(test_ones_out_of_order);
   RUN_TEST(test_no_ones);
   RUN_TEST(test_twos);
   RUN_TEST(test_fours);
   RUN_TEST(test_yacht_counted_as_threes);
   RUN_TEST(test_yacht_of_3s_counted_as_fives);
   RUN_TEST(test_fives);
   RUN_TEST(test_sixes);
   RUN_TEST(test_full_house_two_small_three_big);
   RUN_TEST(test_full_house_three_small_two_big);
   RUN_TEST(test_two_pair_is_not_a_full_house);
   RUN_TEST(test_four_of_a_kind_is_not_a_full_house);
   RUN_TEST(test_yacht_is_not_a_full_house);
   RUN_TEST(test_four_of_a_kind);
   RUN_TEST(test_yacht_can_be_scored_as_four_of_a_kind);
   RUN_TEST(test_full_house_is_not_four_of_a_kind);
   RUN_TEST(test_little_straight);
   RUN_TEST(test_little_straight_as_big_straight);
   RUN_TEST(test_four_in_order_but_not_a_little_straight);
   RUN_TEST(test_no_pairs_but_not_a_little_straight);
   RUN_TEST(test_minimum_is_1_maximum_is_5_but_not_a_little_straight);
   RUN_TEST(test_big_straight);
   RUN_TEST(test_big_straight_as_little_straight);
   RUN_TEST(test_no_pairs_but_not_a_big_straight);
   RUN_TEST(test_choice);
   RUN_TEST(test_yacht_as_choice);

   return UNITY_END();
}
