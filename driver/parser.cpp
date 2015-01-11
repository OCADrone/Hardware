
#include "parser.hpp"

#include <iostream>
#include <stdint.h>

Parser::Parser(char delim)
{
  _delim = delim;
}

void Parser::feed(const char *str)
{
  std::string tmp(str);

  _buff += tmp;
}

bool Parser::isReady()
{
  std::size_t found = _buff.find(_delim);
  return (found!=std::string::npos);
}

void Parser::getToken(std::string &dest)
{
  std::size_t pos = _buff.find(_delim);
  dest = _buff.substr(0, pos);
  _buff.erase(0, pos + 1);
}
