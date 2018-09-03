#include <string.h>
#include "vendor/unity.h"
#include "../src/sieve.h"

static primes_array_t result_array;
#define ARRAY_LENGTH(x)   sizeof(x)/sizeof(x[0])

void setUp(void)
{
}

void tearDown(void)
{
}

void test_no_primes_under_two(void)
{
   const unsigned int limit = 1;
   const unsigned int expected_prime_count = 0;
   unsigned int result_prime_count;

   memset(result_array, 0, sizeof(result_array));

   result_prime_count = sieve(limit, result_array);
   TEST_ASSERT_EQUAL(expected_prime_count, result_prime_count);
}

void test_find_first_prime(void)
{
   TEST_IGNORE();               // delete this line to run test
   const unsigned int limit = 2;
   const primes_array_t expected_prime_array = { 2 };
   const unsigned int expected_prime_count = 1;
   unsigned int result_prime_count;

   memset(result_array, 0, sizeof(result_array));

   result_prime_count = sieve(limit, result_array);
   TEST_ASSERT_EQUAL(expected_prime_count, result_prime_count);
   TEST_ASSERT_EQUAL_UINT_ARRAY(expected_prime_array, result_array,
                                ARRAY_LENGTH(expected_prime_array));

}

void test_find_primes_up_to_10(void)
{
   TEST_IGNORE();
   const unsigned int limit = 10;
   const primes_array_t expected_prime_array = { 2, 3, 5, 7 };
   const unsigned int expected_prime_count = 4;
   unsigned int result_prime_count;

   memset(result_array, 0, sizeof(result_array));

   result_prime_count = sieve(limit, result_array);
   TEST_ASSERT_EQUAL(expected_prime_count, result_prime_count);
   TEST_ASSERT_EQUAL_UINT_ARRAY(expected_prime_array, result_array,
                                ARRAY_LENGTH(expected_prime_array));

}

void test_limit_is_prime(void)
{
   TEST_IGNORE();
   const unsigned int limit = 13;
   const primes_array_t expected_prime_array = { 2, 3, 5, 7, 11, 13 };
   const unsigned int expected_prime_count = 6;
   unsigned int result_prime_count;

   memset(result_array, 0, sizeof(result_array));

   result_prime_count = sieve(limit, result_array);
   TEST_ASSERT_EQUAL(expected_prime_count, result_prime_count);
   TEST_ASSERT_EQUAL_UINT_ARRAY(expected_prime_array, result_array,
                                ARRAY_LENGTH(expected_prime_array));

}

void test_find_primes_up_to_1000(void)
{
   TEST_IGNORE();
   const unsigned int limit = 1000;
   const primes_array_t expected_prime_array = {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
      61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,
      131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
      197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
      271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
      353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431,
      433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
      509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
      601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673,
      677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761,
      769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857,
      859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947,
      953, 967, 971, 977, 983, 991, 997
   };
   const unsigned int expected_prime_count = 168;
   unsigned int result_prime_count;

   memset(result_array, 0, sizeof(result_array));

   result_prime_count = sieve(limit, result_array);
   TEST_ASSERT_EQUAL(expected_prime_count, result_prime_count);
   TEST_ASSERT_EQUAL_UINT_ARRAY(expected_prime_array, result_array,
                                ARRAY_LENGTH(expected_prime_array));

}

int main(void)
{
   UnityBegin("test/test_sieve.c");

   RUN_TEST(test_no_primes_under_two);
   RUN_TEST(test_find_first_prime);
   RUN_TEST(test_find_primes_up_to_10);
   RUN_TEST(test_limit_is_prime);
   RUN_TEST(test_find_primes_up_to_1000);

   UnityEnd();
   return 0;
}
