

#include	"main.hpp"


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
  //  std::cout << path << " : GET : " << res << std::endl; 
  return (res);
}


void dispatchMotors(AIRegistry::client &client, Serial &serial)
{
  // std::cout << "MOTTTTTTTTTTOR" << std::endl;
  int m1, m2, m3, m4;
  std::stringstream str;

  m1 = getMotorValue(client, PATH_MOTOR1);
  m2 = getMotorValue(client, PATH_MOTOR2);
  m3 = getMotorValue(client, PATH_MOTOR3);
  m4 = getMotorValue(client, PATH_MOTOR4);

  if (m1 < 0)
    m1 = 0;
  if (m2 < 0)
    m2 = 0;
  if (m3 < 0)
    m3 = 0;
  if (m4 < 0)
    m4 = 0;
  
  m1 = (m1) + 30;
  m2 = (m2) + 30;
  m3 = (m3) + 30;
  m4 = (m4) + 30;

  
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
}

int main()
{
  AIRegistry::client registry("127.0.0.1", 5006);

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
      if (i > 35)
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
