# Instructions

Lucian's girlfriend is on her way home and he hasn't cooked their anniversary dinner!

In this exercise, you're going to write some code to help Lucian cook an exquisite lasagna from his favorite cookbook.

~~~~exercism/note
The `lasagna.h` file, and the `#import` at the top of `lasagna.c` will be explained in later Concepts.

For now, please just leave these parts unchanged.
~~~~

You have four tasks, all related to the time spent cooking the lasagna.

All numerical values are of type `int`.

## 1. Define the expected oven time in minutes

Define `expected_minutes_in_oven` as a `const int`, representing how many minutes the lasagna should be in the oven.
According to the cookbook, the expected oven time is 40 minutes:

```c
expected_minutes_in_oven;
// => 40
```

## 2. Calculate the remaining oven time in minutes

Define the `remaining_minutes_in_oven(int actual_minutes_in_oven)` function that takes the actual minutes the lasagna has been in the oven as an argument and returns how many minutes the lasagna still has to remain in the oven, based on the expected oven time in minutes from the previous task.

```c
remaining_minutes_in_oven(30);
// => 10
```

## 3. Calculate the preparation time in minutes

Define the `preparation_time_in_minutes(int number_of_layers)` function that takes the number of layers you added to the lasagna as an argument and returns how many minutes you spent preparing the lasagna, assuming each layer takes you 2 minutes to prepare.

```c
preparation_time_in_minutes(2);
// => 4
```

## 4. Calculate the elapsed time in minutes

Define the `elapsed_time_in_minutes(int number_of_layers, int actual_minutes_in_oven)` function that takes two arguments: the first argument is the number of layers you added to the lasagna, and the second argument is the number of minutes the lasagna has been in the oven. 
The function should return how many minutes you've worked on cooking the lasagna, which is the sum of the preparation time in minutes, and the time in minutes the lasagna has spent in the oven at the moment.

```c
elapsed_time_in_minutes(3, 20);
// => 26
```
