

#include "PingPool.h"

PingPool::PingPool()
{
  _pings[D_FRONT] = new NewPing(PIN_D_TRIG_FRONT, PIN_D_ECHO_FRONT, D_MAXDISTANCE);
  _pings[D_RIGHT] = new NewPing(PIN_D_TRIG_RIGHT, PIN_D_ECHO_RIGHT, D_MAXDISTANCE);
  _pings[D_BACK] = new NewPing(PIN_D_TRIG_BACK, PIN_D_ECHO_BACK, D_MAXDISTANCE);
  _pings[D_LEFT] = new NewPing(PIN_D_TRIG_LEFT, PIN_D_ECHO_LEFT, D_MAXDISTANCE);
  _pings[D_UP] = new NewPing(PIN_D_TRIG_UP, PIN_D_ECHO_UP, D_MAXDISTANCE);
  _pings[D_UNDER] = new NewPing(PIN_D_TRIG_UNDER, PIN_D_ECHO_UNDER, D_MAXDISTANCE);
  
  for (int i = 0; i < D_SIZE; i++) // Set the starting time for each sensor.
    {
      _distances[i] = D_NOT_SET;
    }
  _nextTime = millis() + D_PING_INTERVAL;
}

void PingPool::setup()
{
}

void PingPool::update()
{
  String str = "";
  loop();
  str = getString(str);
  SENDLN(str);
}

void PingPool::loop()
{

  if (_nextTime < millis())
    {
      for (int i = 0; i < D_SIZE; i++) { // Loop through all the sensors.
	_distances[i] = _pings[i]->ping_cm();
      }
      _nextTime = millis() + D_PING_INTERVAL * 2;
    }
}

String &PingPool::getString(String &str)
{
  str += D_IDENTIFIER;
  for (int i = 0; i < D_SIZE; i++) { // Loop through all the sensors.
    str += SERIAL_OUTPUT_DELIM;
    str += _distances[i];
  }
  return (str);
}

