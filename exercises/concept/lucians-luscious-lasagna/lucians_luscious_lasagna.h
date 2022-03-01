#ifndef LUCIANS_LUSCIOUS_LASAGNA_H
#define LUCIANS_LUSCIOUS_LASAGNA_H

extern int expected_minutes_in_oven;

int remaining_minutes_in_oven(int actual_minutes_in_oven);

int preparation_time_in_minutes(int number_of_layers);

int elapsed_time_in_minutes(int number_of_layers, int actual_minutes_in_oven);

#endif
