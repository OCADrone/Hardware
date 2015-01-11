/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 09:55:10
* @Last update   : 2014-06-12 23:25:16
*/

#ifndef REGISTRY_COMMON_ANSWER_HH
#define REGISTRY_COMMON_ANSWER_HH

#include <string>
#include "Commands.hh"
#include <KError.hh>
#include <KSocket.hh>

using namespace KNM;

namespace registry
{
	/**
	 * Registry answer packet.
	 * Wrap client <-> server answers.
	 */
	class Answer
	{
	public:
		Answer();								/**< Default constructor. */
		Answer(const Answer &);					/**< Copy constructor. */
		Answer &operator=(const Answer &);		/**< Assignment operator. */
		Answer(KSocket *);						/**< Construct with a connection. */
		void reset();							/**< Reset obect to its initial state. */
		~Answer();								/**< Destructor. */

		// Configuration
		void 	set_sock(KSocket *);			/**< Set socket. */
		void 	flush();						/**< Clear buffers. */

		// Packet handling
		void 	set(bool state,
					const string & = "");		/**< Set request content. */
		bool 	send();							/**< Send a request. */
		bool 	receive();						/**< Receive a request. */

		// Result handling
		bool 			get_state();			/**< Return last command state. */
		const string 	&get_data();			/**< Return last command data. */

	private:
		KSocket 	*sock;						/**< Socket. */
		bool 		state;						/**< Command execution state. */
		string 		data;						/**< Answer data / failure message. */
	};
}

#endif
