#include "../src/complex_numbers.h"

#include "vendor/unity.h"

#include <math.h>

#define PI acos(-1)
#define E exp(1)

void compare_complex(complex_t lhs, complex_t rhs)
{
   TEST_ASSERT_EQUAL(lhs.real, rhs.real);
   TEST_ASSERT_EQUAL(lhs.imag, rhs.imag);
}

void test_imaginary_unit(void)
{
   complex_t z = {.real = 0.0,.imag = 1.0 };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t result = c_mul(z, z);

   compare_complex(result, expected);
}

void test_add_purely_real_numbers(void)
{
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 3.0,.imag = 0.0 };
   complex_t result = c_add(z1, z2);

   compare_complex(result, expected);
}

void test_add_purely_imaginary_numbers(void)
{
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.0,.imag = 3.0 };
   complex_t result = c_add(z1, z2);

   compare_complex(result, expected);
}

void test_add_numbers_with_real_and_imaginary_part(void)
{
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = 4.0,.imag = 6.0 };
   complex_t result = c_add(z1, z2);

   compare_complex(result, expected);
}

void test_subtract_purely_real_numbers(void)
{
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t result = c_sub(z1, z2);

   compare_complex(result, expected);
}

void test_subtract_purely_imaginary_numbers(void)
{
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.0,.imag = -1.0 };
   complex_t result = c_sub(z1, z2);

   compare_complex(result, expected);
}

void test_subtract_numbers_with_real_and_imaginary_part(void)
{
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = -2.0,.imag = -2.0 };
   complex_t result = c_sub(z1, z2);

   compare_complex(result, expected);
}

void test_multiply_purely_real_numbers(void)
{
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 2.0,.imag = 0.0 };
   complex_t result = c_mul(z1, z2);

   compare_complex(result, expected);
}

void test_multiply_purely_imaginary_numbers(void)
{
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = -2.0,.imag = 0.0 };
   complex_t result = c_mul(z1, z2);

   compare_complex(result, expected);
}

void test_multiply_numbers_with_real_and_imaginary_part(void)
{
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = -5.0,.imag = 10.0 };
   complex_t result = c_mul(z1, z2);

   compare_complex(result, expected);
}

void test_divide_purely_real_numbers(void)
{
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 0.5,.imag = 0.0 };
   complex_t result = c_div(z1, z2);

   compare_complex(result, expected);
}

void test_divide_purely_imaginary_numbers(void)
{
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.5,.imag = 0.0 };
   complex_t result = c_div(z1, z2);

   compare_complex(result, expected);
}

void test_divide_numbers_with_real_and_imaginary_part(void)
{
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = 0.44,.imag = 0.08 };
   complex_t result = c_div(z1, z2);

   compare_complex(result, expected);
}

