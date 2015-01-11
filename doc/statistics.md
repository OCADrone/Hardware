
Statistics
==========

> Interface from [ISensor](isensor.html).

This module is used to analyse how the firmware do:

> See [our study on how our firmware do](study.html)!

Every Statistics code is available in ``Statistics/`` folder.

This is a fake module used in order to get datas from the firmware. This maybe activated or deactivated in the ``config.hpp`` file as it is only useful during development process or benchmarking.

Available datas:

* Time spent for each update loop
* current Arduino time (``millis()``)
* Remaining free memory on the Arduino
* Number of characters printed per update loops (number of ``SERIAL.print()``)
* Number of commands send per update loops (number of ``SERIAL.println()``)
* Number of characters read per update loops (number of ``SERIAL.getchar()``)

