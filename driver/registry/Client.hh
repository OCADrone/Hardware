/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-10 15:20:06
* @Last update   : 2014-06-13 01:42:39
*/

/**
 * \file client/Client.hh
 */

#ifndef _H_CLIENT__
#define _H_CLIENT__

#include <string>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include "Commands.hh"
#include "Default.hh"
#include "Request.hh"
#include "Answer.hh"

using namespace std;
using namespace KNM;
using namespace registry;

namespace registry
{
	/**
	 * Registry client API.
	 * Access a registry server using a single object.
	 */
	class 	Client
	{
	public:
		Client();											/**< Default constructor. */
		Client(const Client &);								/**< Copy constructor. */
		Client &operator=(const Client &);					/**< Assignment operator. */
		Client(KSocket *);									/**< Construct with a KSocket. */
		Client(const string &,
			   int = REGISTRY_DEFAULT_SERVER_PORT);			/**< Construct with server network parameters. */
		void reset();										/**< Reset object initial state. */
		~Client();											/**< Destructor. */

		void 			set_sock(KSocket *);				/**< Set socket object. */
		void 			set_network(const string &, int);	/**< Set network parameters. */
		void 			set_address(const string &);		/**< Set server address. */
		void 			set_port(int);						/**< Set server port. */
		void			connect();							/**< Connect to server. */
		void 			disconnect();						/**< Disconnect from server. */
		const string 	&query(enum commands,
							   const string &,
							   const string & = "");		/**< Send a request to the server. */


	private:
		KSocket 		*sock;								/**< Socket to use in connection. */
		KSocket::pool 	pool;								/**< Socket pool for I/O operations. */
		Request 		request;							/**< Protocol request wrapper. */
		Answer 			answer;								/**< Protocol answer wrapper. */
		string 			result;								/**< Stored result. */
	};
}

#endif
