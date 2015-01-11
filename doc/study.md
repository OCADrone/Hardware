
Here are some interesting facts about our firmware datas.

We measured (6/21/2014):

* **Low constant memory usage** of around 2KB of the 6KB provided by the Arduino Mega board
* Around **10 updates per seconds of all our sensors**. The GPS is updated one time per second, the other sensors are updated every 90 ms!
* Low serial communication with around **70 byte sent per updates**.
* **No init time**, every sensor works as soon as Arduino booted. (the GPS may need fixing time).
* **No temperature variation** of the Arduino board (overheating).
* **Constant power consumption**.
* Let the firmware run for 10 hours without any changes in statistics.
