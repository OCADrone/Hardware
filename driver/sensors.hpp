
#ifndef __H_SENSORS__
#define __H_SENSORS__

#include <AIRegistry/client.hh>
#include "parser.hpp"

#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include <3DGeo/orientation.hh>
#include <3DGeo/vect.hh>

//#include "drone.hh"

#define FORCE_UNIT 1000
#define FORCE_GRAVITY 11
#define FORCE_TIME 1000000.0

void parse_distance(Parser&, AIRegistry::client &);
void parse_position(Parser&, AIRegistry::client &);
void parse_force(Parser&, AIRegistry::client &);
void parse_statistics(Parser&, AIRegistry::client &);

#endif
