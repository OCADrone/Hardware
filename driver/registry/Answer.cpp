/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 10:26:52
* @Last update   : 2014-06-12 23:44:20
*/

#include "Answer.hh"

using namespace std;
using namespace registry;
using namespace KNM;

Answer::Answer()
{
	sock  = NULL;
	state = false;
}

/**
 * @param _ref Reference to copy from.
 */
Answer::Answer(const Answer &_ref)
{
	if (&_ref != this)
		*this = _ref;
}

/**
 * @param _ref Reference to copy from.
 */
Answer 	&Answer::operator=(const Answer &_ref)
{
	if (&_ref != this)
	{
		sock  = _ref.sock;
		state = _ref.state;
		data  = _ref.data;
	}
	return (*this);
}

/**
 * @param _sock Socket to use.
 */
Answer::Answer(KSocket *_sock)
{
	sock  = _sock;
	state = false;
}

void 	Answer::reset()
{
	if (sock){sock->close();}
	state = false;
}

Answer::~Answer()
{
	if (sock){sock->close();}
}

/**
 * @param _sock Socket to use.
 */
void 	Answer::set_sock(KSocket *_sock)
{
	sock = _sock;
}

void 	Answer::flush()
{
	state = false;
	data  = "";
}

/**
 * @param _state Set answer state.
 * @param _data Set answer data.
 */
void 	Answer::set(bool _state, const string &_data)
{
	state = _state;
	data  = _data;
}

bool 	Answer::send()
{
	if (sock)
	{
		try
		{
			sock->send((int)state);
			sock->send((int)data.size());
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

bool 	Answer::receive()
{
	int 	data_len = 0;
	char 	*buffer  = NULL;

	if (sock)
	{
		try
		{
			sock->receive((int*)&state);
			sock->receive((int*)&data_len);

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

bool 	Answer::get_state()
{
	return state;
}

const string 	&Answer::get_data()
{
	return data;
}