#include "test-framework/unity.h"
#include "perfect_numbers.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_smallest_perfect_number_is_classified_correctly(void)
{
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(6));
}

static void test_medium_perfect_number_is_classified_correctly(void)
{
   TEST_IGNORE();   // delete this line to run test
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(28));
}

static void test_large_perfect_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(33550336));
}

static void test_smallest_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(12));
}

static void test_medium_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(30));
}

static void test_large_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(33550335));
}

static void test_smallest_prime_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(2));
}

static void
test_smallest_non_prime_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(4));
}

static void test_medium_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(32));
}

static void test_large_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(33550337));
}

static void test_edge_case_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(1));
}

static void test_zero_is_rejected(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ERROR, classify_number(0));
}

static void test_negative_integer_is_rejected(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ERROR, classify_number(-1));
}

int main(void)
{
   UnityBegin("test_perfect_numbers.c");

   RUN_TEST(test_smallest_perfect_number_is_classified_correctly);
   RUN_TEST(test_medium_perfect_number_is_classified_correctly);
   RUN_TEST(test_large_perfect_number_is_classified_correctly);
   RUN_TEST(test_smallest_abundant_number_is_classified_correctly);
   RUN_TEST(test_medium_abundant_number_is_classified_correctly);
   RUN_TEST(test_large_abundant_number_is_classified_correctly);
   RUN_TEST(test_smallest_prime_deficient_number_is_classified_correctly);
   RUN_TEST(test_smallest_non_prime_deficient_number_is_classified_correctly);
   RUN_TEST(test_medium_deficient_number_is_classified_correctly);
   RUN_TEST(test_large_deficient_number_is_classified_correctly);
   RUN_TEST(test_edge_case_is_classified_correctly);
   RUN_TEST(test_zero_is_rejected);
   RUN_TEST(test_negative_integer_is_rejected);

   return UnityEnd();
}
