/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 09:54:51
* @Last update   : 2014-06-12 23:24:39
*/

#ifndef REGISTRY_COMMON_REQUEST_HH
#define REGISTRY_COMMON_REQUEST_HH

#include <string>
#include "Commands.hh"
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>

using namespace KNM;

namespace registry
{
	/**
	 * Registry request packet.
	 * Wrap client <-> server requests.
	 */
	class Request
	{
	public:
		Request();								/**< Default constructor. */
		Request(const Request &);				/**< Copy constructor. */
		Request &operator=(const Request &);	/**< Assignment operator. */
		Request(KSocket *);						/**< Construct with a connection. */
		void reset();							/**< Reset obect to its initial state. */
		~Request();								/**< Destructor. */

		// Configuration
		void 	set_sock(KSocket *);			/**< Set socket. */
		void 	flush();						/**< Clear buffer. */

		// Packet handling
		void 	set(enum commands,
					const string &,
					const string & = "");		/**< Set request content. */
		bool 	send();							/**< Send a request. */
		bool 	receive();						/**< Receive a request. */

		// Result handling
		enum commands 	get_command();			/**< Return command. */
		const string 	&get_path();			/**< Return path to access. */
		const string 	&get_data();			/**< Return data to use. */

	private:
		KSocket 		*sock;					/**< Socket. */
		enum commands 	command;				/**< Request type. */
		string 			path;					/**< Path to access / create. */
		string 			data;					/**< Data to insert / update. */
	};
}

#endif