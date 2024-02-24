# RPi-Mega-Dashboard

**Design Concept:** Vehicle speed, fuel, engine RPM, gearbox temp etc. of an off-road ATV are crucial data, which needs to be updated on driver's display on dashboard, as well as sent to the pit via radio.
Hall effect sensors for speed, fuel, and RPM are mounted on the vehicle, and wired up to an arduino which has an interrupt service routine running.
Gearbox temperature measurement require thermocouple, a basic one-wire DS18B20 will suffice as temps don't reach that high, and if it does go out of range, means vehicle needs to be stopped and cooled down.
Thercouple is also wired to same arduino, but this time is taking readings via normal polling routine.

Arduino is then further wired up with Raspberry Pi via generic USB cable. This provides the arduino with power, as well as data lines. RPi expects serial data, spaces between the data depicts whatthe data actually is.
A python script is running, expecting the serial data in a specified format, and will display the data on a 5inch diplay hooked up with RPi via HDMI cable.
Sensors and arduino have about 5m of wires between them, as sensors are mouonted on one of the front wheel while controllers are mounted behind driver, on the firewall.
Similarly for the display, it is mounted infront of the steering wheel, HDMI wire going back to the firewall.


During static testing, LoRa was found to work with arduino, sending raw data back to pit about 800m far away. But during dynamic testing, it was found to be incredibly unreliable and incoming data was too corrupt to be
interpreted back. RPi could've been used to upload data to some form of server, but that required a reliable internet connection to be present via mobile hotspot, which wasn't feasible. Hence, this idea was dropped
and only driver's display was used as vehicle diagnostics tool.


**Possible optimizations:** 
1. Update speed of data was slow; two data points per second is too slow for an offroad racing vehcile.
2. Data needs to be transmitted to pit for vehicle status. Vehcile isn't always in line-of-sight.
3. Sensors can directly be hooked up to RPi, eradicating the need of an entire controller. However, code reliability and update speed cannot be compromised to achieve this.
