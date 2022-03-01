#include "lucians_luscious_lasagna.h"

int expected_minutes_in_oven = 40;

int remaining_minutes_in_oven(int actual_minutes_in_oven)
{
   return expected_minutes_in_oven - actual_minutes_in_oven;
}

int preparation_time_in_minutes(int number_of_layers)
{
   return number_of_layers * 2;
}

int elapsed_time_in_minutes(int number_of_layers, int actual_minutes_in_oven)
{
   return preparation_time_in_minutes(number_of_layers) +
          actual_minutes_in_oven;
}
