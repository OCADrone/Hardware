
#ifndef __ISENSOR_H__
#define __ISENSOR_H__

class ISensor
{
private:

public:
  virtual void update(void) = 0;
  virtual void setup(void) = 0;
};

#endif
