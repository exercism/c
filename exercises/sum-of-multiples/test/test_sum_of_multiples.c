#include "vendor/unity.h"
#include "../src/sum_of_multiples.h"

#define NUM_OF_ELEMENTS(a)    (sizeof(a) / sizeof(a[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sum_of_multiples_of_3_and_5_up_to_1(void)
{
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(0,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      1));
}

void test_sum_of_multiples_of_3_and_5_up_to_4(void)
{
   TEST_IGNORE();               // delete this line to run test
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(3,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      4));
}

void test_sum_of_multiples_of_3_and_5_up_to_10(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(23,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      10));
}

void test_sum_of_multiples_of_3_and_5_up_to_100(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(2318,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      100));
}

void test_sum_of_multiples_of_3_and_5_up_to_1000(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 3, 5 };
   TEST_ASSERT_EQUAL(233168,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      1000));
}

void test_sum_of_multiples_of_7_13_and_17_up_to_20(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 7, 13, 17 };
   TEST_ASSERT_EQUAL(51,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      20));
}

void test_sum_of_multiples_of_4_and_6_up_to_15(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 4, 6 };
   TEST_ASSERT_EQUAL(30,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      15));
}

void test_sum_of_multiples_of_5_6_and_8_up_to_150(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 5, 6, 8 };
   TEST_ASSERT_EQUAL(4419,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      150));
}

void test_sum_of_multiples_of_5_and_25_up_to_51(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 5, 25 };
   TEST_ASSERT_EQUAL(275,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      51));
}

void test_sum_of_multiples_of_43_and_47_up_to_10000(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 43, 47 };
   TEST_ASSERT_EQUAL(2203160,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      10000));
}

void test_sum_of_multiples_of_1_up_to_100(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 1 };
   TEST_ASSERT_EQUAL(4950,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      100));
}

void test_sum_of_multiples_of_0_up_to_100(void)
{
   TEST_IGNORE();
   const unsigned int multiples[] = { 0 };
   TEST_ASSERT_EQUAL(0,
                     sum_of_multiples(multiples, NUM_OF_ELEMENTS(multiples),
                                      100));
}

void test_no_multiples_given(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, sum_of_multiples(NULL, 0, 10000));
}

void test_null_ptr_multiple(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, sum_of_multiples(NULL, 3, 10000));
}

int main(void)
{
   UnityBegin("test/test_sum_of_multiples.c");

   RUN_TEST(test_sum_of_multiples_of_3_and_5_up_to_1);
   RUN_TEST(test_sum_of_multiples_of_3_and_5_up_to_4);
   RUN_TEST(test_sum_of_multiples_of_3_and_5_up_to_10);
   RUN_TEST(test_sum_of_multiples_of_3_and_5_up_to_100);
   RUN_TEST(test_sum_of_multiples_of_3_and_5_up_to_1000);
   RUN_TEST(test_sum_of_multiples_of_7_13_and_17_up_to_20);
   RUN_TEST(test_sum_of_multiples_of_4_and_6_up_to_15);
   RUN_TEST(test_sum_of_multiples_of_5_6_and_8_up_to_150);
   RUN_TEST(test_sum_of_multiples_of_5_and_25_up_to_51);
   RUN_TEST(test_sum_of_multiples_of_43_and_47_up_to_10000);
   RUN_TEST(test_sum_of_multiples_of_1_up_to_100);
   RUN_TEST(test_sum_of_multiples_of_0_up_to_100);
   RUN_TEST(test_no_multiples_given);
   RUN_TEST(test_null_ptr_multiple);

   UnityEnd();
   return 0;
}
