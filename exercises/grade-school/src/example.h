#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 20

typedef struct {
   uint8_t grade;
   char *name;
} student_t;

char **roster(size_t count, student_t * students);

char **grade(size_t count, student_t * students, uint8_t desired_grade);

void delete_listing(char **listing);

#endif
