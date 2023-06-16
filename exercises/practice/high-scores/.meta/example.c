#include "high_scores.h"

#define MAX_TOP_SCORES (3)

int32_t latest(const int32_t *scores, size_t scores_len)
{
   if (scores_len == 0) {
      return 0;
   }

   return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
   int32_t best;
   if (scores_len == 0) {
      return 0;
   }

   best = scores[0];
   for (size_t i = 1; i < scores_len; i++) {
      if (best < scores[i]) {
         best = scores[i];
      }
   }
   return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
   size_t count = 0;
   for (size_t i = 0; i < scores_len; i++) {
      const int32_t score = scores[i];
      if (count < MAX_TOP_SCORES) {
         count++;
      } else if (score <= output[count - 1]) {
         // The current score is not one of the highest.
         continue;
      }

      // Insert score into output.
      size_t k = count - 1;
      while (k > 0 && output[k - 1] < score) {
         output[k] = output[k - 1];
         --k;
      }
      output[k] = score;
   }
   return count;
}
