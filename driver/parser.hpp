
#ifndef __PARSER__H_
#define __PARSER__H_

#include <stdint.h>
#include <string>

class Parser
{

private:
  std::string _buff;
  char _delim;

public:
  Parser(char);
  void feed(const char *str);
  bool isReady();
  void getToken(std::string &dest);

};

#endif
