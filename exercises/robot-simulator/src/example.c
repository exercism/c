#include <string.h>
#include "robot_simulator.h"

RobotGridStatus_t robot_init(void)
{
   return (robot_init_with_position
           (Default_Bearing, Default_X_Coordinate, Default_Y_Coordinate));
}

RobotGridStatus_t robot_init_with_position(int bearing, int x, int y)
{
   RobotGridStatus_t robot = { bearing, {x, y} };

   if ((bearing < Heading_North) || (bearing >= Heading_Max)) {
      robot.bearing = Default_Bearing;
   }
   return robot;
}

void robot_turn_right(RobotGridStatus_t * robot)
{
   robot->bearing = (robot->bearing + 1) % Heading_Max;
}

void robot_turn_left(RobotGridStatus_t * robot)
{
   robot->bearing = ((robot->bearing - 1) + Heading_Max) % Heading_Max;
}

void robot_advance(RobotGridStatus_t * robot)
{
   switch (robot->bearing) {
   case Heading_North:
      robot->grid.y_position++;
      break;

   case Heading_East:
      robot->grid.x_position++;
      break;

   case Heading_South:
      robot->grid.y_position--;
      break;

   case Heading_West:
      robot->grid.x_position--;
      break;

   default:
      break;
   }
}

void robot_simulator(RobotGridStatus_t * robot, const char *commands)
{
   for (unsigned long index = 0; index < strlen(commands); index++) {
      switch (commands[index]) {
      case Command_Left:
         robot_turn_left(robot);
         break;

      case Command_Right:
         robot_turn_right(robot);
         break;

      case Command_Advance:
         robot_advance(robot);
         break;

      default:
         break;
      }
   }
}
