#ifndef __STATS_H_
#define __STATS_H_

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif


#include "../config.hpp"
#include "../helpers.h"
#include "../ISensor.hpp"

class Statistics : public ISensor
{
 private:

  unsigned long _lastMillis;

  int freeRam();

 public:

  virtual void setup();
  virtual  void update();

};

#endif
