
#ifndef __VOLTS_H_
#define __VOLTS_H_

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif

#include "../config.hpp"
#include "../helpers.h"
#include "../ISensor.hpp"

class Volts : public ISensor
{
 private:
  float _value;
  
  void updateValue();
  void sendValue();

 public:
  virtual void setup();
  virtual  void update();

};

#endif
