#ifndef PADS_PARAMS_H
#define PADS_PARAMS_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Delay in secs
#define delay 1

//Define address of temperature, pressure, frequency and central nodes
#define blade1 1
#define blade2 2
#define blade3 3
#define blade4 4
//#define vibration 5
#define central_node 5

//Defines Alarm Value
int blade_alarm = 85;
//int vibration_alarm = 10;

//Defines ShutDown Value
int blade_shutdown = 105;
//int vibration_shutdown = 20;

//Set values to be transmitted
int bladeOne[] = {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};
int bladeTwo[] = {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};
int bladeThree[] = {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};
int bladeFour[] = {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};


#endif // PADS_PARAMS_H

