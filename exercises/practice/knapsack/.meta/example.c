#include <string.h>
#include "knapsack.h"

unsigned int maximum_value(unsigned int maximum_weight, item_t *items,
                           size_t item_count)
{
   unsigned int table[item_count + 1][maximum_weight + 1];
   memset(table, 0, sizeof(table));

   for (size_t i = 0; i < item_count; i++) {
      for (unsigned int capacity = 1; capacity <= maximum_weight; capacity++) {
         unsigned int weight = items[i].weight;
         unsigned int value = items[i].value;

         if (weight > capacity) {
            table[i + 1][capacity] = table[i][capacity];
         } else if (table[i][capacity] <= value + table[i][capacity - weight]) {
            table[i + 1][capacity] = value + table[i][capacity - weight];
         } else {
            table[i + 1][capacity] = table[i][capacity];
         }
      }
   }

   unsigned int result = table[item_count][maximum_weight];

   return result;
}
