#include <stddef.h>
#include <stdio.h>
#include "vendor/unity.h"
#include "../src/react.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static int plus(int x, int y)
{
   return x + y;
}

static int plus1(int x)
{
   return x + 1;
}

static int minus(int x, int y)
{
   return x - y;
}

static int minus1(int x)
{
   return x - 1;
}

static int concat_digits(int a, int b)
{
   return b * 10 + a;
}

static int times(int x, int y)
{
   return x * y;
}

static int times2(int x)
{
   return x * 2;
}

static int times30(int x)
{
   return x * 30;
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

static int big_if_three(int x)
{
   return x < 3 ? 111 : 222;
}

static void test_input_cells_have_value(void)
{
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 10);

   TEST_ASSERT_EQUAL_INT(10, get_cell_value(input));

   destroy_reactor(r);
}

static void test_input_cells_value_can_be_set(void)
{
   TEST_IGNORE();               // delete this line to run test
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 4);

   set_cell_value(input, 20);
   TEST_ASSERT_EQUAL_INT(20, get_cell_value(input));

   destroy_reactor(r);
}

static void test_compute_cells_calculate_initial_value(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   TEST_ASSERT_EQUAL_INT(2, get_cell_value(output));

   destroy_reactor(r);
}

static void test_compute_cells_take_inputs_in_the_right_order(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *one = create_input_cell(r, 1);
   struct cell *two = create_input_cell(r, 2);
   struct cell *output = create_compute2_cell(r, one, two, concat_digits);

   TEST_ASSERT_EQUAL_INT(21, get_cell_value(output));

   destroy_reactor(r);
}

static void test_compute_cells_update_value_when_dependencies_are_changed(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   set_cell_value(input, 3);
   TEST_ASSERT_EQUAL_INT(4, get_cell_value(output));

   destroy_reactor(r);
}

static void test_compute_cells_can_depend_on_other_compute_cells(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *times_two = create_compute1_cell(r, input, times2);
   struct cell *times_thirty = create_compute1_cell(r, input, times30);
   struct cell *output = create_compute2_cell(r, times_two, times_thirty, plus);

   TEST_ASSERT_EQUAL_INT(32, get_cell_value(output));
   set_cell_value(input, 3);
   TEST_ASSERT_EQUAL_INT(96, get_cell_value(output));

   destroy_reactor(r);
}

static void test_compute_cells_fire_callbacks(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   set_cell_value(input, 3);
   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(4, cbinfo.last_value);

   destroy_reactor(r);
}

static void test_callbacks_only_fire_on_change(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, big_if_three);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   set_cell_value(input, 2);
   TEST_ASSERT_EQUAL_INT(0, cbinfo.times_called);

   set_cell_value(input, 4);
   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(222, cbinfo.last_value);

   destroy_reactor(r);
}

static void test_callbacks_do_not_report_already_reported_values(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   set_cell_value(input, 2);
   TEST_ASSERT_EQUAL_INT(3, cbinfo.last_value);

   set_cell_value(input, 3);
   TEST_ASSERT_EQUAL_INT(4, cbinfo.last_value);

   destroy_reactor(r);
}

