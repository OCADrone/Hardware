
Architecture
============

The Harware part make the link between the components and the flight controller of OCADrone.

They are three levels of communication:

* **Firmware / Driver** which is a serial communication following [our protocol](protocol.html).
* **Driver / OCadrone** which is a communication made with registery.
* **Firmware / Components** which depends on the type of component.

![architecture image](assets/img/architecture.png)
