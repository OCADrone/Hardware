/*
 
 */
#include "config.hpp"
 
/*
** SENSORS
*/
#include "ISensor.hpp"
#include "Distance/PingPool.h"
#include "GPS/GPS.h"
#include "Forces/Forces.h"
#include "Statistics/Statistics.h"
#include "Volts/Volts.h"
#include "Motors/Motors.h"
#include "Position/Position.h"

PingPool pingPool;
GPS gps;
Forces forces;
Statistics stats;
Volts volts;
Position position;

Motors motors;

void readSerial(String &cmd)
{
  char c;

  while (SERIAL.available() > 0) {
    c = (char) SERIAL.read();
    if (c == '\n') {
      cmd += (char) c;
      motors.update(cmd);
      cmd = "";
    }
    else if (c == 'M') {
      cmd = "";
    } else {
      cmd += (char) c; 
    }
  }
}


void setup() {
  SERIAL.begin(SERIAL_BAUDRATE);
  //  pingPool.setup();
  // gps.setup();
  position.setup();
//  forces.setup(); //Old Force sensors
//  stats.setup();
//  volts.setup();
  
  motors.setup();
}

String cmd = "";

void loop() {
  
  readSerial(cmd);
  
//  pingPool.update();


//  gps.update();
  position.update();
//  stats.update();
//  forces.update();
//  volts.update();  
}

