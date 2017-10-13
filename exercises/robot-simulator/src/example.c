#include <string.h>
#include "robot_simulator.h"

robot_grid_status_t robot_init(void)
{
   return (robot_init_with_position
           (default_bearing, default_x_coordinate, default_y_coordinate));
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y)
{
   robot_grid_status_t robot = { bearing, {x, y} };

   if ((bearing < heading_north) || (bearing >= heading_max)) {
      robot.bearing = default_bearing;
   }
   return robot;
}

void robot_turn_right(robot_grid_status_t * robot)
{
   robot->bearing = (robot->bearing + 1) % heading_max;
}

void robot_turn_left(robot_grid_status_t * robot)
{
   robot->bearing = ((robot->bearing - 1) + heading_max) % heading_max;
}

void robot_advance(robot_grid_status_t * robot)
{
   switch (robot->bearing) {
   case heading_north:
      robot->grid.y_position++;
      break;

   case heading_east:
      robot->grid.x_position++;
      break;

   case heading_south:
      robot->grid.y_position--;
      break;

   case heading_west:
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
      case command_left:
         robot_turn_left(robot);
         break;

      case command_right:
         robot_turn_right(robot);
         break;

      case command_advance:
         robot_advance(robot);
         break;

      default:
         break;
      }
   }
}
