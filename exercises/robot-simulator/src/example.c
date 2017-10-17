#include <string.h>
#include "robot_simulator.h"

robot_grid_status_t robot_init(void)
{
   return (robot_init_with_position
           (DEFAULT_BEARING, DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE));
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y)
{
   robot_grid_status_t robot = { bearing, {x, y} };

   if ((bearing < HEADING_NORTH) || (bearing >= HEADING_MAX)) {
      robot.bearing = DEFAULT_BEARING;
   }
   return robot;
}

void robot_turn_right(robot_grid_status_t * robot)
{
   robot->bearing = (robot->bearing + 1) % HEADING_MAX;
}

void robot_turn_left(robot_grid_status_t * robot)
{
   robot->bearing = ((robot->bearing - 1) + HEADING_MAX) % HEADING_MAX;
}

void robot_advance(robot_grid_status_t * robot)
{
   switch (robot->bearing) {
   case HEADING_NORTH:
      robot->grid.y_position++;
      break;

   case HEADING_EAST:
      robot->grid.x_position++;
      break;

   case HEADING_SOUTH:
      robot->grid.y_position--;
      break;

   case HEADING_WEST:
      robot->grid.x_position--;
      break;

   default:
      break;
   }
}

void robot_simulator(robot_grid_status_t * robot, const char *commands)
{
   for (unsigned long index = 0; index < strlen(commands); index++) {
      switch (commands[index]) {
      case COMMAND_LEFT:
         robot_turn_left(robot);
         break;

      case COMMAND_RIGHT:
         robot_turn_right(robot);
         break;

      case COMMAND_ADVANCE:
         robot_advance(robot);
         break;

      default:
         break;
      }
   }
}
