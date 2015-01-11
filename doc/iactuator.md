
IActuator
=========

IActuator is an interface that actuators should use. It is defined in ``IActuator.hpp``.

Methods
-------

> setup()

Called during the setup of the firmware. In this callback, you should init things such as Serial communication, memory allocation..

> update()

Called everytime to update the datas and send them if it is needed. The datas should be received using ``SERIAL`` define. Never block the execution as other modules may also need to update.



