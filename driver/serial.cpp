
#include "serial.hpp"

Serial::Serial(std::string name, int baudrate)
  :_dev(name), _baudrate(baudrate)
{
  _serial = serial_new();
  if (_serial)
    {
      serial_open(_serial, (char *) name.c_str()); //FIXME CONST hack..
      serial_setBaud(_serial, baudrate);
    }
}

int Serial::read(char *buff, int count)
{
  int r = 1;

  r = serial_waitInput(_serial, 500);
  if (r > 0)
    return (serial_read(_serial, buff, count));
  else
    return (0);
}

int Serial::write(std::string &str)
{
  serial_discardInput(_serial);
  int res = serial_write(_serial, (const char *) str.c_str(), str.length() + 2);
  serial_flushOutput(_serial);
  //  std::cout << str.c_str() << std::endl;
  return (res);

}
