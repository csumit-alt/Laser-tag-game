# Laser-tag-game

To design a circuit diagram and write a code for a laser tag game system for the outdoor environment (Range 500 meters) that includes:
A laser emitter circuit (e.g., using IR LEDs or Laser Diode).
A sensor array (e.g., using an IR receiver or Photo Diode) to detect hits on the wearable unit.
Visual/audible indicators (LEDs/buzzers) to show when a player is hit.
A GPS module(you can take any GPS module that uses NMEA packets over UART e.g. Quectel L80) for getting the player’s positional information (Latitude & Longitude).
An RF module transmits the data to the control room through the network
Program microcontrollers (e.g., Arduino, ESP32) to process emitters and sensor signals.
Implement the following features:
Disabling a player’s laser emitter after they are hit.
Friendly fire can be on/off  
The ammunition Counter should be there (Range  0-100)
Reload of the ammunition should be there.
LED should blink for the 3 Sec after getting hit.
The buzzer should beep for 3 Sec after getting hit.
The system should be capable of getting the hit location.
