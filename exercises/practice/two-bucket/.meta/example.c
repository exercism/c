#include "two_bucket.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct {
   bucket_liters_t size;
   bucket_liters_t current;
} bucket_t;

static bucket_t bucket_new(bucket_liters_t size)
{
   return (bucket_t){ .size = size, .current = 0 };
}

static bucket_liters_t bucket_size(const bucket_t *self)
{
   return self->size;
}

static bucket_liters_t bucket_current(const bucket_t *self)
{
   return self->current;
}

static bool bucket_is_empty(const bucket_t *self)
{
   return self->current == 0;
}

static bool bucket_is_full(const bucket_t *self)
{
   return self->current == self->size;
}

static bool bucket_contains(const bucket_t *self, bucket_liters_t amount)
{
   return self->current == amount;
}

static void bucket_empty(bucket_t *self)
{
   self->current = 0;
}

static void bucket_fill(bucket_t *self)
{
   self->current = self->size;
}

static void bucket_pour_into(bucket_t *self, bucket_t *other)
{
   bucket_liters_t amount = MIN(self->current, other->size - other->current);
   self->current -= amount;
   other->current += amount;
}

static int solve(bucket_t *bucket_1, bucket_t *bucket_2,
                 bucket_liters_t goal_liters, bucket_id_t start_bucket)
{
   int max_moves = (bucket_size(bucket_1) + 1) * (bucket_size(bucket_2) + 1);
   int move_count = 0;

   bucket_t *start = (start_bucket == BUCKET_ID_1) ? bucket_1 : bucket_2;
   bucket_t *other = (start_bucket == BUCKET_ID_2) ? bucket_1 : bucket_2;

   bucket_fill(start);
   move_count += 1;

   while ((move_count <= max_moves) && !bucket_contains(start, goal_liters) &&
          !bucket_contains(other, goal_liters)) {
      if (bucket_size(other) == goal_liters) {
         bucket_fill(other);
      } else if (bucket_is_full(other)) {
         bucket_empty(other);
      } else if (!bucket_is_empty(start)) {
         bucket_pour_into(start, other);
      } else {
         bucket_fill(start);
      }

      move_count += 1;
   }

   return move_count;
}

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_liters, bucket_id_t start_bucket)
{
   bucket_t bucket_1 = bucket_new(bucket_1_size);
   bucket_t bucket_2 = bucket_new(bucket_2_size);

   int move_count = solve(&bucket_1, &bucket_2, goal_liters, start_bucket);

   if (bucket_contains(&bucket_1, goal_liters)) {
      return (bucket_result_t){ .possible = true,
                                .move_count = move_count,
                                .goal_bucket = BUCKET_ID_1,
                                .other_bucket_liters =
                                    bucket_current(&bucket_2) };
   } else if (bucket_contains(&bucket_2, goal_liters)) {
      return (bucket_result_t){ .possible = true,
                                .move_count = move_count,
                                .goal_bucket = BUCKET_ID_2,
                                .other_bucket_liters =
                                    bucket_current(&bucket_1) };
   } else {
      return (bucket_result_t){ .possible = false };
   }
}
