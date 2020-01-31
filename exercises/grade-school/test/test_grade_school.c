#include "vendor/unity.h"
#include "../src/grade_school.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
   clear_roster();
}

static void populate_roster(roster_t * expected)
{
   for (size_t i = 0; i < expected->count; ++i)
      TEST_ASSERT_TRUE(add_student
                       (expected->students[i].name,
                        expected->students[i].grade));
}

static void check_roster_names(roster_t * expected, roster_t * actual)
{
   TEST_ASSERT_EQUAL(expected->count, actual->count);

   for (size_t i = 0; i < expected->count; ++i)
      TEST_ASSERT_EQUAL_STRING(expected->students[i].name,
                               actual->students[i].name);
}

static void check_roster(roster_t * input, roster_t * expected)
{
   populate_roster(input);

   roster_t actual = get_roster();

   check_roster_names(expected, &actual);
}

static void
test_grade_returns_an_empty_list_if_there_are_no_students_enrolled(void)
{
   roster_t roster = get_roster();

   TEST_ASSERT_EQUAL(0, roster.count);
}

static void test_adding_student_adds_to_roster(void)
{
   TEST_IGNORE();               // delete this line to run test
   roster_t input = {
      .count = 1,
      .students = {
                   (student_t) {
                                .grade = 2,
                                .name = "Aimee"}}
   };

   roster_t expected = { 1, {(student_t) {2, "Aimee"}} };

   check_roster(&input, &expected);
}

static void test_adding_more_students_adds_to_roster(void)
{
   TEST_IGNORE();
   roster_t input = {
      3, {
          (student_t) {2, "Blair"},
          (student_t) {2, "James"},
          (student_t) {2, "Paul"}}
   };

   roster_t expected = {
      3, {
          (student_t) {2, "Blair"},
          (student_t) {2, "James"},
          (student_t) {2, "Paul"}}
   };

   check_roster(&input, &expected);
}

static void test_adding_students_to_different_grades_adds_to_same_roster(void)
{
   TEST_IGNORE();
   roster_t input = {
      2, {
          (student_t) {3, "Chelsea"},
          (student_t) {7, "Logan"}}
   };

   roster_t expected = {
      2, {
          (student_t) {3, "Chelsea"},
          (student_t) {7, "Logan"}}
   };

   check_roster(&input, &expected);
}

static void test_students_in_same_grade_are_sorted_in_same_roster(void)
{
   TEST_IGNORE();
   roster_t input = {
      3, {
          (student_t) {1, "Peter"},
          (student_t) {1, "Anna"},
          (student_t) {1, "Barb"}}
   };

   roster_t expected = {
      3, {
          (student_t) {1, "Anna"},
          (student_t) {1, "Barb"},
          (student_t) {1, "Peter"}}
   };

   check_roster(&input, &expected);
}

static void test_students_with_grades_listed_in_same_sorted_roster(void)
{
   TEST_IGNORE();
   roster_t input = {
      7, {
          (student_t) {2, "Peter"},
          (student_t) {1, "Anna"},
          (student_t) {1, "Barb"},
          (student_t) {2, "Zoe"},
          (student_t) {2, "Alex"},
          (student_t) {3, "Jim"},
          (student_t) {1, "Charlie"}}
   };

   roster_t expected = {
      7, {
          (student_t) {1, "Anna"},
          (student_t) {1, "Barb"},
          (student_t) {1, "Charlie"},
          (student_t) {2, "Alex"},
          (student_t) {2, "Peter"},
          (student_t) {2, "Zoe"},
          (student_t) {3, "Jim"}}
   };

   check_roster(&input, &expected);
}

static void test_grade_lists_students_in_that_grade_in_alphabetical_order(void)
{
   TEST_IGNORE();
   roster_t input = {
      3, {
          (student_t) {5, "Franklin"},
          (student_t) {5, "Bradley"},
          (student_t) {1, "Jeff"}}
   };

   uint8_t desired_grade = 5;
   roster_t expected = {
      2, {
          (student_t) {5, "Bradley"},
          (student_t) {5, "Franklin"}}
   };

   populate_roster(&input);

   roster_t actual = get_grade(desired_grade);

   check_roster_names(&expected, &actual);
}

int main(void)
{
   UnityBegin("test/test_grade_school.c");

   RUN_TEST(test_grade_returns_an_empty_list_if_there_are_no_students_enrolled);
   RUN_TEST(test_adding_student_adds_to_roster);
   RUN_TEST(test_adding_more_students_adds_to_roster);
   RUN_TEST(test_adding_students_to_different_grades_adds_to_same_roster);
   RUN_TEST(test_students_in_same_grade_are_sorted_in_same_roster);
   RUN_TEST(test_students_with_grades_listed_in_same_sorted_roster);
   RUN_TEST(test_grade_lists_students_in_that_grade_in_alphabetical_order);

   return UnityEnd();
}
