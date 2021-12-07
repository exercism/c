#include "test-framework/unity.h"
#include "grade_school.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NON_EMPTY_DUMMY_ROSTER                                                 \
   {                                                                           \
      1,                                                                       \
      {                                                                        \
         (student_t)                                                           \
         {                                                                     \
            255, "DEADBEEF"                                                    \
         }                                                                     \
      }                                                                        \
   }

void setUp(void)
{
}

void tearDown(void)
{
}

static void check_roster_names(roster_t expected, roster_t actual)
{
   for (size_t i = 0; i < expected.count; ++i)
      TEST_ASSERT_EQUAL_STRING(expected.students[i].name,
                               actual.students[i].name);
}

static void check_rosters(roster_t expected, roster_t actual)
{
   TEST_ASSERT_EQUAL_size_t_MESSAGE(expected.count, actual.count,
                                    "Incorrect number of students");
   check_roster_names(expected, actual);
}

static void test_roster_is_empty_when_no_student_added(void)
{
   roster_t actual = NON_EMPTY_DUMMY_ROSTER;
   init_roster(&actual);
   TEST_ASSERT_EQUAL(0, actual.count);
}

static void test_add_student(void)
{
   TEST_IGNORE();   // delete this line to run test
   roster_t actual;
   init_roster(&actual);

   TEST_ASSERT_TRUE(add_student(&actual, "Aimee", 2));
}

