#include "vendor/unity.h"
#include "../src/perfect_numbers.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_smallest_perfect_number_is_classified_correctly(void)
{
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(6));
}

void test_medium_perfect_number_is_classified_correctly(void)
{
   TEST_IGNORE();               // delete this line to run test
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(28));
}

void test_large_perfect_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(PERFECT_NUMBER, classify_number(33550336));
}

void test_smallest_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(12));
}

void test_medium_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(30));
}

void test_large_abundant_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ABUNDANT_NUMBER, classify_number(33550335));
}

void test_smallest_prime_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(2));
}

void test_smallest_non_prime_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(4));
}

void test_medium_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(32));
}

void test_large_deficient_number_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(33550337));
}

void test_edge_case_is_classified_correctly(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(DEFICIENT_NUMBER, classify_number(1));
}

void test_zero_is_rejected(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ERROR, classify_number(0));
}

void test_negative_integer_is_rejected(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(ERROR, classify_number(-1));
}

int main(void)
{
   UnityBegin("test/test_perfect_numbers.c");

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

   UnityEnd();
   return 0;
}
