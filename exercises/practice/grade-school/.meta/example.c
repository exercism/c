#include "grade_school.h"
#include <stdlib.h>
#include <string.h>

static bool student_is_on_roster(roster_t * roster, char *name)
{
   bool is_on_roster = false;
   for (size_t i = 0; i < roster->count; ++i) {
      if (!strncmp(roster->students[i].name, name, MAX_NAME_LENGTH)) {
         is_on_roster = true;
         break;
      }
   }
   return is_on_roster;
}

static int compare_student_names(const void *s1, const void *s2)
{
   const student_t *student1 = (const student_t *)s1;
   const student_t *student2 = (const student_t *)s2;
   return strncmp(student1->name, student2->name, MAX_NAME_LENGTH);
}

static int compare_student_grades_and_names(const void *s1, const void *s2)
{
   const student_t *student1 = (const student_t *)s1;
   const student_t *student2 = (const student_t *)s2;

   if (student1->grade > student2->grade)
      return 1;
   else if (student1->grade < student2->grade)
      return -1;
   else
      return compare_student_names(student1, student2);
}

void init_roster(roster_t * roster)
{
   memset(roster, 0, sizeof(*roster));
}

bool add_student(roster_t * roster, char *name, uint8_t grade)
{
   bool added = false;

   if (student_is_on_roster(roster, name)) {
      added = false;
   } else if (roster->count < MAX_STUDENTS && strlen(name) < MAX_NAME_LENGTH) {
      strcpy(roster->students[roster->count].name, name);
      roster->students[roster->count].grade = grade;
      ++roster->count;
      qsort(roster->students, roster->count, sizeof(roster->students[0]),
            compare_student_grades_and_names);
      added = true;
   }
   return added;
}

roster_t get_grade(roster_t * roster, uint8_t grade)
{
   roster_t grade_roster = { 0 };

   for (size_t i = 0; i < roster->count && grade_roster.count < MAX_STUDENTS;
        ++i) {
      if (roster->students[i].grade == grade) {
         strcpy(grade_roster.students[grade_roster.count].name,
                roster->students[i].name);
         grade_roster.students[grade_roster.count].grade = grade;
         ++grade_roster.count;
      }
   }
   return grade_roster;
}
