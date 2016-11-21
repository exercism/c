#include "robot_simulator.h"

RobotGridStatus_t robot_init(Bearing_t bearing, int x_coordinate,
                             int y_coordinate)
{
   RobotGridStatus_t robot = { {0, 0}, 0 };

   (void)bearing;
   (void)x_coordinate;
   (void)y_coordinate;

   return robot;
}

void robot_turn_right(RobotGridStatus_t * robot)
{
   (void)robot;
}

void robot_turn_left(RobotGridStatus_t * robot)
{
   (void)robot;
}

void robot_advance(RobotGridStatus_t * robot)
{
   (void)robot;
}

void robot_simulator(RobotGridStatus_t * robot, unsigned char *commands)
{
   (void)robot;
   (void)commands;
}
