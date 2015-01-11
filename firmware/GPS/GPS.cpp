
#include "GPS.h"

GPS::GPS()
{

}

void GPS::setup()
{
  P_SERIAL.begin(P_SERIAL_BAUDRATE);
}

void GPS::update()
{
  char c;
  while (P_SERIAL.available())
    {
      c = P_SERIAL.read();
      if (_gps.encode(c))
	{
	  SEND(P_IDENTIFIER);
	  SEND(SERIAL_OUTPUT_DELIM);
	  SEND(_gps.location.lat());
	  SEND(SERIAL_OUTPUT_DELIM);
	  SEND(_gps.location.lng());
	  SEND(SERIAL_OUTPUT_DELIM);
	  SEND(_gps.altitude.meters());
	  SEND(SERIAL_OUTPUT_DELIM);
	  SEND(_gps.satellites.value());
	  SEND(SERIAL_OUTPUT_DELIM);
	  SENDLN(_gps.speed.mps());
	  return;
	}
      else
	{
	}
    }
}


