OCADrone Hardware
=================

Introduction
-----------

Welcome to the documentation of the Hardware part of the [OCADrone project](http://ocadrone.com). The Hardware part is responsible of making the link between the different sensors and motors and the kernel of the project.

The interaction with the electronics parts is made with an [Arduino MEGA](http://arduino.cc/en/Main/arduinoBoardMega). In order to link the Arduino and the [Raspberry Pi](http://www.raspberrypi.org/), we use Serial communication provided by USB linkage from the two platforms.


Going into the source code
--------------------------

* Every Arduino PINS and configurable values is defined in the file: ``config.hpp`` at the root of the source code. This file is heavily documentated and maintained.
* Every hardware parts has a folder and class dedicated to it. You can find more documentation about an hardware component following the menus links.



List of components
------------------

Here is the list of components we used to build our initial drones. However, we support a lot of different components, you can also easily adapt our sourcecode to your component just by changing values in the config file (Learn more in each composant page).

List of components:

* GPS
* Distance

Statistics
----------

We measured some performance of our firmware and [here are some interesting results](study.html).