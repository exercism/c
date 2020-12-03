#ifndef TWO_BUCKET_H
#define TWO_BUCKET_H

#include <stdbool.h>

typedef enum {
   bucket_id_1,
   bucket_id_2
} bucket_id_t;

typedef unsigned int bucket_volume_t;

typedef struct {
   bool possible;
   int move_count;
   bucket_id_t goal_bucket;
   bucket_volume_t other_bucket_volume;
} bucket_result_t;

bucket_result_t measure(bucket_volume_t bucket_1_size,
                        bucket_volume_t bucket_2_size,
                        bucket_volume_t goal_volume, bucket_id_t start_bucket);

#endif
