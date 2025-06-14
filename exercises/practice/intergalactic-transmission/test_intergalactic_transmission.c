#include "intergalactic_transmission.h"

#include "test-framework/unity.h"

#include <stdint.h>

#define BUFFER_SIZE 100
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_transmitsequence_empty_message(void)
{
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(0, transmit_sequence(buffer, NULL, 0));
}

static void test_transmitsequence_0x00_is_transmitted_as_0x0000(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x00, 0x00 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_0x02_is_transmitted_as_0x0300(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x02 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x03, 0x00 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_0x06_is_transmitted_as_0x0600(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x06 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x06, 0x00 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_0x05_is_transmitted_as_0x0581(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x05 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x05, 0x81 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_0x29_is_transmitted_as_0x2881(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x29 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x28, 0x81 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void
test_transmitsequence_0xc001c0de_is_transmitted_as_0xc000711be1(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0xc0, 0x01, 0xc0, 0xde };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0xc0, 0x00, 0x71, 0x1b, 0xe1 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_six_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x47, 0x72, 0x65, 0x61, 0x74, 0x21 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x47, 0xb8, 0x99, 0xac, 0x17, 0xa0, 0x84 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_seven_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x47, 0x72, 0x65, 0x61, 0x74, 0x31, 0x21 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = {
      0x47, 0xb8, 0x99, 0xac, 0x17, 0xa0, 0xc5, 0x42
   };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_eight_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0xc0, 0x01, 0x13, 0x37, 0xc0, 0xde, 0x21, 0x21 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0xc0, 0x00, 0x44, 0x66, 0x7d,
                                0x06, 0x78, 0x42, 0x21, 0x81 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_transmitsequence_twenty_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x45, 0x78, 0x65, 0x72, 0x63, 0x69, 0x73,
                               0x6d, 0x20, 0x69, 0x73, 0x20, 0x61, 0x77,
                               0x65, 0x73, 0x6f, 0x6d, 0x65, 0x21 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x44, 0xbd, 0x18, 0xaf, 0x27, 0x1b, 0xa5, 0xe7,
                                0x6c, 0x90, 0x1b, 0x2e, 0x33, 0x03, 0x84, 0xee,
                                0x65, 0xb8, 0xdb, 0xed, 0xd7, 0x28, 0x84 };
   TEST_ASSERT_EQUAL_INT(
       ARRAY_SIZE(expected),
       transmit_sequence(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_empty_message(void)
{
   TEST_IGNORE();
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(0, decode_message(buffer, NULL, 0));
}

static void test_decodemessage_zero_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x00, 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x00 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_0x0300_is_decoded_to_0x02(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x03, 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x02 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_0x0581_is_decoded_to_0x05(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x05, 0x81 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x05 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_0x2881_is_decoded_to_0x29(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x28, 0x81 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x29 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_first_byte_has_wrong_parity(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x07, 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(WRONG_PARITY,
                         decode_message(buffer, message, ARRAY_SIZE(message)));
}

static void test_decodemessage_second_byte_has_wrong_parity(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x03, 0x68 };
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(WRONG_PARITY,
                         decode_message(buffer, message, ARRAY_SIZE(message)));
}

static void test_decodemessage_0xcf4b00_is_decoded_to_0xce94(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0xcf, 0x4b, 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0xce, 0x94 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_0xe2566500_is_decoded_to_0xe2ad90(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0xe2, 0x56, 0x65, 0x00 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0xe2, 0xad, 0x90 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_six_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x47, 0xb8, 0x99, 0xac, 0x17, 0xa0, 0x84 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x47, 0x72, 0x65, 0x61, 0x74, 0x21 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_seven_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x47, 0xb8, 0x99, 0xac, 0x17, 0xa0, 0xc5, 0x42 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x47, 0x72, 0x65, 0x61, 0x74, 0x31, 0x21 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_last_byte_has_wrong_parity(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x47, 0xb8, 0x99, 0xac, 0x17, 0xa0, 0xc5, 0x43 };
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(WRONG_PARITY,
                         decode_message(buffer, message, ARRAY_SIZE(message)));
}

static void test_decodemessage_eight_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0xc0, 0x00, 0x44, 0x66, 0x7d,
                               0x06, 0x78, 0x42, 0x21, 0x81 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = {
      0xc0, 0x01, 0x13, 0x37, 0xc0, 0xde, 0x21, 0x21
   };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_twenty_byte_message(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x44, 0xbd, 0x18, 0xaf, 0x27, 0x1b, 0xa5, 0xe7,
                               0x6c, 0x90, 0x1b, 0x2e, 0x33, 0x03, 0x84, 0xee,
                               0x65, 0xb8, 0xdb, 0xed, 0xd7, 0x28, 0x84 };
   uint8_t buffer[BUFFER_SIZE];
   const uint8_t expected[] = { 0x45, 0x78, 0x65, 0x72, 0x63, 0x69, 0x73,
                                0x6d, 0x20, 0x69, 0x73, 0x20, 0x61, 0x77,
                                0x65, 0x73, 0x6f, 0x6d, 0x65, 0x21 };
   TEST_ASSERT_EQUAL_INT(ARRAY_SIZE(expected),
                         decode_message(buffer, message, ARRAY_SIZE(message)));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, buffer, ARRAY_SIZE(expected));
}

static void test_decodemessage_wrong_parity_on_16th_byte(void)
{
   TEST_IGNORE();
   const uint8_t message[] = { 0x44, 0xbd, 0x18, 0xaf, 0x27, 0x1b, 0xa5, 0xe7,
                               0x6c, 0x90, 0x1b, 0x2e, 0x33, 0x03, 0x84, 0xef,
                               0x65, 0xb8, 0xdb, 0xed, 0xd7, 0x28, 0x84 };
   uint8_t buffer[BUFFER_SIZE];
   TEST_ASSERT_EQUAL_INT(WRONG_PARITY,
                         decode_message(buffer, message, ARRAY_SIZE(message)));
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_transmitsequence_empty_message);
   RUN_TEST(test_transmitsequence_0x00_is_transmitted_as_0x0000);
   RUN_TEST(test_transmitsequence_0x02_is_transmitted_as_0x0300);
   RUN_TEST(test_transmitsequence_0x06_is_transmitted_as_0x0600);
   RUN_TEST(test_transmitsequence_0x05_is_transmitted_as_0x0581);
   RUN_TEST(test_transmitsequence_0x29_is_transmitted_as_0x2881);
   RUN_TEST(test_transmitsequence_0xc001c0de_is_transmitted_as_0xc000711be1);
   RUN_TEST(test_transmitsequence_six_byte_message);
   RUN_TEST(test_transmitsequence_seven_byte_message);
   RUN_TEST(test_transmitsequence_eight_byte_message);
   RUN_TEST(test_transmitsequence_twenty_byte_message);
   RUN_TEST(test_decodemessage_empty_message);
   RUN_TEST(test_decodemessage_zero_message);
   RUN_TEST(test_decodemessage_0x0300_is_decoded_to_0x02);
   RUN_TEST(test_decodemessage_0x0581_is_decoded_to_0x05);
   RUN_TEST(test_decodemessage_0x2881_is_decoded_to_0x29);
   RUN_TEST(test_decodemessage_first_byte_has_wrong_parity);
   RUN_TEST(test_decodemessage_second_byte_has_wrong_parity);
   RUN_TEST(test_decodemessage_0xcf4b00_is_decoded_to_0xce94);
   RUN_TEST(test_decodemessage_0xe2566500_is_decoded_to_0xe2ad90);
   RUN_TEST(test_decodemessage_six_byte_message);
   RUN_TEST(test_decodemessage_seven_byte_message);
   RUN_TEST(test_decodemessage_last_byte_has_wrong_parity);
   RUN_TEST(test_decodemessage_eight_byte_message);
   RUN_TEST(test_decodemessage_twenty_byte_message);
   RUN_TEST(test_decodemessage_wrong_parity_on_16th_byte);

   return UNITY_END();
}
