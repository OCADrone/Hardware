
Helpers
=======

Helpers are a simple collection of function the different part of the project may need:

String
------

> String splitString(String s, char parser, int index)

Split a string with a delimiter character.

> int countCharacter(String s, char c);

Count how many time a character appears in a string.

Serial
------

> void resetSerial();

Reset the stats of serial usage (internal).

> void serialCharIncrement(int i);

Increment the number of character sent (internal).

> void serialCommandIncrement();

Increment the number of command sent (internal).

> int getCharSent();

Get how many characters were sent to the driver during last loop.

> int getCommandsSent();

Get how many commands were sent to the driver during last loop.

> void SEND(value)

Send a string, character, int or float to the driver.

> void SENDLN(value)

Send a string, character, int or float with a newline to the driver.

