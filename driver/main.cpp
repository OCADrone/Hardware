

#include	"main.hpp"

double front = 0;
double side = 0;

int first = 1;

void dispatchCmd(std::string &cmd, AIRegistry::client &client)
{
  Parser parser_cmd(SERIAL_OUTPUT_DELIM);
  char type = cmd[0];
  
  parser_cmd.feed(cmd.c_str());
  if (parser_cmd.isReady())
    {
      switch(type) {
      case D_IDENTIFIER :
	parse_distance(parser_cmd, client);
	break;
      case P_IDENTIFIER :
	parse_position(parser_cmd, client);
	break;
      case F_IDENTIFIER :
	parse_force(parser_cmd, client);
	break;
      case S_IDENTIFIER :
	parse_statistics(parser_cmd, client);
	break;
      }
    }
}

int getMotorValue(AIRegistry::client &registry, std::string path)
{
  string tmp = "";
  int res = 0;

  tmp = registry.query(AIRegistry::READ, path);
  istringstream(tmp) >> res;
  std::cout << path << " : GET : " << res << std::endl; 
  return (res);
}


void dispatchMotors(AIRegistry::client &client, Serial &serial)
{
  std::cout << "MOTTTTTTTTTTOR" << std::endl;
  int m1, m2, m3, m4;
  std::stringstream str;

  m1 = getMotorValue(client, PATH_MOTOR1);
  m2 = getMotorValue(client, PATH_MOTOR2);
  m3 = getMotorValue(client, PATH_MOTOR3);
  m4 = getMotorValue(client, PATH_MOTOR4);

  if (first == 1 && m1 == 30 && m2 == 30 && m3 == 69 && m4 == 30)
    {
      first = 0;
      return;
    }
  if (first == 1)
    return;
  //  m2 = front * 100 + side * 100;
  //m3 = front * -100 + side * 100;
  //m4 = front * 100;
  if (m1 == 0 && m1 != 30 && m2 != 30)
    {
      m1 = 1;
      //      return;
    }


 

  m1 = (-front * 100 + side * 100) / 180 * 100 + 30;
  m2 = (front * 100 + side * 100) / 180 * 100 + 30;
  m3 = (front * 100 - side * 100) / 180 * 100 + 30;
  m4 = (-front * 100 - side * 100) / 180 * 100 + 30;

  if (m1 <30)
    m1 = 30;
  if (m2 <30)
    m2 = 30;
  if (m3 <30)
    m3 = 30;
  if (m4 <30)
    m4 = 30;


  str << M_IDENTIFIER;
  str << SERIAL_OUTPUT_DELIM;
  str <<  m1;
  str << SERIAL_OUTPUT_DELIM;
  str <<  m2;
  str << SERIAL_OUTPUT_DELIM;
  str <<  m3;
  str << SERIAL_OUTPUT_DELIM;
  str <<  m4;
  str << SERIAL_OUTPUT_DELIM;
  str << '\n';
  std::string f = str.str();
  serial.write(f);
  std::cout << "OK :: " << f << std::endl;
}

int main()
{
  AIRegistry::client registry(127.0.0.1, 5006);

  Serial serial(SERIAL_PORT, SERIAL_BAUDRATE);
  Parser parser_global(SERIAL_LINE_DELIM);
  
  char buffer[BUFFER_LEN];
  int read;
  std::string cmd;


  registry.connect();
  std::cout << "Registry connected" << std::endl;
  int i = 0;

  while (true)
    {
      i++;
      //Do motors
      if (i == 10)
	{
	  dispatchMotors(registry, serial);
	  i =0;
	}
      //Read and make CMD
      read = serial.read(buffer, BUFFER_LEN -1);
      if (read > 0)
	{
	  buffer[read] = 0;
	  parser_global.feed(buffer);
	  if (parser_global.isReady())
	    {
	      parser_global.getToken(cmd);
	      std::cout << cmd << std::endl;
	      dispatchCmd(cmd, registry);
	    }
	}


      
    }

  registry.disconnect();
}
