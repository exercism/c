#include <stdarg.h>
#include <string.h>
#include "robot_simulator.h"

RobotGridStatus_t robot_init(int argCount, ...)
{
   RobotGridStatus_t robot =
       { Default_Bearing, {Default_X_Coordinate, Default_Y_Coordinate} };
   va_list valist;
   int argument;

   va_start(valist, argCount);

   for (int index = 0; (index < argCount) && (index < 3); index++) {
      argument = va_arg(valist, int);
      switch (index) {
      case 0:
         if ((argument >= HeadingNorth) && (argument < HeadingMax)) {
            robot.bearing = (Bearing_t) argument;
         }
         break;

      case 1:
         robot.grid.x_position = argument;
         break;

      case 2:
         robot.grid.y_position = argument;
         break;
      }
   }
   return robot;
}

void robot_turn_right(RobotGridStatus_t * robot)
{
   robot->bearing = (robot->bearing + 1) % HeadingMax;
}

void robot_turn_left(RobotGridStatus_t * robot)
{
   robot->bearing = ((robot->bearing - 1) + HeadingMax) % HeadingMax;
}

void robot_advance(RobotGridStatus_t * robot)
{
   switch (robot->bearing) {
   case HeadingNorth:
      robot->grid.y_position++;
      break;

   case HeadingEast:
      robot->grid.x_position++;
      break;

   case HeadingSouth:
      robot->grid.y_position--;
      break;

   case HeadingWest:
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
