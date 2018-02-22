#include "vendor/unity.h"
#include "../src/prime_factors.h"
#include <stdint.h>

static uint64_t buf[MAXFACTORS] = { 0 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_no_factors(void)
{
   size_t expected_len = 0;
   size_t actual_len = find_factors(1, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_prime_number(void)
{
   TEST_IGNORE();               // delete this line to run test
   uint64_t expected_factors[] = { 2 };
   size_t expected_len = 1;
   size_t actual_len = find_factors(2, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

void test_square_of_a_prime(void)
{
   TEST_IGNORE();
   uint64_t expected_factors[] = { 3, 3 };
   size_t expected_len = 2;
   size_t actual_len = find_factors(9, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

void test_cube_of_a_prime(void)
{
   TEST_IGNORE();
   uint64_t expected_factors[] = { 2, 2, 2 };
   size_t expected_len = 3;
   size_t actual_len = find_factors(8, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

void test_product_of_primes_and_non_primes(void)
{
   TEST_IGNORE();
   uint64_t expected_factors[] = { 2, 2, 3 };
   size_t expected_len = 3;
   size_t actual_len = find_factors(12, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

void test_product_of_primes(void)
{
   TEST_IGNORE();
   uint64_t expected_factors[] = { 5, 17, 23, 461 };
   size_t expected_len = 4;
   size_t actual_len = find_factors(901255, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

void test_factors_include_a_large_prime(void)
{
   TEST_IGNORE();
   uint64_t expected_factors[] = { 11, 9539, 894119 };
   size_t expected_len = 3;
   size_t actual_len = find_factors(93819012551, buf);
   TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
   TEST_ASSERT_EQUAL_INT64_ARRAY(expected_factors, buf, expected_len);
}

int main(void)
{
   UnityBegin("test/test_prime_factors.c");

   RUN_TEST(test_no_factors);
   RUN_TEST(test_prime_number);
   RUN_TEST(test_square_of_a_prime);
   RUN_TEST(test_cube_of_a_prime);
   RUN_TEST(test_product_of_primes_and_non_primes);
   RUN_TEST(test_product_of_primes);
   RUN_TEST(test_factors_include_a_large_prime);

   UnityEnd();
   return 0;
}
