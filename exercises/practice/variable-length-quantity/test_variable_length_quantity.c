#include "test-framework/unity.h"
#include "variable_length_quantity.h"

#define BUFFER_SIZE (100)

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_zero(void)
{
   uint64_t integers[1] = { 0 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 0 };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_single_byte(void)
{
   uint64_t integers[1] = { 64 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 64 };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_largest_single_byte(void)
{
   uint64_t integers[1] = { 127 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 127 };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_smallest_double_byte(void)
{
   uint64_t integers[1] = { 128 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 129, 0 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_double_byte(void)
{
   uint64_t integers[1] = { 8192 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 192, 0 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_largest_double_byte(void)
{
   uint64_t integers[1] = { 16383 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 255, 127 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_smallest_triple_byte(void)
{
   uint64_t integers[1] = { 16384 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 129, 128, 0 };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_triple_byte(void)
{
   uint64_t integers[1] = { 1048576 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 192, 128, 0 };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_largest_triple_byte(void)
{
   uint64_t integers[1] = { 2097151 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 255, 255, 127 };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_smallest_quadruple_byte(void)
{
   uint64_t integers[1] = { 2097152 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 129, 128, 128, 0 };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_quadruple_byte(void)
{
   uint64_t integers[1] = { 134217728 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 192, 128, 128, 0 };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_largest_quadruple_byte(void)
{
   uint64_t integers[1] = { 268435455 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 255, 255, 255, 127 };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_smallest_quintuple_byte(void)
{
   uint64_t integers[1] = { 268435456 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 129, 128, 128, 128, 0 };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_quintuple_byte(void)
{
   uint64_t integers[1] = { 4278190080 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 143, 248, 128, 128, 0 };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_maximum_32_bit_integer_input(void)
{
   uint64_t integers[1] = { 4294967295 };
   int input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 143, 255, 255, 255, 127 };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_two_single_byte_values(void)
{
   uint64_t integers[2] = { 64, 127 };
   int input_len = 2;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 64, 127 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_two_multi_byte_values(void)
{
   uint64_t integers[2] = { 16384, 1193046 };
   int input_len = 2;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[6] = { 129, 128, 0, 200, 232, 86 };
   int expected_len = 6;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_many_multi_byte_values(void)
{
   uint64_t integers[6] = { 8192, 1193046, 268435455, 0, 16383, 16384 };
   int input_len = 6;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[15] = { 192, 0, 200, 232, 86,  255, 255, 255,
                            127, 0, 255, 127, 129, 128, 0 };
   int expected_len = 15;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, response, expected_len);
}

static void test_one_byte(void)
{
   uint8_t input[1] = { 127 };
   int input_len = 1;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[1] = { 127 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

static void test_two_bytes(void)
{
   uint8_t input[2] = { 192, 0 };
   int input_len = 2;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[1] = { 8192 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

static void test_three_bytes(void)
{
   uint8_t input[3] = { 255, 255, 127 };
   int input_len = 3;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[1] = { 2097151 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

static void test_four_bytes(void)
{
   uint8_t input[4] = { 129, 128, 128, 0 };
   int input_len = 4;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[1] = { 2097152 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

static void test_maximum_32_bit_integer(void)
{
   uint8_t input[5] = { 143, 255, 255, 255, 127 };
   int input_len = 5;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[1] = { 4294967295 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

static void test_incomplete_sequence_causes_error(void)
{
   uint8_t input[1] = { 255 };
   int input_len = 1;
   uint64_t response[BUFFER_SIZE];
   int expected_len = -1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
}

static void test_incomplete_sequence_causes_error_even_if_value_is_zero(void)
{
   uint8_t input[1] = { 128 };
   int input_len = 1;
   uint64_t response[BUFFER_SIZE];
   int expected_len = -1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
}

static void test_multiple_values(void)
{
   uint8_t input[15] = { 192, 0, 200, 232, 86,  255, 255, 255,
                         127, 0, 255, 127, 129, 128, 0 };
   int input_len = 15;
   uint64_t response[BUFFER_SIZE];
   int expected_len = 6;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint64_t expected[6] = { 8192, 1193046, 268435455, 0, 16383, 16384 };
   TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, response, expected_len);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_zero);
   RUN_TEST(test_arbitrary_single_byte);
   RUN_TEST(test_largest_single_byte);
   RUN_TEST(test_smallest_double_byte);
   RUN_TEST(test_arbitrary_double_byte);
   RUN_TEST(test_largest_double_byte);
   RUN_TEST(test_smallest_triple_byte);
   RUN_TEST(test_arbitrary_triple_byte);
   RUN_TEST(test_largest_triple_byte);
   RUN_TEST(test_smallest_quadruple_byte);
   RUN_TEST(test_arbitrary_quadruple_byte);
   RUN_TEST(test_largest_quadruple_byte);
   RUN_TEST(test_smallest_quintuple_byte);
   RUN_TEST(test_arbitrary_quintuple_byte);
   RUN_TEST(test_maximum_32_bit_integer_input);
   RUN_TEST(test_two_single_byte_values);
   RUN_TEST(test_two_multi_byte_values);
   RUN_TEST(test_many_multi_byte_values);
   RUN_TEST(test_one_byte);
   RUN_TEST(test_two_bytes);
   RUN_TEST(test_three_bytes);
   RUN_TEST(test_four_bytes);
   RUN_TEST(test_maximum_32_bit_integer);
   RUN_TEST(test_incomplete_sequence_causes_error);
   RUN_TEST(test_incomplete_sequence_causes_error_even_if_value_is_zero);
   RUN_TEST(test_multiple_values);

   return UNITY_END();
}
