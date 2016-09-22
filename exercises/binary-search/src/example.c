#include "binary_search.h"

size_t binary_search(const int value, const int *arr, const size_t length)
{
   if (0 == length || NULL == arr) {
      return 0;
   }
   size_t low = 0;
   size_t high = length - 1;
   while (low <= high) {
      size_t mid = low + (high - low) / 2;
      if (arr[mid] > value) {
         high = mid - 1;
         if (high > mid) {
            break;
         }
      } else if (arr[mid] < value) {
         low = mid + 1;
      } else {
         return mid;
      }
   }
   return length;
}
