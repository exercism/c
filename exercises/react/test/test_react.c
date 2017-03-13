#include <stddef.h>
#include <stdio.h>
#include "vendor/unity.h"
#include "../src/react.h"

void test_input_cells_have_value(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 2);

   TEST_ASSERT_EQUAL_INT(2, cell_value(input));

   destroy_reactor(r);
}

static int plus1(int x)
{
   return x + 1;
}

void test_compute_cells_calculate_initial_value(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   TEST_ASSERT_EQUAL_INT(2, cell_value(output));

   destroy_reactor(r);
}

static int concat_digits(int a, int b)
{
   return b * 10 + a;
}

void test_compute_cells_take_inputs_in_the_right_order(void)
{
   struct reactor *r = create_reactor();
   struct cell *one = create_input_cell(r, 1);
   struct cell *two = create_input_cell(r, 2);
   struct cell *output = create_compute2_cell(r, one, two, concat_digits);

   TEST_ASSERT_EQUAL_INT(21, cell_value(output));

   destroy_reactor(r);
}

void test_compute_cells_update_value_when_dependencies_are_changed(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   cell_value_set(input, 3);
   TEST_ASSERT_EQUAL_INT(4, cell_value(output));

   destroy_reactor(r);
}

static int times2(int x)
{
   return x * 2;
}

static int times30(int x)
{
   return x * 30;
}

static int plus(int x, int y)
{
   return x + y;
}

void test_compute_cells_can_depend_on_other_compute_cells(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *times_two = create_compute1_cell(r, input, times2);
   struct cell *times_thirty = create_compute1_cell(r, input, times30);
   struct cell *output = create_compute2_cell(r, times_two, times_thirty, plus);

   TEST_ASSERT_EQUAL_INT(32, cell_value(output));
   cell_value_set(input, 3);
   TEST_ASSERT_EQUAL_INT(96, cell_value(output));

   destroy_reactor(r);
}

struct cbinfo {
   int last_value;
   int times_called;
};

static void cb_spy(void *obj, int v)
{
   struct cbinfo *cbinfo = (struct cbinfo *)obj;
   cbinfo->last_value = v;
   ++cbinfo->times_called;
}

void test_compute_cells_fire_callbacks(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   cell_value_set(input, 3);
   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(4, cbinfo.last_value);

   destroy_reactor(r);
}

static void cb_noop(void *obj, int v)
{
   (void)obj;
   (void)v;
}

void test_compute_cells_dont_access_callback_obj(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   add_callback(output, NULL, cb_noop);

   cell_value_set(input, 3);

   destroy_reactor(r);
}

static int big_if_three(int x)
{
   return x < 3 ? 111 : 222;
}

void test_callbacks_only_fire_on_change(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, big_if_three);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   cell_value_set(input, 2);
   TEST_ASSERT_EQUAL_INT(0, cbinfo.times_called);

   cell_value_set(input, 4);
   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(222, cbinfo.last_value);

   destroy_reactor(r);
}

void test_callbacks_can_be_added_and_removed(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 11);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   callback_id cb1 = add_callback(output, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   add_callback(output, &cbinfo2, cb_spy);

   cell_value_set(input, 31);

   remove_callback(output, cb1);
   struct cbinfo cbinfo3 = { -1, 0 };
   add_callback(output, &cbinfo3, cb_spy);

   cell_value_set(input, 41);

   TEST_ASSERT_EQUAL_INT(1, cbinfo1.times_called);
   TEST_ASSERT_EQUAL_INT(32, cbinfo1.last_value);
   TEST_ASSERT_EQUAL_INT(2, cbinfo2.times_called);
   TEST_ASSERT_EQUAL_INT(42, cbinfo2.last_value);
   TEST_ASSERT_EQUAL_INT(1, cbinfo3.times_called);
   TEST_ASSERT_EQUAL_INT(42, cbinfo3.last_value);

   destroy_reactor(r);
}

void test_removing_most_recent_callback(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 11);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   add_callback(output, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   callback_id cb2 = add_callback(output, &cbinfo2, cb_spy);
   remove_callback(output, cb2);

   cell_value_set(input, 31);

   TEST_ASSERT_EQUAL_INT(1, cbinfo1.times_called);
   TEST_ASSERT_EQUAL_INT(32, cbinfo1.last_value);
   TEST_ASSERT_EQUAL_INT(0, cbinfo2.times_called);

   destroy_reactor(r);
}

void test_removing_a_callback_multiple_times(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 11);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   callback_id cb1 = add_callback(output, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   add_callback(output, &cbinfo2, cb_spy);
   for (int i = 0; i < 10; ++i) {
      remove_callback(output, cb1);
   }

   cell_value_set(input, 2);

   TEST_ASSERT_EQUAL_INT(0, cbinfo1.times_called);
   TEST_ASSERT_EQUAL_INT(1, cbinfo2.times_called);
   TEST_ASSERT_EQUAL_INT(3, cbinfo2.last_value);

   destroy_reactor(r);
}

static int minus1(int x)
{
   return x - 1;
}

static int times(int x, int y)
{
   return x * y;
}

void test_callbacks_only_called_once_even_if_multiple_inputs_change(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *plus_one = create_compute1_cell(r, input, plus1);
   struct cell *minus_one1 = create_compute1_cell(r, input, minus1);
   struct cell *minus_one2 = create_compute1_cell(r, minus_one1, minus1);
   struct cell *output = create_compute2_cell(r, plus_one, minus_one2, times);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   cell_value_set(input, 4);

   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(10, cbinfo.last_value);

   destroy_reactor(r);
}

static int minus(int x, int y)
{
   return x - y;
}

void test_callbacks_not_called_if_inputs_change_but_output_doesnt(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *plus_one = create_compute1_cell(r, input, plus1);
   struct cell *minus_one = create_compute1_cell(r, input, minus1);
   struct cell *always_two =
       create_compute2_cell(r, plus_one, minus_one, minus);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(always_two, &cbinfo, cb_spy);

   for (int i = 0; i < 10; ++i) {
      cell_value_set(input, i);
   }

   TEST_ASSERT_EQUAL_INT(0, cbinfo.times_called);

   destroy_reactor(r);
}

int main(void)
{
   UnityBegin("test/test_react.c");

   RUN_TEST(test_input_cells_have_value);
   RUN_TEST(test_compute_cells_calculate_initial_value);
   RUN_TEST(test_compute_cells_take_inputs_in_the_right_order);
   RUN_TEST(test_compute_cells_update_value_when_dependencies_are_changed);
   RUN_TEST(test_compute_cells_can_depend_on_other_compute_cells);
   RUN_TEST(test_compute_cells_fire_callbacks);
   RUN_TEST(test_compute_cells_dont_access_callback_obj);
   RUN_TEST(test_callbacks_only_fire_on_change);
   RUN_TEST(test_callbacks_can_be_added_and_removed);
   RUN_TEST(test_removing_most_recent_callback);
   RUN_TEST(test_removing_a_callback_multiple_times);
   RUN_TEST(test_callbacks_only_called_once_even_if_multiple_inputs_change);
   RUN_TEST(test_callbacks_not_called_if_inputs_change_but_output_doesnt);

   UnityEnd();

   return 0;
}
