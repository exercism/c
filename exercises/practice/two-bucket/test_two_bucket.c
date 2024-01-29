#include "test-framework/unity.h"
#include "two_bucket.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void assert_results_match(bucket_result_t expected,
                                 bucket_result_t actual)
{
   TEST_ASSERT_EQUAL(expected.possible, actual.possible);

   if (expected.possible) {
      TEST_ASSERT_EQUAL(expected.move_count, actual.move_count);
      TEST_ASSERT_EQUAL(expected.goal_bucket, actual.goal_bucket);
      TEST_ASSERT_EQUAL(expected.other_bucket_liters,
                        actual.other_bucket_liters);
   }
}

static void
test_measure_using_bucket_one_of_size_3_and_bucket_two_of_size_5_start_with_bucket_one(
    void)
{
   bucket_result_t expected = { .possible = true,
                                .move_count = 4,
                                .goal_bucket = BUCKET_ID_1,
                                .other_bucket_liters = 5 };
   bucket_result_t actual = measure(3, 5, 1, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

static void
test_measure_using_bucket_one_of_size_3_and_bucket_two_of_size_5_start_with_bucket_two(
    void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 8,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters = 3 };
   bucket_result_t actual = measure(3, 5, 1, BUCKET_ID_2);
   assert_results_match(expected, actual);
}

static void
test_measure_using_bucket_one_of_size_7_and_bucket_two_of_size_11_start_with_bucket_one(
    void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 14,
                                .goal_bucket = BUCKET_ID_1,
                                .other_bucket_liters = 11 };
   bucket_result_t actual = measure(7, 11, 2, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

static void
test_measure_using_bucket_one_of_size_7_and_bucket_two_of_size_11_start_with_bucket_two(
    void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 18,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters = 7 };
   bucket_result_t actual = measure(7, 11, 2, BUCKET_ID_2);
   assert_results_match(expected, actual);
}

static void
test_measure_one_step_using_bucket_one_of_size_1_and_bucket_two_of_size_3_start_with_bucket_two(
    void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 1,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters = 0 };
   bucket_result_t actual = measure(1, 3, 3, BUCKET_ID_2);
   assert_results_match(expected, actual);
}

static void
test_measure_using_bucket_one_of_size_2_and_bucket_two_of_size_3_start_with_bucket_one_and_end_with_bucket_two(
    void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 2,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters = 2 };
   bucket_result_t actual = measure(2, 3, 3, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

static void test_not_possible_to_reach_the_goal(void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = false };
   bucket_result_t actual = measure(6, 15, 5, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

static void
test_with_the_same_buckets_but_a_different_goal_then_it_is_possible(void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = true,
                                .move_count = 10,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters = 0 };
   bucket_result_t actual = measure(6, 15, 9, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

static void test_goal_larger_than_both_buckets_is_impossible(void)
{
   TEST_IGNORE();
   bucket_result_t expected = { .possible = false };
   bucket_result_t actual = measure(5, 7, 8, BUCKET_ID_1);
   assert_results_match(expected, actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(
       test_measure_using_bucket_one_of_size_3_and_bucket_two_of_size_5_start_with_bucket_one);
   RUN_TEST(
       test_measure_using_bucket_one_of_size_3_and_bucket_two_of_size_5_start_with_bucket_two);
   RUN_TEST(
       test_measure_using_bucket_one_of_size_7_and_bucket_two_of_size_11_start_with_bucket_one);
   RUN_TEST(
       test_measure_using_bucket_one_of_size_7_and_bucket_two_of_size_11_start_with_bucket_two);
   RUN_TEST(
       test_measure_one_step_using_bucket_one_of_size_1_and_bucket_two_of_size_3_start_with_bucket_two);
   RUN_TEST(
       test_measure_using_bucket_one_of_size_2_and_bucket_two_of_size_3_start_with_bucket_one_and_end_with_bucket_two);
   RUN_TEST(test_not_possible_to_reach_the_goal);
   RUN_TEST(
       test_with_the_same_buckets_but_a_different_goal_then_it_is_possible);
   RUN_TEST(test_goal_larger_than_both_buckets_is_impossible);

   return UNITY_END();
}
