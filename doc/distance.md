
Distance sensors
================

> Interface from [ISensor](isensor.html).

Every Distance sensor code is available in ``Distance/`` folder.

In order to find distance between objects surrounding a drone, we use **ultrasonic sansors**. This kind of sensors are perfectly adapted to our project because they have a high frequency of updating (around 30 per seconds) and a range from 1cm to 250cm.

In our basic configuration we use 8 sensors:

* FRONT
* LEFT
* BACK
* RIGHT
* UNDER
* UP
* FRONTLEFT (this have to be with 20 degrees angle from FRONT sensor)
* FRONTRIGHT (this have to be with 20 degrees angle from FRONT sensor)

![sensors image](assets/img/sensors.svg)

In order to make our project the most generic and reliable possible, we use the [NewPing Arduino library](http://playground.arduino.cc/Code/NewPing) which offers a lot of hardware compatibility (See in Compatible sensors section).

Configuration
-------------

A classical ultrasonic sensor use **4 Arduino pins**. We'll describe it under:

* VCC (+5 Volt pin on Arduino)
* GND (GND pin on Arduino)
* TRIGGER (Configurable in ``config.hpp``)
* ECHO (Configurable in ``config.hpp``)

Code
----

In order to manipulate multiple ultrasonic sensors, we provide a class ``Distance/PingPool.h``. This class manage all our different sensors and update them as soon are they are available.

Once they are updated, they send the value to the driver through Serial communication in the following format: ``SENSOR1;SENSOR2;...``

Compatible sensors
------------------

* SR04 (We used this one)
* SRF05
* SRF06
* DYP-ME007
* Parallax PING)))