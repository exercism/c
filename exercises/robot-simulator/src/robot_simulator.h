#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

typedef enum {
   heading_north = 0,
   heading_east,
   heading_south,
   heading_west,
   heading_max
} bearing_t;

enum {
   default_bearing = heading_north,
   default_x_coordinate = 0,
   default_y_coordinate = 0,
};

enum {
   command_left = 'L',
   command_right = 'R',
   command_advance = 'A'
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
