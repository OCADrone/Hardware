
Protocol
========

The protocol is used to communicate between the firmware and the driver. This communication is made through serial, you can set the ``SERIAL_BAUDRATE`` int ``config.hpp`` file.

Each command is for a ``ISensor`` (from firmware to driver) or ``IActuator`` (from driver to firmware).

Format of a command:
--------------------

Here is the format for a command (String):

> [TYPE] ([DELIM][VALUE])* [ENDLINE]

* ``TYPE`` is a character defining a module, ``D`` for distance, ``M`` for motors..
* ``DELIM`` is a character defined in ``config.hpp``
* ``VALUE`` is a value to pass to the module.

Each module handle his messages the way it wants.
