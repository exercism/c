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
   uint32_t integers[1] = { 0x0 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 0x0 };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_single_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x40 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 0x40 };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_largest_single_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x7f };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[1] = { 0x7f };
   int expected_len = 1;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_smallest_double_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x80 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 0x81, 0x0 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_double_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x2000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 0xc0, 0x0 };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_largest_double_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x3fff };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 0xff, 0x7f };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_smallest_triple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x4000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 0x81, 0x80, 0x0 };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_triple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x100000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 0xc0, 0x80, 0x0 };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_largest_triple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x1fffff };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[3] = { 0xff, 0xff, 0x7f };
   int expected_len = 3;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_smallest_quadruple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x200000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 0x81, 0x80, 0x80, 0x0 };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_quadruple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x8000000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 0xc0, 0x80, 0x80, 0x0 };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_largest_quadruple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0xfffffff };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[4] = { 0xff, 0xff, 0xff, 0x7f };
   int expected_len = 4;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_smallest_quintuple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0x10000000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 0x81, 0x80, 0x80, 0x80, 0x0 };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_arbitrary_quintuple_byte(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0xff000000 };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 0x8f, 0xf8, 0x80, 0x80, 0x0 };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_maximum_32_bit_integer_input(void)
{
   TEST_IGNORE();
   uint32_t integers[1] = { 0xffffffff };
   size_t input_len = 1;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[5] = { 0x8f, 0xff, 0xff, 0xff, 0x7f };
   int expected_len = 5;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_two_single_byte_values(void)
{
   TEST_IGNORE();
   uint32_t integers[2] = { 0x40, 0x7f };
   size_t input_len = 2;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[2] = { 0x40, 0x7f };
   int expected_len = 2;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_two_multi_byte_values(void)
{
   TEST_IGNORE();
   uint32_t integers[2] = { 0x4000, 0x123456 };
   size_t input_len = 2;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[6] = { 0x81, 0x80, 0x0, 0xc8, 0xe8, 0x56 };
   int expected_len = 6;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_many_multi_byte_values(void)
{
   TEST_IGNORE();
   uint32_t integers[6] = { 0x2000, 0x123456, 0xfffffff, 0x0, 0x3fff, 0x4000 };
   size_t input_len = 6;
   uint8_t response[BUFFER_SIZE];
   uint8_t expected[15] = { 0xc0, 0x0, 0xc8, 0xe8, 0x56, 0xff, 0xff, 0xff,
                            0x7f, 0x0, 0xff, 0x7f, 0x81, 0x80, 0x0 };
   int expected_len = 15;
   int response_len = encode(integers, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, response, expected_len);
}

static void test_one_byte(void)
{
   uint8_t input[1] = { 0x7f };
   size_t input_len = 1;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[1] = { 0x7f };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
}

static void test_two_bytes(void)
{
   TEST_IGNORE();
   uint8_t input[2] = { 0xc0, 0x0 };
   size_t input_len = 2;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[1] = { 0x2000 };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
}

static void test_three_bytes(void)
{
   TEST_IGNORE();
   uint8_t input[3] = { 0xff, 0xff, 0x7f };
   size_t input_len = 3;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[1] = { 0x1fffff };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
}

static void test_four_bytes(void)
{
   TEST_IGNORE();
   uint8_t input[4] = { 0x81, 0x80, 0x80, 0x0 };
   size_t input_len = 4;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[1] = { 0x200000 };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
}

static void test_maximum_32_bit_integer(void)
{
   TEST_IGNORE();
   uint8_t input[5] = { 0x8f, 0xff, 0xff, 0xff, 0x7f };
   size_t input_len = 5;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[1] = { 0xffffffff };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
}

static void test_incomplete_sequence_causes_error(void)
{
   TEST_IGNORE();
   uint8_t input[1] = { 0xff };
   size_t input_len = 1;
   uint32_t response[BUFFER_SIZE];
   int expected_len = -1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
}

static void test_incomplete_sequence_causes_error_even_if_value_is_zero(void)
{
   TEST_IGNORE();
   uint8_t input[1] = { 0x80 };
   size_t input_len = 1;
   uint32_t response[BUFFER_SIZE];
   int expected_len = -1;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
}

static void test_multiple_values(void)
{
   TEST_IGNORE();
   uint8_t input[15] = { 0xc0, 0x0, 0xc8, 0xe8, 0x56, 0xff, 0xff, 0xff,
                         0x7f, 0x0, 0xff, 0x7f, 0x81, 0x80, 0x0 };
   size_t input_len = 15;
   uint32_t response[BUFFER_SIZE];
   int expected_len = 6;
   int response_len = decode(input, input_len, response);
   TEST_ASSERT_EQUAL_INT(expected_len, response_len);
   uint32_t expected[6] = { 0x2000, 0x123456, 0xfffffff, 0x0, 0x3fff, 0x4000 };
   TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, response, expected_len);
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
