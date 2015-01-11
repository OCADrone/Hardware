
#include "Statistics.h"

void Statistics::setup()
{
}

void Statistics::update()
{
  unsigned long currentMillis = millis();

  SEND(S_IDENTIFIER);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(currentMillis);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(currentMillis - _lastMillis);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(getCharSent());
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(getCommandsSent());
  SEND(SERIAL_OUTPUT_DELIM);
  SENDLN(freeRam());

  resetSerial();
  _lastMillis = millis();
}

int Statistics::freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
