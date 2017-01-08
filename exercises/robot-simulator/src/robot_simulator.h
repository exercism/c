#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

typedef enum {
   Heading_North = 0,
   Heading_East,
   Heading_South,
   Heading_West,
   Heading_Max
} Bearing_t;

enum {
   Default_Bearing = Heading_North,
   Default_X_Coordinate = 0,
   Default_Y_Coordinate = 0,
};

enum {
   Command_Left = 'L',
   Command_Right = 'R',
   Command_Advance = 'A'
};

typedef struct RobotCoordinates {
   int x_position;
   int y_position;
} RobotCoordinates_t;

typedef struct RobotGridStatus {
   Bearing_t bearing;
   RobotCoordinates_t grid;
} RobotGridStatus_t;

RobotGridStatus_t robot_init(void);
RobotGridStatus_t robot_init_with_position(int bearing, int x, int y);
void robot_turn_right(RobotGridStatus_t * robot);
void robot_turn_left(RobotGridStatus_t * robot);
void robot_advance(RobotGridStatus_t * robot);
void robot_simulator(RobotGridStatus_t * robot, const char *commands);

#endif
