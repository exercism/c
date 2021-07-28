#include "test-framework/unity.h"
#include "grade_school.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
   clear_roster();
}

static void populate_roster(roster_t * expected)
{
   for (size_t i = 0; i < expected->count; ++i) {
      char name_buffer[MAX_NAME_LENGTH];
      strcpy(name_buffer, expected->students[i].name);
      add_student(name_buffer, expected->students[i].grade);
   }
}

static void check_roster_names(roster_t * expected, roster_t * actual)
{
   TEST_ASSERT_EQUAL_size_t_MESSAGE(expected->count, actual->count,
                                    "Incorrect number of students");

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

static void test_adding_student_adds_to_the_sorted_roster(void)
{
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

static void
test_student_can_only_be_added_to_the_same_grade_in_the_roster_once(void)
{
   TEST_IGNORE();               // delete this line to run test
   roster_t input = {
      2, {
          (student_t) {2, "Aimee"},
          (student_t) {2, "Aimee"}}
   };

   roster_t expected = { 1, {(student_t) {2, "Aimee"}} };

   check_roster(&input, &expected);
}

static void test_adding_more_students_adds_to_the_sorted_roster(void)
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

static void
test_adding_students_to_different_grades_adds_to_the_same_sorted_roster(void)
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

static void
test_student_cannot_be_added_to_more_than_one_grade_in_the_sorted_roster(void)
{
   TEST_IGNORE();
   roster_t input = {
      2, {
          (student_t) {2, "Aimee"},
          (student_t) {1, "Aimee"}}
   };

   roster_t expected = { 1, {(student_t) {2, "Aimee"}} };

   check_roster(&input, &expected);
}

static void
test_roster_returns_an_empty_list_if_there_are_no_students_enrolled(void)
{
   TEST_IGNORE();
   roster_t actual = get_roster();

   TEST_ASSERT_EQUAL(0, actual.count);
}

static void
test_student_names_with_grades_displayed_in_the_same_sorted_roster(void)
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

static void
test_grade_returns_students_in_that_grade_in_alphabetical_order(void)
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

static void
test_grade_returns_an_empty_list_if_there_are_no_students_in_that_grade(void)
{
   TEST_IGNORE();

   uint8_t desired_grade = 1;
   roster_t actual = get_grade(desired_grade);

   TEST_ASSERT_EQUAL(0, actual.count);
}

int main(void)
{
   UnityBegin("test_grade_school.c");

   RUN_TEST(test_adding_student_adds_to_the_sorted_roster);
   RUN_TEST
       (test_student_can_only_be_added_to_the_same_grade_in_the_roster_once);
   RUN_TEST(test_adding_more_students_adds_to_the_sorted_roster);
   RUN_TEST
       (test_adding_students_to_different_grades_adds_to_the_same_sorted_roster);
   RUN_TEST
       (test_student_cannot_be_added_to_more_than_one_grade_in_the_sorted_roster);
   RUN_TEST
       (test_roster_returns_an_empty_list_if_there_are_no_students_enrolled);
   RUN_TEST(test_student_names_with_grades_displayed_in_the_same_sorted_roster);
   RUN_TEST(test_grade_returns_students_in_that_grade_in_alphabetical_order);
   RUN_TEST
       (test_grade_returns_an_empty_list_if_there_are_no_students_in_that_grade);

   return UnityEnd();
}
