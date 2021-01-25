#include "vendor/unity.h"
#include "../src/sum_of_multiples.h"

#define NUM_OF_ELEMENTS(a)    (sizeof(a) / sizeof(a[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_no_multiples_within_limit(void)
{
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1));
}

static void test_one_factor_has_multiples_within_limit(void)
{
   TEST_IGNORE();               // delete this line to run test
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(3, sum(multiples, NUM_OF_ELEMENTS(multiples), 4));
}

static void test_more_than_one_multiple_withiin_limit(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3 };
   TEST_ASSERT_EQUAL(9, sum(multiples, NUM_OF_ELEMENTS(multiples), 7));
}

static void test_more_than_one_factor_with_multiples_within_limit(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(23, sum(multiples, NUM_OF_ELEMENTS(multiples), 10));
}

static void test_each_multiple_is_only_counted_once(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(2318, sum(multiples, NUM_OF_ELEMENTS(multiples), 100));
}

static void test_a_much_larger_limit(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(233168, sum(multiples, NUM_OF_ELEMENTS(multiples), 1000));
}

static void test_three_factors(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 7, 13, 17 };
   TEST_ASSERT_EQUAL(51, sum(multiples, NUM_OF_ELEMENTS(multiples), 20));
}

static void test_factors_not_relatively_prime(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 4, 6 };
   TEST_ASSERT_EQUAL(30, sum(multiples, NUM_OF_ELEMENTS(multiples), 15));
}

static void test_some_pairs_of_factors_relatively_prime_and_some_not(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 5, 6, 8 };
   TEST_ASSERT_EQUAL(4419, sum(multiples, NUM_OF_ELEMENTS(multiples), 150));
}

static void test_one_factor_is_a_multiple_of_another(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 5, 25 };
   TEST_ASSERT_EQUAL(275, sum(multiples, NUM_OF_ELEMENTS(multiples), 51));
}

static void test_much_larger_factors(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 43, 47 };
   TEST_ASSERT_EQUAL(2203160,
                     sum(multiples, NUM_OF_ELEMENTS(multiples), 10000));
}

static void test_all_numbers_are_multiples_of_1(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 1 };
   TEST_ASSERT_EQUAL(4950, sum(multiples, NUM_OF_ELEMENTS(multiples), 100));
}

static void test_no_factors_means_an_empty_sum(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 0 };
   TEST_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1000));
}

static void test_the_only_multiple_of_zero_is_zero(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 0 };
   TEST_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1));
}

static void
test_the_factor_0_does_not_affect_the_sum_of_multiples_of_other_factors(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 0 };
   TEST_ASSERT_EQUAL(3, sum(multiples, NUM_OF_ELEMENTS(multiples), 4));
}

static void
 test_solutions_using_include_exclude_must_extend_to_cardinality_greater_than_3
    (void) {
   TEST_IGNORE();
   const unsigned int multiples[] = { 2, 3, 5, 7, 11 };
   TEST_ASSERT_EQUAL(39614537,
                     sum(multiples, NUM_OF_ELEMENTS(multiples), 10000));
}

int main(void)
{
   UnityBegin("test/test_sum_of_multiples.c");

   RUN_TEST(test_no_multiples_within_limit);
   RUN_TEST(test_one_factor_has_multiples_within_limit);
   RUN_TEST(test_more_than_one_multiple_withiin_limit);
   RUN_TEST(test_more_than_one_factor_with_multiples_within_limit);
   RUN_TEST(test_each_multiple_is_only_counted_once);
   RUN_TEST(test_a_much_larger_limit);
   RUN_TEST(test_three_factors);
   RUN_TEST(test_factors_not_relatively_prime);
   RUN_TEST(test_some_pairs_of_factors_relatively_prime_and_some_not);
   RUN_TEST(test_one_factor_is_a_multiple_of_another);
   RUN_TEST(test_much_larger_factors);
   RUN_TEST(test_all_numbers_are_multiples_of_1);
   RUN_TEST(test_no_factors_means_an_empty_sum);
   RUN_TEST(test_the_only_multiple_of_zero_is_zero);
   RUN_TEST
       (test_the_factor_0_does_not_affect_the_sum_of_multiples_of_other_factors);
   RUN_TEST
       (test_solutions_using_include_exclude_must_extend_to_cardinality_greater_than_3);

   return UnityEnd();
}
