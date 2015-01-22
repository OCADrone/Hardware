
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
  static Vect speed(0, 0, 0);
  static double sumx, sumy, sumz;
  static int iterator = 0;
  static double altitude = -1;

  double alti;
  int tmptime  = 0;
  std::string tmp, ox, oy, oz, ax, ay, az, temp, alt;
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
  parser.getToken(ay);
  parser.getToken(az);
  parser.getToken(temp);
  parser.getToken(alt);

  alti = stringToAngle(alt);
  if (altitude == -1)
    altitude = alti;
  client.query(AIRegistry::WRITE, PATH_SPEED, ares.str());
  Vect begin(stringToAngle(ax) * FORCE_UNIT, stringToAngle(ay) * FORCE_UNIT, stringToAngle(az) * FORCE_UNIT);
  Position a(Gps(0,0,0), Vect(0, 0, (alti - altitude) * 1000));
  client.query(AIRegistry::WRITE, PATH_POSITION, a.Serialize());
  Vect gravity(0, 0, -(FORCE_GRAVITY * FORCE_UNIT));
  gravity.RotX(o.X().GetRad());
  gravity.RotY(o.Y().GetRad());
  gravity.RotZ(o.Z().GetRad());
  
  o = o * FORCE_UNIT;
  gravity = begin - gravity;
  //  std::cout << gravity << std::endl;  
  double sec = (tmptime - time) / FORCE_TIME;
  double timespan = 1.0 / sec;
  
  //  gravity = gravity * timespan;
  speed = speed + gravity;

  time = tmptime;
  std::cout << "Orientation (deg) : " << ox << ";" << oy << ";" << oz  << std::endl;
  std::cout << "Acceleration (N) : " << ax << ";" << ay << ";" << az << std::endl;
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

