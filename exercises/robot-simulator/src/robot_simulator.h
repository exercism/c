#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

typedef enum {
   HEADING_NORTH = 0,
   HEADING_EAST,
   HEADING_SOUTH,
   HEADING_WEST,
   HEADING_MAX
} bearing_t;

enum {
   DEFAULT_BEARING = HEADING_NORTH,
   DEFAULT_X_COORDINATE = 0,
   DEFAULT_Y_COORDINATE = 0,
};

enum {
   COMMAND_LEFT = 'L',
   COMMAND_RIGHT = 'R',
   COMMAND_ADVANCE = 'A'
};

typedef struct robot_coordinates {
   int x_position;
   int y_position;
} robot_coordinates_t;

typedef struct robot_grid_status {
   bearing_t bearing;
   robot_coordinates_t grid;
} robot_grid_status_t;

robot_grid_status_t robot_init(void);
robot_grid_status_t robot_init_with_position(int bearing, int x, int y);
void robot_turn_right(robot_grid_status_t * robot);
void robot_turn_left(robot_grid_status_t * robot);
void robot_advance(robot_grid_status_t * robot);
void robot_simulator(robot_grid_status_t * robot, const char *commands);

#endif
