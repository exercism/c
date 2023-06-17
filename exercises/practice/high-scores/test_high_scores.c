#include "test-framework/unity.h"
#include "high_scores.h"
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define TOP_SCORES_ARRAY_SIZE (3)

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_personal_top_three(const int32_t *scores, size_t scores_len,
                                     const int32_t *expected,
                                     size_t expected_len)
{
   int32_t top_scores[TOP_SCORES_ARRAY_SIZE] = { 0 };

   size_t actual_len = personal_top_three(scores, scores_len, top_scores);

   TEST_ASSERT_EQUAL_INT32(expected_len, actual_len);

   if (expected_len > 0) {
      TEST_ASSERT_EQUAL_INT32_ARRAY(expected, top_scores, expected_len);
   }
}

static void test_latest_score(void)
{
   const int scores[] = { 100, 0, 90, 30 };
   TEST_ASSERT_EQUAL_INT(latest(scores, ARRAY_SIZE(scores)), 30);
}

static void test_personal_best(void)
{
   TEST_IGNORE();   // delete this line to run test
   const int scores[] = { 40, 100, 70 };
   TEST_ASSERT_EQUAL_INT(personal_best(scores, ARRAY_SIZE(scores)), 100);
}

static void test_personal_top_three_from_a_list_of_scores(void)
{
   TEST_IGNORE();
   const int scores[] = { 10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70 };
   const int expected[] = { 100, 90, 70 };
   check_personal_top_three(scores, ARRAY_SIZE(scores), expected,
                            ARRAY_SIZE(expected));
}

static void test_personal_top_highest_to_lowest(void)
{
   TEST_IGNORE();
   const int scores[] = { 20, 10, 30 };
   const int expected[] = { 30, 20, 10 };
   check_personal_top_three(scores, ARRAY_SIZE(scores), expected,
                            ARRAY_SIZE(expected));
}

static void test_personal_top_when_there_is_a_tie(void)
{
   TEST_IGNORE();
   const int scores[] = { 40, 20, 40, 30 };
   const int expected[] = { 40, 40, 30 };
   check_personal_top_three(scores, ARRAY_SIZE(scores), expected,
                            ARRAY_SIZE(expected));
}

static void test_personal_top_when_there_are_less_than_3(void)
{
   TEST_IGNORE();
   const int scores[] = { 30, 70 };
   const int expected[] = { 70, 30 };
   check_personal_top_three(scores, ARRAY_SIZE(scores), expected,
                            ARRAY_SIZE(expected));
}

static void test_personal_top_when_there_is_only_one(void)
{
   TEST_IGNORE();
   const int scores[] = { 40 };
   const int expected[] = { 40 };
   check_personal_top_three(scores, ARRAY_SIZE(scores), expected,
                            ARRAY_SIZE(expected));
}

int main(void)
{
   UnityBegin("test_high_scores.c");

   RUN_TEST(test_latest_score);
   RUN_TEST(test_personal_best);
   RUN_TEST(test_personal_top_three_from_a_list_of_scores);
   RUN_TEST(test_personal_top_highest_to_lowest);
   RUN_TEST(test_personal_top_when_there_is_a_tie);
   RUN_TEST(test_personal_top_when_there_are_less_than_3);
   RUN_TEST(test_personal_top_when_there_is_only_one);

   return UnityEnd();
}
