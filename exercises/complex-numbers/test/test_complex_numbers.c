#include "vendor/unity.h"
#include "../src/complex_numbers.h"
#include <math.h>

#define PI acos(-1)
#define E exp(1)

void compare_complex(complex_t lhs, complex_t rhs)
{
   TEST_ASSERT_EQUAL_FLOAT(lhs.real, rhs.real);
   TEST_ASSERT_EQUAL_FLOAT(lhs.imag, rhs.imag);
}

void test_imaginary_unit(void)
{
   complex_t z = {.real = 0.0,.imag = 1.0 };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t actual = c_mul(z, z);

   compare_complex(expected, actual);
}

void test_add_purely_real_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 3.0,.imag = 0.0 };
   complex_t actual = c_add(z1, z2);

   compare_complex(expected, actual);
}

void test_add_purely_imaginary_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.0,.imag = 3.0 };
   complex_t actual = c_add(z1, z2);

   compare_complex(expected, actual);
}

void test_add_numbers_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = 4.0,.imag = 6.0 };
   complex_t actual = c_add(z1, z2);

   compare_complex(expected, actual);
}

void test_subtract_purely_real_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t actual = c_sub(z1, z2);

   compare_complex(expected, actual);
}

void test_subtract_purely_imaginary_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.0,.imag = -1.0 };
   complex_t actual = c_sub(z1, z2);

   compare_complex(expected, actual);
}

void test_subtract_numbers_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = -2.0,.imag = -2.0 };
   complex_t actual = c_sub(z1, z2);

   compare_complex(expected, actual);
}

void test_multiply_purely_real_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 2.0,.imag = 0.0 };
   complex_t actual = c_mul(z1, z2);

   compare_complex(expected, actual);
}

void test_multiply_purely_imaginary_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = -2.0,.imag = 0.0 };
   complex_t actual = c_mul(z1, z2);

   compare_complex(expected, actual);
}

void test_multiply_numbers_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = -5.0,.imag = 10.0 };
   complex_t actual = c_mul(z1, z2);

   compare_complex(expected, actual);
}

void test_divide_purely_real_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 0.0 };
   complex_t z2 = {.real = 2.0,.imag = 0.0 };

   complex_t expected = {.real = 0.5,.imag = 0.0 };
   complex_t actual = c_div(z1, z2);

   compare_complex(expected, actual);
}

void test_divide_purely_imaginary_numbers(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 0.0,.imag = 1.0 };
   complex_t z2 = {.real = 0.0,.imag = 2.0 };

   complex_t expected = {.real = 0.5,.imag = 0.0 };
   complex_t actual = c_div(z1, z2);

   compare_complex(expected, actual);
}

void test_divide_numbers_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z1 = {.real = 1.0,.imag = 2.0 };
   complex_t z2 = {.real = 3.0,.imag = 4.0 };

   complex_t expected = {.real = 0.44,.imag = 0.08 };
   complex_t actual = c_div(z1, z2);

   compare_complex(expected, actual);
}

void test_abs_of_a_positive_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 5.0,.imag = 0.0 };

   double expected = 5.0;
   double actual = c_abs(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_abs_of_a_negative_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = -5.0,.imag = 0.0 };

   double expected = 5.0;
   double actual = c_abs(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_abs_of_a_purely_imaginary_number_with_positive_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = 5.0 };

   double expected = 5.0;
   double actual = c_abs(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_abs_of_a_purely_imaginary_number_with_negative_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = -5.0 };

   double expected = 5.0;
   double actual = c_abs(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_abs_of_a_number_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 3.0,.imag = 4.0 };

   double expected = 5.0;
   double actual = c_abs(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_complex_conjugate_of_a_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 5.0,.imag = 0.0 };

   complex_t expected = {.real = 5.0,.imag = 0.0 };
   complex_t actual = c_conjugate(z);

   compare_complex(expected, actual);
}

void test_complex_conjugate_of_a_purely_imaginary_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = 5.0 };

   complex_t expected = {.real = 0.0,.imag = -5.0 };
   complex_t actual = c_conjugate(z);

   compare_complex(expected, actual);
}

void test_complex_conjugate_of_a_number_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 1.0 };

   complex_t expected = {.real = 1.0,.imag = -1.0 };
   complex_t actual = c_conjugate(z);

   compare_complex(expected, actual);
}

void test_real_part_of_a_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 0.0 };

   double expected = 1.0;
   double actual = c_real(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_real_part_of_a_purely_imaginary_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = 1.0 };

   double expected = 0.0;
   double actual = c_real(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_real_part_of_a_number_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 2.0 };

   double expected = 1.0;
   double actual = c_real(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_imaginary_part_of_a_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 0.0 };

   double expected = 0.0;
   double actual = c_imag(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_imaginary_part_of_a_purely_imaginary_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = 1.0 };

   double expected = 1.0;
   double actual = c_imag(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_imaginary_part_of_a_number_with_real_and_imaginary_part(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 2.0 };

   double expected = 2.0;
   double actual = c_imag(z);

   TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void test_eulers_identity(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 0.0,.imag = PI };

   complex_t expected = {.real = -1.0,.imag = 0.0 };
   complex_t actual = c_exp(z);

   TEST_ASSERT_FLOAT_WITHIN(1e-10, expected.real, actual.real);
   TEST_ASSERT_FLOAT_WITHIN(1e-10, expected.imag, actual.imag);
}

void test_exponential_of_zero(void)
{
   TEST_IGNORE();
   complex_t zero = {.real = 0.0,.imag = 0.0 };

   complex_t expected = {.real = 1.0,.imag = 0.0 };
   complex_t actual = c_exp(zero);

   compare_complex(expected, actual);
}

void test_exponential_of_a_purely_real_number(void)
{
   TEST_IGNORE();
   complex_t z = {.real = 1.0,.imag = 0.0 };

   complex_t expected = {.real = E,.imag = 0.0 };
   complex_t actual = c_exp(z);

   compare_complex(expected, actual);
}

int main(void)
{
   UnityBegin("test/test_complex_numbers.c");

   RUN_TEST(test_imaginary_unit);
   RUN_TEST(test_add_purely_real_numbers);
   RUN_TEST(test_add_purely_imaginary_numbers);
   RUN_TEST(test_add_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_subtract_purely_real_numbers);
   RUN_TEST(test_subtract_purely_imaginary_numbers);
   RUN_TEST(test_subtract_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_multiply_purely_real_numbers);
   RUN_TEST(test_multiply_purely_imaginary_numbers);
   RUN_TEST(test_multiply_numbers_with_real_and_imaginary_part);
   RUN_TEST(test_divide_purely_real_numbers);
   RUN_TEST(test_divide_purely_imaginary_numbers);
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
