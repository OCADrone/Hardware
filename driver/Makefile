



CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS = $(wildcard **/*.cpp) $(wildcard **/*.c) $(wildcard *.cpp) $(wildcard *.c)

all:
	g++ -std=c++0x $(SRCS) -lAIRegistry -lKNM -Wl,-rpath /usr/local/lib -I /usr/local/include/KNM/ -I /usr/local/include/KNM/base/ -I /usr/local/include/KNM/net/ -I ../../OCADrone-Flight/common/ -I /usr/local/include/AIRegisty/ -I /usr/local/include/3DGeo -l3DGeo -lm -ldl -o driver
