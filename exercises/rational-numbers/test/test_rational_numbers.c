#include "vendor/unity.h"
#include "../src/rational_numbers.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_rational_numbers_equal(rational_t expected, rational_t actual)
{
   TEST_ASSERT_EQUAL_INT16(expected.numerator, actual.numerator);
   TEST_ASSERT_EQUAL_INT16(expected.denominator, actual.denominator);
}

static void test_add_two_positive_rational_numbers(void)
{
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 2, 3 };
   rational_t expected = { 7, 6 };
   rational_t actual = add(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_add_positive_and_negative_rational_numbers(void)
{
   TEST_IGNORE();               // delete this line to run test
   rational_t r1 = { 1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { -1, 6 };
   rational_t actual = add(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_add_two_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { -1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { -7, 6 };
   rational_t actual = add(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_add_rational_number_to_additive_inverse(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { -1, 2 };
   rational_t expected = { 0, 1 };
   rational_t actual = add(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_subtract_two_positive_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 2, 3 };
   rational_t expected = { -1, 6 };
   rational_t actual = sub(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_subtract_positive_and_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { 7, 6 };
   rational_t actual = sub(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_subtract_two_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { -1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { 1, 6 };
   rational_t actual = sub(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_subtract_rational_number_from_itself(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 1, 2 };
   rational_t expected = { 0, 1 };
   rational_t actual = sub(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_two_positive_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 2, 3 };
   rational_t expected = { 1, 3 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_positive_and_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { -1, 2 };
   rational_t r2 = { 2, 3 };
   rational_t expected = { -1, 3 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_two_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { -1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { 1, 3 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_rational_number_by_reciprocal(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 2, 1 };
   rational_t expected = { 1, 1 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_rational_number_by_one(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 1, 1 };
   rational_t expected = { 1, 2 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_multiply_rational_number_by_zero(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 0, 1 };
   rational_t expected = { 0, 1 };
   rational_t actual = mul(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_divide_two_positive_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 2, 3 };
   rational_t expected = { 3, 4 };
   rational_t actual = div(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_divide_positive_and_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { -3, 4 };
   rational_t actual = div(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_divide_two_negative_rational_numbers(void)
{
   TEST_IGNORE();
   rational_t r1 = { -1, 2 };
   rational_t r2 = { -2, 3 };
   rational_t expected = { 3, 4 };
   rational_t actual = div(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_divide_rational_number_by_one(void)
{
   TEST_IGNORE();
   rational_t r1 = { 1, 2 };
   rational_t r2 = { 1, 1 };
   rational_t expected = { 1, 2 };
   rational_t actual = div(r1, r2);
   check_rational_numbers_equal(expected, actual);
}

static void test_absolute_value_of_positive_rational_number(void)
{
   TEST_IGNORE();
   rational_t r = { 1, 2 };
   rational_t expected = { 1, 2 };
   rational_t actual = abs(r);
   check_rational_numbers_equal(expected, actual);
}

static void
    test_absolute_value_of_positive_rational_with_negative_numerator_and_denominator
    (void) {
   TEST_IGNORE();
   rational_t r = { -1, -2 };
   rational_t expected = { 1, 2 };
   rational_t actual = abs(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_absolute_value_of_negative_rational_number(void)
{
   TEST_IGNORE();
   rational_t r = { -1, 2 };
   rational_t expected = { 1, 2 };
   rational_t actual = abs(r);
   check_rational_numbers_equal(expected, actual);
}

static void
test_absolute_value_of_negative_rational_number_with_negative_denominator(void)
{
   TEST_IGNORE();
   rational_t r = { 1, -2 };
   rational_t expected = { 1, 2 };
   rational_t actual = abs(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_absolute_value_of_zero(void)
{
   TEST_IGNORE();
   rational_t r = { 0, 1 };
   rational_t expected = { 0, 1 };
   rational_t actual = abs(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_positive_rational_number_to_integer_power(void)
{
   TEST_IGNORE();
   rational_t r = { 1, 2 };
   uint16_t n = 3;
   rational_t expected = { 1, 8 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_negative_rational_number_to_integer_power(void)
{
   TEST_IGNORE();
   rational_t r = { -1, 2 };
   uint16_t n = 3;
   rational_t expected = { -1, 8 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_zero_to_integer_power(void)
{
   TEST_IGNORE();
   rational_t r = { 0, 1 };
   uint16_t n = 5;
   rational_t expected = { 0, 1 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_one_to_integer_power(void)
{
   TEST_IGNORE();
   rational_t r = { 1, 2 };
   uint16_t n = 3;
   rational_t expected = { 1, 8 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_positive_rational_number_to_power_of_zero(void)
{
   TEST_IGNORE();
   rational_t r = { 1, 2 };
   uint16_t n = 0;
   rational_t expected = { 1, 1 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_negative_rational_number_to_power_of_zero(void)
{
   TEST_IGNORE();
   rational_t r = { -1, 2 };
   uint16_t n = 0;
   rational_t expected = { 1, 1 };
   rational_t actual = exp_rational(r, n);
   check_rational_numbers_equal(expected, actual);
}

static void test_raise_real_number_to_positive_rational_number(void)
{
   TEST_IGNORE();
   uint16_t x = 8;
   rational_t r = { 4, 3 };
   float delta = 0.05;
   float expected = 16.0;
   float actual = exp_real(x, r);
   TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual);
}

static void test_raise_real_number_to_negative_rational_number(void)
{
   TEST_IGNORE();
   uint16_t x = 9;
   rational_t r = { -1, 2 };
   float delta = 0.000005;
   float expected = 0.3333333333333333;
   float actual = exp_real(x, r);
   TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual);
}

static void test_raise_real_number_to_zero_rational_number(void)
{
   TEST_IGNORE();
   uint16_t x = 2;
   rational_t r = { 0, 0 };
   float delta = 0.000005;
   float expected = 1.0;
   float actual = exp_real(x, r);
   TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual);
}

static void test_reduce_positive_rational_number_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { 2, 4 };
   rational_t expected = { 1, 2 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_reduce_negative_rational_number_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { -4, 6 };
   rational_t expected = { -2, 3 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

static void
test_reduce_rational_number_with_negative_denominator_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { 3, -9 };
   rational_t expected = { -1, 3 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_reduce_zero_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { 0, 6 };
   rational_t expected = { 0, 1 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_reduce_integer_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { -14, 7 };
   rational_t expected = { -2, 1 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

static void test_reduce_one_to_lowest_terms(void)
{
   TEST_IGNORE();
   rational_t r = { 13, 13 };
   rational_t expected = { 1, 1 };
   rational_t actual = reduce(r);
   check_rational_numbers_equal(expected, actual);
}

int main(void)
{
   UnityBegin("test/test_rational_numbers.c");

   RUN_TEST(test_add_two_positive_rational_numbers);
   RUN_TEST(test_add_positive_and_negative_rational_numbers);
   RUN_TEST(test_add_two_negative_rational_numbers);
   RUN_TEST(test_add_rational_number_to_additive_inverse);
   RUN_TEST(test_subtract_two_positive_rational_numbers);
   RUN_TEST(test_subtract_positive_and_negative_rational_numbers);
   RUN_TEST(test_subtract_two_negative_rational_numbers);
   RUN_TEST(test_subtract_rational_number_from_itself);
   RUN_TEST(test_multiply_two_positive_rational_numbers);
   RUN_TEST(test_multiply_positive_and_negative_rational_numbers);
   RUN_TEST(test_multiply_two_negative_rational_numbers);
   RUN_TEST(test_multiply_rational_number_by_reciprocal);
   RUN_TEST(test_multiply_rational_number_by_one);
   RUN_TEST(test_multiply_rational_number_by_zero);
   RUN_TEST(test_divide_two_positive_rational_numbers);
   RUN_TEST(test_divide_positive_and_negative_rational_numbers);
   RUN_TEST(test_divide_two_negative_rational_numbers);
   RUN_TEST(test_divide_rational_number_by_one);
   RUN_TEST(test_absolute_value_of_positive_rational_number);
   RUN_TEST
       (test_absolute_value_of_positive_rational_with_negative_numerator_and_denominator);
   RUN_TEST(test_absolute_value_of_negative_rational_number);
   RUN_TEST
       (test_absolute_value_of_negative_rational_number_with_negative_denominator);
   RUN_TEST(test_absolute_value_of_zero);
   RUN_TEST(test_raise_positive_rational_number_to_integer_power);
   RUN_TEST(test_raise_negative_rational_number_to_integer_power);
   RUN_TEST(test_raise_zero_to_integer_power);
   RUN_TEST(test_raise_one_to_integer_power);
   RUN_TEST(test_raise_positive_rational_number_to_power_of_zero);
   RUN_TEST(test_raise_negative_rational_number_to_power_of_zero);
   RUN_TEST(test_raise_real_number_to_positive_rational_number);
   RUN_TEST(test_raise_real_number_to_negative_rational_number);
   RUN_TEST(test_raise_real_number_to_zero_rational_number);
   RUN_TEST(test_reduce_positive_rational_number_to_lowest_terms);
   RUN_TEST(test_reduce_negative_rational_number_to_lowest_terms);
   RUN_TEST
       (test_reduce_rational_number_with_negative_denominator_to_lowest_terms);
   RUN_TEST(test_reduce_zero_to_lowest_terms);
   RUN_TEST(test_reduce_integer_to_lowest_terms);
   RUN_TEST(test_reduce_one_to_lowest_terms);

   return UnityEnd();
}
