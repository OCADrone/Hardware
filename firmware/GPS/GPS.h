
#ifndef __GPS_H_
#define __GPS_H_

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif

#include "../config.hpp"
#include "../helpers.h"
#include "TinyGPS++.h"
#include "../ISensor.hpp"

class GPS : public ISensor
{
 private:
  TinyGPSPlus _gps;

  double _flat, _flon;
  unsigned long _fix_age;
  double _falt;
  double _fc;
  double _fmps;

 public:
  GPS();
  virtual void setup();
  void getString(String &s);
  virtual  void update();

};

#endif
