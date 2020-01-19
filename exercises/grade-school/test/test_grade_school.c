#include "vendor/unity.h"
#include "../src/grade_school.h"
#include <stdlib.h>

#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_roster_is_empty_if_there_are_no_students_enrolled(void)
{
   // TEST_IGNORE();
   student_t *students = NULL;
   size_t length = 0;

   char **actual = roster(length, students);

   TEST_ASSERT_NULL(actual);

   delete_listing(actual);
}

static void test_adding_student_adds_to_roster(void)
{
   student_t students[] = { {2, "Aimee"} };
   char *expected[] = { "Aimee" };
   size_t length = ARRAY_LENGTH(students);

   char **actual = roster(length, students);

   TEST_ASSERT_EQUAL_STRING(expected[0], actual[0]);

   delete_listing(actual);
}

static void test_adding_more_students_adds_to_roster(void)
{
   // TEST_IGNORE();               // delete this line to run test
   student_t students[] = { {2, "Blair"}, {2, "James"}, {2, "Paul"} };
   char *expected[] = { "Blair", "James", "Paul" };
   size_t length = ARRAY_LENGTH(students);

   char **actual = roster(length, students);

   for (size_t i = 0; i < length; ++i)
      TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);

   delete_listing(actual);
}

static void test_adding_students_to_different_grades_adds_to_same_roster(void)
{
   // TEST_IGNORE();
   student_t students[] = { {3, "Chelsea"}, {7, "Logan"} };
   char *expected[] = { "Chelsea", "Logan" };
   size_t length = ARRAY_LENGTH(students);

   char **actual = roster(length, students);

   for (size_t i = 0; i < length; ++i)
      TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);

   delete_listing(actual);
}

static void test_students_in_same_grade_are_sorted_in_same_roster(void)
{
   // TEST_IGNORE();
   student_t students[] = { {1, "Peter"}, {1, "Anna"}, {1, "Barb"} };
   char *expected[] = { "Anna", "Barb", "Peter" };
   size_t length = ARRAY_LENGTH(students);

   char **actual = roster(length, students);

   for (size_t i = 0; i < length; ++i)
      TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);

   delete_listing(actual);
}

static void test_students_with_grades_listed_in_same_sorted_roster(void)
{
   // TEST_IGNORE();
   student_t students[] = { {2, "Peter"}, {1, "Anna"}, {1, "Barb"}, {2, "Zoe"},
   {2, "Alex"}, {3, "Jim"}, {1, "Charlie"}
   };
   char *expected[] =
       { "Anna", "Barb", "Charlie", "Alex", "Peter", "Zoe", "Jim" };
   size_t length = ARRAY_LENGTH(students);

   char **actual = roster(length, students);

   for (size_t i = 0; i < length; ++i)
      TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);

   delete_listing(actual);
}

static void
test_grade_returns_an_empty_list_if_there_are_no_students_enrolled(void)
{
   // TEST_IGNORE();
   student_t *students = NULL;
   uint8_t desired_grade = 1;
   size_t length = 0;

   char **actual = grade(length, students, desired_grade);

   TEST_ASSERT_NULL(actual);

   delete_listing(actual);
}

static void test_grade_lists_students_in_that_grade_in_alphabetical_order(void)
{
   // TEST_IGNORE();
   student_t students[] = { {5, "Franklin"}, {5, "Bradley"}, {1, "Jeff"} };
   uint8_t desired_grade = 5;
   char *expected[] = { "Bradley", "Franklin" };
   size_t students_length = ARRAY_LENGTH(students);
   size_t expected_length = ARRAY_LENGTH(expected);

   char **actual = grade(students_length, students, desired_grade);

   for (size_t i = 0; i < expected_length; ++i)
      TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);

   delete_listing(actual);
}

int main(void)
{
   UnityBegin("test/test_grade_school.c");

   RUN_TEST(test_roster_is_empty_if_there_are_no_students_enrolled);
   RUN_TEST(test_adding_student_adds_to_roster);
   RUN_TEST(test_adding_more_students_adds_to_roster);
   RUN_TEST(test_adding_students_to_different_grades_adds_to_same_roster);
   RUN_TEST(test_students_in_same_grade_are_sorted_in_same_roster);
   RUN_TEST(test_students_with_grades_listed_in_same_sorted_roster);
   RUN_TEST(test_grade_returns_an_empty_list_if_there_are_no_students_enrolled);
   RUN_TEST(test_grade_lists_students_in_that_grade_in_alphabetical_order);

   return UnityEnd();
}
