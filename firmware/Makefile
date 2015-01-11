#
# The OCADrone Firmware
# http://ocadrone.com/
#

# Please install https://github.com/sudar/Arduino-Makefile
#You may also need to install 'screen' for monitor debugging

# Commands: (guide can be found here: http://hardwarefun.com/tutorials/compiling-arduino-sketches-using-makefile
# make upload 
# make monitor

#Please see Config.h for Sensors and pins configuration

#You may have to change few variables here:
ARDUINO_DIR   = /usr/share/arduino
ARDMK_DIR     = /usr/share/arduino
AVR_TOOLS_DIR = /usr/bin
AVR_TOOLS_PATH = /usr/bin

BOARD_TAG     = mega2560
#BOARD_TAG     = uno
MONITOR_PORT  = /dev/ttyACM0

AVRDDUDE     = /usr/bin/avrdude
AVRDUDE_CONF = /etc/avrdude/avrdude.conf

#Set sources
LOCAL_C_SRCS    ?= $(wildcard *.c) $(wildcard */*.c)
LOCAL_CPP_SRCS  ?= $(wildcard *.cpp) $(wildcard */*.cpp)

CXXFLAGS         += -pedantic -Wall -Wextra
CFLAGS_STD      = -lm

ARDUINO_LIBS = Servo Wire EEPROM 

// Custom Rules for easing :)
re: clean all

reup: clean upload

#Go for Arduino specific
include /usr/share/arduino/Arduino.mk
