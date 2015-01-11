
#ifndef __H_SENSORS__
#define __H_SENSORS__

#include <AIRegistry/client.hh>
#include "parser.hpp"
//#include "drone.hh"

void parse_distance(Parser&, AIRegistry::client &);
void parse_position(Parser&, AIRegistry::client &);
void parse_force(Parser&, AIRegistry::client &);
void parse_statistics(Parser&, AIRegistry::client &);

#endif
