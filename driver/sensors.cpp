
#include "sensors.hpp"
#include "main.hpp"

extern double front;
extern double side;

void parse_distance(Parser &parser, AIRegistry::client &client)
{
  std::string tmp;

  parser.getToken(tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_FRONT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_RIGHT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_BACK, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_LEFT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_UNDER, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_UP, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_FRONTLEFT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_DISTANCE_FRONTRIGHT, tmp);
}

void parse_position(Parser&parser, AIRegistry::client &client)
{
  std::string tmp;

  parser.getToken(tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_GPS_LAT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_GPS_LON, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_GPS_ALT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_GPS_SAT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_GPS_MPS, tmp);
}

double angleToRad(std::string &s)
{
  double angle = ::atof(s.c_str());
  return ((double)(angle) * 1000000);
}

void parse_force(Parser &parser, AIRegistry::client &client)
{
  std::string tmp;
  std::stringstream res;

  parser.getToken(tmp);
  parser.getToken(tmp);
  side = ::atof(tmp.c_str());
  res << angleToRad(tmp);
  res << ';';
  parser.getToken(tmp);
  front = ::atof(tmp.c_str());
  res << angleToRad(tmp);
  res << ';';
  parser.getToken(tmp);
  res << angleToRad(tmp);
  //  std::cout << res.str() << std::endl;
  client.query(AIRegistry::WRITE, PATH_ORIENTATION, res.str());

  client.query(AIRegistry::WRITE, PATH_ROT_SPEED, "1;1;0");

   client.query(AIRegistry::WRITE, PATH_SPEED, "100000;10000;100");

  /*  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_GX, tmp);
  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_GY, tmp);
  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_GZ, tmp);

  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_MX, tmp);
  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_MY, tmp);
  parser.getToken(tmp);
  client.query(registry::WRITE, PATH_FORCES_MZ, tmp);
  */
}

void parse_statistics(Parser &parser, AIRegistry::client &client)
{
  std::string tmp;

  parser.getToken(tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_STATS_CURRENTMILLIS, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_STATS_UPDATEDURATION, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_STATS_CHARSENT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_STATS_COMMANDSENT, tmp);
  parser.getToken(tmp);
  client.query(AIRegistry::WRITE, PATH_STATS_FREERAM, tmp);
}

