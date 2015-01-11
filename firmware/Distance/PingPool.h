
#ifndef __PINGPOOL_H__
#define __PINGPOOL_H__

#include "../config.hpp"
#include "../helpers.h"
#include "../ISensor.hpp"

#include "./NewPing.h"

class PingPool : public ISensor
{
 private:
  NewPing *_pings[D_SIZE];
  int _distances[D_SIZE];
  unsigned int _nextTime;

  void loop();

 public:  
  PingPool();
  virtual void setup();
  virtual void update();
  String &getString(String &str);
};

#endif
