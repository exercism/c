#include "vendor/unity.h"
#include "../src/circular_buffer.h"
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_ERROR_MSG_LEN 100
#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void write_values_to_buffer(size_t length, buffer_value_t values[],
                                   bool writeover, circular_buffer_t * buffer)
{
   for (size_t i = 0; i < length; ++i) {
      int16_t status = 0;
      if (!writeover)
         status = write(buffer, values[i]);
      else
         status = overwrite(buffer, values[i]);

      char error_message[MAX_ERROR_MSG_LEN] = { 0 };
      snprintf(error_message, MAX_ERROR_MSG_LEN,
               "Writing %d at %zu resulted in errno %d", values[i], i, errno);
      TEST_ASSERT_EQUAL_INT16_MESSAGE(EXIT_SUCCESS, status, error_message);
   }
}

static void read_values_from_buffer(size_t length, buffer_value_t values[],
                                    circular_buffer_t * buffer)
{
   for (size_t i = 0; i < length; ++i) {
      buffer_value_t read_value = 0;
      int16_t status = read(buffer, &read_value);

      char error_message[MAX_ERROR_MSG_LEN] = { 0 };
      snprintf(error_message, MAX_ERROR_MSG_LEN,
               "Reading at %zu resulted in errno %d, expected to read %d", i,
               errno, values[i]);
      TEST_ASSERT_EQUAL_INT16_MESSAGE(EXIT_SUCCESS, status, error_message);

      snprintf(error_message, MAX_ERROR_MSG_LEN,
               "Read %d at %zu where %d was expected", read_value, i,
               values[i]);
      TEST_ASSERT_EQUAL_INT16_MESSAGE(values[i], read_value, error_message);
   }
}

static void test_reading_empty_buffer_fails(void)
{
   size_t capacity = 1;
   buffer_value_t read_value = 0;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   int16_t status = read(buffer, &read_value);
   TEST_ASSERT_EQUAL_INT16(EXIT_FAILURE, status);
   TEST_ASSERT_EQUAL_INT16(ENODATA, errno);

   delete_buffer(buffer);
}

static void test_can_read_item_just_written(void)
{
   TEST_IGNORE();               // delete this line to run test
   size_t capacity = 1;
   buffer_value_t values[] = { 1 };
   size_t values_length = ARRAY_LENGTH(values);
   circular_buffer_t *buffer = new_circular_buffer(capacity);

   write_values_to_buffer(values_length, values, false, buffer);
   read_values_from_buffer(values_length, values, buffer);

   delete_buffer(buffer);
}

static void test_each_item_may_only_be_read_once(void)
{
   TEST_IGNORE();
   size_t capacity = 1;
   buffer_value_t values[] = { 1 };
   size_t values_length = ARRAY_LENGTH(values);
   buffer_value_t read_value = 0;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(values_length, values, false, buffer);
   read_values_from_buffer(values_length, values, buffer);

   int16_t status = read(buffer, &read_value);
   TEST_ASSERT_EQUAL_INT16(EXIT_FAILURE, status);
   TEST_ASSERT_EQUAL_INT16(ENODATA, errno);

   delete_buffer(buffer);
}

static void test_items_are_read_in_order_written(void)
{
   TEST_IGNORE();
   size_t capacity = 2;
   buffer_value_t values[] = { 1, 2 };
   size_t values_length = ARRAY_LENGTH(values);

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(values_length, values, false, buffer);
   read_values_from_buffer(values_length, values, buffer);

   delete_buffer(buffer);
}

static void test_full_buffer_cannot_be_written_to(void)
{
   TEST_IGNORE();
   size_t capacity = 1;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          1}, false, buffer);

   int16_t status = write(buffer, 2);
   TEST_ASSERT_EQUAL_INT16(EXIT_FAILURE, status);
   TEST_ASSERT_EQUAL_INT16(ENOBUFS, errno);

   delete_buffer(buffer);

}

static void test_read_frees_capacity_for_another_write(void)
{
   TEST_IGNORE();
   size_t capacity = 1;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          1}, false, buffer);
   read_values_from_buffer(1, (buffer_value_t[]) {
                           1}, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          2}, false, buffer);
   read_values_from_buffer(1, (buffer_value_t[]) {
                           2}, buffer);

   delete_buffer(buffer);
}

static void test_read_position_maintained_across_multiple_writes(void)
{
   TEST_IGNORE();
   size_t capacity = 3;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(2, (buffer_value_t[]) {
                          1, 2}, false, buffer);
   read_values_from_buffer(1, (buffer_value_t[]) {
                           1}, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          3}, false, buffer);
   read_values_from_buffer(2, (buffer_value_t[]) {
                           2, 3}, buffer);

   delete_buffer(buffer);
}