static void test_student_added_to_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 1, { (student_t){ 2, "Aimee" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Aimee", 2);

   check_rosters(expected, actual);
}

static void test_adding_multiple_students_in_same_grade_in_roster(void)
{
   TEST_IGNORE();
   roster_t actual;
   init_roster(&actual);

   TEST_ASSERT_TRUE(add_student(&actual, "Blair", 2));
   TEST_ASSERT_TRUE(add_student(&actual, "James", 2));
   TEST_ASSERT_TRUE(add_student(&actual, "Paul", 2));
}

static void test_multiple_students_in_same_grade_are_added_to_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 3,
                         { (student_t){ 2, "Blair" }, (student_t){ 2, "James" },
                           (student_t){ 2, "Paul" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Blair", 2);
   add_student(&actual, "James", 2);
   add_student(&actual, "Paul", 2);
   ;

   check_rosters(expected, actual);
}

static void test_cannot_add_student_to_same_grade_more_than_once(void)
{
   TEST_IGNORE();
   roster_t actual;
   init_roster(&actual);

   TEST_ASSERT_TRUE(add_student(&actual, "Blair", 2));
   TEST_ASSERT_TRUE(add_student(&actual, "James", 2));
   TEST_ASSERT_FALSE(add_student(&actual, "James", 2));
   TEST_ASSERT_TRUE(add_student(&actual, "Paul", 2));
}

static void test_student_not_added_to_same_grade_in_roster_more_than_once(void)
{
   TEST_IGNORE();
   roster_t expected = { 3,
                         { (student_t){ 2, "Blair" }, (student_t){ 2, "James" },
                           (student_t){ 2, "Paul" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Blair", 2);
   add_student(&actual, "James", 2);
   add_student(&actual, "James", 2);
   add_student(&actual, "Paul", 2);

   check_rosters(expected, actual);
}

static void test_adding_students_in_multiple_grades(void)
{
   TEST_IGNORE();
   roster_t actual;
   init_roster(&actual);

   TEST_ASSERT_TRUE(add_student(&actual, "Chelsea", 3));
   TEST_ASSERT_TRUE(add_student(&actual, "Logan", 7));
}

static void test_students_in_multiple_grades_are_added_to_roster(void)
{
   TEST_IGNORE();
   roster_t expected = {
      2,
      { (student_t){ 3, "Chelsea" }, (student_t){ 7, "Logan" } },
   };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Chelsea", 3);
   add_student(&actual, "Logan", 7);

   check_rosters(expected, actual);
}

static void test_cannot_add_same_student_to_multiple_grades_in_roster(void)
{
   TEST_IGNORE();
   roster_t actual;
   init_roster(&actual);

   TEST_ASSERT_TRUE(add_student(&actual, "Blair", 2));
   TEST_ASSERT_TRUE(add_student(&actual, "James", 2));
   TEST_ASSERT_FALSE(add_student(&actual, "James", 3));
   TEST_ASSERT_TRUE(add_student(&actual, "Paul", 3));
}

static void test_student_not_added_to_multiple_grades_in_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 3,
                         { (student_t){ 2, "Blair" }, (student_t){ 2, "James" },
                           (student_t){ 3, "Paul" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Blair", 2);
   add_student(&actual, "James", 2);
   add_student(&actual, "James", 3);
   add_student(&actual, "Paul", 3);

   check_rosters(expected, actual);
}

static void test_students_are_sorted_by_grades_in_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 3,
                         { (student_t){ 1, "Anna" }, (student_t){ 2, "Peter" },
                           (student_t){ 3, "Jim" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Jim", 3);
   add_student(&actual, "Peter", 2);
   add_student(&actual, "Anna", 1);

   check_rosters(expected, actual);
}

static void test_students_are_sorted_by_name_in_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 3,
                         { (student_t){ 2, "Alex" }, (student_t){ 2, "Peter" },
                           (student_t){ 2, "Zoe" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Peter", 2);
   add_student(&actual, "Zoe", 2);
   add_student(&actual, "Alex", 2);

   check_rosters(expected, actual);
}

static void test_students_are_sorted_by_grades_and_then_by_names_in_roster(void)
{
   TEST_IGNORE();
   roster_t expected = { 7,
                         { (student_t){ 1, "Anna" }, (student_t){ 1, "Barb" },
                           (student_t){ 1, "Charlie" },
                           (student_t){ 2, "Alex" }, (student_t){ 2, "Peter" },
                           (student_t){ 2, "Zoe" }, (student_t){ 3, "Jim" } } };
   roster_t actual;
   init_roster(&actual);

   add_student(&actual, "Peter", 2);
   add_student(&actual, "Anna", 1);
   add_student(&actual, "Barb", 1);
   add_student(&actual, "Zoe", 2);
   add_student(&actual, "Alex", 2);
   add_student(&actual, "Jim", 3);
   add_student(&actual, "Charlie", 1);

   check_rosters(expected, actual);
}

static void test_grade_empty_if_no_students_in_roster(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 1;
   roster_t roster;
   init_roster(&roster);

   roster_t actual = get_grade(&roster, desired_grade);

   TEST_ASSERT_EQUAL(0, actual.count);
}

static void test_grade_empty_if_no_students_in_grade(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 1;
   roster_t roster;
   init_roster(&roster);

   add_student(&roster, "Peter", 2);
   add_student(&roster, "Zoe", 2);
   add_student(&roster, "Alex", 2);
   add_student(&roster, "Jim", 3);

   roster_t actual = get_grade(&roster, desired_grade);

   TEST_ASSERT_EQUAL(0, actual.count);
}

static void test_student_not_added_to_same_grade_more_than_once(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 2;
   roster_t expected = { 3,
                         { (student_t){ 2, "Blair" }, (student_t){ 2, "James" },
                           (student_t){ 2, "Paul" } } };
   roster_t roster;
   init_roster(&roster);

   add_student(&roster, "Blair", 2);
   add_student(&roster, "James", 2);
   add_student(&roster, "James", 2);
   add_student(&roster, "Paul", 2);

   roster_t actual = get_grade(&roster, desired_grade);

   check_rosters(expected, actual);
}

static void test_student_not_added_to_multiple_grades(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 2;
   roster_t expected = {
      2, { (student_t){ 2, "Blair" }, (student_t){ 2, "James" } }
   };
   roster_t roster;
   init_roster(&roster);

   add_student(&roster, "Blair", 2);
   add_student(&roster, "James", 2);
   add_student(&roster, "James", 3);
   add_student(&roster, "Paul", 3);

   roster_t actual = get_grade(&roster, desired_grade);

   check_rosters(expected, actual);
}

static void test_student_not_added_to_other_grade_for_multiple_grades(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 3;
   roster_t expected = { 1, { (student_t){ 3, "Paul" } } };
   roster_t roster;
   init_roster(&roster);

   add_student(&roster, "Blair", 2);
   add_student(&roster, "James", 2);
   add_student(&roster, "James", 3);
   add_student(&roster, "Paul", 3);

   roster_t actual = get_grade(&roster, desired_grade);

   check_rosters(expected, actual);
}

static void test_students_are_sorted_by_name_in_grade(void)
{
   TEST_IGNORE();
   uint8_t desired_grade = 5;
   roster_t expected = {
      2, { (student_t){ 5, "Bradley" }, (student_t){ 5, "Franklin" } }
   };
   roster_t roster;
   init_roster(&roster);

   add_student(&roster, "Franklin", 5);
   add_student(&roster, "Bradley", 5);
   add_student(&roster, "Jeff", 1);

   roster_t actual = get_grade(&roster, desired_grade);

   check_rosters(expected, actual);
}

int main(void)
{
   UnityBegin("test_grade_school.c");

   RUN_TEST(test_roster_is_empty_when_no_student_added);
   RUN_TEST(test_add_student);
   RUN_TEST(test_student_added_to_roster);
   RUN_TEST(test_adding_multiple_students_in_same_grade_in_roster);
   RUN_TEST(test_multiple_students_in_same_grade_are_added_to_roster);
   RUN_TEST(test_cannot_add_student_to_same_grade_more_than_once);
   RUN_TEST(test_student_not_added_to_same_grade_in_roster_more_than_once);
   RUN_TEST(test_adding_students_in_multiple_grades);
   RUN_TEST(test_students_in_multiple_grades_are_added_to_roster);
   RUN_TEST(test_cannot_add_same_student_to_multiple_grades_in_roster);
   RUN_TEST(test_student_not_added_to_multiple_grades_in_roster);
   RUN_TEST(test_students_are_sorted_by_grades_in_roster);
   RUN_TEST(test_students_are_sorted_by_name_in_roster);
   RUN_TEST(test_students_are_sorted_by_grades_and_then_by_names_in_roster);
   RUN_TEST(test_grade_empty_if_no_students_in_roster);
   RUN_TEST(test_grade_empty_if_no_students_in_grade);
   RUN_TEST(test_student_not_added_to_same_grade_more_than_once);
   RUN_TEST(test_student_not_added_to_multiple_grades);
   RUN_TEST(test_student_not_added_to_other_grade_for_multiple_grades);
   RUN_TEST(test_students_are_sorted_by_name_in_grade);

   return UnityEnd();
}