void test_abs_of_a_positive_purely_real_number(void)
{
   complex_t z = {.real = 5.0,.imag = 0.0 };

   double expected = 5.0;
   double result = c_abs(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_abs_of_a_negative_purely_real_number(void)
{
   complex_t z = {.real = -5.0,.imag = 0.0 };

   double expected = 5.0;
   double result = c_abs(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_abs_of_a_purely_imaginary_number_with_positive_imaginary_part(void) {
   complex_t z = {.real = 0.0,.imag = 5.0 };

   double expected = 5.0;
   double result = c_abs(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_abs_of_a_purely_imaginary_number_with_negative_imaginary_part(void) {
   complex_t z = {.real = 0.0,.imag = -5.0 };

   double expected = 5.0;
   double result = c_abs(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_abs_of_a_number_with_real_and_imaginary_part(void)
{
   complex_t z = {.real = 3.0,.imag = 4.0 };

   double expected = 5.0;
   double result = c_abs(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_complex_conjugate_of_a_purely_real_number(void)
{
   complex_t z = {.real = 5.0,.imag = 0.0 };

   complex_t expected = {.real = 5.0,.imag = 0.0 };
   complex_t result = c_conjugate(z);

   compare_complex(result, expected);
}

void test_complex_conjugate_of_a_purely_imaginary_number(void)
{
   complex_t z = {.real = 0.0,.imag = 5.0 };

   complex_t expected = {.real = 0.0,.imag = -5.0 };
   complex_t result = c_conjugate(z);

   compare_complex(result, expected);
}

void test_complex_conjugate_of_a_number_with_real_and_imaginary_part(void)
{
   complex_t z = {.real = 1.0,.imag = 1.0 };

   complex_t expected = {.real = 1.0,.imag = -1.0 };
   complex_t result = c_conjugate(z);

   compare_complex(result, expected);
}

void test_real_part_of_a_purely_real_number(void)
{
   complex_t z = {.real = 1.0,.imag = 0.0 };

   double expected = 1.0;
   double result = c_real(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_real_part_of_a_purely_imaginary_number(void)
{
   complex_t z = {.real = 0.0,.imag = 1.0 };

   double expected = 0.0;
   double result = c_real(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_real_part_of_a_number_with_real_and_imaginary_part(void)
{
   complex_t z = {.real = 1.0,.imag = 2.0 };

   double expected = 1.0;
   double result = c_real(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_imaginary_part_of_a_purely_real_number(void)
{
   complex_t z = {.real = 1.0,.imag = 0.0 };

   double expected = 0.0;
   double result = c_imag(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_imaginary_part_of_a_purely_imaginary_number(void)
{
   complex_t z = {.real = 0.0,.imag = 1.0 };

   double expected = 1.0;
   double result = c_imag(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_imaginary_part_of_a_number_with_real_and_imaginary_part(void)
{
   complex_t z = {.real = 1.0,.imag = 2.0 };

   double expected = 2.0;
   double result = c_imag(z);

   TEST_ASSERT_EQUAL(result, expected);
}

void test_eulers_identity(void)
{
   complex_t z = {.real = 0.0,.imag = PI };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t result = c_exp(z);

   compare_complex(result, expected);
}

void test_exponential_of_zero(void)
{
   complex_t zero = {.real = 0.0,.imag = 0.0 };

   complex_t expected = {.real = 1.0,.imag = 0.0 };
   complex_t result = c_exp(zero);

   compare_complex(result, expected);
}

void test_exponential_of_a_purely_real_number(void)
{
   complex_t z = {.real = 1.0,.imag = 0.0 };

   complex_t expected = {.real = E,.imag = 0.0 };
   complex_t result = c_exp(z);

   compare_complex(result, expected);
}

int main(void)
{
   UnityBegin("complex_numbers.c");

   RUN_TEST(test_imaginary_unit);
   RUN_TEST(test_add_purely_real_numbers);
   RUN_TEST(test_add_purely_imaginary_numbers);
   RUN_TEST(test_add_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_subtract_purely_real_numbers);
   RUN_TEST(test_subtract_purely_imaginary_numbers);
   RUN_TEST(test_subtract_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_multiply_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_multiply_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_multiply_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_divide_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_divide_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_divide_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_abs_of_a_positive_purely_real_number);
   RUN_TEST(test_abs_of_a_negative_purely_real_number);
   RUN_TEST(test_abs_of_a_purely_imaginary_number_with_positive_imaginary_part);
   RUN_TEST(test_abs_of_a_purely_imaginary_number_with_negative_imaginary_part);
   RUN_TEST(test_abs_of_a_number_with_real_and_imaginary_part);
   RUN_TEST(test_complex_conjugate_of_a_purely_real_number);
   RUN_TEST(test_complex_conjugate_of_a_purely_imaginary_number);
   RUN_TEST(test_complex_conjugate_of_a_number_with_real_and_imaginary_part);
   RUN_TEST(test_real_part_of_a_purely_real_number);
   RUN_TEST(test_real_part_of_a_purely_imaginary_number);
   RUN_TEST(test_real_part_of_a_number_with_real_and_imaginary_part);
   RUN_TEST(test_imaginary_part_of_a_purely_real_number);
   RUN_TEST(test_imaginary_part_of_a_purely_imaginary_number);
   RUN_TEST(test_imaginary_part_of_a_number_with_real_and_imaginary_part);
   RUN_TEST(test_eulers_identity);
   RUN_TEST(test_exponential_of_zero);
   RUN_TEST(test_exponential_of_a_purely_real_number);

   UnityEnd();
   return 0;
}
