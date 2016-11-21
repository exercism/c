#ifndef _ROBOT_SIMULATOR_H
#define _ROBOT_SIMULATOR_H

typedef enum {
   HeadingNorth = 0,
   HeadingEast,
   HeadingSouth,
   HeadingWest,
   HeadingMax
} Bearing_t;

typedef struct RobotCoordinates {
   int x_position;
   int y_position;
} Robott_Coordinates_t;

typedef struct RobotGridStatus {
   Robott_Coordinates_t grid;
   Bearing_t bearing;
} RobotGridStatus_t;

RobotGridStatus_t robot_init(Bearing_t bearing, int x_coordinate,
                             int y_coordinate);
void robot_turn_right(RobotGridStatus_t * robot);
void robot_turn_left(RobotGridStatus_t * robot);
void robot_advance(RobotGridStatus_t * robot);
void robot_simulator(RobotGridStatus_t * robot, unsigned char *commands);

#endif
