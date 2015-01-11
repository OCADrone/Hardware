
#ifndef __HELPERS_H_
#define __HELPERS_H_

#if defined(ARDUINO) && ARDUINO >= 100
        #include <Arduino.h>
#else
        #include <WProgram.h>
        #include <pins_arduino.h>
#endif

#include "config.hpp"

String splitString(String s, char parser,int index);
int countCharacter(String s, char c);

void resetSerial();
void serialCharIncrement(int i);
void serialCommandIncrement();

int getCharSent();
int getCommandsSent();

#define SEND(value) serialCharIncrement(SERIAL.print(value))
#define SENDLN(value) serialCharIncrement(SERIAL.println(value)); serialCommandIncrement()

#endif
