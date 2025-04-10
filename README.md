
#  Arduino-Based Outdoor Laser Tag System

This project is a outdoor **laser tag system** built using an **Arduino Uno**, a **433 MHz RF transmitter**, and a **GPS module (Quectel L80)**. It simulates realistic laser tag gameplay with features like hit detection, GPS tracking, ammo counter, friendly fire options, and remote hit reporting.

---

##  Features

-  *Laser Emitter Simulation** (via LED or IR Laser)
-  **Hit Detection** (via pushbutton or IR sensor)
-  **Visual & Audible Feedback** (LED + buzzer after hit)
-  **GPS Integration** using Quectel L80 (NMEA over UART)
-  **433 MHz RF Transmitter** to send hit + location data
-  **Ammo Counter** with reload button
-  **Optional Friendly Fire Mode**

---

## Hardware Requirements

| Component         | Description                       |
|------------------|-----------------------------------|
| Arduino Uno       | Main controller                   |
| Quectel L80 GPS   | GPS module (UART, NMEA output)    |
| RF 433 MHz Transmitter | ASK type, for wireless TX       |
| IR/Laser LED      | Simulated firing output           |
| IR Receiver / Button | For hit detection              |
| Buzzer + LED      | Hit indicators                    |
| Pushbutton        | Reload and hit simulation         |
| Jumper wires, resistors, breadboard, etc. |

---

##  Pin Connections

| Arduino Pin | Component          |
|-------------|--------------------|
| D2          | Hit button         |
| D9          | GPS TX             |
| D4          | GPS RX             |
| D5          | Laser emitter LED  |
| D6          | LED and buzzer indicator    |
| D8          | Reload button      |
| D12         | 433 MHz RF TX Data |

---

## Libraries Used

- [`TinyGPS++`](https://github.com/mikalhart/TinyGPSPlus) – for GPS parsing  
- [`RadioHead`](https://www.airspayce.com/mikem/arduino/RadioHead/) – for RF transmission

> Install via Arduino Library Manager

---

##  How It Works

1. Player presses fire → laser blinks + ammo decreases.
2. When hit (button or IR sensor), RF module sends "HIT" + GPS coordinates.
3. LED + buzzer activate for 3 seconds.
4. Player can reload ammo (100 max) using reload button.
5. Data can be received at a base station (Arduino with RF Receiver).

---

##  Circuit Diagrams
![circuit ](https://github.com/user-attachments/assets/79a359b3-e42a-4722-a7b3-833a278b23db)



---



