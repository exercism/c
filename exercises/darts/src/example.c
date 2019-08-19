#include "darts.h"
#include <stdbool.h>
#include <math.h>

static const float INNER_CIRCLE_RADIUS = 1;
static const float MIDDLE_CIRCLE_RADIUS = 5;
static const float OUTER_CIRCLE_RADIUS = 10;

static const uint8_t INNER_CIRCLE_SCORE = 10;
static const uint8_t MIDDLE_CIRCLE_SCORE = 5;
static const uint8_t OUTER_CIRCLE_SCORE = 1;
static const uint8_t OFF_BOARD_SCORE = 0;

static float distanceFromOrigin(coordinate_t point)
{
   // calculate distance using pythagorean theorem:
   // d = sqrt(|xC - xP|^2 + |yC - yP|^2)
   // where xC and yC are 0 (the origin) in this case
   return sqrt(point.x * point.x + point.y * point.y);
}

uint8_t score(coordinate_t landing_position)
{
   uint8_t score = OFF_BOARD_SCORE;
   float landingPositionDistanceFromOrigin =
       distanceFromOrigin(landing_position);

   if (landingPositionDistanceFromOrigin <= INNER_CIRCLE_RADIUS)
      score = INNER_CIRCLE_SCORE;
   else if (landingPositionDistanceFromOrigin <= MIDDLE_CIRCLE_RADIUS)
      score = MIDDLE_CIRCLE_SCORE;
   else if (landingPositionDistanceFromOrigin <= OUTER_CIRCLE_RADIUS)
      score = OUTER_CIRCLE_SCORE;

   return score;
}
