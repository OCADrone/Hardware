/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-10 15:20:06
* @Last update   : 2014-06-13 01:42:17
*/

/**
 * \file client/Client.cpp
 */


#include "Client.hh"

using namespace std;
using namespace KNM;
using namespace registry;

Client::Client()
{
	sock = new KSocket(KSocket::TCP4,
					   REGISTRY_DEFAULT_SERVER_ADDRESS,
					   REGISTRY_DEFAULT_SERVER_PORT);

}

/**
 * @param _ref Reference to copy from.
 */
Client::Client(const Client &_ref)
{
	if (&_ref != this)
		*this = _ref;
}

/**
 * @param _ref Reference to copy from.
 */
Client &Client::operator=(const Client &_ref)
{
	if (&_ref != this)
	{
		reset();
		sock   = _ref.sock;
		result = "";
	}
	return *this;
}

/**
 * @param _sock Socket to use for connection.
 */
Client::Client(KSocket *_sock): sock(_sock)
{

}

/**
 * @param _address Server address.
 * @param _port Server port.
 */
Client::Client(const string &_address, int _port)
{
	sock = new KSocket(KSocket::TCP4, _address, _port);
}

void Client::reset()
{
	if (sock)
		sock->disconnect();
}

Client::~Client()
{
	reset();
}

/**
 * @param _sock Socket to use for connection.
 */
void 	Client::set_sock(KSocket *_sock)
{
	reset();
	sock = _sock;
}

/**
 * @param _address Server address.
 * @param _port Server port.
 */
void 	Client::set_network(const string &_address, int _port)
{
	set_address(_address);
	set_port(_port);
}

/**
 * @param _address Server address.
 */
void 	Client::set_address(const string &_address)
{
	if (sock)
		sock->setAddress(_address);
	else
		sock = new KSocket(KSocket::TCP4, _address, REGISTRY_DEFAULT_SERVER_PORT);
}

/**
 * @param _port Server port.
 */
void 	Client::set_port(int _port)
{
	if (sock)
		sock->setPort(_port);
	else
		sock = new KSocket(KSocket::TCP4, REGISTRY_DEFAULT_SERVER_ADDRESS, _port);
}

void 	Client::connect()
{
	if (sock)
	{
		sock->connect();
		sock->setNagle(false);
		answer.set_sock(sock);
		request.set_sock(sock);
	}
	else
		throw new KError("Client::connect()", "connection is not configured");
}

void 	Client::disconnect()
{
	if (sock)
	{
		answer.set_sock(NULL);
		request.set_sock(NULL);
		reset();
	}
	else
		throw new KError("Client::disconnect()", "connection is not configured");
}

/**
 * @param _cmd Command to perform.
 * @param _path Path of key to create / update.
 * @param _value Value to insert.
 */
const string 	&Client::query(enum commands _cmd, const string &_path, const string &_data)
{
	if (sock)
	{
		try
		{
			request.set(_cmd, _path, _data);
			request.send();
			answer.receive();
			if (answer.get_state())
				result = answer.get_data();
			else
				result = "";
		}

		catch (KError *error)
		{
			disconnect();
		}

	}
	else
		throw new KError("Client::query()", "connection is not configured");

	return result;
}
