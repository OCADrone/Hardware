/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 10:01:19
* @Last update   : 2014-06-12 23:42:54
*/


#ifndef REGISTRY_COMMON_COMMANDS_HH
#define REGISTRY_COMMON_COMMANDS_HH

namespace registry
{
	/**
	 * Registry client <-> server commands.
	 * Faster and safer than command-as-string.
	 */
	enum commands
	{
		CTRL,		/**< Test connection. */
		READ,		/**< Get key value. */
		WRITE,		/**< Update key value. */
		MKNODE,		/**< Insert a node. */
		CHECK		/**< Check if a key exists. */
	};
}

#endif