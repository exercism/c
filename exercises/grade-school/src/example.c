#include "grade_school.h"
#include <stdlib.h>
#include <string.h>

static int compare_student_names(const void *s1, const void *s2)
{
   return strncmp(*(const char **)s1, *(const char **)s2, MAX_NAME_LENGTH);
}

static int compare_student_grades_and_names(const void *s1, const void *s2)
{
   const student_t *student1 = *(const student_t **)s1;
   const student_t *student2 = *(const student_t **)s2;

   if (student1->grade > student2->grade)
      return 1;
   else if (student1->grade < student2->grade)
      return -1;
   else
      return compare_student_names(&student1->name, &student2->name);
}

char **roster(size_t count, student_t * students)
{
   if (!count || !students)
      return NULL;

   student_t **listing = malloc(sizeof(student_t *) * count);

   if (listing) {
      for (size_t i = 0; i < count; ++i) {
         listing[i] = &students[i];
      }

      qsort(listing, count, sizeof(*listing), compare_student_grades_and_names);

      char **names = malloc(sizeof(char *) * count);

      if (names) {
         for (size_t i = 0; i < count; ++i) {
            names[i] = listing[i]->name;
         }
      }

      free(listing);

      return names;
   }

   return NULL;
}

char **grade(size_t count, student_t * students, uint8_t desired_grade)
{
   if (!count || !students)
      return NULL;

   char **names = malloc(sizeof(char *) * count);

   if (names) {
      size_t j = 0;
      for (size_t i = 0; i < count && j < count; ++i) {
         if (students[i].grade == desired_grade) {
            names[j++] = students[i].name;
         }
      }

      qsort(names, j, sizeof(*names), compare_student_names);
   }
   return names;
}

void delete_listing(char **listing)
{
   free(listing);
}
