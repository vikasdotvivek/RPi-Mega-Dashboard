# RPi-Mega-Dashboard

**Design Concept:** Vehicle speed, fuel, engine RPM, gearbox temp etc. of an off-road ATV are crucial data, which needs to be updated on driver's display on dashboard, as well as sent to the pit via radio.
Hall effect sensors for speed, fuel, and RPM are mounted on the vehicle, and wired up to an Arduino which has an interrupt service routine running.
Gearbox temperature measurement requires thermocouple, a basic one-wire DS18B20 will suffice as temps don't reach that high, and if it does go out of range, means vehicle needs to be stopped and cooled down.
Thercouple is also wired to same arduino, but this time it's taking readings via normal polling routine.

Arduino is then further wired up with Raspberry Pi via generic USB cable. This provides the arduino with power, as well as data lines. RPi expects serial data, spaces between the data depicts what the data actually is.
A python script is running, expecting the serial data in a specified format, and will show data on a 5inch display hooked up with RPi via HDMI cable.
Sensors and arduino have about 5m of wires between them, as sensors are mounted on one of the front wheels while controllers are mounted behind driver, on the firewall.
Similarly for the display, it is mounted infront of the steering wheel, with HDMI wire going back to the firewall.


During static testing, LoRa was found to work with arduino, sending raw data back to pit about 800m far away. But during dynamic testing, it was found to be incredibly unreliable and incoming data was too corrupt to be
interpreted back. RPi could've been used to upload data to some form of server, but that required a reliable internet connection to be present via mobile hotspot, which wasn't feasible. Hence, this idea was dropped
and only driver's display was used as vehicle diagnostics tool.

**Important:** QtGUI wasn't completed in time for competition, a pre-made open source library was used from ardiotech.com

**Possible optimizations:** 
1. Update speed of data was slow; two data points per second is too slow for an offroad racing vehcile.
2. Data needs to be transmitted to pit for vehicle status. Vehcile isn't always in line-of-sight.
3. Sensors can directly be hooked up to RPi, eradicating the need of an entire controller. However, code reliability and update speed cannot be compromised to achieve this.

![image](https://github.com/vikasdotvivek/RPi-Mega-Dashboard/assets/43683145/8076757d-fee7-40fd-8dfc-828c62d1ec02)


**Some previous iterations:**


![image](https://github.com/vikasdotvivek/RPi-Mega-Dashboard/assets/43683145/24a351be-611d-4e54-887e-7f0d196ce43b)

![image](https://github.com/vikasdotvivek/RPi-Mega-Dashboard/assets/43683145/4cc89bfa-cefb-451e-9d49-7d02b04abe14)

![image](https://github.com/vikasdotvivek/RPi-Mega-Dashboard/assets/43683145/b9efe121-9a00-445e-8cfa-644a844b38c8)

![image](https://github.com/vikasdotvivek/RPi-Mega-Dashboard/assets/43683145/f91ce5b9-c9ca-4e48-aee2-dfff3f4bcb26)