static void test_cleared_buffer_cannot_be_read(void)
{
   TEST_IGNORE();
   size_t capacity = 1;
   buffer_value_t read_value = 0;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          1}, false, buffer);
   clear_buffer(buffer);
   int16_t status = read(buffer, &read_value);
   TEST_ASSERT_EQUAL_INT16(EXIT_FAILURE, status);
   TEST_ASSERT_EQUAL_INT16(ENODATA, errno);

   delete_buffer(buffer);
}

static void test_clear_frees_capacity_for_another_write(void)
{
   TEST_IGNORE();
   size_t capacity = 1;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          1}, false, buffer);
   clear_buffer(buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          2}, false, buffer);
   read_values_from_buffer(1, (buffer_value_t[]) {
                           2}, buffer);

   delete_buffer(buffer);
}

static void test_clear_does_nothing_on_an_empty_buffer(void)
{
   TEST_IGNORE();
   size_t capacity = 1;
   buffer_value_t values[] = { 1 };
   size_t values_length = ARRAY_LENGTH(values);

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   clear_buffer(buffer);
   write_values_to_buffer(values_length, values, false, buffer);

   delete_buffer(buffer);
}

static void test_overwrite_acts_like_write_on_non_full_buffer(void)
{
   TEST_IGNORE();
   size_t capacity = 2;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          1}, false, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          2}, true, buffer);
   read_values_from_buffer(2, (buffer_value_t[]) {
                           1, 2}, buffer);

   delete_buffer(buffer);
}

static void test_overwrite_replaces_oldest_item_on_full_buffer(void)
{
   TEST_IGNORE();
   size_t capacity = 2;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(2, (buffer_value_t[]) {
                          1, 2}, false, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          3}, true, buffer);
   read_values_from_buffer(2, (buffer_value_t[]) {
                           2, 3}, buffer);

   delete_buffer(buffer);
}

static void test_overwrite_replaces_oldest_item_remaining_following_read(void)
{
   TEST_IGNORE();
   size_t capacity = 3;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   write_values_to_buffer(3, (buffer_value_t[]) {
                          1, 2, 3}, false, buffer);
   read_values_from_buffer(1, (buffer_value_t[]) {
                           1}, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          4}, false, buffer);
   write_values_to_buffer(1, (buffer_value_t[]) {
                          5}, true, buffer);
   read_values_from_buffer(3, (buffer_value_t[]) {
                           3, 4, 5}, buffer);

   delete_buffer(buffer);
}

static void test_initial_clear_does_not_affect_wrapping(void)
{
   TEST_IGNORE();
   size_t capacity = 2;
   buffer_value_t read_value = 0;

   circular_buffer_t *buffer = new_circular_buffer(capacity);
   clear_buffer(buffer);
   write_values_to_buffer(2, (buffer_value_t[]) {
                          1, 2}, false, buffer);
   write_values_to_buffer(2, (buffer_value_t[]) {
                          3, 4}, true, buffer);
   read_values_from_buffer(2, (buffer_value_t[]) {
                           3, 4}, buffer);

   int16_t status = read(buffer, &read_value);
   TEST_ASSERT_EQUAL_INT16(EXIT_FAILURE, status);
   TEST_ASSERT_EQUAL_INT16(ENODATA, errno);

   delete_buffer(buffer);
}

int main(void)
{
   UnityBegin("test/test_circular_buffer.c");

   RUN_TEST(test_reading_empty_buffer_fails);
   RUN_TEST(test_can_read_item_just_written);
   RUN_TEST(test_each_item_may_only_be_read_once);
   RUN_TEST(test_items_are_read_in_order_written);
   RUN_TEST(test_full_buffer_cannot_be_written_to);
   RUN_TEST(test_read_frees_capacity_for_another_write);
   RUN_TEST(test_read_position_maintained_across_multiple_writes);
   RUN_TEST(test_cleared_buffer_cannot_be_read);
   RUN_TEST(test_clear_frees_capacity_for_another_write);
   RUN_TEST(test_clear_does_nothing_on_an_empty_buffer);
   RUN_TEST(test_overwrite_acts_like_write_on_non_full_buffer);
   RUN_TEST(test_overwrite_replaces_oldest_item_on_full_buffer);
   RUN_TEST(test_overwrite_replaces_oldest_item_remaining_following_read);
   RUN_TEST(test_initial_clear_does_not_affect_wrapping);

   return UnityEnd();
}
