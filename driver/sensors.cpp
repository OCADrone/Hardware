
#include "sensors.hpp"
#include "main.hpp"

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
  std::string tmp, ox, oy, oz, ax, ay, az;
  std::stringstream ores, ares;

  parser.getToken(tmp);
  parser.getToken(ox);
  ores << angleToRad(ox);
  ores << ';';
  parser.getToken(oy);
  ores << angleToRad(oy);
  ores << ';';
  parser.getToken(oz);
  ores <<  angleToRad(oz);
  client.query(AIRegistry::WRITE, PATH_ORIENTATION, ores.str());

  parser.getToken(ax);
  ares << ax;
  ares << ';';
  parser.getToken(ay);
  ares << ay;
  ares << ';';
  parser.getToken(az);
  ares <<  az;
  client.query(AIRegistry::WRITE, PATH_SPEED, ares.str());

  client.query(AIRegistry::WRITE, PATH_ROT_SPEED, "1;1;0");

   std::cout << "Orientation (deg) : " << ox << ";" << oy << ";" << oz << "  (rad) : " << ores.str() << std::endl;
   std::cout << "Acceleration (N) : " << ax << ";" << ay << ";" << az << "  (N) : " << ares.str() << std::endl;
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

