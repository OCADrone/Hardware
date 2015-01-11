
#include "helpers.h"

static int s_char_sent = 0;
static int s_commands_sent = 0;

String splitString(String s, char parser, int index) {
  String rs = '\0';
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;
  
  while (index>=parserCnt){
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);
    if (index == parserCnt){
      if(rToIndex == 0 || rToIndex == -1){
        return '\0';
      }
      return s.substring(rFromIndex,rToIndex);
    }
    else{
      parserCnt++;
    }
  }
  return rs;
}

int countCharacter(String s, char c) {
  int count = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == c) count++;
  return count;
}

void resetSerial()
{
  s_char_sent = 0;
  s_commands_sent = 0;
}

int getCharSent()
{
  return (s_char_sent);
}

int getCommandsSent()
{
  return (s_commands_sent);
}

void serialCharIncrement(int i)
{
  s_char_sent += i;
}

void serialCommandIncrement()
{
  s_commands_sent++;
}
