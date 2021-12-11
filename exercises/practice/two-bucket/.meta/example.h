#ifndef TWO_BUCKET_H
#define TWO_BUCKET_H

#include <stdbool.h>

typedef enum { BUCKET_ID_1, BUCKET_ID_2 } bucket_id_t;

typedef unsigned int bucket_liters_t;

typedef struct {
   bool possible;
   int move_count;
   bucket_id_t goal_bucket;
   bucket_liters_t other_bucket_liters;
} bucket_result_t;

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket);

#endif
