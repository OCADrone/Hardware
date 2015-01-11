/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 10:27:04
* @Last update   : 2014-06-12 23:45:40
*/

#include "Request.hh"

using namespace std;
using namespace registry;
using namespace KNM;

Request::Request()
{
	command = CTRL;
	sock 	= NULL;
}

/**
 * @param _ref Reference to copy from.
 */
Request::Request(const Request &_ref)
{
	if (&_ref != this)
	{
		*this = _ref;
		/*this->sock 		= _ref.sock;
		this->command 	= _ref.command;
		this->path 		= _ref.path;
		this->data 		= _ref.data;*/
	}
}

/**
 * @param _ref Reference to copy from.
 */
Request	&Request::operator=(const Request &_ref)
{
	if (&_ref != this)
	{
		reset();
		this->sock 		= _ref.sock;
		this->command 	= _ref.command;
		this->path 		= _ref.path;
		this->data 		= _ref.data;
	}
	return *(this);
}

/**
 * @param _sock Socket to use.
 */
Request::Request(KSocket *_sock)
{
	command = CTRL;
	sock 	= _sock;
}

void 	Request::reset()
{
	if (sock){sock->close();}
	command = CTRL;
	path 	= "";
	data 	= "";
}

Request::~Request()
{
	if (sock){sock->close();}
}

/**
 * @param _sock Socket to use.
 */
void 	Request::set_sock(KSocket *_sock)
{
	sock = _sock;
}

void 			Request::flush()
{
	path    = "";
	data    = "";
	command = CTRL;
}

/**
 * @param _cmd Command to perform.
 * @param _path To to access or create.
 * @param _data Data to insert.
 */
void 	Request::set(enum commands _cmd, const string &_path, const string &_data)
{
	command = _cmd;
	path 	= _path;
	data 	= _data;
}

bool 	Request::send()
{
	if (sock)
	{
		try
		{
			sock->send((int)command);
			sock->send(path.size());
			sock->send(data.size());
			if (path.size() > 0) {sock->send(path);}
			if (data.size() > 0) {sock->send(data);}
		}
		catch (KError *error)
		{
			//error->dump();
			return false;
		}
		return true;
	}
	return false;
}

bool 	Request::receive()
{
	size_t 	path_len = 0;
	size_t 	data_len = 0;
	char 	*buffer  = NULL;

	if (sock)
	{
		try
		{
			sock->receive((int*)&command);
			sock->receive((int*)&path_len);
			sock->receive((int*)&data_len);

			if (path_len > 0)
			{
				buffer = new char[path_len + 1];
				memset(buffer, 0, path_len + 1);
				sock->receive(buffer, path_len);
				path.assign(buffer);
				delete[] buffer;
			}

			if (data_len > 0)
			{
				buffer = new char[data_len + 1];
				memset(buffer, 0, data_len + 1);
				sock->receive(buffer, data_len);
				data.assign(buffer);
				delete[] buffer;
			}
		}
		catch (KError *error)
		{
			//error->dump();
			return false;
		}
		return true;
	}
	return false;
}

enum commands 	Request::get_command()
{
	return command;
}

const string 	&Request::get_path()
{
	return path;
}

const string 	&Request::get_data()
{
	return data;
}
