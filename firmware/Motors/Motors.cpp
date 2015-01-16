
#include "./Motors.h"

void Motors::setup()
{
  m[0].attach(M_1_PIN);
  m[1].attach(M_2_PIN);
  m[2].attach(M_3_PIN);
  m[3].attach(M_4_PIN);
}

void Motors::update(String &cmd)
{
  m[0].write(atoi(splitString(cmd, SERIAL_OUTPUT_DELIM, 1).c_str()));
  m[1].write(atoi(splitString(cmd, SERIAL_OUTPUT_DELIM, 2).c_str()));
  m[2].write(atoi(splitString(cmd, SERIAL_OUTPUT_DELIM, 3).c_str()));
  m[3].write(atoi(splitString(cmd, SERIAL_OUTPUT_DELIM, 4).c_str()));
  SEND(splitString(cmd, SERIAL_OUTPUT_DELIM, 1).c_str());
}
