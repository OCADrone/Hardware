

#ifndef ____SERIAL_HPP__
#define ____SERIAL_HPP__

#include "serial.h"
#include <string>
#include <iostream>

class Serial
{
private:
  std::string _dev;
  int _baudrate;
  t_serial *_serial;

public:
  Serial(std::string name, int baudrate);
  int read(char*, int);
  int write(std::string &str);
};

#endif
