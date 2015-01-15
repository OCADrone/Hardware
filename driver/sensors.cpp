
#include "sensors.hpp"
#include "main.hpp"


int getRealTime( )
{
  struct timeval tm;
  gettimeofday( &tm, NULL );
  return (int) ((tm.tv_sec * 1000000 + tm.tv_usec));
}

double stringToAngle(std::string &s)
{
  double angle = ::atof(s.c_str());
  return ((double)(angle));
}

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

void parse_force(Parser &parser, AIRegistry::client &client)
{
  static int time = 1;
  static Orientation otmp;
  
  int tmptime  = 0;
  std::string tmp, ox, oy, oz, ax, ay, az;
  std::stringstream ores, ares;

  tmptime = getRealTime();
  parser.getToken(tmp);
  parser.getToken(ox);
  parser.getToken(oy);
  parser.getToken(oz);

  Orientation o(Angle(Angle::DegToRad(stringToAngle(ox))), Angle::DegToRad(stringToAngle(oy)), Angle::DegToRad(stringToAngle(oz)));
  Orientation v = otmp - o;
  v = v / (tmptime - time);
  //  std::cout <<  v << std::endl;;
  client.query(AIRegistry::WRITE, PATH_ORIENTATION, o.Serialize());
  client.query(AIRegistry::WRITE, PATH_ROT_SPEED, v.Serialize());
  otmp = o;
  parser.getToken(ax);
  ares << ax;
  ares << ';';
  parser.getToken(ay);
  ares << ay;
  ares << ';';
  parser.getToken(az);
  ares <<  az;

  client.query(AIRegistry::WRITE, PATH_SPEED, ares.str());
  Vect begin(stringToAngle(ax) * FORCE_UNIT, stringToAngle(ay) * FORCE_UNIT, stringToAngle(az) * FORCE_UNIT);
  Vect gravity(0, 0, -(FORCE_GRAVITY * FORCE_UNIT));
  gravity.RotX(o.X().GetRad());
  gravity.RotY(o.Y().GetRad());
  gravity.RotZ(o.Z().GetRad());


  o = o * FORCE_UNIT;
  gravity = begin - gravity;
  double sec = (tmptime - time) / FORCE_TIME;
  double timespan = 1.0 / sec;
  gravity = gravity * timespan;
  //std::cout << o << std::endl;
  //  std::cout << "Diff time = " << tmptime - time << std::endl;
  time = tmptime;
  // std::cout << "Orientation (deg) : " << ox << ";" << oy << ";" << oz << "  (rad) : " << ores.str() << std::endl;
  // std::cout << "Acceleration (N) : " << ax << ";" << ay << ";" << az << "  (N) : " << ares.str() << std::endl;
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

