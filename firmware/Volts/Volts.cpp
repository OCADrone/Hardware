
#include "Volts.h"

void Volts::setup()
{
  pinMode(V_PIN, OUTPUT);
}

void Volts::update()
{
  updateValue();
  sendValue();
}

void Volts::updateValue()
{
  int read;
  float temp;

  read = analogRead(V_PIN);
  temp = read * 5 /1024;  //FIXME
  _value = (int)temp;
}

void Volts::sendValue()
{
  SEND(V_IDENTIFIER);
  SEND(SERIAL_OUTPUT_DELIM);
  SENDLN(_value);
}