static void test_callbacks_can_fire_from_multiple_cells(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *plus_one = create_compute1_cell(r, input, plus1);
   struct cell *minus_one = create_compute1_cell(r, input, minus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   add_callback(plus_one, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   add_callback(minus_one, &cbinfo2, cb_spy);

   set_cell_value(input, 10);

   TEST_ASSERT_EQUAL_INT(11, cbinfo1.last_value);
   TEST_ASSERT_EQUAL_INT(9, cbinfo2.last_value);

   destroy_reactor(r);
}

static void test_callbacks_can_be_added_and_removed(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 11);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   callback_id cb1 = add_callback(output, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   add_callback(output, &cbinfo2, cb_spy);

   set_cell_value(input, 31);

   TEST_ASSERT_EQUAL_INT(32, cbinfo1.last_value);
   TEST_ASSERT_EQUAL_INT(32, cbinfo2.last_value);
   TEST_ASSERT_EQUAL_INT(1, cbinfo1.times_called);

   remove_callback(output, cb1);
   struct cbinfo cbinfo3 = { -1, 0 };
   add_callback(output, &cbinfo3, cb_spy);

   set_cell_value(input, 41);

   TEST_ASSERT_EQUAL_INT(42, cbinfo2.last_value);
   TEST_ASSERT_EQUAL_INT(42, cbinfo3.last_value);
   TEST_ASSERT_EQUAL_INT(1, cbinfo1.times_called);

   destroy_reactor(r);
}

static void
    test_removing_a_callback_multiple_times_doesnt_interfere_with_other_callbacks
    (void) {
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *output = create_compute1_cell(r, input, plus1);

   struct cbinfo cbinfo1 = { -1, 0 };
   callback_id cb1 = add_callback(output, &cbinfo1, cb_spy);
   struct cbinfo cbinfo2 = { -1, 0 };
   add_callback(output, &cbinfo2, cb_spy);
   for (int i = 0; i < 10; ++i) {
      remove_callback(output, cb1);
   }

   set_cell_value(input, 2);

   TEST_ASSERT_EQUAL_INT(0, cbinfo1.times_called);
   TEST_ASSERT_EQUAL_INT(1, cbinfo2.times_called);
   TEST_ASSERT_EQUAL_INT(3, cbinfo2.last_value);

   destroy_reactor(r);
}

static void
test_callbacks_only_called_once_even_if_multiple_dependencies_change(void)
{
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *plus_one = create_compute1_cell(r, input, plus1);
   struct cell *minus_one1 = create_compute1_cell(r, input, minus1);
   struct cell *minus_one2 = create_compute1_cell(r, minus_one1, minus1);
   struct cell *output = create_compute2_cell(r, plus_one, minus_one2, times);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(output, &cbinfo, cb_spy);

   set_cell_value(input, 4);

   TEST_ASSERT_EQUAL_INT(1, cbinfo.times_called);
   TEST_ASSERT_EQUAL_INT(10, cbinfo.last_value);

   destroy_reactor(r);
}

static void
 test_callbacks_not_called_if_dependencies_change_but_output_value_doesnt_change
    (void) {
   TEST_IGNORE();
   struct reactor *r = create_reactor();
   struct cell *input = create_input_cell(r, 1);
   struct cell *plus_one = create_compute1_cell(r, input, plus1);
   struct cell *minus_one = create_compute1_cell(r, input, minus1);
   struct cell *always_two =
       create_compute2_cell(r, plus_one, minus_one, minus);

   struct cbinfo cbinfo = { -1, 0 };
   add_callback(always_two, &cbinfo, cb_spy);

   for (int i = 2; i <= 5; ++i) {
      set_cell_value(input, i);
   }

   TEST_ASSERT_EQUAL_INT(0, cbinfo.times_called);

   destroy_reactor(r);
}

int main(void)
{
   UnityBegin("test/test_react.c");

   RUN_TEST(test_input_cells_have_value);
   RUN_TEST(test_input_cells_value_can_be_set);
   RUN_TEST(test_compute_cells_calculate_initial_value);
   RUN_TEST(test_compute_cells_take_inputs_in_the_right_order);
   RUN_TEST(test_compute_cells_update_value_when_dependencies_are_changed);
   RUN_TEST(test_compute_cells_can_depend_on_other_compute_cells);
   RUN_TEST(test_compute_cells_fire_callbacks);
   RUN_TEST(test_callbacks_only_fire_on_change);
   RUN_TEST(test_callbacks_do_not_report_already_reported_values);
   RUN_TEST(test_callbacks_can_fire_from_multiple_cells);
   RUN_TEST(test_callbacks_can_be_added_and_removed);
   RUN_TEST
       (test_removing_a_callback_multiple_times_doesnt_interfere_with_other_callbacks);
   RUN_TEST
       (test_callbacks_only_called_once_even_if_multiple_dependencies_change);
   RUN_TEST
       (test_callbacks_not_called_if_dependencies_change_but_output_value_doesnt_change);

   return UnityEnd();
}
