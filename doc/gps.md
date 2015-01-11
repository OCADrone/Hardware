
GPS sensor
==========

> Interface from [ISensor](isensor.html).

Every GPS code is available in ``GPS/`` folder.

In order to have compatibility with a lot of sensors and efficiency we use the [TinyGPS library](http://jules.dourlens.com/gps-ublox-neo-6m-and-arduino/).

Configuration
-------------

The GPS does not need a lot of configuration. Just plug the GPS with the following:

![gps image](assets/img/gps.png)

The way of handling the GPS is more described [here](http://jules.dourlens.com/gps-ublox-neo-6m-and-arduino/).

for configuration, you have few settings in the file ``config.hpp`` such as choosing the ``SERIAL`` port and ``BAUDRATE``.

Code
----

The code of the GPS sensor heavily depends on TinyGPS library. However, in order to integrate the lirary in our firmware we use a class GPS available at: ``GPS/GPS.h``.

Compatible sensors
------------------

We use the NEO 6M gps module. However all the GPS that use the ``NMEA 0183`` protocol should work. Here is a list of GPS modules you could use:

* Copernicus II (12 Channel)
* Copernicus II DIP (12 Channel)
* Venus638FLPx-L 20Hz (14 Channel)
* EM-506 (48 Channel)
* EM-408 SiRF III (20 Channel)
* GP-635T (50 Channel)
* LS20031 5Hz (66 Channel)

A lot more..

