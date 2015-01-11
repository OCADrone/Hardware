
#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef DRIVER
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#endif

/*
** GENERAL
*/

#define SERIAL Serial
#define SERIAL_OUTPUT_DELIM ';'
#define SERIAL_LINE_DELIM '\n'

#define SERIAL_BAUDRATE 9600
#define SERIAL_PORT "/dev/ttyACM0"

/*
*	DISTANCE
*/

// We define pins for the distance sensors
// The compatible Distance sensors are: SR04, SRF05, SRF06, DYP-ME007 & Parallax PING)))

#define D_IDENTIFIER 'D'

#define D_SIZE 6 //They are 6 distance sensors.

#define PIN_D_ECHO_FRONT 41
#define PIN_D_TRIG_FRONT 40
#define PIN_D_ECHO_RIGHT 52
#define PIN_D_TRIG_RIGHT 53
#define PIN_D_ECHO_BACK 36
#define PIN_D_TRIG_BACK 37
#define PIN_D_ECHO_LEFT 32
#define PIN_D_TRIG_LEFT 33
#define PIN_D_ECHO_UP 34
#define PIN_D_TRIG_UP 35
#define PIN_D_ECHO_UNDER 60
#define PIN_D_TRIG_UNDER 60

#define D_FRONT 0
#define D_RIGHT 1
#define D_BACK 2
#define D_LEFT 3
#define D_UP 4
#define D_UNDER 5

#define D_NOT_SET -1

#define D_MAXDISTANCE 300 // Maximum distance (in cm) to ping.
#define D_PING_INTERVAL 50 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

/*
 *	GPS
 */

//P obviously stands for position

//This GPS code is made for any Serial GPS using NMEA 183 (we use TinyGPS lib)

#define P_IDENTIFIER 'P'

#define P_SERIAL Serial3 //Serial to use for GPS
#define P_SERIAL_BAUDRATE 9600 //baudrate of the GPS


/*
**	FORCE
*/

//F stands (not obviously) stands for Accelerometer

#define F_IDENTIFIER 'F'

#define DMP9150
#define MPU9150

/*
**	MOTORS
*/

#define M_IDENTIFIER 'M'

#define M_NUMBERS 4

#define M_1_PIN 11
#define M_2_PIN 10
#define M_3_PIN 6
#define M_4_PIN 5

/*
**	STATISTICS
*/

#define S_IDENTIFIER 'S'

/*
**	VOLTS
*/

#define V_IDENTIFIER 'V'
#define V_PIN 44

#define V_VOLTCONSTANT 4.092

#endif
