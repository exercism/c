#include "../src/robot_simulator.h"
#include "vendor/unity.h"

int main(void)
{
   UnityBegin("test/test_word_count.c");

//   RUN_TEST(test_word_count_one_word);

   UnityEnd();

   return 0;
}

#if (0)

Stuff from Python equivalent ....Description ...
A robot factory 's test facility needs a program to verify robot movements.

The robots have three possible movements:

turn right
turn left
advance
Robots are placed on a hypothetical infinite grid, facing a particular direction
(north, east, south, or west) at a set of {x,y} coordinates, e.g., {3,8}, with coordinates
increasing to the north and east.

The robot then receives a number of instructions, at which point the testing facility
verifies the robot' s new position, and in which direction it is pointing.The letter - string "RAALAL" means:Turn right Advance twice Turn left Advance once Turn left yet again Say a robot starts at {
7, 3}
facing north.Then running this stream of instructions should leave it at {
9, 4}
facing west.....The tests from python .... {
   "#":["Some tests have two expectations: one for the position, one for the direction", "Optionally, you can also test", " - An invalid direction throws an error", " - An invalid instruction throws an error", " - Default starting position and direction if none are provided"], "create": {
 "description": "A robot is created with a position and a direction", "cases":[ {
 "description": "Robots are created with a position and direction", "robot":{
 "position": "(0,0)", "direction":"north"}
       , "expected": {
 "position": "(0,0)", "direction":"north"}
       }
       , {
 "description": "Negative positions are allowed", "robot":{
 "position": "(-1,-1)", "direction":"south"}
 , "expected":{
 "position": "(-1,-1)", "direction":"south"}
       }
      ]
   }
 , "turn_right":{
 "description": "rotates the robot's direction 90 degrees clockwise", "cases":[ {
 "description": "does not change the position", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "position":"(0,0)"}
       }
       , {
 "description": "changes the direction from north to east", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "direction":"east"}
       }
       , {
 "description": "changes the direction from east to south", "robot":{
 "position": "(0,0)", "direction":"east"}
 , "expected":{
 "direction":"south"}
       }
       , {
 "description": "changes the direction from south to west", "robot":{
 "position": "(0,0)", "direction":"south"}
 , "expected":{
 "direction":"west"}
       }
       , {
 "description": "changes the direction from west to north", "robot":{
 "position": "(0,0)", "direction":"west"}
 , "expected":{
 "direction":"north"}
       }
      ]
   }
 , "turn_left":{
 "description": "rotates the robot's direction 90 degrees counter-clockwise", "cases":[ {
 "description": "does not change the position", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "position":"(0,0)"}
       }
       , {
 "description": "changes the direction from north to west", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "direction":"west"}
       }
       , {
 "description": "changes the direction from west to south", "robot":{
 "position": "(0,0)", "direction":"west"}
 , "expected":{
 "direction":"south"}
       }
       , {
 "description": "changes the direction from south to east", "robot":{
 "position": "(0,0)", "direction":"south"}
 , "expected":{
 "direction":"east"}
       }
       , {
 "description": "changes the direction from east to north", "robot":{
 "position": "(0,0)", "direction":"east"}
 , "expected":{
 "direction":"north"}
       }
      ]
   }
 , "advance":{
 "description": "moves the robot forward 1 space in the direction it is pointing", "cases":[ {
 "description": "does not change the direction", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "direction":"north"}
       }
       , {
 "description": "increases the y coordinate one when facing north", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "expected":{
 "position":"(0,1)"}
       }
       , {
 "description": "decreases the y coordinate by one when facing south", "robot":{
 "position": "(0,0)", "direction":"south"}
 , "expected":{
 "position":"(0,-1)"}
       }
       , {
 "description": "increases the x coordinate by one when facing east", "robot":{
 "position": "(0,0)", "direction":"east"}
 , "expected":{
 "position":"(1,0)"}
       }
       , {
 "description": "decreases the x coordinate by one when facing west", "robot":{
 "position": "(0,0)", "direction":"west"}
 , "expected":{
 "position":"(-1,0)"}
       }
      ]
   }
 , "instructions":{
 "description": "Where R = Turn Right, L = Turn Left and A = Advance, the robot can follow a series of instructions and end up with the correct position and direction", "cases":[ {
 "description": "instructions to move west and north", "robot":{
 "position": "(0,0)", "direction":"north"}
 , "instructions": "LAAARALA", "expected":{
 "position": "(-4,1)", "direction":"west"}
       }
       , {
 "description": "instructions to move west and south", "robot":{
 "position": "(2,-7)", "direction":"east"}
 , "instructions": "RRAAAAALA", "expected":{
 "position": "(-3,-8)", "direction":"south"}
       }
       , {
 "description": "instructions to move east and north", "robot":{
 "position": "(8,4)", "direction":"south"}
 , "instructions": "LAAARRRALLLL", "expected":{
 "position": "(11,5)", "direction":"north"}
       }
      ]
   }
}

#endif
