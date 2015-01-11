
#ifndef __FORCES_H_
#define __FORCES_H_

#include "../config.hpp"
#include "../helpers.h"
#include "../ISensor.hpp"

#include "Wire.h"
#include "I2Cdev.h"
#include "RTIMUSettings.h"
#include "RTIMU.h"
#include "RTFusionRTQF.h" 
#include "CalLib.h"
#include "EEPROM.h"

class Forces : public ISensor
{
 private:
  RTIMU *imu;                                           // the IMU object
  RTFusionRTQF fusion;                                  // the fusion object
  RTIMUSettings settings;                               // the settings object

#define DISPLAY_INTERVAL  300                         // interval between pose displays
#define  SERIAL_PORT_SPEED  115200

  unsigned long lastDisplay;
  unsigned long lastRate;
  int sampleCount;


 public:
  virtual void setup();
  virtual void update();
};

#endif
