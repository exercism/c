#include "kindergarten_garden.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int student_to_index(const char *student)
{
   static const char *students[] = { "Alice",  "Bob",    "Charlie", "David",
                                     "Eve",    "Fred",   "Ginny",   "Harriet",
                                     "Ileana", "Joseph", "Kincaid", "Larry" };
   for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
      if (strcmp(students[i], student) == 0) {
         return i;
      }
   }
   printf("error: student %s not found\n", student);
   exit(1);
}

static plant_t letter_to_plant(char letter)
{
   switch (letter) {
      case 'C':
         return CLOVER;
      case 'G':
         return GRASS;
      case 'R':
         return RADISHES;
      case 'V':
         return VIOLETS;
   }
   printf("error: letter %c does not match any plant\n", letter);
   exit(1);
}

plants_t plants(const char *diagram, const char *student)
{
   const char *rows[] = { diagram, strchr(diagram, '\n') + 1 };
   const size_t student_col = student_to_index(student) * 2;
   plants_t res;
   for (int i = 0; i < 4; ++i) {
      const size_t row_index = i / 2;
      const size_t col_index = student_col + i % 2;
      res.plants[i] = letter_to_plant(rows[row_index][col_index]);
   }
   return res;
}
