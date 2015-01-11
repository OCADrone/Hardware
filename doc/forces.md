
Forces sensors
================

> Interface from [ISensor](isensor.html).

Every Force sensor code is available in ``Force/`` folder.


In order to get the position and forces that apply to the drone we use an **Nine-Axis (Gyro + Accelerometer + Compass)**. 

In order to make our project the most generic and reliable possible, we use the
[MPU6050 / MPU9150 sensor library from Adafruit](http://playground.arduino.cc/Main/MPU-6050).

Configuration
-------------

The MPU-9050 does not need a lot of configuration. Just plug the GPS with the followi
ng:

![forces image](assets/img/forces.png)


* VCC (+3 Volt pin on Arduino)
* GND (GND pin on Arduino)
* SCL (SCL pin 21 on Arduino Mega)
* SDA (SDA pin 20 on Arduino Mega)

Compatible sensors
------------------

* MPU-9050
* MPU-6050 (but doesn't have compass sensor)
