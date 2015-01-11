
#ifndef __H_MOTORS__
#define __H_MOTORS__

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif

#include "../config.hpp"
#include "../helpers.h"
#include <Servo.h>

class Motors
{
 public:
  void setup();
  void update(String &cmd);

 private:
  Servo m[M_NUMBERS];
};

#endif
