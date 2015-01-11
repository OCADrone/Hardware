
#ifndef __H_POSITION__
#define __H_POSITION__

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif

#include "../config.hpp"
#include "../helpers.h"
#include "../ISensor.hpp"

#include "./Adafruit_Sensor.h"
#include "./Adafruit_LSM303_U.h"
#include "./Adafruit_BMP085_U.h"
#include "./Adafruit_L3GD20_U.h"
#include "./Adafruit_10DOF.h"

class Position : public ISensor
{
 private:

  Adafruit_LSM303_Accel_Unified accel;
  Adafruit_LSM303_Mag_Unified   mag;
  Adafruit_BMP085_Unified       bmp;
  Adafruit_L3GD20_Unified       gyro; 
  Adafruit_10DOF                dof;

 public:

  //  Position();
  virtual void setup();
  virtual  void update();

  
};

#endif
