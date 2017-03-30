#include "vendor/unity.h"
#include "../src/perfect_numbers.h"

void test_smallest_perfect_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(6) == perfect_number);
}

void test_medium_perfect_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(28) == perfect_number);
}

void test_large_perfect_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(33550336) == perfect_number);
}

void test_smallest_abundant_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(12) == abundant_number);
}

void test_medium_abundant_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(30) == abundant_number);
}

void test_large_abundant_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(33550335) == abundant_number);
}

void test_smallest_prime_deficient_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(2) == deficient_number);
}

void test_smallest_non_prime_deficient_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(4) == deficient_number);
}

void test_medium_deficient_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(32) == deficient_number);
}

void test_large_deficient_number_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(33550337) == deficient_number);
}

void test_edge_case_is_classified_correctly(void)
{
   TEST_ASSERT_TRUE(classify_number(1) == deficient_number);
}

void test_zero_is_rejected(void)
{
   TEST_ASSERT_TRUE(classify_number(0) == error);
}

void test_negative_integer_is_rejected(void)
{
   TEST_ASSERT_TRUE(classify_number(-1) == error);
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
